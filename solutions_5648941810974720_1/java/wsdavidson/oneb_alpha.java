import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class oneb_alpha {
	public static void main(String[] args) {
		try {
			process();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void process()
	throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
			System.out.println("Case #" + (i+1) + ":" + processTestCase(reader));
		}
		
		reader.close();
	}
	
	private static String processTestCase(BufferedReader reader)
	throws IOException {
		String s = reader.readLine();
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		while (s.length() > 0) {
			if (s.indexOf('Z') != -1) s = removeOneLetter(s, "ZERO", list, 0);
			else if (s.indexOf('W') != -1) s = removeOneLetter(s, "TWO", list, 2);
			else if (s.indexOf('U') != -1) s = removeOneLetter(s, "FOUR", list, 4);
			else if (s.indexOf('R') != -1) s = removeOneLetter(s, "THREE", list, 3);
			else if (s.indexOf('X') != -1) s = removeOneLetter(s, "SIX", list, 6);
			else if (s.indexOf('S') != -1) s = removeOneLetter(s, "SEVEN", list, 7);
			else if (s.indexOf('V') != -1) s = removeOneLetter(s, "FIVE", list, 5);
			else if (s.indexOf('G') != -1) s = removeOneLetter(s, "EIGHT", list, 8);
			else if (s.indexOf('O') != -1) s = removeOneLetter(s, "ONE", list, 1);
			else if (s.indexOf('E') != -1) s = removeOneLetter(s, "NINE", list, 9);
		}
		
		Collections.sort(list);
		
		String ret = "";
		for (int i = 0; i < list.size(); ++i) {
			ret += "" + list.get(i);
		}
		
		return " " + ret;
	}
	
	private static String removeOneLetter(String s, String toRemove, ArrayList<Integer> list, int val) {
		list.add(val);
		for (int i = 0; i < toRemove.length(); ++i) {
			int index = s.indexOf(toRemove.charAt(i));
			if (index == -1) System.out.println("Couldn't remove " + i + " of " + toRemove + " from " + s);
			if (index == 0) s = s.substring(1);
			else if (index == s.length()-1) s = s.substring(0, s.length()-1);
			else s = s.substring(0, index) + s.substring(index+1);
			
			// System.out.println("New string: " + s);
		}
		
		return s;
	}
}