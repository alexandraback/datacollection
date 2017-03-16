import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class DeceitfulWar {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
		} catch(Exception e) {
			System.out.println(e);
		}

		final int T = sc.nextInt();
		for( int t = 1; t <= T; t++ ) {
			final int N = sc.nextInt();
			ArrayList<Double> naomi = new ArrayList<Double>();
			ArrayList<Double> ken1 = new ArrayList<Double>();
			ArrayList<Double> ken2 = new ArrayList<Double>();
			
			for( int i = 0; i < N; i++ ) {
				naomi.add( sc.nextDouble() );
			}
			for( int i = 0; i < N; i++ ) {
				double tmp = sc.nextDouble();
				ken1.add( tmp );
				ken2.add( tmp );
			}
			
			Collections.sort( naomi );
			Collections.sort( ken1 );
			Collections.sort( ken2 );
			
			int res2 = 0;
			for( int i = 0; i < N; i++ ) {
				if( naomi.get(i) > kensSelect( ken2, naomi.get(i) ) ) {
					res2++;
				}
			}
			
			int res1 = 0;
			FORI: for( int i = 0; i < N; i++ ) {
				for( int j = 0; j < naomi.size(); j++ ) {
					if( naomi.get(j) > ken1.get(0) ) {
						naomi.remove(j);
						ken1.remove(0);
						res1++;
						continue FORI;
					}
				}
			}
//			System.out.println( "Case #" + t + ": " + res1 + " " +res2 );
			fout.println( "Case #" + t + ": " + res1 + " " +res2 );
		}
		
		fout.close();
		sc.close();
	}
	
	private static double kensSelect( ArrayList<Double> list, double naomi ) {
		double ret = 0;
		for( int i = 0; i < list.size(); i++ ) {
			if( list.get(i) > naomi ) {
				ret = list.get(i);
				list.remove(i);
				return ret;
			}
		}
		ret = list.get(0);
		list.remove(0);
		return ret;
	}
}
