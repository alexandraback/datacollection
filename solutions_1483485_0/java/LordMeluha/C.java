import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Scanner;


public class C {

	public static String googleresse(String str, HashMap<Character, Character> map){	
	
	StringBuilder retVal = new StringBuilder();
	
	for(int i=0;i<str.length();i++){
		
		retVal.append(map.get(str.charAt(i)));
	}
	
	return retVal.toString();
	
	}
	public static void main(String args[]){
		
		File file = new File("A-small-attempt0.in");
		
		HashMap<Character, Character> map = new HashMap<Character, Character>();
		
		map.put('a','y');
		map.put('b','h');
		map.put('c','e');
		map.put('d','s');
		map.put('e','o');
		map.put('f','c');
		map.put('g','v');
		map.put('h','x');
		map.put('i','d');
		map.put('j','u');
		map.put('k','i');
		map.put('l','g');
		map.put('m','l');
		map.put('n','b');
		map.put('o','k');
		map.put('p','r');
		map.put('q','z');
		map.put('r','t');
		map.put('s','n');
		map.put('t','w');
		map.put('u','j');
		map.put('v','p');
		map.put('w','f');
		map.put('x','m');
		map.put('y','a');
		map.put('z','q');
		map.put(' ', ' ');
		
		int N = 0;
		try{
			  FileInputStream fstream = new FileInputStream(file);
			
			  DataInputStream in = new DataInputStream(fstream);
			  BufferedReader br = new BufferedReader(new InputStreamReader(in));
			  String strLine;
			  if ((strLine = br.readLine()) != null)   {
				  N = Integer.parseInt(strLine);
			  }
			  int currentCase = 1;
			  while(N > 0 && currentCase <= N){
						
						String str= br.readLine();
						
						System.out.println("Case #"+currentCase+": " + googleresse(str, map));
						currentCase++;
					}
			
			  in.close();
			    }catch (Exception e){
			  System.err.println("Error: " + e.getMessage());
			  }
		
		
		
	}
	
}
