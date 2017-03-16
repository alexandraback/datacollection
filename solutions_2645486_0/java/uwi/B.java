package gcj2013.r1a;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class B {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt2.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int e = ni(), r = ni(), n = ni();
		int[] v = new int[n];
		for(int i = 0;i < n;i++){
			v[i] = ni();
		}
		long[][] dp = new long[n+1][e+1];
		for(int i = 0;i <= n;i++){
			Arrays.fill(dp[i], -99999999);
		}
		dp[0][e] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= e;j++){
				if(j < e){
					for(int k = 0;k <= e;k++){
						if(k-j+r >= 0 && k-(k-j+r) >= 0){
							dp[i][j] = Math.max(dp[i][j], dp[i-1][k] + (k-j+r)*v[i-1]);
						}
					}
				}else{
					for(int k = 0;k <= e;k++){
						for(int c = 0;c <= r;c++){
							if(k-c+r >= e && k-c >= 0){
								dp[i][j] = Math.max(dp[i][j], dp[i-1][k] + c*v[i-1]);
							}
						}
					}
				}
			}
		}
		long ret = 0;
		for(int j = 0;j <= e;j++){
			ret = Math.max(ret, dp[n][j]);
		}
		out.println(ret);
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public B(int cas, Scanner in, PrintWriter out)
	{
		this.cas = cas;
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		boolean real = INPUT.isEmpty();
		
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = real ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = real ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new B(i+1, in, out).call();
			out.flush();
			if(real)System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
