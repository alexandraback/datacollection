package password;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;

public class Main {
	
	private static DecimalFormat df = new DecimalFormat("0.000000");

	public static void main(String[] args) throws IOException {
		File file = new File("A-small-attempt0.in");
		FileReader fr = new FileReader(file);
		BufferedReader in = new BufferedReader(fr);

		String line = in.readLine();
		String[] tokens;
		int num = Integer.parseInt(line);
		int i=1,A,B;
		double[] p;
		while (i <= num) {
			line = in.readLine();
			tokens = line.split(" ");
			A = Integer.parseInt(tokens[0]);
			B = Integer.parseInt(tokens[1]);
			line = in.readLine();
			tokens = line.split(" ");
			p = new double[tokens.length];
			for(int j=0;j<tokens.length;j++){
				p[j] = Double.parseDouble(tokens[j]);
			}
			System.out.println("Case #" + i + ": " + handleCase(A, B, p));
			i++;
		}
	}

	private static String handleCase(int A, int B, double[] p) {
		double probabilityRight = 1;
		for(double p1:p){
			probabilityRight *= p1;
		}
		
		double res = caseContinue(A, B, p, probabilityRight);
		double temp;
		for(int i=1;i<A;i++){
			temp = caseBackspace(A, B, p, i);
			if(temp<res){
				res = temp;
			}
		}
		temp = caseRestart(A, B);
		if(temp<res){
			res = temp;
		}
		
		return df.format(res);
	}

	private static double caseContinue(int A, int B, double[] p, double probabilityRight){
		return probabilityRight*(B-A+1) + (1-probabilityRight)*(B*2-A+2);
	}
	
	private static double caseBackspace(int A, int B, double[] p, int backspaceTimes){
		double probabilityRight = 1;
		for(int j=0;j<A-backspaceTimes;j++){
			probabilityRight *= p[j];
		}
		return backspaceTimes + caseContinue(A-backspaceTimes, B, p, probabilityRight);
	}
	
	private static double caseRestart(int A, int B){
		return B+2;
	}
	
	
}
