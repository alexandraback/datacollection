import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class Main {

	public static double case3 (int B)
	{
		return (B+2);
	}
	
	public static double case12(int A, int B, double[] prob, int i)
	{
		double total = 0;
		// for i backspace
		double P = 1; //Problabilty that there is nothing wrong in A-i characters
		for(int j=0; j<A-i; j++)
			P = P*prob[j];
		
		total = ((P*(2*i + B -A + 1)) + ((1-P)*(2*i + 2*B - A + 2))); 
		return total;
	}
	
	public static void runCase(int A, int B, double[] P, int caseNum) {
		double min = case3(B);
		
		for(int i=0; i <= A; i++) {
			double temp = case12(A, B, P, i);
			if(min > temp)
				min = temp;
		}
		
		System.out.print("Case #" +caseNum + ": ");
		System.out.printf("%.6f\n", min);
		
	}
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
		
		File ffile = new File(args[0]);
		Scanner scanner;
		scanner = new Scanner(new FileReader(ffile));
		
		int T;
		T = scanner.nextInt();
		
		for(int i=0; i<T; i++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			
			double[] P = new double[A];
			
			for(int j=0; j<A; j++) {
				P[j] = scanner.nextDouble();
			}
			
			runCase(A, B, P, i+1);
		}
	}

}
