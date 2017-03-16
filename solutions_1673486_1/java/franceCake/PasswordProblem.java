package year2012.round1a.a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class PasswordProblem {
	public static void main(String[] args) throws Exception {
		// GCJ共通
		String filename = "src/year2012/round1a/a/A-large";
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		Scanner scan = new Scanner(new File(filename + ".in"));

		final int T = scan.nextInt();

		
		TESTCASE_LOOP: for (int i = 0; i < T; i++) {
			int A = scan.nextInt();
			int B=scan.nextInt();
			double[] p = new double[A];
			double allCorrect = 1.0;
			double temp=0.0;
			for (int j = 0; j < A; j++) {
				temp=scan.nextDouble();
				allCorrect *= temp;
				p[j]=temp;
			}
			
			double min=Double.MAX_VALUE;
			long _pow = pow(2,A);
			//1.keystrokes if i keep typing
			double expected1= (double)((B-A+1)*allCorrect + ((B*2-A+2))*(1-allCorrect));
			min=Math.min(min, expected1);			
			//2. keystrokes if i press backspace n times
			for(int n=1;n<=A;n++){
				//最初の[0..A-n-1]が正しい確率
				double p2=1.0;
				for(int j=0;j<=A-n-1;j++){
					p2*=p[j];
				}
				
				double expected2 = (double)((2*n+B-A+1)*p2 + ((2*n+2*B-A+2))*(1-p2));
				min=Math.min(min, expected2);
			}
			//3.keystrokes if i press enter right away
			double expected3 = 2+B;
			min=Math.min(min, expected3);

			// 出力
			System.out.printf("Case #%d: %s\n", i + 1, min);
			out.printf("Case #%d: %s\n", i + 1, min);
		}
		out.flush();
	}
	
	public static long pow(long a, long b){
		//0乗すると1
		if(b==0){
			return 1;
		}
		//0を何乗しても0
		if(a==0){
			return 0;
		}
		long ans=a;
		for(long i=0;i<b-1;i++){
			ans*=a;
		}
		return ans;
	}

}