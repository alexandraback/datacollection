package gcj2012;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class B {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	static int[][] best = new int[31][2];
	
	public static void prepare()
	{
		for(int i = 0;i <= 30;i++){
			best[i][0] = -1;
			best[i][1] = -1;
		}
		for(int i = 0;i <= 10;i++){
			for(int j = i;j <= 10;j++){
				for(int k = j;k <= 10;k++){
					int s = i+j+k;
					if(k-i <= 1){
						best[s][0] = Math.max(best[s][0], k);
					}else if(k-i == 2){
						best[s][1] = Math.max(best[s][1], k);
					}
				}
			}
		}
	}
	
	public void call()
	{
		int n = ni(), s = ni(), p = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		int[][] dp = new int[n+1][s+1];
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= s;j++){
				dp[i][j] = dp[i-1][j] + (best[a[i-1]][0] >= p ? 1 : 0);
				if(j-1 >= 0){
					dp[i][j] = Math.max(dp[i][j], dp[i-1][j-1] + (best[a[i-1]][1] >= p ? 1 : 0));
				}
			}
		}
		out.println(dp[n][s]);
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
	static void tr_(Object... o) { System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		boolean real = INPUT.isEmpty();
		
		prepare();
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
