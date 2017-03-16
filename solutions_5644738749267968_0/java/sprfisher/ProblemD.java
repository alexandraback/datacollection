package contest2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ProblemD {
	
	private static ArrayList<String> inputList = new ArrayList<>();
	private static ArrayList<String> outputList = new ArrayList<>();
	private static String input = "D-small-attempt0.in"; 
	private static String output = "outputD.out";
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
		int blocks = Integer.parseInt( inputList.remove(0) );
		double number = 0;
		ArrayList<Double> deceitfulNao = new ArrayList<>();
		ArrayList<Double> deceitfulKen = new ArrayList<>();
		
		ArrayList<Double> warNao = new ArrayList<>();
		ArrayList<Double> warKen = new ArrayList<>();
		
		for( int j = 0; j < inputList.get(0).length(); j++ ){
			if( inputList.get(0).charAt( j ) == ' ' ){
				
				number = Double.parseDouble( inputList.get(0).substring( start, j ) );
				start = j + 1;
				deceitfulNao.add(number);
				warNao.add(number);
				
			}
			if( j == inputList.get(0).length() - 1 ){

				number = Double.parseDouble( inputList.get(0).substring( start ) );
				deceitfulNao.add(number);
				warNao.add(number);
			}
		}
		inputList.remove( 0 );
		start = 0;
		for( int j = 0; j < inputList.get(0).length(); j++ ){
			if( inputList.get(0).charAt( j ) == ' ' ){
				
				number = Double.parseDouble( inputList.get(0).substring( start, j ) );
				start = j + 1;
				deceitfulKen.add(number);
				warKen.add(number);
				
			}
			if( j == inputList.get(0).length() - 1 ){

				number = Double.parseDouble( inputList.get(0).substring( start ) );
				deceitfulKen.add(number);
				warKen.add(number);
			}
		}
		inputList.remove( 0 );
		
		for( int i = 0; i < blocks - 1; i++ ){
			for( int j = i + 1; j < blocks; j++ ){
				if( deceitfulNao.get( i ) > deceitfulNao.get( j ) ){
					double tmp = deceitfulNao.get( i );
					deceitfulNao.set( i, deceitfulNao.get( j ) );
					deceitfulNao.set( j, tmp );
				}
				if( warNao.get( i ) > warNao.get( j ) ){
					double tmp = warNao.get( i );
					warNao.set( i, warNao.get( j ) );
					warNao.set( j, tmp );
				}
				if( deceitfulKen.get( i ) > deceitfulKen.get( j ) ){
					double tmp = deceitfulKen.get( i );
					deceitfulKen.set( i, deceitfulKen.get( j ) );
					deceitfulKen.set( j, tmp );
				}
				if( warKen.get( i ) > warKen.get( j ) ){
					double tmp = warKen.get( i );
					warKen.set( i, warKen.get( j ) );
					warKen.set( j, tmp );
				}
			}			
		}
		System.out.println(deceitfulNao);
		System.out.println(deceitfulKen);
		System.out.println(blocks);
		int deceitful = 0;
		int war = 0;
		for( int i = 0; i < blocks; i++ ){
			if( deceitfulNao.get( deceitfulNao.size() - 1 ) > deceitfulKen.get( deceitfulKen.size() - 1 ) ){
				for( int j = deceitfulNao.size() - 1; j >= 0; j-- ){
					if( deceitfulNao.get( j ) < deceitfulKen.get(  deceitfulKen.size() - 1 ) ){
						deceitfulNao.remove( j + 1 );
						deceitfulKen.remove( deceitfulKen.size() - 1 );
						break;
					}
				}
				deceitful++;
			}
			else{
				deceitfulNao.remove(0);
				deceitfulKen.remove(deceitfulKen.size() -1 );
			}
			if( warNao.get(warNao.size() - 1) > warKen.get(warKen.size()-1)){
				war++;
				warKen.remove(0);
				warNao.remove(warNao.size() - 1);
			}
			else{
				for( int j = warKen.size() - 1; j >= 0; j-- ){
					if( warNao.get( warNao.size() - 1 ) > warKen.get( j ) ){
						warNao.remove(warNao.size() - 1);
						warKen.remove( j + 1 );
						break;
					}
				}
			}
		}
		
		
		
		return deceitful + " " + war;
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
