import java.util.*;
import java.io.*;
import java.util.regex.*;

public class consonants {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/consonants.in"));
		PrintWriter out = new PrintWriter(new File("output/consonants.out"));
		int sets = input.nextInt();
		input.nextLine();
		primary: for (int onSet = 1; onSet <= sets; onSet++) {
			System.out.printf("%d of %d%n", onSet, sets);
			System.out.printf("Case #%d: ", onSet);
			String word = input.next();
			int n = input.nextInt();
			//input.nextLine();
			Pattern p = Pattern.compile("[^aeiou]{" + n-- + "}");
			Matcher m = p.matcher(word);
			System.out.println(word + " " + p.toString());
			long tot = 0;
			Map<Integer, Set<Integer>> cache = new HashMap<Integer, Set<Integer>>();
			while (m.find()) {
				//System.out.println(m.start() + " " + m.end());
				int si = m.start(); int ei = m.end();
				System.out.printf("INIT: %d,%d%n",si,ei);
				for (int s=si; s<=ei-n; s++) {
					System.out.println("NEW START " + s);
					for (int e=s+n; e<=ei; e++) {
						System.out.printf("%d,%d%n", s, e);
						for (int i=0; i<=s; i++) {
							if (!cache.containsKey(i)) {
								cache.put(i, new HashSet<Integer>());
							}
							for (int j=e; j<word.length(); j++) {
								if (cache.get(i).add(j)) tot++;
							}
						}
					}
				}
			}
			System.out.println(tot);
			System.out.println(cache.toString());
		}
		out.close();
	}
}