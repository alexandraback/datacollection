package jp.gr.java_conf.satstnka.gcj2014.qualification;

import java.util.*;
import java.io.*;

public class ProblemD {

	/**
	 * main method
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {
		// input
		BufferedReader reader
		= new BufferedReader( new InputStreamReader( System.in ) );
		
		String line = reader.readLine();
		int num = Integer.parseInt( line );
		
		// each test cases
		for( int i = 1; i <= num; i++ ) {
			line = reader.readLine();
			
			int n = Integer.parseInt( line ) ;
			double[] naomi = new double[ n ];
			double[] ken = new double[ n ];
			
			line = reader.readLine();
			StringTokenizer st = new StringTokenizer( line );
			for( int j = 0; j < n; j++ ) {
				naomi[ j ] = Double.parseDouble( st.nextToken() );				
			}
			Arrays.sort( naomi );
			
			line = reader.readLine();
			st = new StringTokenizer( line );
			for( int j = 0; j < n; j++ ) {
				ken[ j ] = Double.parseDouble( st.nextToken() );
			}
			Arrays.sort( ken );
			
			int naomiLose = calc( naomi, ken, n );
			int kenLose = calc( ken, naomi, n );
			
			System.out.println( "Case #" + i + ": " + kenLose + " " + ( n - naomiLose ) );
		}
		reader.close();
	}
	
	/**
	 * calculate
	 * @param arr0 array 0
	 * @param arr1 array 1
	 * @param n array size
	 * @return the number of loses
	 */
	static int calc( double[] arr0, double[] arr1, int n ) {
		int cnt = 0;
		int idx = 0;
		for( int i = 0; i < n && idx < n; i++ ) {
			double val = arr0[ i ];
			while( idx < n && arr1[ idx ] <= val ) {
				idx++;
			}
			if( idx < n ) {
				cnt++;
				idx++;
			}
		}
		
		return cnt;
	}
}
