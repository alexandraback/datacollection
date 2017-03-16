import java.util.*;
import java.io.*;



public class SpeakingInTongues {


	private static final Scanner sc = new Scanner(System.in);
	private static HashMap<Character, Character> gMap = new HashMap<Character, Character>();
	
	/**
	 * @param args
	 */
	public static void main(String[] args)  throws NumberFormatException, IOException {

		InputStreamReader converter = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(converter);

		int T = Integer.parseInt(in.readLine());
				
		initializeMap();
				

		for (int i = 0; i < T; i++){
			
			String line = in.readLine(); 
			char[] cArray = line.toCharArray();
			
			System.out.print("Case #" + (i + 1) + ": ");
			
			for (int j = 0; j < line.length(); j++)
				if (cArray[j] == ' ')
					System.out.print(' ');
				else
					System.out.print(gMap.get(cArray[j]));
			
			System.out.println("");
			
		}
		

	}
	
	private static void initializeMap(){
		
		
		gMap.put('y','a');
		gMap.put('n','b');
		gMap.put('f','c');
		gMap.put('i','d');
		gMap.put('c','e');
		gMap.put('w','f');
		gMap.put('l','g');
		gMap.put('b','h');
		gMap.put('k','i');
		gMap.put('u','j');
		gMap.put('o','k');
		gMap.put('m','l');
		gMap.put('x','m');
		gMap.put('s','n');
		gMap.put('e','o');
		gMap.put('v','p');
		gMap.put('z','q');
		gMap.put('p','r');
		gMap.put('d','s');
		gMap.put('r','t');
		gMap.put('j','u');
		gMap.put('g','v');
		gMap.put('t','w');
		gMap.put('h','x');
		gMap.put('a','y');
		gMap.put('q','z');

		
	}

}
