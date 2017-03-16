import cra.common.Array_jsc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Minesweeper {

	public Minesweeper(){}
	public static void main( String[] asArguments ){
		doProblem();
	}
	
	static void doProblem(){
		StringBuffer sbError = new StringBuffer();
		StringBuffer sbAnswer = new StringBuffer();
		String sAbsolutePath_input = "C:\\codejam\\Minesweeper\\C-small-attempt1.in";
		String sAbsolutePath_output = "C:\\codejam\\Minesweeper\\C-small-attempt1.out";
		ArrayList<String> listLines = zLoadLines( sAbsolutePath_input, 50000, sbError );
		int ctTestCases = 0;
		try {
			ctTestCases = Integer.parseInt( listLines.get( 0 ) );
			System.out.println( "test case count: " + ctTestCases ); 
		} catch( Throwable t ) {
			System.err.println( "count test cases: " + t );
			System.exit( -1 );
		}
		int xLine = 0;
		for( int xTestCase = 1; xTestCase <= ctTestCases; xTestCase++ ){
			xLine++;
			String sLine = listLines.get( xLine );
			String[] asParameters = split(sLine, ' ');
			int ctRows = Integer.parseInt( asParameters[ 0 ] );
			int ctColumns = Integer.parseInt(asParameters[1]);
			int ctMines = Integer.parseInt(asParameters[2]);
			vPopulateNeighborLookup( ctRows, ctColumns );
			System.out.println( "doing test case: " + xTestCase + " rows: " + ctRows + " columns: " + ctColumns );

			// visit every non-symmetric starting location (every cell in the octant)
			int[] answer = null;
			int xRow_start = 0;
			int xColumn_start = 0;
VisitStartingLocations:
			for( int xRow = 0; (xRow + 1) * 2 <= ctRows + 1; xRow++ ){
				for( int xColumn = xRow; (xColumn + 1) * 2 <= ctColumns + 1; xColumn++ ){
					xRow_start = xRow + 1;
					xColumn_start = xColumn + 1;
					System.out.print( "(" + xRow_start + "," + xColumn_start + ") " );
					int[] revealed_list = new int[ctRows * ctColumns + 1];
					revealed_list[ 1 ] = xRow * ctColumns + xColumn + 1;
					revealed_list[ 0 ] = 1; // count of items in the revealed list
					answer = getAnswer( revealed_list, ctRows, ctColumns, ctMines );
					if( answer != null ) break VisitStartingLocations;
				}
			}
			System.out.println();

			// write output
			if( answer == null ){
				sbAnswer.append( "Case #" + xTestCase + ":\nImpossible\n" );
			} else {
				sbAnswer.append( "Case #" + xTestCase + ":\n" );

				// make answer cell map
				char[][] cell_map_chars = new char[ ctRows + 1 ][ ctColumns + 1 ];
				for( int xRow = 1; xRow <= ctRows; xRow++ ){
					for( int xColumn = 1; xColumn <= ctColumns; xColumn++ ){
						cell_map_chars[xRow][xColumn] = '*'; // default all cells to mine
					}
				}
				for( int xCellRevealed = 1; xCellRevealed <= answer[0]; xCellRevealed++ ){
					int iRevealedCellNumber = answer[ xCellRevealed ];
					cell_map_chars[cell_x[iRevealedCellNumber]][cell_y[iRevealedCellNumber]] = '.';
				}
				cell_map_chars[xRow_start][xColumn_start]  = 'c';

				// write answer
				for( int xRow = 1; xRow <= ctRows; xRow++ ){
					for( int xColumn = 1; xColumn <= ctColumns; xColumn++ ){
						sbAnswer.append( cell_map_chars[xRow][xColumn] );
					}
					sbAnswer.append( "\n" );
				}
			}
		}
		fileSave( sAbsolutePath_output, sbAnswer.toString(), sbError );
		System.out.println( "wrote " + ctTestCases + " cases" );
	}

	static int[][] all_neighbors = new int[2501][9];
	static int[] cell_x = new int[2501];
	static int[] cell_y = new int[2501];
	static void vPopulateNeighborLookup( int ctRows, int ctColumns ){
		int[][] cell_map = new int[ctRows + 1][ctColumns + 1];
		int xCell = 0;
		for( int xRow = 1; xRow <= ctRows; xRow++ ){
			for( int xColumn = 1; xColumn <= ctColumns; xColumn++ ){
				xCell++;
				cell_map[xRow][xColumn] = xCell;
				cell_x[xCell] = xRow;
				cell_y[xCell] = xColumn;
			}
		}
		for( int xRow = 1; xRow <= ctRows; xRow++ ){
			for( int xColumn = 1; xColumn <= ctColumns; xColumn++ ){
				int iNeighborCount = 0;
				xCell = cell_map[xRow][xColumn];
				if( xRow > 1 ){
					if( xColumn > 1 ) all_neighbors[xCell][++iNeighborCount] = cell_map[xRow - 1][xColumn - 1];
					all_neighbors[xCell][++iNeighborCount] = cell_map[xRow - 1][xColumn];
					if( xColumn < ctColumns ) all_neighbors[xCell][++iNeighborCount] = cell_map[xRow - 1][xColumn + 1];
				}
				if( xColumn > 1 ) all_neighbors[xCell][++iNeighborCount] = cell_map[xRow][xColumn - 1];
				if( xColumn < ctColumns ) all_neighbors[xCell][++iNeighborCount] = cell_map[xRow][xColumn + 1];
				if( xRow < ctRows ){
					if( xColumn > 1 ) all_neighbors[xCell][++iNeighborCount] = cell_map[xRow + 1][xColumn - 1];
					all_neighbors[xCell][++iNeighborCount] = cell_map[xRow + 1][xColumn];
					if( xColumn < ctColumns ) all_neighbors[xCell][++iNeighborCount] = cell_map[xRow + 1][xColumn + 1];
				}
				all_neighbors[xCell][0] = iNeighborCount;
			}
		}
	}

	static int[] getAnswer( int[] revealed_list, int ctRows, int ctColumns, int ctMines ){
		int ctRevealedCells = revealed_list[0];
		if( ctRevealedCells + ctMines == ctRows * ctColumns ) return revealed_list; // found solution
		if( ctRevealedCells + ctMines > ctRows * ctColumns ) return null; // no solution on this branch
		for( int xRevealedCell = 1; xRevealedCell <= ctRevealedCells; xRevealedCell++ ){ // try zeroing every revealed cell in turn
			int[] neighbors = all_neighbors[ revealed_list[ xRevealedCell ] ]; // get list of neighbors of selected cell
			int ctNewlyRevealedCells = 0;
			int[] new_revealed_list = null;
			for( int xNeighbor = 1; xNeighbor <= neighbors[0]; xNeighbor++ ){
				int iNeighborNumber = neighbors[ xNeighbor ];
				if( zNeighborRevealed( revealed_list, iNeighborNumber ) ) continue; // neighbor has already been revealed
				ctNewlyRevealedCells++;
				if( new_revealed_list == null ){
					new_revealed_list = new int[ctRows * ctColumns + 1];
					System.arraycopy( revealed_list, 0, new_revealed_list, 0, revealed_list.length );
				}
				new_revealed_list[ ctRevealedCells + ctNewlyRevealedCells ] = iNeighborNumber;
				new_revealed_list[0]++;
			}
			if( new_revealed_list != null ){
				// if we have seen this pattern before continue
//				Array_jsc.printArray_space_separated( new_revealed_list, true );
				int[] answer = getAnswer( new_revealed_list, ctRows, ctColumns, ctMines );
				if( answer != null ) return answer;
			}
		}
		return null; // no answer found
	}

	static boolean zNeighborRevealed( int[] revealed_list, int neighbor_number ){
		int xRevealed = 0;
		while( true ){
			xRevealed++;
			if( xRevealed > revealed_list[0] ) return false;
			if( revealed_list[xRevealed] == neighbor_number ) return true;
		}
	}

	// loads lines in a file into an array list of lines
	// content can include newlines if in quotation marks
	// End of Line:
	//   PC - carriage return plus line feed
	//   Macintosh - carriage return
	//   UNIX - line feed (usually called "new line" in UNIX parlance)
	// ASCII code in decimal: LF = 10; CR = 13
	public static ArrayList<String> zLoadLines( String sAbsolutePath, int iEstimatedSize, StringBuffer sbError){
		if( sAbsolutePath == null ){ sbError.append("path missing"); return null; }
		StringBuffer sbContent = new StringBuffer(iEstimatedSize);
		if( !fileLoadIntoBuffer( sAbsolutePath, sbContent, sbError ) ){
			sbError.insert(0, "error loading file (" + sAbsolutePath + "): ");
			return null;
		}
		return zLoadLines( sbContent, sbError );
	}
	
	public static ArrayList<String> zLoadLines( StringBuffer sbContent, StringBuffer sbError ){
		return zLoadLines( sbContent.toString(), sbError );
	}
		
	public static ArrayList<String> zLoadLines( String sContent, StringBuffer sbError ){ 
		int lenContent = sContent.length();
		ArrayList<String> listLines = new ArrayList<String>();
		StringBuffer sbLine = new StringBuffer(120);
		int pos = 0;
		int eState = 1;
		while( pos < lenContent ){
			char c = sContent.charAt(pos);
			switch( eState ){
				case( 1 ): // in line
					if( c == 13 ){
						eState = 2; // after CR
					} else if( c == 10 ){ // end of UNIX line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
					} else {
						sbLine.append(c);
					}
					pos++;
					break;
				case( 2 ): // after CR
					if( c == 10 ){ // reached end of PC line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
						eState = 1;
					} else if( c == 13 ){ // two mac lines in a row (stay in CR state)
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
					} else { // single mac line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						eState = 1;
					}
			}
		}
		if( sbLine.length() > 0 ) listLines.add(sbLine.toString()); // add any unterminated lines at end
		return listLines;
	}
	
	public static boolean fileLoadIntoBuffer( String sAbsolutePath, StringBuffer sbResource, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		if( !file.exists() ){
			sbError.append("file not found");
			return false;
		}
		java.io.InputStream inputstreamResource = null;
		try {
			inputstreamResource = new FileInputStream(file);
		} catch(Exception ex) {
			sbError.append("unable to open file: " + ex);
			return false;
		}
		return zLoadString( inputstreamResource, sbResource, sbError );
	}
	
	public static boolean zLoadString( java.io.InputStream inputstreamResource, StringBuffer sbResource, StringBuffer sbError){
		if( inputstreamResource == null ){
			sbError.append("resource input stream does not exist");
			return false;
		}
		BufferedReader brFileToBeLoaded = null;
		try {
			int iFileCharacter;
			brFileToBeLoaded = new BufferedReader(new InputStreamReader(inputstreamResource));
			while(true) {
				iFileCharacter = brFileToBeLoaded.read();
				if(iFileCharacter==-1) break;
				sbResource.append((char)iFileCharacter);
			}
		} catch(Exception ex) {
			sbError.append("Failed to read resource: " + ex);
			return false;
		} finally {
			try {
				if(brFileToBeLoaded!=null) brFileToBeLoaded.close();
			} catch(Exception ex) {
				sbError.append("Failed to close resource: " + ex);
				return false;
			}
		}
		return true;
	}
		public static boolean fileSave( String sAbsolutePath, String sContent, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		return fileSave( file, sContent, sbError );
	}

	public static boolean fileSave(  File file, String sContent, StringBuffer sbError ){

		// if file does not exist, create it
		try {
			if( ! file.exists() ){
				file.createNewFile();
			}
		} catch( Exception ex ) {
			sbError.append("failed to create file " + file + ": " + ex );
			return false;
		}


		// open file
		java.io.FileOutputStream fos = null;
		try {
		    fos = new java.io.FileOutputStream(file);
		} catch(Exception ex) {
			sbError.append("failed to open file for writing: " + ex);
			return false;
		}

		// save to file
		try {
			fos.write( sContent.getBytes() );
		} catch(Exception ex) {
			System.err.println("write failure (" + sContent.length() + " bytes): " + ex);
			return false;
		} finally {
			try {
				if( fos!=null ) fos.close();
			} catch(Exception ex) {}
		}
		return true;
	}

	public static String[] split( String s, char c ){
		if( s == null ) return null;
		int ctChar = getOccurrenceCount(s, c);
		int ctSegments = ctChar + 1;
		String[] asSegments = new String[ctSegments];
		if( ctChar == 0 ){ // minimal case
			asSegments[0] = s;
			return asSegments;
		}
		int len = s.length();
		int xSegment = 0;
		int posStartOfSegment = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ){
				asSegments[xSegment] = s.substring(posStartOfSegment, pos);
				posStartOfSegment = pos + 1; // skip delimiter
				xSegment++;
			}
		}
		asSegments[xSegment] = s.substring(posStartOfSegment, len);
		return asSegments;
	}

	public static int getOccurrenceCount(String s, char c){
		if( s == null ) return 0;
		int len = s.length();
		if( len == 0 ) return 0;
		int iCount = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ) iCount++;
		}
		return iCount;
	}

	final public static int powerToInteger( int base, int power ){
		int result = base;
		for( int index = 2; index <= power; index++ ){
			result *= base;
		}
		return result;
	}

}