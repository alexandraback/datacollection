import java.io.*;
import java.util.*;

public class TrainCars {
	static String removeDups(String s) {
		String out = "";
		out += s.charAt(0);
		char current = s.charAt(0);
		for(int i = 1; i < s.length(); i++) {
			if(s.charAt(i) == current)
				continue;
			current = s.charAt(i);
			out += current;
		}
		return out;
	}
	
	static boolean checkPossible(String s) {
		int[] letters = new int[26];
		for(char c: s.toCharArray()) {
			if(letters[c - 'a'] != 0)
				return false;
			letters[c - 'a']++;
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(new File("B-small-attempt0.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.next());
		for(int c = 1; c <= T; c++){
			int N = Integer.parseInt(scan.next());
			String[] cars = new String[N];
			boolean possible = true;
			for(int i = 0; i < N && possible; i++) {
				cars[i] = removeDups(scan.next());
				if(!checkPossible(cars[i]))
					possible = false;
			}
			
			if(!possible)
				System.out.println("Case #" + c + ": 0");
			else {
				long result = 1;
				Arrays.sort(cars);
				ArrayList<String> finished = new ArrayList<String>();
				int count = 1;
				for(int i = 1; i < N; i++) {
					if(cars[i].equals(cars[i-1]))
						count++;
					else {
						for(int k = 2; k <= count; k++) {
							result *= k;
							result %= 1000000007;
						}
						count = 1;
					}
				}
				for(int k = 2; k <= count; k++) {
					result *= k;
					result %= 1000000007;
				}
				for(int i = 0; i < N; i++) {
					boolean unique = true;
					for(int j = i+1; j < N; j++) {
						if(cars[j].charAt(cars[j].length()-1) == cars[i].charAt(0)) {
							unique = false;
							cars[j] = removeDups(cars[j] + cars[i]);
							break;
						}
						if(cars[i].charAt(cars[i].length()-1) == cars[j].charAt(0)) {
							unique = false;
							cars[j] = removeDups(cars[i] + cars[j]);
							break;
						}
					}
					if(unique)
						finished.add(cars[i]);
				}
				int[] letters = new int[26];
				for(String s: finished)
					for(char t: s.toCharArray())
						letters[t - 'a']++;
				for(int i: letters)
					if(i > 1) {
						possible = false;
						break;
					}
				if(!possible)
					System.out.println("Case #" + c + ": 0");
				else {
					for(int i = 2; i <= finished.size(); i++) {
						result *= i;
						result %= 1000000007;
					}
					System.out.println("Case #" + c + ": " + result);
				}
			}
		}
	}
}
