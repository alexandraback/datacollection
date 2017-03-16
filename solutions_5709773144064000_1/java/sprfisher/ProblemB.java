package contest2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ProblemB {
	
	private static ArrayList<String> inputList = new ArrayList<>();
	private static ArrayList<String> outputList = new ArrayList<>();
	private static String input = "B-large.in"; 
	private static String output = "output.out";
	private static BufferedWriter buffer;
	
	public static void main( String args[] ){
		
		inputList = readFile( input );
		int trys = Integer.parseInt( inputList.remove( 0 ) );
		for( int i = 0; i < trys; i++ ){
			
				outputList.add("Case #" + ( i + 1 ) + ": " + question() );
			
		}
		writeFile( output , outputList );
	}
	
	public static String question(){
		
		int start = 0;
		double number = 0;
		ArrayList<Double> numbers = new ArrayList<>();
		for( int i = 0; i < inputList.get(0).length(); i++ ){
			if( inputList.get(0).charAt( i ) == ' ' ){
				
				number = Double.parseDouble( inputList.get(0).substring( start, i ) );
				start = i + 1;
				numbers.add(number);
				
			}
			if( i == inputList.get(0).length() - 1 ){

				number = Double.parseDouble( inputList.get(0).substring( start ) );
				numbers.add(number);
			}
		}
		
		inputList.remove(0);
		double totalTime = 0;
		double timeCookie = 2;
		double time = 0;
		
		while(true){
			time = totalTime + ( numbers.get(2) / timeCookie );
			totalTime  += ( numbers.get(0) / timeCookie );
			timeCookie += numbers.get(1);
			if( totalTime + ( numbers.get(2) / timeCookie ) > time ){
				break;
			}
		}
		timeCookie -= numbers.get(1);
		totalTime  -= ( numbers.get(0) / timeCookie );
		
		
		totalTime +=  ( numbers.get(2) / timeCookie );
		return totalTime + "";
		
	}
	
	
	
	public static ArrayList<String> readFile( String fileName ){
		File file = new File( fileName );
		FileReader fileReader = null;
		try{
			fileReader = new FileReader( file );
		} 
		catch( FileNotFoundException e ){
			System.err.println( "The File Doesn't Exist(error 1)." );
			e.printStackTrace();
			return null;
		}
		BufferedReader buffer = new BufferedReader( fileReader );
		String line = null;
		ArrayList<String> list = new ArrayList<String>();
		try{
			while( ( line = buffer.readLine() ) != null ){
				list.add( line );
			}
		}
		catch( IOException e ){
			System.err.println( "Buffer Can't read the line(error 2)." );
			e.printStackTrace();
			return null;
		}
		try{
			buffer.close();
		}catch( IOException e ){
			System.err.println( "Buffer Can´t close(error 3)." );
			e.printStackTrace();
			return null;
		}
		return list;
	}
	
	public static boolean writeFile(String fileName, ArrayList <String> lines){
		File file=new File(fileName);
		FileWriter fileWriter=null;
		try {
			fileWriter=new FileWriter(file);
		} catch (IOException e) {
			System.err.println("The File Doesn't Exist(error 4).");
			e.printStackTrace();
		}
		buffer = new BufferedWriter(fileWriter);
		for(String line : lines){
			try {
				buffer.write(line);
				buffer.newLine();
			} catch (IOException e) {
				System.err.println("Buffer Can't Read The Line(error 5).");
				e.printStackTrace();
				return false;
			}	
		}
		try {
			buffer.close();
		} catch (IOException e) {
			System.out.println("Buffer Can't Close(error 6).");
			e.printStackTrace();
		}
		return true;
	}
}
