import java.io.*;
import java.util.*;

public class A {
	public static BufferedReader in;
	public static StringTokenizer st;
	
	public static double EPS = 1e-9;
	
	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			
			int numC = readInt();
			int[] scores = new int[numC];
			double total=0;
			for (int i=0; i<numC; i++){
				scores[i] = readInt();
				total+=scores[i];
			}
			
			double orig=total;
			total*=2;
			int counter = numC;
			double[] ans = new double[numC];
			Arrays.fill(ans, -1);
			for (int k=0; k<numC; k++){
				for (int i=0; i<numC; i++){
					double min = total/counter; //need to get min
					if (min<scores[i] && abs(ans[i])>EPS){
						ans[i] = 0;
						total -= scores[i]; counter--;
					}
				}
			}
			
			System.out.println(total);
			for (int i=0; i<numC; i++){
				double min = total/counter; //need to get min
				double req = (min-scores[i])/orig;
				if (abs(ans[i]+1)<EPS)
					ans[i] = req;
				out.printf("%.6f ", 100*ans[i]);
			}
			
			out.println();
		}
		
		out.close();
		in.close();
	}
	
	public static double abs(double d){
		return (d<0)?-d:d;
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
