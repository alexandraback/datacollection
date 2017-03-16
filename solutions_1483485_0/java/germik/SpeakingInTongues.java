package qualification.p1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class SpeakingInTongues
{
	private static void calculate( String testCase, BufferedWriter bw, int n ) throws Exception
	{
		String s11 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String s12 = "our language is impossible to understand";
		
		String s21 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String s22 = "there are twenty six factorial possibilities";
		
		String s31 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String s32 = "so it is okay if you want to just give up";
		
		String s41 = "aozq";
		String s42 = "yeqz";
		
		String decoded = "";
		
		main: for ( char c : testCase.toCharArray() )
		{
			for ( int i = 0; i < s11.length(); i++ )
			{
				char cc = s11.charAt( i );
				if ( cc == c )
				{
					decoded += s12.charAt( i );
					continue main;
				}
			}
			
			for ( int i = 0; i < s21.length(); i++ )
			{
				char cc = s21.charAt( i );
				if ( cc == c )
				{
					decoded += s22.charAt( i );
					continue main;
				}
			}

			for ( int i = 0; i < s31.length(); i++ )
			{
				char cc = s31.charAt( i );
				if ( cc == c )
				{
					decoded += s32.charAt( i );
					continue main;
				}
			}
			
			for ( int i = 0; i < s41.length(); i++ )
			{
				char cc = s41.charAt( i );
				if ( cc == c )
				{
					decoded += s42.charAt( i );
					continue main;
				}
			}

		}
		
		bw.append( "Case #"+n+": "+decoded+"\n" );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/qualification/p1/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/qualification/p1/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String testCase = br.readLine();
			calculate( testCase, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
