import java.util.Arrays;
import java.util.Scanner;


public class Osmos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		 for (int i = 1; i <= t; i++) {
			 int a = sc.nextInt();
			 int n = sc.nextInt();
			 int[] arr = new int[n+1];
			 int[] mat = new int[n+1];
			 arr[n] = 0;
			 for (int k = 0; k < n ; k++) {
				 arr[k] = sc.nextInt();
			 }
			 Arrays.sort(arr);
			 mat[0] = 0;
			 for (int k = 1; k < n+1; k++) {
				 if (a > arr[k]) {
					 mat[k] = mat[k-1];
					 a += arr[k];
				 } else {
					 if (a == 1) {
						 mat[k] = 100000000;
						 continue;
					 }
					 mat[k] = mat[k-1];
					 while (a <= arr[k]) {
						 mat[k] += 1;
						 a += a - 1;
					 }
					 a += arr[k];	 
				 }
			 }
			 int min = Integer.MAX_VALUE ;
			 for (int k = 0 ; k < n + 1 ; k++) {
				 min = Math.min(n - k + mat[k], min);
			 }
			 System.out.println("Case #" + i + ": " + min);
		 }

	}

}
