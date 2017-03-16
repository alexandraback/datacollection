import java.io.*;
import java.util.*;

public class C {
	
	public static BufferedReader in;
	public static StringTokenizer st;

	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			
			int start = readInt(), end = readInt();
			
			int counter=0;
			for (int i=start; i<=end; i++){
				counter += test(i, start, end);
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
	
	public static int test(int i, int start, int end){
		int curr = i;
		int ret =0;
		int numDigits = String.valueOf(i).length();
		int mult = (int)Math.pow(10, numDigits-1);
		do{
			int last = curr%10;
			curr = curr/10 + last*mult;
			if (curr>i && curr<=end) ret++;
		}while(curr!=i);
		return ret;
	}
}
