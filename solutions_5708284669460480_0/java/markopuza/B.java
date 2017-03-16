import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class B {
	
	private static ArrayList<String> allString = new ArrayList<String>();
	
	public static int  max_occ(String str, int len) {
		int res;
		
		if (str.length() > len) return 0;
		
		int cnt = 1;

		for (int i  = 0; i < str.length(); i++) {
			//System.out.println(str.substring(str.length() - i, str.length()));
			//System.out.println(str.substring(0, i));
			if (str.substring(str.length() - i, str.length()).equals(str.substring(0, i))) cnt = i;
		}
		int gen = len - str.length();
		res = 1 + gen / (str.length() - cnt);
		return res;
	}
	
	public static int count(String tar, String test) {
		int count = 0;
		for (int i = 0; i <= (test.length() - tar.length()); i++) {
			//System.out.println(test.substring(i, i + tar.length()));
			if (test.substring(i, i + tar.length()).equals(tar)) count++;
		}
		return count;
	}
	
	
	static void generate(String kb, String prefix, int n, int k) {
        if (k == 0) {
            allString.add(prefix);
            return;
        }
        for (int i = 0; i < n; ++i) {
            String newPrefix = prefix + kb.charAt(i); 
            generate(kb, newPrefix, n, k - 1); 
        }
    }
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
		
		//System.out.println(max_occ("abc", 3));
		
		int t = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= t; i++) {
			double res = 0;
			
			String[] next = in.readLine().split(" ");
			int k = Integer.parseInt(next[0]);
			int l = Integer.parseInt(next[1]);
			int s = Integer.parseInt(next[2]);
			
			String keyboard = in.readLine();
			String target = in.readLine();
			
			HashMap<Character, Integer> letters = new HashMap<Character, Integer>();
			for (char letter : keyboard.toCharArray()) {
				if (!letters.containsKey(letter)) {
					letters.put(letter, 1);
				}
				else {
					int current = letters.get(letter);
					current++;
					letters.put(letter, current);
				}
			}
			
			boolean possible = true;
			for (char tar : target.toCharArray()) {
				if (!letters.containsKey(tar)) {
					possible = false;
					break;
				}
			}
			
			if (possible) {
				
				//generate all possible strings
				allString = new ArrayList<String>();
				generate(keyboard, "", keyboard.length(), s);
				//System.out.println(allString);
				
				long total = 0;
				for (String str : allString) {
					total += count(target, str);
				}
				
				
				res = max_occ(target, s) - (double) total / allString.size();
			}
			
			System.out.format("Case #%d: %.7f\n", i, res);
		}
	}
}
