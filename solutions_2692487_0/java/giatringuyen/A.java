import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner (new File("A-small-attempt0.in"));
		FileWriter fstream = new FileWriter("A-small-attempt0-out.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		
//		Scanner sc = new Scanner (System.in);
		
		int tstSz = sc.nextInt();
		for (int t = 1; t <= tstSz; ++t) {
			int a = sc.nextInt();
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; ++i)
				arr[i] = sc.nextInt();
			Arrays.sort(arr);
			
//			System.out.println("Case #" + t + ": " + cal(a, arr, 0));
			out.write("Case #" + t + ": " + cal(a, arr, 0) + "\n");
		}
		
		out.close();
	}
	
	private static int cal (int a, int[] arr, int ind) {
		if (ind == arr.length)
			return 0;
		
		if (a > arr[ind])
			return cal(a + arr[ind], arr, ind+1);
		else {
			int k = (int) Math.floor(Math.log((arr[ind]-1.0)/(a-1.0)) / Math.log(2.0) + 1);
			int tmp = (int)(Math.pow(2,k)*a - (Math.pow(2, k) - 1) + arr[ind]);
			
			k = k + cal(tmp, arr, ind+1);
			if (k > arr.length - ind || a-1 == 0)
				return (arr.length - ind);
			else
				return k;
		}
		
	}
}
