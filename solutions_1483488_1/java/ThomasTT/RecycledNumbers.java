import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/**
 * @author Seitaro Sakoda
 *
 */
public class RecycledNumbers {
	
	private static final HashMap<Long, Integer> cache = new HashMap<Long, Integer>();
	private static final ArrayList<Long> list = new ArrayList<Long>();
	private static final long MASK = 10000000;
	
	private static void init(){
		for(int i=10;i<=2000000;i++){
			int L = (int)Math.log10(i);
			int D = (int)Math.pow(10.0, L);
			int k = i;
			for(int j=0;j<L;j++){
				k = (k%D)*10+(k/D);
				if(k!=i) {
					long min = Math.min(i, k);
					long max = Math.max(i,k);
					long key = min*MASK + max;
					if(!cache.containsKey(key)){
						cache.put(key, 0);
					}
				}
			}
		}
		list.addAll(cache.keySet());
	}

	
	public static void main(String[] args) throws Exception {
		DataReader dr = new DataReader();
		int NoT = dr.readInt();
		ArrayList<String> ans = new ArrayList<String>();
		long start = System.currentTimeMillis();
		init();
		System.out.println("INIT:"+(System.currentTimeMillis()-start)+" ms");
		for(int not=0;not<NoT;not++){
			int[] tmp = dr.readInts();
			long start1 = System.currentTimeMillis();
			ans.add("Case #"+(not+1)+": "+doit(tmp[0],tmp[1]));
			System.out.println((not+1)+":"+(System.currentTimeMillis()-start1)+" ms");	
		}
		dr.close();
		DataWriter dw = new DataWriter();
		for(int not=0;not<NoT;not++) dw.writeLine(ans.get(not));
		dw.close();
	}

	/**
	 * @param c
	 * @param data 523
	 * @return
	 */
	private static int doit(int A, int B) {
		int ans = 0;
		for(long a : list){
			if((int)(a/MASK)>=A && (int)(a%MASK)<=B) ans++;
		}
		return ans;
	}
	
	
	
	
	
	
	static class DataReader {
		public BufferedReader br;
		
		public DataReader(String filename) throws Exception {
			br = new BufferedReader(new FileReader(filename));
		}
		
		public DataReader() throws Exception {
			this("data.in");
		}
		
		private String readLine() throws Exception {
			return br.readLine();
		}
		
		public int readInt() throws Exception {
			return Integer.parseInt(readLine());
		}
		
		public int[] readInts() throws Exception {
			String[] tmp = readLine().split(" ");
			int[] ret = new int[tmp.length];
			for(int i=0;i<tmp.length;i++) ret[i] = Integer.parseInt(tmp[i]);
			return ret;
		}
		
		public String readString() throws Exception {
			return readLine();
		}
		
		public String[] readStrings() throws Exception {
			return readLine().split(" ");
		}
		
		public void close() throws Exception {
			br.close();
		}	
	}
		
	static class DataWriter {
		public BufferedWriter bw;
		
		public DataWriter(String filename) throws Exception {
			bw = new BufferedWriter(new FileWriter(filename));
		}
		
		public DataWriter() throws Exception {
			this("data.out");
		}
		
		public void writeLine(String line) throws Exception {
			bw.write(line);
			bw.newLine();
		}
		
		public void close() throws Exception {
			bw.flush();
			bw.close();
		}
		
	}

}
