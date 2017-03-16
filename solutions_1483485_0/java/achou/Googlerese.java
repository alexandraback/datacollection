import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;


public class Googlerese {

	public static void main(String[] args){
		HashMap hm = new HashMap(); 
		String cypher = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y e q z";
		String orig = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a o z q";
		char[] cypherArary = cypher.toCharArray();
		char[] origArray = orig.toCharArray();
		for(int i = 0; i < cypher.length(); i++){
			hm.put(cypherArary[i], origArray[i]);
		}
		try{
			// Open the file that is the first 
			// command line parameter
			FileInputStream fstream = new FileInputStream(args[0]);
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			//Read File Line By Line
			int numTest = Integer.parseInt(br.readLine());
			for(int i = 0; i < numTest; i ++){
				String str = br.readLine();
				char[] stringArray = str.toCharArray();
				for(int index = 0; index < stringArray.length; index++){
					char c = (Character) hm.get(stringArray[index]);
					stringArray[index] = c;
				}
				String finalString = new String(stringArray);
				int x = i + 1;
				System.out.println("Case #" + x + ": " + finalString);
				
			}
			//Close the input stream
			in.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
		
	}
	
	
}
