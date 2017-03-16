package interview;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class Solution_GJ {
	
	private Solution_GJ(){}
	
	public static void main(String[] args) throws IOException{
		//String file = "C:/zfeng/A-small-attempt0.in";
		//String output = "C:/zfeng/A-small-attempt0.out";
		String file = "C:/zfeng/B-small-attempt1.in";
		String output = "C:/zfeng/output.txt";
		BufferedReader content =  new BufferedReader(new FileReader(file));	
		PrintWriter outputFile = new PrintWriter(new FileWriter(output));
		
		int num_cases = Integer.parseInt( content.readLine() );
		
		for( int i = 1; i<=num_cases; i++ ){
			int N = Integer.parseInt( content.readLine() );
			String dataRow = content.readLine();
			String[] data = dataRow.split(" ");

			int num = connectTrain( data );
			System.out.println(i);

			outputFile.println("Case #"+i+": "+num);
			
		}
		
		content.close();
		outputFile.close();		
	}
	
	public static int connectTrain( String[] data ){
		// remove reproduction
		HashMap<String, Integer> rep = new HashMap<String, Integer>();
		ArrayList<String> strs = new ArrayList<String>();
		for( String str: data){
			if( rep.containsKey(str) ){
				boolean valid = true;
				for( int k=1; k<str.length(); k++)
					valid = valid && (str.charAt(0)==str.charAt(k));
				if( !valid )
					return 0;
				
				rep.put(str, 1+rep.get(str));
			}else{
				rep.put(str, 1);
				strs.add(str);
			}
		}
		
		// remove words begin with the same char
		HashMap<Integer, String> begin = new HashMap<Integer, String>();
		int extra = 1;
		for(int i=strs.size()-1; i>=0; i--){
			String str = strs.get(i);
			if( rep.get( str )>1 ){
				int temp = 1;
				for( int k=1; k<=rep.get( str );k++)
					temp *= k;
				extra *= temp; 
			}
			
			int id = str.charAt( 0 );
			if( begin.containsKey(id)){
				String temp = begin.get(id);
				if( str.charAt(str.length()-1)==id ){
					begin.put(id, str+temp);
					strs.remove(temp);
					strs.remove(i);
					strs.add( str+temp );
				}
				else if ( temp.charAt(temp.length()-1)==id ){
					begin.put(id, temp+str);
					strs.remove(temp);
					strs.remove(i);
					strs.add( temp+str );
				}
				else
					return 0;
			}else
				begin.put(id, str);
		}
		
		// connect words possible
		for(int i=strs.size()-1; i>=0; i--){
			String str = strs.get(i);
			int nb = str.charAt(str.length()-1);
			if( begin.containsKey(nb )){
				String temp = begin.get(nb);
				if( temp.equals(str))
					continue;
				strs.add( str+temp );
				strs.remove(str);
				strs.remove(temp);
				begin.remove(nb);
				int str_nb = str.charAt(0);
				begin.put(str_nb, str+temp);
			}				
		}
		
		HashSet<Integer> set = new HashSet<Integer>();
		for( int k=0; k<strs.size();k++){
			String str = strs.get(k);
			int nb1 = str.charAt(0);
			int nb2 = str.charAt(str.length()-1);
			if( nb1 == nb2 ){
				for( int j=1; j<str.length()-1; j++){
					int nbj = str.charAt(j);
					if( nbj != nb1)
						return 0;
				}
			}
				
			if( !set.contains( nb1 ))
				set.add(nb1);
			if( !set.contains( nb2 ))
				set.add(nb2);
		}
			
		for( int k=0; k<strs.size();k++){
			String str = strs.get(k);
			int bb = 0;
			int ee = str.length();
			for( int j=0; j<str.length(); j++){
				if( str.charAt(0)!=str.charAt(j))
				{
					bb = j;
					break;							
				}
			}
			for( int j=str.length(); j>0; j--){
				if( str.charAt(str.length()-1)!=str.charAt(j-1))
				{
					ee = j;
					break;							
				}
			}
			
			if( ee<= bb || ( ee== str.length()&& bb==0) )
				continue;
			
			for(int j=bb; j<ee; j++){
				int nbj = str.charAt(j);
				if( nbj==str.charAt(j-1) )
					continue;

				if( !set.contains( nbj ))
					set.add(nbj);
				else
					return 0;
			}
		}
		
		for( int k=1; k<=strs.size();k++)
			extra *= k;
		
		return extra;
	}
	
	
}
