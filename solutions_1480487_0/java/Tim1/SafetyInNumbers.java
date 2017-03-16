package gcj2012;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SafetyInNumbers {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Integer t = Integer.parseInt(br.readLine());
		int init = t;
		main: while (t-- > 0) {
			String[] parts = br.readLine().split("\\s+");
			int n = Integer.parseInt(parts[0]);
			int[] arr = new int[n];
			int sum = 0;
			for(int i = 0; i < n; i++){
				arr[i] = Integer.parseInt(parts[i+1]);
				sum += arr[i];
			}
			System.out.print("Case #"+(init-t) + ": ");			
			for(int i = 0; i < n; i++){
				int sum1 = sum + (sum-arr[i]) - (n-1)*arr[i];
				if(sum1 <= 0){
					System.out.print((i == 0 ? "" : " ") + 0.0);					
				} else {
					double p = ((double)sum1 / (double)n / (double)sum) * 100.0;
					System.out.print((i == 0 ? "" : " ") + p);					
				}
			}
			System.out.println();
		}
	}
}
