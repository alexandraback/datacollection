import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/**
 * @author Seitaro Sakoda
 *
 */
public class SpeakingInTongues {
	private static final String MAP = "yhesocvxduiglbkrztnwjpfmaq";
	public static void main(String[] args) throws Exception {
		DataReader dr = new DataReader();
		int N = dr.readInt();
		ArrayList<String> ans = new ArrayList<String>();
		for(int n=0;n<N;n++){
			String data = dr.readString();
			ans.add("Case #"+(n+1)+": "+doit(data));
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
	private static String doit(String data) {
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<data.length();i++){
			if(data.charAt(i) == ' '){
				sb.append(" ");
			}else{
				sb.append(MAP.charAt(data.charAt(i)-97));
			}
		}
		return sb.toString();
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
