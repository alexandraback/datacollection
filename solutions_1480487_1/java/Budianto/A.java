import java.util.*;
import java.io.*;

public class A{
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for(int caseNo = 1;caseNo <= T; caseNo++) {
			int N = in.nextInt();
			int[] arr = new int[N];
			int total = 0;
			
			for(int i=0;i<N;i++){
				arr[i] = in.nextInt();
				total += arr[i];
			}
			
			System.out.print("Case #"+caseNo+":");
			for(int i=0;i<N;i++) {
				double low = 0, high = 1, mid = 0;
				for(int cnt=0;cnt < 1000; cnt++) {
					mid = (low + high) / 2;
					double nextScore = arr[i] + mid *  total;
					
					double remaining = 1 - mid;
					boolean can = true;
					
					String needS = "";
					
					for(int j = 0;j < N; j++) {
						if (i != j) {
							double need = Math.max((nextScore - arr[j]) / total, 0);
							if (need > remaining) {
								can = false;
								break;
							} else {
								remaining -= need;
							}
							needS += String.format("%.5f ", need);
						}
					}
										
					if (can) {
						low = mid;
					} else {
						high = mid;
					}
					
					if (Math.abs(high - low) < 1e-9) break;
				}
				System.out.printf(" %.6f", mid * 100);
			}
			System.out.println();
		}
	}
}