import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class B {
	static String file = "B-large";	
	static char[] alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
	static long MOD = 1000000007;
	
	static class T {
		public List<String> v = new ArrayList<String>();
		
		public T(String v) {
			this.v.add(v);			
		}
		
		public char first() {
			return v.get(0).charAt(0);			
		}
		
		public char last() {
			String tmp = v.get(v.size() - 1);
			return tmp.charAt(tmp.length() - 1);			
		}
		
		public void append(T t) {
			this.v.addAll(t.v);			
		}
					
		public boolean isValid() {
			StringBuffer supers = new StringBuffer();
			for(String s : v) {
				supers.append(s);
			}
			
			String superss = supers.toString();
			Set<Character> seen = new HashSet<Character>();
			char c1 =superss.charAt(0); 
			for (int i = 1; i < superss.length(); i++) {
				char c2 = superss.charAt(i);
				if (c1 != c2) {
					if (seen.contains(c1))
						return false;					
					else
						seen.add(c1);
				}
				
				c1 = c2;
			}
			
			if (seen.contains(c1))
				return false;
			
			return true;
		}
		
		public List<Character> getChars() {
			Set<Character> chars = new HashSet<Character>();
			
			for(String s : v) {
				for (Character ch : s.toCharArray()) {
					chars.add(ch);
				}
			}
			
			return new ArrayList<Character>(chars);
		}
		
		public int ans() {
			Map<Character, Integer> vals = new HashMap<Character, Integer>();
						
			for(String s : v) {
				boolean ok = true;
				char c = s.charAt(0);
				for (int i = 1; i < s.length(); i++) {
					if (s.charAt(i) != c)
					{
						ok = false;
						break;
					}
				}
				
				if (ok) {
					if (!vals.containsKey(c)) {
						vals.put(c, 0);						
					}
					
					vals.put(c, vals.get(c) + 1);
				}
			}			
			
			int ans = 1;		
			for(Character k : vals.keySet()) {
				int f = fact(vals.get(k));
				ans = (int)(((long)ans) * ((long)f) % MOD);	
			}
			
			return ans;
		}
		
		
	}
	
	static int fact(int v) {
		int ans = 1;
		
		for (int i = 2; i <= v; i++) {
			ans = (int)(((long)ans) * ((long)i) % MOD);
		}
		
		return ans;
	}
	
	static int solve(String[] v) {
		List<T> sub = new ArrayList<T>();
		for (int i = 0; i < v.length; i++) {
			sub.add(new T(v[i]));
		}
		
		while(true) {						
			int removed = -1;
			
			for (int i = 0; i < sub.size(); i++) {
				if (removed != -1)
					break;
				
				for (int j = 0; j < sub.size(); j++) {
					if (i == j)
						continue;
					
					T t1 = sub.get(i);
					T t2 = sub.get(j);
					
					if (t1.last() == t2.first() && t2.first() == t2.last()) {
						t1.append(t2);
						removed = j;
						break;
					}
				}
			}
			
			if (removed == -1) {
 				for (int i = 0; i < sub.size(); i++) {
					if (removed != -1)
						break;
 					
 					for (int j = 0; j < sub.size(); j++) {
						if (i == j)
							continue;
						
						T t1 = sub.get(i);
						T t2 = sub.get(j);
						
						if (t1.last() == t2.first()) {
							t1.append(t2);
							removed = j;
							break;
						}
					}
				}
			}
			
			if (removed == -1)
				break;
			
			sub.remove(removed);		
		}
		
		// validation
		for(T t : sub) {
			if (!t.isValid())
				return 0;
		}
		
		Map<Character, Integer> counts = new HashMap<Character, Integer>();
		for(T t : sub) {
			List<Character> chars = t.getChars();
			for(Character ch : chars) {
				if (!counts.containsKey(ch)) {
					counts.put(ch, 1);
				} else {
					return 0;
				}
			}
		}
		
		int ans = 1;		
		for (int i = 2; i <= sub.size(); i++) {
			ans = (int)(((long)ans) * ((long)i) % MOD);
		}
		
		for (int i = 0; i < sub.size(); i++) {
			int subRes = sub.get(i).ans();			
			ans = (int)(((long)ans) * ((long)subRes) % MOD);
		}
		
		return ans;
	}
	
	public static void main(String[] args) throws IOException {	
			
		FileInputStream fis = new FileInputStream(file+ ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			int n = Integer.parseInt(lines.get(currentIndex++));			
			String[] d = lines.get(currentIndex++).split(" "); 
								
			String r = "Case #" + (i+1) + ": " + solve(d);
									
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();			
	}
}