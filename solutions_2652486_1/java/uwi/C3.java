package gcj2013.r1a;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class C3 {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + C3.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-2-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
//	static String INPUT = "1\n2 3 4 4 9 4 36 1 1 1 1 1";
//	static String INPUT = "1\n1 12 8 12 1 2 3 4 5 6 7 8 9 10 12 12";
	
	List<int[]> ds;
	int[] hist;
	
	public void call()
	{
		int R = ni(), n = ni(), m = ni(), K = ni();
		hist = new int[n];
		ds = new ArrayList<int[]>();
		dfs(0, 2, m);
		tr(ds.size());
		
		int[][] C = new int[20][20];
		for(int i = 0;i < 20;i++){
			C[i][0] = 1;
			for(int j = 1;j <= i;j++){
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
		
//		save("x:\\gcj\\ds", ds);
		List<long[]> dbs = new ArrayList<long[]>();
		List<long[]> dfreq = new ArrayList<long[]>();
		for(int[] h : ds){
			long[][] lmap = new long[1<<n][];
			for(int i = 0;i < 1<<n;i++){
				long prod = 1;
				for(int j = 0;j < n;j++){
					if(i<<31-j<0){
						prod *= h[j];
					}
				}
				int bc = Integer.bitCount(i);
				lmap[i] = new long[]{prod, C[n][bc]};
			}
			Arrays.sort(lmap, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return Long.signum(a[0] - b[0]);
				}
			});
			int p = 0;
			for(int i = 0;i < 1<<n;i++){
				if(i == 0 || lmap[i][0] != lmap[i-1][0]){
					lmap[p++] = lmap[i];
				}else{
					lmap[p-1][1] += lmap[i][1];
				}
			}
			
			long[] bs = new long[p];
			long[] freq = new long[p];
			for(int i = 0;i < p;i++)bs[i] = lmap[i][0];
			for(int i = 0;i < p;i++)freq[i] = lmap[i][1];
			
			dbs.add(bs);
			dfreq.add(freq);
		}
//		save("x:\\gcj\\dbs", dbs);
//		save("x:\\gcj\\dfreq", dfreq);
//		List<long[]> dbs = load("x:\\gcj\\dbs");
//		List<long[]> dfreq = load("x:\\gcj\\dfreq");
		
		out.println();
		for(int r = 0;r < R;r++){
			long[] a = new long[K];
			for(int i = 0;i < K;i++)a[i] = nl();
			double maxpp = 0;
			int maxi = 0;
			inner:
			for(int i = 0;i < dbs.size();i++){
				double pp = 1;
				long[] bs = dbs.get(i);
				long[] freq = dfreq.get(i);
				for(int j = 0;j < K;j++){
					int ind = Arrays.binarySearch(bs, a[j]);
					if(ind < 0)continue inner;
					pp *= freq[ind];
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
	
	
	public static void save(String path, Object arg)
	{
		try {
			ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(path));
			oos.writeObject(arg);
			oos.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static <T> T load(String path)
	{
		try {
			ObjectInputStream ois = new ObjectInputStream(new FileInputStream(path));
			@SuppressWarnings("unchecked")
			T ret = (T)ois.readObject();
			ois.close();
			return ret;
		} catch (SecurityException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
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
	
	public C3(int cas, Scanner in, PrintWriter out)
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
			new C3(i+1, in, out).call();
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
