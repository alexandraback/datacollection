package preprocessor;

import java.io.IOException;

import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class ProbA {

	
	public static double countCase1(int A, int B, double[] p){
		double totP = 1;
		for(int i = 0; i < A; i++)
			totP *= p[i];		
		return (1-totP)*(B-A+1+B+1)+totP*(B-A+1);
	}
	
	public static double countCase2(int A, int B, double[] p){
		double[] totStrokes = new double[A+1];
		double totP = 1;
		for(int i = A; i >= 0; i--){
			totStrokes[i] = (i+B-(A-i)+1)*totP + ( i+B-(A-i)+1+B+1)*(1-totP);
			if(i > 0)
				totP = totP*p[A-i];
		}
		
		double maxTotStroke = 5*B;
		for(int i = A; i >= 0; i--)
			if(totStrokes[i] < maxTotStroke)
				maxTotStroke = totStrokes[i];
		
		return maxTotStroke;
	}
	
	public static double countCase3(int A, int B, double[] p){
		return B+2;		
	}
	
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader in = new BufferedReader( new InputStreamReader(new FileInputStream("./ProbA.in")) );
		PrintWriter out = new PrintWriter(new FileWriter("./ProbA.out"));
		
		int T = Integer.parseInt(in.readLine());
		
		for(int t = 0; t < T; t++){
			String[] parts = in.readLine().split(" ");
			int A = Integer.parseInt(parts[0]); int B = Integer.parseInt(parts[1]);
			double[] p = new double[A];
			parts = in.readLine().split(" ");
			for(int i = 0; i < A; i++){
				p[i] = Double.parseDouble(parts[i]);				
			}
			
			double n1 = countCase1(A, B, p);
			double n2 = countCase2(A, B, p);
			if(n2 > n1)
				 n2 = n1;
			double n3 = countCase3(A,B,p);
			if(n3 > n2)
				n3 = n2;
			out.println("Case #"+(t+1)+": "+n3);
			//System.out.println(n3);
		}
		
		in.close();
		out.close();
		
	}
	
}
