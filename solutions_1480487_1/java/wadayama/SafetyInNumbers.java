import java.io.*;
import java.util.*;

public class SafetyInNumbers {

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
			int[] s = new int[n];
			int sum = 0;
			
			for( int j = 0; j < n; j++ ) {
				s[j] = sc.nextInt();
				sum += s[j];
			}
			
			int[] c = s.clone();
			Arrays.sort( c );
			
			double[] res = new double[n];
			int tmp = 0;
			for( int j = 1; j < n; j++ ) {
				tmp += j * ( c[j] - c[j-1] );
				if( tmp > sum ) {
					double a = (double)( j * ( c[j] - c[j-1] ) - ( tmp - sum ) ) / j;
					for( int k = 0; k < j; k++ ) {
						res[k] += a;
					}
					break;
				}
				else {
					for( int k = 0; k < j; k++ ) {
						res[k] += c[j] - c[j-1];
					}
				}
			}
			if( tmp < sum ) {
				for( int j = 0; j < n; j++ ) {
					res[j] += (double)( sum - tmp ) / n;
				}
			}
			
			double[] ret = new double[n];
			for( int j = 0; j < n; j++ ) {
				for( int k = 0; k < n; k++ ) {
					if( s[j] != c[k] ) continue;
					ret[j] = 100 * res[k] / sum;
				}
			}
			
			/*
			System.out.print("Case #" + (i+1) + ":");
			for( int j = 0; j < n; j++ ) {
				System.out.print( " " + ( 100 * min[j] ) );
			}
			System.out.println();
			*/
			fout.print("Case #" + (i+1) + ":");
			for( int j = 0; j < n; j++ ) {
				fout.print( " " + ret[j] ) ;
			}
			fout.println();
		}

		fout.close();
		sc.close();
	}

}
