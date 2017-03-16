import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		Map<Character, Character> map = main.makeMap();
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String line = bf.readLine();
			int T = Integer.parseInt(line);
			for (int testcaseIndex=0; testcaseIndex<T; testcaseIndex++) {
				String testCase = bf.readLine();
				
				String out  = main.solve(testCase, map);
				
				System.out.print("Case #"+(testcaseIndex+1)+": ");
				System.out.println(out);

			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
	
	private String solve(String str, Map<Character, Character> map) {
		StringBuffer buffer = new StringBuffer();
		for (int i=0; i<str.length(); i++) {
			buffer.append(map.get(str.charAt(i)));
		}		
		return buffer.toString();
	}
	
	private Map<Character, Character>makeMap() {
		HashMap<Character, Character> map = new HashMap<Character, Character>();
		String a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		for (int i=0; i<a.length(); i++) {
			map.put(a.charAt(i), b.charAt(i));
		}
		map.put('z', 'q');
		map.put('q', 'z');
		
		return map;
	}
}
