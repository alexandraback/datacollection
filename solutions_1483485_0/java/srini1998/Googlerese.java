import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;
import java.util.Hashtable;
import java.util.Arrays;



public class Googlerese {
	
	private static String decrypt(String pString) {
		char[] converter = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
		String inLower = pString.toLowerCase();
		//ASCII value of lowercase a is 97
		String output = "";
		for (int i=0;i<inLower.length();i++) {
			if (inLower.charAt(i) == ' ') {
				output += " ";
			} else {
				output += converter[(int)inLower.charAt(i) - 97];
			}
		}
		return output;
	}
	
	
	public static void main(String[] args) throws IOException{
		
		/* System.out.println(decrypt("ejp mysljylc kd kxveddknmc re jsicpdrysi"));
		System.out.println(decrypt("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"));
		System.out.println(decrypt("de kr kd eoya kw aej tysr re ujdr lkgc jv")); */
		 if (args.length != 1) {
			System.out.println("Error: incorrect number of arguments.");
			System.out.println("Usage: Googlerese <input-filename>");
		} else {
			BufferedReader inputStream = null;
			try {
				 inputStream = new BufferedReader(new FileReader(args[0]));
				 int totalCases = Integer.valueOf(inputStream.readLine()).intValue();
				 //System.out.println("Total number of cases is: "+totalCases);
				 for (int i=0;i<totalCases;i++) {
					System.out.print("Case #"+(i+1)+": ");
					String googlereseLine = inputStream.readLine();
					System.out.println(decrypt(googlereseLine));
				 }
			} catch (IOException e) {
				System.out.println("Error in reading file");
			} finally {
				if (inputStream != null) {
					inputStream.close();
				}
			}
		} 
	} 
}