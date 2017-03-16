import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.*;
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {

		
		String sampleInput = "qaozejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
		String sampleOutput = "zyeqour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

		//Character[] allLetter = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','x','t','u','v','w','x','y','z'};
		//Set allLInput = new HashSet<Character>(Arrays.asList(allLetter));
		//Set allLOutput = new HashSet<Character>(Arrays.asList(allLetter));
		
		HashMap<Character, Character> map = new HashMap<Character, Character>();
		for(int i=0; i<sampleInput.length(); i++) {
			map.put(sampleInput.charAt(i), sampleOutput.charAt(i));
			
			//allLInput.remove(sampleInput.charAt(i));
			//allLOutput.remove(sampleOutput.charAt(i));
		}

		//System.out.println(allLInput.toString());
		//System.out.println(allLOutput.toString());
		
		/*
		System.out.println(translate("ejp mysljylc kd kxveddknmc re jsicpdrysi", map));
		System.out.println(translate("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", map));
		System.out.println(translate("de kr kd eoya kw aej tysr re ujdr lkgc jv", map));
		*/
		
		
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\input.txt")));
		int cases = Integer.parseInt(reader.readLine());
		for(int i=0; i<cases; i++){
			String inputString = reader.readLine();		
			System.out.println("Case #"+(i+1)+": "+translate(inputString, map));
		}
		
	}
	
	public static String translate(String in, HashMap<Character, Character> map) {
		StringBuilder sb = new StringBuilder();
		char[] inArrary = in.toCharArray();
		for(int i=0; i<inArrary.length;i++) {
			sb.append(map.get(inArrary[i]));
		}
		return sb.toString();
	}
		

}
