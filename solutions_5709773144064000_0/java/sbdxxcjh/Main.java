import java.util.Scanner;


public class Main {
	static Scanner in = new Scanner(System.in);
	public static void main(String[] arg){
		int T = in.nextInt();
		for(int i = 1; i <= T; i++){
			solve(i);
		}
	}
	public static void solve(int casenumber){
		double C = in.nextDouble();
		double F = in.nextDouble();
		double X = in.nextDouble();
		int n = (int)((F * X - 2 * C) / (F * C));
		if(n < 0) n = 0;
		double sum = 0;
		for(int i = 0 ; i < n ; i++){
			sum += C / (2 + i * F);
		}
		sum += X / (2 + n * F);
		System.out.println("Case #" + casenumber + ": " + sum);
	}
}
