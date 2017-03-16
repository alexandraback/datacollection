package roundone;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class A implements Runnable {
	static final boolean PRODUCT_CODE = true;
	static final int NTHREAD = 4;
    static final String PROBLEM_NAME = "roundonea";
    static final String WORK_DIR = "C:\\Users\\Okubo\\Desktop\\gcjfile\\" + PROBLEM_NAME + "\\";
    static final String INPUT_FILE_NAME = "A-small-attempt0.in";
    static final String OUTPUT_FILE_NAME = "output.txt";
	
	static String INPATH = WORK_DIR + INPUT_FILE_NAME;
	static String OUTPATH = WORK_DIR + OUTPUT_FILE_NAME;
	
	static String INPUT = "";
	
	int r;
	int c;
	int w;
	
	public void read() // not parallelized
	{
		r = ni();
		c = ni();
		w = ni();
	}
	
	public void process() // parallelized!
	{
		int ans = 0;
		int left = c;
		if (r > 1) {
			ans += (c / w) * (r - 1);
		}
		
		//one move
		while (left > w) {
			ans++;
			left -= w;
		}
		ans += w;
		out.println(ans);
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
	
	public A(int caseNum, Scanner in)
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
		CompletionService<A> cs = new ExecutorCompletionService<A>(es);
		
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
			A runner = new A(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			A runner = cs.take().get(); // not ordered
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
