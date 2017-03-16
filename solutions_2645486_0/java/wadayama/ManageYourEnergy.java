import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class ManageYourEnergy {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int T = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			T = sc.nextInt();
		}
		catch( Exception e ) {
			System.out.println(e);
		}

		for( int a = 1; a <= T; a++ ) {
			int E = sc.nextInt();
			int R = sc.nextInt();
			int N = sc.nextInt();
			int[] v = new int[N];
			long res = 0;
			
			for( int i = 0; i < N; i++ ) {
				v[i] = sc.nextInt();
			}
			
			FORI: for( int i = 0, e = E; i < N; i++, e += R ) {
				int p0 = e + R;
				int p1 = R;

				int de = e;
				for( int j = i + 1; j < N; j++ ) {
					if( p0 < E ) {
						if( v[j] > v[i] ) continue FORI;
					}
					else if( p1 < E ) {
						if( v[j] > v[i] ) {
							de = Math.min( de, p0 - E );
						}
					}
					
					p0 = p0 + R;
					p1 = p1 + R;
				}
				e -= de;
				res += (long)de * v[i];
			}
			
//			System.out.println("Case #" + a + ": " + res );
			fout.println("Case #" + a + ": " + res );
		}

		fout.close();
		sc.close();
	}

}
