package contest2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ProblemC {
	
	private static ArrayList<String> inputList = new ArrayList<>();
	private static ArrayList<String> outputList = new ArrayList<>();
	private static String input = "C-small-attempt7.in"; 
	private static String output = "outputC.out";
	private static BufferedWriter buffer;
	
	public static void main( String args[] ){
	
		inputList = readFile( input );
		ArrayList<String> a = new ArrayList<>();
		int trys = Integer.parseInt( inputList.remove( 0 ) );
		for( int i = 0; i < trys; i++ ){
			
				outputList.add("Case #" + ( i + 1 ) + ": ");
				a = question();
				for( String tmp : a ){
					outputList.add( tmp );
				}
				
		}
		writeFile( output , outputList );
	}
	
	public static ArrayList<String> question(){
		
		int start = 0;
		int number = 0;
		ArrayList<Integer> numbers = new ArrayList<>();
		
		for( int i = 0; i < inputList.get(0).length(); i++ ){
			if( inputList.get(0).charAt( i ) == ' ' ){
				
				number = Integer.parseInt( inputList.get(0).substring( start, i ) );
				start = i + 1;
				numbers.add(number);
				
			}
			if( i == inputList.get(0).length() - 1 ){

				number = Integer.parseInt( inputList.get(0).substring( start ) );
				numbers.add(number);
			}
		}
		
		char [][]minesWeeper = new char[numbers.get(0)][numbers.get(1)];
		
		int mines = numbers.get(2);
		int row = numbers.get(0);
		int col = numbers.get(1);
		
		for( int i = 0; i < row; i++ ){
			for( int j = 0; j < col; j++ ){
				minesWeeper[i][j] = '.';
				if( i == row - 1 && j == col - 1 ){
					minesWeeper[i][j] = 'c';
				}
			}
		}
		int miRow = row;
		int miCol = col;
		while( mines != 0 && ( miRow > 0 || miCol > 0 ) ){
			if( miRow > miCol ){
				if( miCol <= mines ){
					for( int i = col - miCol; i < col; i++ ){
						
						if( mines == 0 ){
							break;
						}
						minesWeeper[row - miRow][i] = '*';
						mines--;
					}
					
					miRow--;
				}else{
					for( int i = col - miCol; i < col - 2 ; i++ ){
						if( mines == 0 ){
							break;
						}
						minesWeeper[row - miRow][i] = '*';
						mines--;
					}
					miRow--;
				}
			}else{
				if( miRow <= mines ){
					for( int i = row - miRow; i < row; i++ ){
						if( mines == 0 ){
							break;
						}
						minesWeeper[i][col - miCol] = '*';
						mines--;
					}
					miCol--;
				}else{
					for( int i = row - miRow; i < row - 2 ; i++ ){
						if( mines == 0 ){
							break;
						}
						minesWeeper[i][col - miCol] = '*';
						mines--;
					}
					miCol--;
				}
			}
		}
		
		System.out.println(mines);
		/*for( int i = 0; i < row - 2; i++ ){
			for( int j = 0; j < col; j++ ){
				if( mines == 0 ){
					break;
				}
				minesWeeper[i][j] = '*';
				mines--;
			}
			if( mines == 0 ){
				break;
			}
		}
		for( int i = 0; i < col; i++ ){
			for( int j = row - 2; j < row; j++ ){
				if( mines == 0 ){
					break;
				}
				if( i >= 0 && j >= 0 ){
					minesWeeper[j][i] = '*';
					mines--;
				}
				
			}
			if( mines == 0 ){
				break;
			}
		}*/
		int posR = row - 1;
		int posC = col - 1;
		
		inputList.remove(0);
		
		
		String mw = "";
		ArrayList<String> list = new ArrayList<>();
		list.clear();
		for( int i = 0; i < row; i++ ){
			for( int j = 0; j < col; j++ ){
				mw += minesWeeper[i][j] + "";
			}
			list.add(mw);
			mw = "";
		}
		
		if( row * col - numbers.get(2) == 1 ){
			return list;
		}
		if( posR - 1  >= 0 )
			if( minesWeeper[posR - 1][posC] == '*' ){
				list.clear();
				list.add("Impossible");
				return list;
			}
		if( posC - 1  >= 0 )
			if( minesWeeper[posR][posC - 1] == '*' ){
				list.clear();
				list.add("Impossible");
				return list;
			}
		if( posR - 1  >= 0 && posC - 1  >= 0 )
			if( minesWeeper[posR - 1][posC - 1] == '*' ){
				list.clear();
				list.add("Impossible");
				return list;
			}
		return list;
		
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
