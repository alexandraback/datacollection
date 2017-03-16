package jp.gr.java_conf.satstnka.gcj2014.qualification;

import java.util.*;
import java.io.*;

public class ProblemC {
	
	final static int CELL_UNDETECTED = 0;
	final static int CELL_BLANK = 1;

	/**
	 * main method
	 * @param args arguments 
	 * @throws Exception exception
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
			StringTokenizer st = new StringTokenizer( line );
			int r = Integer.parseInt( st.nextToken() );
			int c = Integer.parseInt( st.nextToken() );
			int m = Integer.parseInt( st.nextToken() );
			
			int size = r * c;
			int[] array = new int[ size ];
			Arrays.fill( array,  CELL_UNDETECTED );			
			HashSet< Integer > cellSet = new HashSet< Integer >();
			
			int clickRow = 0;
			int clickCol = 0;
			boolean result = search( array, cellSet, r, c, m, clickRow, clickCol, size );
			
			System.out.println( "Case #" + i + ":" );			
			if( result ) {
				for( int j = 0; j < r; j++ ) {
					for( int k = 0; k < c; k++ ) {
						int idx = getIndex( j, k, r, c );
						if( j == clickRow && k == clickCol ) {
							System.out.print( "c" );
						}
						else if( array[ idx ] == CELL_BLANK ) {
							System.out.print( "." );
						}
						else {
							System.out.print( "*" );
						}
					}
					System.out.println( "" );
				}
				
			}
			else {
				System.out.println( "Impossible" );
			}
		}
		
		reader.close();
	}
	
	/**
	 * search searches blanks
	 * @param array array
	 * @param cellSet cell set
	 * @param row row size
	 * @param col column size
	 * @param mine the number of mines
	 * @param rPos row position for searching
	 * @param cPos column position for searching
	 * @param remain remain cells
	 * @return If true, the answer is found.
	 */
	static boolean search( int[] array, HashSet< Integer > cellSet, int row, int col, int mine, int rPos, int cPos, int remain ) {
		// result
		boolean result = false;
		
		// copy
		HashSet< Integer > newSet = new HashSet< Integer >( cellSet );
		
		int[] newArray = new int[ array.length ];
		System.arraycopy( array, 0, newArray, 0, array.length );
		
		// index
		int idx = getIndex( rPos, cPos, row, col );
		newSet.add( new Integer( idx ) );
		
		if( newArray[ idx ] == CELL_UNDETECTED ) {
			newArray[ idx ] = CELL_BLANK;		
			remain = remain - 1;			
		}
		if( remain == mine ) {
			result = true;
		}
		
		if( !result ) {
			int[][] searches = { { -1, -1 }, { -1, 0 }, { -1, 1 },
					{ 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
			ArrayList< int[] > searchList = new ArrayList< int[] >();
			
			for( int i = 0; i < searches.length; i++ ) {
				int newRow = rPos + searches[ i ][ 0 ];
				int newCol = cPos + searches[ i ][ 1 ];
				if( newRow >= 0 && newRow < row && newCol >= 0 && newCol < col ) {
					int newIdx = getIndex( newRow, newCol, row, col );
					Integer iObj = new Integer( newIdx );
					if( !newSet.contains( iObj ) ) {
						remain = remain - 1;
						int[] sArray = new int[ 2 ];
						sArray[ 0 ] = newRow;
						sArray[ 1 ] = newCol;
						searchList.add( sArray );
						newArray[ newIdx ] = CELL_BLANK;
						newSet.add( iObj );
					}
				}
			}
			
			if( remain == mine ) {
				result = true;
			}
			
			if( remain > mine ) {			
				for( int i = 0; i < searchList.size() && !result; i++ ) {
					int[] pos = searchList.get( i );
					result = search( newArray, newSet, row, col, mine, pos[ 0 ], pos[ 1 ], remain );
				}
			}
		}
		
		if( result ) {
			System.arraycopy( newArray,  0,  array,  0,  array.length );
		}
		
		return result;
	}
	
	/**
	 * gets the index
	 * @param row row index
	 * @param col column index
	 * @param rowNum row size
	 * @param colNum column size
	 * @return index
	 */
	static int getIndex( int row, int col, int rowNum, int colNum ) {
		return ( row * colNum + col );
	}

}
