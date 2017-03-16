import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class GettingDigits {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tests = s.nextInt();
		for(int t = 1; t <= tests; t++) {
			String str = s.next();
			Map<Character, Integer> chars = new HashMap<Character, Integer>();
			for(int i = 0; i < str.length(); i++) {
				if(chars.containsKey(str.charAt(i))) {
					chars.put(str.charAt(i), chars.get(str.charAt(i))+1);
				} else {
					chars.put(str.charAt(i), 1);
				}
			}
			StringBuilder res = new StringBuilder("");
			if(chars.containsKey('Z')) {
				while(chars.get('Z') > 0) {
					res.append("0");
					chars.put('Z', chars.get('Z') -1);
					chars.put('E', chars.get('E') -1);
					chars.put('R', chars.get('R') -1);
					chars.put('O', chars.get('O') -1);
				}
			}
			if(chars.containsKey('G')) {
				while(chars.get('G') > 0) {
					res.append("8");
					chars.put('E', chars.get('E') -1);
					chars.put('I', chars.get('I') -1);
					chars.put('G', chars.get('G') -1);
					chars.put('H', chars.get('H') -1);
					chars.put('T', chars.get('T') -1);
				}
			}
			if(chars.containsKey('W')) {
				while(chars.get('W') > 0) {
					res.append("2");
					chars.put('T', chars.get('T') -1);
					chars.put('W', chars.get('W') -1);
					chars.put('O', chars.get('O') -1);
				}
			}
			if(chars.containsKey('U')) {
				while(chars.get('U') > 0) {
					res.append("4");
					chars.put('F', chars.get('F') -1);
					chars.put('O', chars.get('O') -1);
					chars.put('U', chars.get('U') -1);
					chars.put('R', chars.get('R') -1);
				}
			}
			if(chars.containsKey('X')) {
				while(chars.get('X') > 0) {
					res.append("6");
					chars.put('S', chars.get('S') -1);
					chars.put('I', chars.get('I') -1);
					chars.put('X', chars.get('X') -1);
				}
			}
			if(chars.containsKey('R')) {
				while(chars.get('R') > 0) {
					res.append("3");
					chars.put('T', chars.get('T') -1);
					chars.put('H', chars.get('H') -1);
					chars.put('R', chars.get('R') -1);
					chars.put('E', chars.get('E') -1);
					chars.put('E', chars.get('E') -1);
				}
			}
			if(chars.containsKey('O')) {
				while(chars.get('O') > 0) {
					res.append("1");
					chars.put('O', chars.get('O') -1);
					chars.put('N', chars.get('N') -1);
					chars.put('E', chars.get('E') -1);
				}
			}
			if(chars.containsKey('F')) {
				while(chars.get('F') > 0) {
					res.append("5");
					chars.put('F', chars.get('F') -1);
					chars.put('I', chars.get('I') -1);
					chars.put('V', chars.get('V') -1);
					chars.put('E', chars.get('E') -1);
				}
			}
			if(chars.containsKey('S')) {
				while(chars.get('S') > 0) {
					res.append("7");
					chars.put('S', chars.get('S') -1);
					chars.put('E', chars.get('E') -1);
					chars.put('V', chars.get('V') -1);
					chars.put('E', chars.get('E') -1);
					chars.put('N', chars.get('N') -1);
				}
			}
			if(chars.containsKey('N')) {
				while(chars.get('N') > 0) {
					res.append("9");
					chars.put('N', chars.get('N') -1);
					chars.put('I', chars.get('I') -1);
					chars.put('N', chars.get('N') -1);
					chars.put('E', chars.get('E') -1);
				}
			}
			char[] sorted = res.toString().toCharArray();
			Arrays.sort(sorted);
			String resStr = new String(sorted);
			System.out.println("Case #"+t+": "+resStr);
		}
	}

}
