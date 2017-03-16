import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/**
 * @author Seitaro Sakoda
 *
 */
public class DancingWithTheGooglers {
	public static void main(String[] args) throws Exception {
		DataReader dr = new DataReader();
		int NoT = dr.readInt();
		ArrayList<String> ans = new ArrayList<String>();
		for(int not=0;not<NoT;not++){
			int[] tmp = dr.readInts();
			int[] t = new int[tmp.length-3];
			System.arraycopy(tmp, 3, t, 0, t.length);
			ans.add("Case #"+(not+1)+": "+doit(tmp[0],tmp[1],tmp[2],t));
		}
		dr.close();
		DataWriter dw = new DataWriter();
		for(int not=0;not<NoT;not++) dw.writeLine(ans.get(not));
		dw.close();
	}

	/**
	 * @param c
	 * @param data
	 * @return
	 */
	private static int doit(int N, int S, int p, int[] t) {
		int[] ns = new int[t.length]; // the best score in not-surprising case
		int[] ss = new int[t.length]; // the best score in surprising case
		for(int i=0;i<t.length;i++){
			switch(t[i]%3){
			case 0: // 7 7 7 or 6 7 8 
				ns[i] = t[i]/3;
				if(t[i] == 30){
					ss[i]=10;
				}else if(t[i] == 0){
					ss[i]=0;
				}else{
					ss[i] = (t[i]/3 + 1);
				}
				break;
			case 1: // 7 7 8 or 6 8 8 
				ns[i] = t[i]/3 + 1;
				ss[i] = t[i]/3 + 1;
				break;
			case 2: // 7 8 8 or 7 8 9 
				ns[i] = t[i]/3 + 1;
				ss[i] = t[i] == 29 ? 10 : (t[i]/3 + 2);
				break;
			default:
				break;
			}
		}
		int nc = 0;
		int sc = 0;
		for(int i=0;i<t.length;i++){
			if(ns[i]>=p) nc++;
			if(ns[i]<p && ss[i]>=p) sc++;
		}
		return nc + (sc > S ? S : sc);
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
