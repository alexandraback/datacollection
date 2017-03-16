package Round_1_A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Manage_your_Energy {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = null;
		PrintWriter out = null;
		try {
			in = new Scanner(new File("B-small-attempt2.in"));
			out = new PrintWriter(new File("b_small.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int cases = in.nextInt();
		for (int cas=1; cas<=cases; cas++) {
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			long[] gain = new long[N];
			for (int i=0; i<gain.length; i++)
				gain[i] = in.nextLong();
			long[][] matrix = new long[N][E+1];
			for (int i=0; i<N; i++) {
				for (int left=0; left<=E; left++) {
					if (i==0) {
						matrix[i][left] = (E - left) * gain[i];
					} else {
						long max = 0;
						for (int ll=0; ll<=E; ll++) {
							long value = 0;
							if (left <= ll+R) {
								value = (Math.min(E, (ll+R))-left) * gain[i] + matrix[i-1][ll];
								//System.out.println(matrix[i-1][ll]);
								//System.out.println("i="+i+" =>  ll:"+ll + " left:" + left + " value=>"+value);
							}
							max = Math.max(max, value);
						}
						matrix[i][left] = max; 
					}
				}
			}
			//for (int i=0; i<N; i++)
			//	System.out.println(Arrays.toString(matrix[i]));
			out.println("Case #"+cas+": " + matrix[N-1][0]);
			out.flush();
		}
	}

}
