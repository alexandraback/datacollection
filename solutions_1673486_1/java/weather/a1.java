import java.util.*;

public class a1 {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		
		for(int i = 1; i <= test; ++i) {
			int a = input.nextInt(), b = input.nextInt();
			double p[] = new double[a];
			double mistake[] = new double[a+1];
			for(int j = 0; j < a; ++j) {
				p[j] = input.nextDouble();
			}
			mistake[0] = 1;
			for(int j = 1; j <= a; ++j) {
				mistake[j] = mistake[j-1]*p[j-1];
			}
//			System.out.println(Arrays.toString(p));
//			System.out.println(Arrays.toString(mistake));
			double aver = Double.MAX_VALUE;
			int no = 0;
			
			for(int j = 0; j <= a; ++j) {
				aver = Math.min(aver, mistake[a-j]*(b-a+j*2+1)+(1-mistake[a-j])*(b-a+j*2+b+2));
			}
			
			aver = Math.min(aver, b+2);
			
			System.out.println("Case #" + i + ": " + aver);
		}
	}
}
