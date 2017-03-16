package gcj2015.q;
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

public class DL implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 7;
	static String BASEPATH = "c:\\temp\\gcj2015\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + DL.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt2.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int x, r, c;
	
	static final String G = "GABRIEL";
	static final String R = "RICHARD";
	
	public void read() // not parallelized
	{
		x = ni(); r = ni(); c = ni();
	}
	
	int[] dr = { 1, 0, -1, 0 };
	int[] dc = { 0, 1, 0, -1 };
	
	public void process() // parallelized!
	{
		if(r*c % x != 0 || r < x && c < x || x >= 7){
			out.println(R);
		}else if(r >= x+2 && c >= x+2){
			out.println(G);
		}else{
			boolean[][] mino = new boolean[13][13];
			mino[6][6] = true;
			out.println(dfs(mino, x-1) ? G : R);
//			tr(ct);
		}
	}
	
	public static void tf(boolean[][] b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}
	
	int ct = 0;
	
	public boolean dfs(boolean[][] mino, int rem)
	{
		if(rem == 0){
			ct++;
			int minr = 9999, maxr = -1;
			int minc = 9999, maxc = -1;
			for(int i = 0;i < 13;i++){
				for(int j = 0;j < 13;j++){
					if(mino[i][j]){
						minr = Math.min(minr, i);
						maxr = Math.max(maxr, i);
						minc = Math.min(minc, j);
						maxc = Math.max(maxc, j);
					}
				}
			}
			
			if(check(r, c, minr, maxr, minc, maxc, mino))return true;
			if(check(c, r, minr, maxr, minc, maxc, mino))return true;
//			tf(mino);
			return false;
		}
		
		for(int i = 0;i < 13;i++){
			for(int j = 0;j < 13;j++){
				if(mino[i][j])continue;
				for(int k = 0;k < 4;k++){
					int nr = i + dr[k], nc = j + dc[k];
					if(nr >= 0 && nr < 13 && nc >= 0 && nc < 13 && mino[nr][nc]){
						mino[i][j] = true;
						if(!dfs(mino, rem-1))return false;
						mino[i][j] = false;
						break;
					}
				}
			}
		}
		return true;
	}
	
	boolean check(int r, int c, int minr, int maxr, int minc, int maxc, boolean[][] mino)
	{
		int h = maxr-minr+1;
		int w = maxc-minc+1;
		for(int i = 0;i+h-1 < r;i++){
			for(int j = 0;j+w-1 < c;j++){
				boolean[][] map = new boolean[r][c];
				for(int k = 0;k < h;k++){
					for(int l = 0;l < w;l++){
						if(mino[k+minr][l+minc]){
							map[k+i][l+j] = true;
						}
					}
				}
				DJSet ds = new DJSet(r*c);
				for(int k = 0;k < r;k++){
					for(int l = 0;l < c-1;l++){
						if(!map[k][l] && !map[k][l+1]){
							ds.union(k*c+l, k*c+l+1);
						}
					}
				}
				for(int k = 0;k < r-1;k++){
					for(int l = 0;l < c;l++){
						if(!map[k][l] && !map[k+1][l]){
							ds.union(k*c+l, (k+1)*c+l);
						}
					}
				}
				
				boolean dead = false;
				for(int k = 0;k < r;k++){
					for(int l = 0;l < c;l++){
						if(!map[k][l] && ds.upper[k*c+l] < 0){
							if(-ds.upper[k*c+1] % x != 0){
								dead = true;
							}
						}
					}
				}
				if(!dead)return true;
			}
		}
		return false;
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}
	
	public static void preprocess()
	{
	}
	
	Scanner in;
	PrintWriter out;
	StringWriter sw;
	int cas;
	static List<Status> running = new ArrayList<Status>();
	
	@Override
	public void run()
	{
		long S = System.nanoTime();
		// register
		synchronized(running){
			Status st = new Status();
			st.id = cas;
			st.S = S;
			running.add(st);
		}
		process();
		// deregister
		synchronized(running){
			for(Status st : running){
				if(st.id == cas){
					running.remove(st);
					break;
				}
			}
		}
		long G = System.nanoTime();
		
		if(PROD){
			System.err.println("case " + cas + " solved. [" + (G-S)/1000000 + "ms]");
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
	
	public DL(int cas, Scanner in)
	{
		this.cas = cas;
		this.in = in;
		this.sw = new StringWriter();
		this.out = new PrintWriter(this.sw);
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private long nl() { return Long.parseLong(in.next()); }
	private int[] na(int n) { int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = ni(); return a; }
	private double nd() { return Double.parseDouble(in.next()); }
	private void tr(Object... o) { if(!PROD)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.nanoTime();
		
		ExecutorService es = Executors.newFixedThreadPool(NTHREAD);
		CompletionService<DL> cs = new ExecutorCompletionService<DL>(es);
		
		if(PROD){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = PROD ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = PROD ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		preprocess();
		for(int i = 0;i < n;i++){
			DL runner = new DL(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			DL runner = cs.take().get(); // not ordered
			runner.out.flush();
			runner.out.close();
			outs[runner.cas-1] = runner.sw.toString();
		}
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			out.append(outs[i]);
			out.flush();
		}
		
		long end = System.nanoTime();
		System.out.println((end - start)/1000000 + "ms");
		if(PROD){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
