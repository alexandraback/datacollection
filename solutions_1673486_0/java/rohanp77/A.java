import java.io.*;
import java.util.*;

public class A {
	
	public static BufferedReader in;
	public static StringTokenizer st;
	
	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			
			int done = readInt();
			int total = readInt();
			
			double min = total+2;
			if (done<1)
				min = done+total+1; //hitting enter right away
			
			double allRight = 1;
			for (int i=1; i<=done; i++){ //i is no. of chars left alone
				allRight *= readDouble();
				int cost = done-i + total-i +1;
				double exp = cost * allRight + (cost+total+1) * (1-allRight);
				if (exp<min) min=exp;
			}
			
			out.printf("%.6f\n", min);			
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
	
	public static double readDouble() throws IOException{
		return Double.parseDouble(readToken());
	}
}