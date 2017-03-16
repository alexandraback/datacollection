import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.RoundingMode;
import java.util.Scanner;
import java.text.DecimalFormat;



public class PasswordProblem {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.in"));
		BufferedWriter bfrw = new BufferedWriter(new FileWriter("output.out"));
		
		int N = in.nextInt();
		String output = "";
		for(int i = 0; i < N;i++){
			
			int A = in.nextInt();
			int B = in.nextInt();
			
			double [] prob = new double[B];
			for(int j = 0; j < A;j++){
				prob[j] = in.nextDouble();
			}
			output += "Case #"+(i+1)+": " + solve(prob,A,B)+"" + "\n";
		}
		
		bfrw.write(output);
		in.close();
		bfrw.close();
	}
	
	private static String solve(double [] prob, int A, int B){
		
		for(int i = A; i < B; i++){
			prob[i] = 1;
		}
		
		double winProd = 1.0;
		double lossProd = 1 - winProd;
		
		double ans = A+B+1;
		
		ans = Math.min(ans, B+2);
		for(int i = 0; i < A; i++){
			winProd = 1.0;
			for(int j = 0; j <= i; j++){
				winProd *= prob[j];
				lossProd = 1 - winProd;
			}
			int bk = A - (i+1);
			int fwd = (B - i);
			int wintotal = fwd +bk;
			int losstotal = fwd +bk+B+1;
			ans = Math.min(ans, (winProd*wintotal + lossProd*losstotal));
			//System.out.println(ans);
		}
		DecimalFormat formatter = new DecimalFormat(".000000");
		
		String s = formatter.format(ans);
		//System.out.println(s);
		return s;
	}
}