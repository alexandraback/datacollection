import java.io.*;
import java.util.*;


public class DancingWithTheGooglers {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int t = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			t = sc.nextInt();
		} catch(Exception e) {
			System.out.println(e);
		}
		
		for( int i = 0; i < t; i++ ) {
			int n = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();
			int[] total = new int[n];
			
			for( int j = 0; j < n; j++ ) {
				total[j] = sc.nextInt();
			}
			
			int ret = 0;
			for( int j = 0; j < n; j++ ) {
				if( total[j] >= p * 3 - 2 * Math.min( p, 1 ) ) {
					ret++;
				}
				else if( total[j] >= p * 3 - 2 * Math.min( p, 2 ) && s > 0 ) {
					ret++;
					s--;
				}
			}
			//System.out.println("Case #" + (i+1) + ": " + ret);
			fout.println("Case #" + (i+1) + ": " + ret);
		}

		fout.close();
		sc.close();
	}

}
