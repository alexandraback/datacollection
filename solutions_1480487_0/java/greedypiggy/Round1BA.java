import java.util.*;

public class Round1BA {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for(int i=0; i<t; i++){
			int n = sc.nextInt();
			
			int[] arr = new int[n];
			int sum = 0;
			
			for(int j=0; j<n; j++){
				int tt = sc.nextInt();
				
				arr[j] = tt;
				sum += tt;
			}
			
			double goal = sum*2.0/((double) n);
			
			double[] ans = new double[n];
			
			System.out.printf("Case #%d:", i+1);
			
			for(int j=0; j<n; j++){
				ans[j] = (goal - arr[j])/((double) sum)*100.0;
			}
			
			int count = n;
			double totalexcess = 0.0;
			
			for(int j=0; j<n; j++){
				if(ans[j] < 0){
					count--;
					totalexcess += ans[j];
				}
			}
			
			double toSubtract = totalexcess/((double) count);
			
			for(int j=0; j<n; j++){
				if(ans[j] > 0 || Math.abs(ans[j]) < 0.00000001){
					ans[j] += toSubtract;
				}
			}
			
			for(int j=0; j<n; j++){
				if(ans[j] < 0){
					System.out.printf(" 0.000000");
				}else{
					System.out.printf(" %.6f", ans[j]);
				}
			}
			
			System.out.println();
		}
	}
}
