import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class SpeakinginTongues {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 * @throws Exception 
	 */
	public static void main(String[] args) throws FileNotFoundException{
		// TODO Auto-generated method stub
		//System.setOut(new PrintStream(new File("SpeakinginTongues.txt")));
		
		Scanner scanner = new Scanner(System.in);
		Integer testcasenum = Integer.valueOf(scanner.next());
		scanner.nextLine();
	
		HashMap<Character,Character> map = new HashMap<Character,Character>();
		
		String googlerese1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String text1 = "our language is impossible to understand";
		String googlerese2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String text2 = "there are twenty six factorial possibilities";
		String googlerese3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String text3 = "so it is okay if you want to just give up";
		
		put(map, googlerese1, text1);
		put(map, googlerese2, text2);
		put(map, googlerese3, text3);
		put(map, "z", "q");
		put(map, "q", "z");
	
//		for (char index = 'a';index <= 'z';index++){
//			System.out.print(index);
//			System.out.print(" ");
//			System.out.println(map.get(index));
//		}
//	
		for (int testcase = 0;testcase < testcasenum;testcase++){
			String line = scanner.nextLine();
			System.out.print("Case #");
			System.out.print(testcase+1);
			System.out.print(": ");
			print(map, line);
			System.out.println();
		}
		
	}
	public static void put(HashMap<Character, Character> map, String googlerese, String text){
		for (int index = 0;index < googlerese.length();index++){
//			if (map.containsKey(googlerese.charAt(index))){
//				System.out.println(googlerese.charAt(index) + " " + map.get(googlerese.charAt(index)) + " " +text.charAt(index));
//			}
			map.put(googlerese.charAt(index), text.charAt(index));
		}
	}
	public static void print(HashMap<Character, Character> map, String googlerese){
		for (int index = 0;index < googlerese.length();index++){
			System.out.print(map.get(googlerese.charAt(index)));
		}
	}
}
