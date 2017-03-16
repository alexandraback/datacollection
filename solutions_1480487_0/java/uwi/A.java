package gcj2012.r1b;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class A {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + A.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt1.in");
	static String OUTPATH = BASEPATH + A.class.getSimpleName() + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int n = ni();
		int[] a = new int[n];
		int s = 0;
		for(int i = 0;i < n;i++){
			a[i] = ni();
			s += a[i];
		}
		for(int i = 0;i < n;i++){
			double low = 0;
			double high = 100;
			while(high - low > 1E-10){
				double x = (high + low) / 2;
				double b = a[i] + s * x / 100;
				
				double u = 0;
				for(int j = 0;j < n;j++){
					if(j != i && a[j] < b){
						u += b-a[j];
					}
				}
				if(u + s*x/100 > s){
					high = x;
				}else{
					low = x;
				}
			}
			
			if(i > 0)out.print(" ");
			out.printf("%.10f", Math.max(0, low));
		}
		out.println();
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public A(int cas, Scanner in, PrintWriter out)
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
			new A(i+1, in, out).call();
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
