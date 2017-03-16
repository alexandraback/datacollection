package roundone;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {

	/**
	 * @param args
	 */
	public static String input = "A-large.in";

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new FileReader(input));
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new FileWriter(input+".out"));
		int t = in.nextInt();
		for(int test = 0;test<t;test++){
			int a = in.nextInt();
			int b = in.nextInt();
			double[] pro = new double[a];
			double[] errorFrom = new double[a];
			double allCorrect = 1.0;
			for(int i = 0;i<pro.length;i++){
				pro[i] = in.nextDouble();
				errorFrom[i] = allCorrect*(1-pro[i]);
				allCorrect*=pro[i];
			}
			double[] errorCum = new double[a];
			errorCum[a-1] = errorFrom[a-1];
			for(int i = pro.length-2;i>=0;i--){
				errorCum[i]+=errorFrom[i]+errorCum[i+1];
				//out.println(errorCum[i]);
			}
			double expectation1 = allCorrect*(b-a+1)+(1-allCorrect)*(2*b+2-a);
			double expectation3 = (b+2);
			
			
			double[] expectation2Group = new double[a+1];
			for(int i = 1;i<=a;i++){
				expectation2Group[i] = (errorCum[a-i]+allCorrect)*(2*i+b-a+1);
				double temp  = (errorCum[0]-errorCum[a-i])*(2*i+b-a+1+b+1);
				expectation2Group[i]+=temp;
				//out.println(expectation2Group[i]);
			}
			double min = Math.min(expectation1, expectation3);
			for(int i = 1;i<=a;i++){
				if(expectation2Group[i]<min){
					min = expectation2Group[i];
				}
			}
			out.println("Case #"+(test+1)+": "+min);
		}
		
		
		out.close();
	}

}
