package codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;

public class Googlerese {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			System.setIn(new FileInputStream("A-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		  InputStreamReader inp = new InputStreamReader(System.in);
		  BufferedReader br = new BufferedReader(inp);
		  
		  String line = "";
		  int arrayLength = 0;
		  
		  try{
			  line = br.readLine();
			  arrayLength = Integer.parseInt( line );
		  } catch(Exception x){
			  System.err.println(x);
			  System.exit(1);
		  }
		  
		  String[] phrases = new String[arrayLength];
		  char[] map = {'e', 'j', 'p', 'm', 'y', 's', 'l', 'c', 'k', 'd', 'x', 'v', 'n', 'r', 'i', 'b', 'a', 'f', 'g', 'h', 'o', 'q', 't', 'u', 'w', 'z'};
		  char[] pam = {'o', 'u', 'r', 'l', 'a', 'n', 'g', 'e', 'i', 's', 'm', 'p', 'b', 't', 'd', 'h', 'y', 'c', 'v', 'x', 'k', 'z', 'w', 'j', 'f', 'q'};
		  		  
		  for(int i=0; i < arrayLength; i++){
			  String casenum = "" + (i+1);
			  String phrase = "";
			  
			  try{
				  phrase = br.readLine();
			  } catch(Exception x){
				  System.err.println(x);
				  System.exit(1);
			  }			  
		  
			  for(int j=0; j < map.length; j++){
			    phrase = phrase.replaceAll(""+map[j], "#"+j+"#");
			  }
			  
			  for(int j=0; j < map.length; j++){
				    phrase = phrase.replaceAll("#"+j+"#", ""+pam[j]);
		      }
			  
			  System.out.println("Case #" + casenum + ": " + phrase);
		  }
	}
}
