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
public class SafetyInNumbers {
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
		DecimalFormat df = new DecimalFormat("0.000000");
		int x = 0;
		for(int i : p) x+=i;
		boolean[] e = new boolean[p.length];
		double ave = 0.0;
		while(true){
			int t = 0; int c = 0;
			for(int i=0;i<p.length;i++){
				if(e[i])continue;
				t += p[i];
				c++;
			}
			double a = (double)(t + x)/(double) c;
			boolean isNG = false;
			for(int i=0;i<p.length;i++){
				if(!e[i] && (double)p[i]>a){
					e[i] = true;
					isNG = true;
				}
			}
			if(isNG) continue;
			ave = a;
			break;
		}
		String ret = "";
		for(int i=0;i<p.length;i++){
			double a = (ave - (double)p[i])/(double)x * 100.0;
			if(a<0) a = 0.0;
			ret += df.format(a) + " ";
		}
		return ret.trim();
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
