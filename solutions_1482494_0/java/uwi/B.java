package gcj2012.r1a;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Comparator;
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
		int n = ni();
		int[][] ne = new int[n][];
		for(int i = 0;i < n;i++){
			ne[i] = new int[]{ni(), ni(), 0};
		}
		Arrays.sort(ne, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] - b[0] != 0)return a[0] - b[0];
				return -(a[1] - b[1]);
			}
		});
		for(int i = 0;i < n;i++){
			ne[i][2] = i;
		}
		
		Arrays.sort(ne, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[1] - b[1] != 0)return a[1] - b[1];
				return -(a[0] - b[0]);
			}
		});
		int[] imap = new int[n];
		for(int i = 0;i < n;i++){
			imap[ne[i][2]] = i;
		}
		
		int[] lo = new int[n];
		int star = 0;
		int ch = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n && star < ne[i][1] && star >= ne[imap[j]][0];j++){
				if(lo[imap[j]] == 0){
					star++;
					ch++;
					lo[imap[j]] = 1;
				}
			}
			if(star < ne[i][1]){
				out.println("Too Bad");
				// dededon!
				return;
			}
//			tr(lo, ch, star, ne[i][1]);
			star += 2-lo[i];
			ch++;
		}
		out.println(ch);
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
