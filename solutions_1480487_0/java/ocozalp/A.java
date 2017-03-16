import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		sc.nextLine();
		
		int numbers [] = new int [200];
		
		for(int i = 1; i<=t; ++i) {
			int n = sc.nextInt();
			int total = 0;
			int total2 = 0;
			for(int j = 0; j<n; ++j) {
				numbers[j] = sc.nextInt();
				total += numbers[j];
			}
			double avg = ((double) 2.0 * total) / n;
			
			int num = n;
			total2 = total;
			
			for(int j = 0; j<n; ++j) {
				if(numbers[j] > avg) {
					--num;
					total2 -= numbers[j];
				}
			}
			
			String s = "Case #" + i + ": ";
			
			for(int j = 0; j<n; ++j) {
				
				if(numbers[j] > avg) {
					s = s + String.format("%.6f ", 0.0);
				} else if(total2 == 0) {
					double val = 100.0d / num;
					s = s + String.format("%.6f ", val);
				} else {
					double avg2 = (total + 1.0 * total2) / num;
					
					double val = ((avg2 - numbers[j]) / total) * 100.0d;
					s = s + String.format("%.6f ", val);
				}
					
			}
			s = s.replace(',', '.');
			System.out.println(s.trim());
		}
		
	}
	
}
