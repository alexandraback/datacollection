import java.util.Scanner;


public class Password {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int cases = Integer.parseInt(sc.nextLine());
		
		for(int c = 0; c < cases; c++) {
			Scanner line = new Scanner(sc.nextLine());
			
			int a = line.nextInt();
			int n = line.nextInt();
			
			line = new Scanner(sc.nextLine());
			
			double[] p = new double[n];
			
			for(int i = 0; i < a; i++) {
				p[i] = line.nextDouble();
			}
			
			int ifenter = n+2; //total remaining keys if press enter now
			
			double min = ifenter;
			
			double[] prod = new double[n+1];
			
			//exp cost if I start with ind already typed
			double[] rem = new double[n+1];
			
			prod[0] = 1.0;
			rem[0] = n + 1; //type all
			
			
			for(int i = 1; i < n; i++) {
				prod[i] = prod[i-1] * p[i-1];
				rem[i] = (1 - prod[i]) * (n+1) + (n-i+1);
			}
			
			for(int b = 0; b <= a; b++) {
				//exp cost if I start with (a-b) already typed
				double cost = rem[a-b] + b;  
				if(cost < min) {
					min = cost;
				}
			}
			
			System.out.printf("Case #%d: %f\n", c+1, min);
		}

	}

}
