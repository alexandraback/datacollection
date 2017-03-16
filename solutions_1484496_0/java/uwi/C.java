package gcj2012.r1b;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.Scanner;

public class C {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = BASEPATH + C.class.getSimpleName() + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
//	static String INPUT = "3\r\n20 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288\r\n" + 
//			"20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20\r\n" + 
//			"20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600";
	
	public void call()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		tr(n, a);
		
		int[][] q = new int[1<<n][];
		for(int i = 0;i < 1<<n;i++){
			int s = 0;
			for(int j = 0;j < n;j++){
				if(i<<31-j<0)s += a[j];
			}
			q[i] = new int[]{s, i};
		}
		Arrays.sort(q, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return a[0] - b[0];
			}
		});
		for(int i = 0;i < 1<<n-1;i++){
			if(q[i][0] == q[i+1][0]){
				int aa = q[i][1]&~q[i+1][1];
				int bb = q[i+1][1]&~q[i][1];
				out.println();
				{
					boolean fi = true;
					for(int j = 0;j < n;j++){
						if(aa<<31-j<0){
							if(!fi)out.print(" ");
							fi = false;
							out.print(a[j]);
						}
					}
				}
				out.println();
				{
					boolean fi = true;
					for(int j = 0;j < n;j++){
						if(bb<<31-j<0){
							if(!fi)out.print(" ");
							fi = false;
							out.print(a[j]);
						}
					}
				}
				out.println();
				return;
			}
		}
		out.println("Impossible");
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public C(int cas, Scanner in, PrintWriter out)
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
			new C(i+1, in, out).call();
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
