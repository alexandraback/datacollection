import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class B {
	public B(){}
	public static void main( String[] asArguments ){
		doB();
	}
	
	static void doB(){
		StringBuffer sbError = new StringBuffer();
		StringBuffer sbAnswer = new StringBuffer();
		String sAbsolutePath = "C:\\dev\\workspace\\Sandbox\\B-small-attempt1.in";
		String sAbsolutePath_output = "C:\\dev\\workspace\\Sandbox\\B-small-attempt1.out";
//		String sAbsolutePath = "C:\\dev\\workspace\\Sandbox\\B-large.in";
//		String sAbsolutePath_output = "C:\\dev\\workspace\\Sandbox\\B-large.out";
		ArrayList<String> listLines = zLoadLines( sAbsolutePath, 50000, sbError );
		int ctTestCases = 0;
		try {
			ctTestCases = Integer.parseInt( listLines.get( 0 ) );
			System.out.println( "test case count: " + ctTestCases ); 
		} catch( Throwable t ) {
			System.err.println( "count test cases: " + t );
			System.exit( -1 );
		}
		
		int xLine = 1;
		for( int xTestCase = 1; xTestCase <= ctTestCases; xTestCase++ ){
			
			// read  E, the maximum (and initial) amount of energy, R, the amount you regain after each activity, and N, the number of activities planned for the day.
			String sLine = listLines.get( xLine );
			String[] asParams = split( sLine, ' ' );
			int E = Integer.parseInt( asParams[0] );
			int R = Integer.parseInt( asParams[1] );
			int N = Integer.parseInt( asParams[2] );
			xLine++;
			
			// read N integers vi, describing the values of the activities you have planned for today. 
			sLine = listLines.get( xLine );
			String[] asValues = split( sLine, ' ' );
			int[] aValues0 = new int[N];
			for( int xActivity = 0; xActivity < N; xActivity++ ){
				aValues0[xActivity] = Integer.parseInt( asValues[xActivity] );  
			}
			xLine++;
			
			int best_value = value( aValues0, 0, N, E, R, E );
			
			// write output
			sbAnswer.append( "Case #" + xTestCase + ": " + best_value + "\n" );
			
		}
		fileSave( sAbsolutePath_output, sbAnswer.toString(), sbError );
		System.out.println( "wrote " + ctTestCases + " cases" );
	}

	static final int value( int[] aValues0, int xActivity, int ctActivities, int energy_remaining, int energy_regained, int energy_max ){
		int best_value = 0;
		for( int eTry = 0; eTry <= energy_remaining; eTry++ ){
			int value_try = eTry * aValues0[xActivity];
			int energy_after_try = energy_remaining - eTry;
			energy_after_try += energy_regained;
			if( energy_after_try > energy_max ) energy_after_try = energy_max;
			if( xActivity < ctActivities - 1 ) value_try += value( aValues0,  xActivity + 1, ctActivities, energy_after_try, energy_regained, energy_max );
			if( value_try > best_value ) best_value = value_try;  
		}
		return best_value;
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
}
