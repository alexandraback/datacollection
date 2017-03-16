import java.io.*;
import java.util.*;

public class B {
	
	public static BufferedReader in;
	public static StringTokenizer st;

	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			
			int num = readInt();
			int surp = readInt();
			int cutoff = readInt();
			
			int first = cutoff*3-2;
			int sec = cutoff*3-4;
			
			if (cutoff==1){
				sec = 1;
			}
			
			int counter = 0;
			for (int i=0; i<num; i++){
				int result = readInt();
				if (first<=result) counter++;
				else if (sec<=result && surp>0){
					counter++;
					surp--;
				}
			}
			
			out.println(counter);
		}
		
		in.close();
		out.close();
	}
	
	public static String readLine() throws IOException{
		return in.readLine();
	}
	
	public static String readToken() throws IOException{
		if (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		
		return st.nextToken();
	}
	
	public static int readInt() throws IOException{
		return Integer.parseInt(readToken());
	}
}
