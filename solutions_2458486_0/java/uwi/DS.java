package gcj2013.q;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DS {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + DS.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt1.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int K = ni(), n = ni();
		int[] has1 = new int[K];
		for(int i = 0;i < K;i++){
			has1[i] = ni()-1;
		}
		int[] openKey = new int[n];
		int[][] gain = new int[n][];
//		int[][] copygain = new int[n][];
		for(int i = 0;i < n;i++){
			openKey[i] = ni()-1;
			int m = ni();
			gain[i] = new int[m];
			for(int j = 0;j < m;j++){
				gain[i][j] = ni()-1;
			}
		}
//		for(int i = 0;i < n;i++){
//			copygain[i] = Arrays.copyOf(gain[i], gain[i].length);
//		}
//		int[] copyopenKey = Arrays.copyOf(openKey, n);
//		
//		tr(openKey);
		
		int[] imap = shrinkX(openKey);
//		tr(imap);
//		tr(openKey);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < gain[i].length;j++){
				int v = gain[i][j];
				int ind = Arrays.binarySearch(imap, v);
				gain[i][j] = ind;
			}
		}
		int[] has = new int[20];
		for(int i = 0;i < K;i++){
			int v = has1[i];
			int ind = Arrays.binarySearch(imap, v);
			if(ind >= 0)has[ind]++;
		}
		
		int[][] canopen = new int[20][]; // [key]=box
		int[] cop = new int[20];
		for(int i = 0;i < n;i++){
			cop[openKey[i]]++;
		}
		for(int i = 0;i < 20;i++){
			canopen[i] = new int[cop[i]];
		}
		for(int i = n-1;i >= 0;i--){
			canopen[openKey[i]][--cop[openKey[i]]] = i;
		}
		
		int[] canReach = new int[1<<n];
		Arrays.fill(canReach, 999);
		outer:
		for(int i = (1<<n)-2;i >= 0;i--){
			int[] keyct = Arrays.copyOf(has, has.length);
			for(int j = 0;j < n;j++){
				if(i<<31-j<0){
					for(int v : gain[j]){
						if(v >= 0){
							keyct[v]++;
						}
					}
					keyct[openKey[j]]--;
				}
			}
			for(int j = 0;j < 20;j++){
				if(keyct[j] < 0)continue outer;
			}
			int min = 99999999;
			for(int j = 0;j < 20;j++){
				if(keyct[j] > 0){
					for(int v : canopen[j]){
						if(i<<31-v>=0 && canReach[i|1<<v] >= 0){
							min = Math.min(min, v);
						}
					}
				}
			}
			canReach[i] = min == 99999999 ? -1 : min;
		}
		
		if(canReach[0] == -1){
			out.println("IMPOSSIBLE");
			return;
		}
		int opened = 0;
		
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int v : has1){
			if(map.containsKey(v)){
				map.put(v, map.get(v)+1);
			}else{
				map.put(v, 1);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		while(opened != (1<<n)-1){
			int nex = canReach[opened];
			opened |= 1<<nex;
			sb.append(" ").append(nex+1);
			
			// D
//			int x = map.get(copyopenKey[nex]);
//			if(--x == 0){
//				map.remove(copyopenKey[nex]);
//			}else{
//				map.put(copyopenKey[nex], x);
//			}
//			for(int v : copygain[nex]){
//				if(map.containsKey(v)){
//					map.put(v, map.get(v)+1);
//				}else{
//					map.put(v, 1);
//				}
//			}
		}
		
		out.println(sb.substring(1));
	}
	
	public static int[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
//		b = radixSort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || (b[i]^b[i-1])>>32!=0)ret[p++] = (int)(b[i]>>32);
			a[(int)b[i]] = p-1;
		}
		return Arrays.copyOf(ret, p);
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public DS(int cas, Scanner in, PrintWriter out)
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
			new DS(i+1, in, out).call();
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
