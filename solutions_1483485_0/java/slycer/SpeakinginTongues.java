import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;


public class SpeakinginTongues {

	static char [] d = new char[300]; 
	static{
	
		d['f']='c';
		d['g']='v';
		d['d']='s';
		d['q']='z';
		d['y']='a';
		//d[' ']= 
		d['z']='q'; 
		d['e']='o';
		d['b']='h';
		d['c']='e';
		d['a']='y';
		d['n']='b';
		d['o']='k';
		d['l']='g';
		d['m']='l';
		d['j']='u';
		d['k']='i';
		d['h']='x';
		d['i']='d';
		d['w']='f';
		d['v']='p';
		d['u']='j';
		d['t']='w';
		d['s']='n';
		d['r']='t';
		d['p']='r';
		d['y']='a';
		d['x']='m';
		d[' ']=' ';
	}
	
	public static char [] translate ( char [] input ){
		char [] output = new char[input.length]; 
		for ( int i=0; i<input.length; i++ ){
			output[i] = d[ input[i] ]; 
		}
		return output; 
	}
	
	public static void main( String [] arg ) throws NumberFormatException, IOException{
		BufferedReader reader = new BufferedReader(new FileReader(new File("input")));
		PrintWriter output = new PrintWriter(new File("output"));
		int cases = Integer.valueOf( reader.readLine() ); 
		for ( int c=1; c<=cases; c++ ){
			char [] out = translate( reader.readLine().toCharArray() );
			output.print( "Case #"+c+": " ); 
			for ( int i=0; i<out.length; i++ ){
				System.out.println( (int)out[i] ); 
				output.print( out[i] );
			}
			output.println(); 
		}
		output.close(); 
	}
	
	public static void main_ ( String [] arg ) throws IOException{
		BufferedReader reader = new BufferedReader ( new InputStreamReader( System.in ) ); 
		Map<Character,Character> map = new HashMap(); 
		for ( int i=0; i<3; i++ ){
			String sursa = reader.readLine(); 
			String destinatie = reader.readLine(); 
			for ( int j=0; j<sursa.length(); j++ ){
				map.put(sursa.charAt(j), destinatie.charAt(j) ); 
			}
		}
		for ( Character key : map.keySet() ){
			System.out.println( "d['"+key+"']="+map.get( key )); 
		}
	}
	
}
