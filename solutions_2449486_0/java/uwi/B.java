package gcj2013.q;
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
	
	public void call()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = ni();
			}
		}
		for(int x = 100;x >= 1;x--){
			boolean[][] b = new boolean[n][m];
			boolean[][] c = new boolean[n][m];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					b[i][j] = a[i][j] <= x;
				}
			}
			inner1:
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if(!b[i][j]){
						continue inner1;
					}
				}
				for(int j = 0;j < m;j++){
					c[i][j] = true;
				}
			}
			inner2:
			for(int i = 0;i < m;i++){
				for(int j = 0;j < n;j++){
					if(!b[j][i]){
						continue inner2;
					}
				}
				for(int j = 0;j < n;j++){
					c[j][i] = true;
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if(b[i][j] != c[i][j]){
						out.println("NO");
						return;
					}
				}
			}
		}
		out.println("YES");
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
