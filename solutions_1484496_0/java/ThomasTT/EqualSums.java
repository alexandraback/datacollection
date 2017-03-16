import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.*;

/**
 * @author Seitaro Sakoda
 *
 */
public class EqualSums {
	public static void main(String[] args) throws Exception {
		DataReader dr = new DataReader();
		int N = dr.readInt();
		ArrayList<String> ans = new ArrayList<String>();
		for(int n=0;n<N;n++){
			int[] ALL = dr.readInts();
			int[] p = new int[ALL.length-1];
			System.arraycopy(ALL, 1, p, 0, p.length);
			ans.add("Case #"+(n+1)+": "+doit(p));
		}
		dr.close();
		DataWriter dw = new DataWriter();
		for(int n=0;n<N;n++) dw.writeLine(ans.get(n));
		dw.close();
	}

	/**
	 * @param c
	 * @param data
	 * @return
	 */
	private static String doit(int[] p) {
		int n = p.length; int N = 1<<n;
		Hashtable<Integer, String> c = new Hashtable<Integer, String>();
		for(int i=0;i<N;i++){
			int t = 0;
			String v = "";
			for(int j=0;j<n;j++){
				if(((i>>j)&1)==0) continue;
				t+=p[j];
				v += "" + p[j] + " ";
			}
			if(t==0)continue;
			v = v.trim();
			if(c.containsKey(t)){
				if(c.get(t).equals(v)) continue;
				return "\n"+c.get(t)+"\n"+v;
			}else{
				c.put(t, v);
			}
		}
		return "Impossible";
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
		
		public double readDouble() throws Exception {
			return Double.parseDouble(readLine());
		}
		
		public int[] readInts() throws Exception {
			String[] tmp = readLine().split(" ");
			int[] ret = new int[tmp.length];
			for(int i=0;i<tmp.length;i++) ret[i] = Integer.parseInt(tmp[i]);
			return ret;
		}
		
		public double[] readDoubles() throws Exception {
			String[] tmp = readLine().split(" ");
			double[] ret = new double[tmp.length];
			for(int i=0;i<tmp.length;i++) ret[i] = Double.parseDouble(tmp[i]);
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
