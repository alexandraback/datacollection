package gcj2013.r1a;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class C2 {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + C2.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-1-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
//	static String INPUT = "1\n2 3 4 4 9 4 36 1 1 1 1 1";
//	static String INPUT = "1\n2 3 5 7 9 4 36 1 1 1 1 1";
	
	List<int[]> ds;
	int[] hist;
	
	public void call()
	{
		int R = ni(), n = ni(), m = ni(), K = ni();
		hist = new int[n];
		ds = new ArrayList<int[]>();
		dfs(0, 2, m);
//		tr(ds.size());
		
		double[][] C = new double[10][10];
		for(int i = 0;i < 10;i++){
			C[i][0] = 1;
			for(int j = 1;j <= i;j++){
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
		
		List<double[]> dl = new ArrayList<double[]>();
		for(int[] h : ds){
			double[] ps = new double[(int)Math.pow(m, n)+1];
			for(int i = 0;i < 1<<n;i++){
				int prod = 1;
				for(int j = 0;j < n;j++){
					if(i<<31-j<0){
						prod *= h[j];
					}
				}
				int bc = Integer.bitCount(i);
				ps[prod] += C[n][bc] / (1<<n);
			}
			dl.add(ps);
		}
		
		out.println();
		for(int r = 0;r < R;r++){
			long[] a = new long[K];
			for(int i = 0;i < K;i++)a[i] = nl();
			double maxpp = 0;
			int maxi = 0;
			for(int i = 0;i < dl.size();i++){
				double[] d = dl.get(i);
				double pp = 1;
				for(int j = 0;j < K;j++){
					pp *= d[(int)a[j]];
				}
				if(pp > maxpp){
					maxpp = pp;
					maxi = i;
				}
			}
			for(int w : ds.get(maxi)){
				out.print(w);
			}
			out.println();
		}
	}
	
	void dfs(int pos, int cur, int m)
	{
		if(pos == hist.length){
			ds.add(Arrays.copyOf(hist, hist.length));
			return;
		}
		
		for(int i = cur;i <= m;i++){
			hist[pos] = i;
			dfs(pos+1, i, m);
		}
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public C2(int cas, Scanner in, PrintWriter out)
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
			new C2(i+1, in, out).call();
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
