import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class DeceitfulWar {

	public DeceitfulWar(){}
	public static void main( String[] asArguments ){
		doProblem();
	}
	
	static void doProblem(){
		StringBuffer sbError = new StringBuffer();
		StringBuffer sbAnswer = new StringBuffer();
		String sAbsolutePath_input = "C:\\codejam\\Deceitful War\\D-small-attempt0.in";
		String sAbsolutePath_output = "C:\\codejam\\Deceitful War\\D-small-attempt0.out";
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
			System.out.println( "test case " + xTestCase );
			xLine++;
			int ctBlocks = Integer.parseInt( listLines.get( xLine ) );
			xLine++;
			String sNaomiBlocks = listLines.get( xLine );
			xLine++;
			String sKenBlocks = listLines.get( xLine );
			String[] asNaomiBlocks = split( sNaomiBlocks, ' ' );
			String[] asKenBlocks = split( sKenBlocks, ' ' );
			double[] adNaomi = new double[ ctBlocks ];
			double[] adKen = new double[ ctBlocks ];
			for( int xBlock = 0; xBlock < ctBlocks; xBlock++ ){
				adNaomi[xBlock] = Double.parseDouble( asNaomiBlocks[ xBlock ] );
				adKen[xBlock] = Double.parseDouble( asKenBlocks[ xBlock ] );
			}
			java.util.Arrays.sort( adNaomi );
			java.util.Arrays.sort( adKen );
			java.util.ArrayList<Double> listNaomi_war = new java.util.ArrayList<Double>();
			java.util.ArrayList<Double> listKen_war = new java.util.ArrayList<Double>();
			java.util.ArrayList<Double> listNaomi_dw = new java.util.ArrayList<Double>();
			java.util.ArrayList<Double> listKen_dw = new java.util.ArrayList<Double>();
			for( int xBlock = 0; xBlock < ctBlocks; xBlock++ ){
				listNaomi_war.add( new Double( adNaomi[ xBlock ] ) );
				listNaomi_dw.add( new Double( adNaomi[ xBlock ] ) );
				listKen_war.add( new Double( adKen[ xBlock ] ) );
				listKen_dw.add( new Double( adKen[ xBlock ] ) );
			}

			// regular war
			int iScore_Naomi_war = 0;
			int iScore_Ken_war = 0;
			while( listNaomi_war.size() > 0 ){
				double dNaomiBlock = listNaomi_war.get( 0 );
				listNaomi_war.remove( 0 );
				int xKenBlock = 0;
				int xBestKenBlock = 0; // if Ken cannot beat Naomi he uses his lowest block
				while( true ){
					if( listKen_war.get( xKenBlock ).doubleValue() > dNaomiBlock ){
						xBestKenBlock = xKenBlock;
						break;
					}
					xKenBlock++;
					if( xKenBlock == listKen_war.size() ) break;
				}
				double dKenBlock = listKen_war.get( xBestKenBlock ).doubleValue();
				listKen_war.remove( xBestKenBlock );
				if( dKenBlock > dNaomiBlock ) iScore_Ken_war++; else iScore_Naomi_war++;
			}

			// deceitful war
			int iScore_Naomi_dw = 0;
			int iScore_Ken_dw = 0;
			while( listNaomi_dw.size() > 0 ){
				int iNaomiBestBlock = iCanBeat( listNaomi_dw, listKen_dw.get( 0 ).doubleValue()  );
				double dNaomiBlock;
				double dNaomiBlock_told;
				if( iNaomiBestBlock == -1 ){ // if Naomi cannot beat the lowest Ken block, she loses all further battles
					dNaomiBlock = listNaomi_dw.get( 0 );
					dNaomiBlock_told = dNaomiBlock;
					listNaomi_dw.remove( 0 );
				} else { // if naomi can beat Ken's lowest block, she forces it
					dNaomiBlock_told = listKen_dw.get( listKen_dw.size() - 1 ) + 1;
					dNaomiBlock = listNaomi_dw.get( iNaomiBestBlock );
					listNaomi_dw.remove( iNaomiBestBlock );
				}
				int xKenBlock = 0;
				int xBestKenBlock = 0; // if Ken cannot beat Naomi he uses his lowest block
				while( true ){
					if( listKen_dw.get( xKenBlock ).doubleValue() > dNaomiBlock_told ){
						xBestKenBlock = xKenBlock;
						break;
					}
					xKenBlock++;
					if( xKenBlock == listKen_dw.size() ) break;
				}
				double dKenBlock = listKen_dw.get( xBestKenBlock ).doubleValue();
				listKen_dw.remove( xBestKenBlock );
				if( dKenBlock > dNaomiBlock ) iScore_Ken_dw++; else iScore_Naomi_dw++;
			}

			// write output
			sbAnswer.append( "Case #" + xTestCase + ": " + iScore_Naomi_dw + " " + iScore_Naomi_war + "\n" );
		}
		fileSave( sAbsolutePath_output, sbAnswer.toString(), sbError );
		System.out.println( "wrote " + ctTestCases + " cases" );
	}

	static int iCanBeat( ArrayList<Double> list, double value ){
		int xList = 0;
		while( true ){
			if( xList == list.size() ) return -1;
			if( list.get( xList ).doubleValue() > value ) return xList;
			xList++;
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
	
}

/**
 Problem

 Naomi and Ken sometimes play games together. Before they play, each of them gets N identical-looking blocks of wood with masses between 0.0kg and 1.0kg (exclusive). All of the blocks have different weights. There are lots of games they could play with those blocks, but they usually play something they call War. Here is how War works:

 Each player weighs each of his or her own blocks, so each player knows the weights of all of his or her own blocks, but not the weights of the other player's blocks.
 They repeat the following process N times:
 Naomi chooses one of her own blocks, with mass ChosenNaomi.
 Naomi tells Ken the mass of the block she chose.
 Ken chooses one of his own blocks, with mass ChosenKen.
 They each put their block on one side of a balance scale, and the person whose block is heavier gets one point.
 Both blocks are destroyed in a fire.

 Naomi has realized three things about War. First, she has realized that she loses a lot. Second, she has realized that there is a unique strategy that Ken can follow to maximize his points without assuming anything about Naomi's strategy, and that Ken always uses it. Third, she has realized that she hates to lose. Naomi has decided that instead of playing War, she will play a game she calls Deceitful War. The great thing about Deceitful War is that Ken will think they're playing War!

 Here is how Deceitful War works, with differences between Deceitful War and War in bold:

 Each player weighs each of his or her own blocks. Naomi also weighs Ken's blocks while he isn't looking, so Naomi knows the weights of all blocks and Ken only knows the weights of his own blocks.
 They repeat the following process N times:
 Naomi chooses one of her own blocks, with mass ChosenNaomi.
 Naomi tells Ken a number, ToldNaomi, between 0.0kg and 1.0kg exclusive. Ken, who thinks they're playing War, thinks the number Naomi just told him is ChosenNaomi.
 Ken chooses one of his own blocks, with mass ChosenKen.
 They each put their block on one side of a balance scale, and the person whose block is heavier gets one point.
 Both blocks are destroyed in a fire.

 Naomi doesn't want Ken to know that she isn't playing War; so when she is choosing which block to play, and what mass to tell Ken, she must make sure that the balance scale won't reveal that ChosenNaomi ≠ ToldNaomi. In other words, she must make decisions so that:

 ChosenNaomi > ChosenKen if, and only if, ToldNaomi > ChosenKen, and
 ToldNaomi is not equal to the mass of any of Ken's blocks, because he knows that isn't possible.

 It might seem like Naomi won't win any extra points by being deceitful, because Ken might discover that she wasn't playing War; but Naomi knows Ken thinks both players are playing War, and she knows what he knows, and she knows Ken will always follow his unique optimal strategy for War, so she can always predict what he will play.

 You'll be given the masses of the blocks Naomi and Ken started with. Naomi will play Deceitful War optimally to gain the maximum number of points. Ken will play War optimally to gain the maximum number of points assuming that both players are playing War. What will Naomi's score be? What would it have been if she had played War optimally instead?
 Examples

 If each player has a single block left, where Naomi has 0.5kg and Ken has 0.6kg, then Ken is guaranteed to score the point. Naomi can't say her number is ≥ 0.6kg, or Ken will know she isn't playing War when the balance scale shows his block was heavier.

 If each player has two blocks left, where Naomi has [0.7kg, 0.2kg] and Ken has [0.8kg, 0.3kg], then Naomi could choose her 0.2kg block, and deceive Ken by telling him that she chose a block that was 0.6kg. Ken assumes Naomi is telling the truth (as in how the War game works) and will play his 0.8kg block to score a point. Ken was just deceived, but he will never realize it because the balance scale shows that his 0.8kg block is, like he expected, heavier than the block Naomi played. Now Naomi can play her 0.7kg block, tell Ken it is 0.7kg, and score a point. If Naomi had played War instead of Deceitful War, then Ken would have scored two points and Naomi would have scored zero.
 Input

 The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing a single integer N, the number of blocks each player has. Next follows a line containing N space-separated real numbers: the masses of Naomi's blocks, in kg. Finally there will be a line containing N space-separated real numbers: the masses of Ken's blocks, in kg.

 Each of the masses given to Ken and Naomi will be represented as a 0, followed by a decimal point, followed by 1-5 digits. Even though all the numbers in the input have 1-5 digits after the decimal point, Ken and Naomi don't know that; so Naomi can still tell Ken that she played a block with mass 0.5000001kg, and Ken has no reason not to believe her.
 Output

 For each test case, output one line containing "Case #x: y z", where x is the test case number (starting from 1), y is the number of points Naomi will score if she plays Deceitful War optimally, and z is the number of points Naomi will score if she plays War optimally.
 Limits

 1 ≤ T ≤ 50.
 All the masses given to Ken and Naomi are distinct, and between 0.0 and 1.0 exclusive.
 Small dataset

 1 ≤ N ≤ 10.
 Large dataset

 1 ≤ N ≤ 1000.
 Sample

 Input


 4
 1
 0.5
 0.6
 2
 0.7 0.2
 0.8 0.3
 3
 0.5 0.1 0.9
 0.6 0.4 0.3
 9
 0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
 0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458



 Output


 Case #1: 0 0
 Case #2: 1 0
 Case #3: 2 1
 Case #4: 8 4

*/