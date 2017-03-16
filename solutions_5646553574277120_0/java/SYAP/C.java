package roundone;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class C implements Runnable {
	static final boolean PRODUCT_CODE = true;
	static final int NTHREAD = 4;
    static final String PROBLEM_NAME = "roundonec";
    static final String WORK_DIR = "C:\\Users\\Okubo\\Desktop\\gcjfile\\" + PROBLEM_NAME + "\\";
    static final String INPUT_FILE_NAME = "C-small-attempt1.in";
    static final String OUTPUT_FILE_NAME = "output.txt";
	
	static String INPATH = WORK_DIR + INPUT_FILE_NAME;
	static String OUTPATH = WORK_DIR + OUTPUT_FILE_NAME;
	
	static String INPUT = "";
	
	int c;
	int d;
	int v;
	int[] denomi;
	
	public void read() // not parallelized
	{
		c = ni();
		d = ni();
		v = ni();
		denomi = new int[d];
		for (int i = 0; i < d; i++) {
			denomi[i] = ni();
		}
	}
	
	public void process() // parallelized!
	{
		boolean[] cango = new boolean[v+1];
		for (int bitmask = 0; bitmask < (1<<d); bitmask++) {
			int sum = 0;
			for (int i = 0; i < d; i++) {
				if ((bitmask & (1<<i)) >= 1) {
					sum += denomi[i];
				}
			}
			if (sum <= v) cango[sum] = true;
		}
		
		int ans = 0;
//		HashSet<Integer> anyofthese = new HashSet<>();
		for (int i = 0; i < v+1; i++) {
			
			if (!cango[i]) {
				ans++;
				d++;
				int[] newdenomi = new int[d];
				for (int j = 0; j < denomi.length; j++) {
					newdenomi[j] = denomi[j];
				}
				newdenomi[d-1] = i;
				denomi = newdenomi;
				cango = rework();
				System.out.println(cango);
				i = 0;
//				boolean alreadythere = false;
//				for (int j = 0; j < i; j++) {
//					int a = i - j;
//					if (anyofthese.contains(a)) {
//						alreadythere = true;
//					}
//				}
//				if (alreadythere) continue;
//				for (int j = 0; j < i; j++) {
//					int a = i - j;
//					anyofthese.add(a);
//				}
//				ans++;
			}
		}
		
		out.println(ans);
	}
	
	public boolean[] rework() {
		boolean[] cango = new boolean[v+1];
		for (int bitmask = 0; bitmask < (1<<d); bitmask++) {
			int sum = 0;
			for (int i = 0; i < d; i++) {
				if ((bitmask & (1<<i)) >= 1) {
					sum += denomi[i];
				}
			}
			if (sum <= v) cango[sum] = true;
		}
		return cango;
	}
	
	public static void preprocess()
	{
	}
	
	Scanner in;
	PrintWriter out;
	StringWriter sw;
	int caseNum;
	static List<Status> running = new ArrayList<Status>();
	
	@Override
	public void run()
	{
		long S = System.nanoTime();
		// register
		synchronized(running){
			Status st = new Status();
			st.id = caseNum;
			st.S = S;
			running.add(st);
		}
		process();
		// deregister
		synchronized(running){
			for(Status st : running){
				if(st.id == caseNum){
					running.remove(st);
					break;
				}
			}
		}
		long G = System.nanoTime();
		
		if(PRODUCT_CODE){
			System.err.println("case " + caseNum + " solved. [" + (G-S)/1000000 + "ms]");
			synchronized(running){
				StringBuilder sb = new StringBuilder("running : ");
				for(Status st : running){
					sb.append(st.id + ":" + (G-st.S)/1000000 + "ms, ");
				}
				System.err.println(sb);
			}
		}
	}
	
	private static class Status {
		public int id;
		public long S;
	}
	
	public C(int caseNum, Scanner in)
	{
		this.caseNum = caseNum;
		this.in = in;
		this.sw = new StringWriter();
		this.out = new PrintWriter(this.sw);
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private long nl() { return Long.parseLong(in.next()); }
	private int[] na(int n) { int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = ni(); return a; }
	private double nd() { return Double.parseDouble(in.next()); }
	private void tr(Object... o) { if(!PRODUCT_CODE)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.nanoTime();
		
		ExecutorService es = Executors.newFixedThreadPool(NTHREAD);
		CompletionService<C> cs = new ExecutorCompletionService<C>(es);
		
		if(PRODUCT_CODE){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = PRODUCT_CODE ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = PRODUCT_CODE ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		preprocess();
		for(int i = 0;i < n;i++){
			C runner = new C(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			C runner = cs.take().get(); // not ordered
			runner.out.flush();
			runner.out.close();
			outs[runner.caseNum-1] = runner.sw.toString();
		}
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			out.append(outs[i]);
			out.flush();
		}
		
		long end = System.nanoTime();
		System.out.println((end - start)/1000000 + "ms");
		if(PRODUCT_CODE){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
