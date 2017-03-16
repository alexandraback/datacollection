import java.io.*;
import java.util.*;

public class EqualSums {

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
			
			fout.println("Case #" + (i+1) + ":");

			for( int j = 0; j < n; j++ ) {
				s[j] = sc.nextInt();
			}
			
			int[] sum = new int[2000001];
			int[] memo = new int[2000001];

			int dig = 1, dn = 0;
			int b = 1;
			for( ; b < (1<<n); b++ ) {
				if( ( dig << 1 ) <= b ) {
					dig <<= 1;
					dn++;
				}
				sum[b] = sum[b-dig] + s[dn];
				if( memo[sum[b]] > 0 && ( memo[sum[b]] & b ) == 0 ) {
//					System.out.println(sum[b] + " "+b+" "+memo[sum[b]]);
					int d = memo[sum[b]];
					String ret1 = "", ret2 = "";
					for( int j = 0; j < n; j++ ) {
						if( ( d & 1 ) == 1 ) {
							ret1 += s[j] + " ";
						}
						d >>= 1;
					}
					ret1 = ret1.trim();
					
					d = b;
					for( int j = 0; j < n; j++ ) {
						if( ( d & 1 ) == 1 ) {
							ret2 += s[j] + " ";
						}
						d >>= 1;
					}
					ret2 = ret2.trim();
					
					fout.println( ret1 );
					fout.println( ret2 );
					break;
				}
				memo[sum[b]] = b;
			}
			if( b == (1<<n) ) fout.println( "Impossible" );
		}

		fout.close();
		sc.close();
	}

}
