import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class cars_real {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/cars_small.in"));
		PrintStream output = new PrintStream(new File("output/cars_small.out"));
		PrintStream out = output;
		int T = input.nextInt();
		primary: for (int oncase = 1; oncase <= T; oncase++) {
			out.printf("Case #%d: ", oncase);
			int n = input.nextInt(); input.nextLine();
			String[] line = input.nextLine().split(" ");
			for (int i=0; i<n; i++) {
				line[i] = line[i].replaceAll("(.)\\1{1,}", "$1");
			}
			Set<Character> outer = new HashSet<Character>();
			for (String cur : line) {
				outer.add(cur.charAt(0));
				outer.add(cur.charAt(cur.length()-1));
			}
			for (int i=0; i<n; i++) {
				if (line[i].length() == 1) {
					line[i] += line[i];
				}
				if (line[i].length() <= 2) continue;
				for (char c : line[i].substring(1, line[i].length()-1).toCharArray()) {
					if (!outer.add(c)) {
						out.println(0);
						continue primary;
					}
				}
				line[i] = line[i].charAt(0) + "" + line[i].charAt(line[i].length()-1);
			}
			ArrayList<String> cars = new ArrayList<String>();
			Set<Character> startsWith = new HashSet<Character>();
			Set<Character> endsWith = new HashSet<Character>();
			int[] dup = new int[26];
			for (String cur : line) {
				cars.add(cur);
				if (cur.charAt(0) == cur.charAt(1)) {
					dup[cur.charAt(0)-97]++;
					continue;
				}
//				System.out.println(startsWith + " " + endsWith);
				if (!(startsWith.add(cur.charAt(0)) && endsWith.add(cur.charAt(1)))) {
//					System.out.println(oncase + " " + cur);
					out.println(0);
					continue primary;
				}
			}
//			System.out.println(startsWith);
//			System.out.println(endsWith);
			Set<Character> temp = new HashSet<>(startsWith);
			startsWith.retainAll(endsWith);
			BigInteger res = BigInteger.ONE;
			int sep = n - startsWith.size();
//			System.out.println(startsWith);
			for (int i=0; i<26; i++) {
				if (dup[i] > 1) {
					res = res.multiply(fact(BigInteger.valueOf(dup[i])));
					if (temp.contains(i+97) || endsWith.contains(i+97)) {
						sep -= dup[i];
					} else {
						sep -= dup[i]-1;
					}
				} else if (dup[i] == 1 && temp.contains(i+97) || endsWith.contains(i+97)) {
					sep--;
				}
			}
//			System.out.println(sep);
			res = res.multiply(fact(BigInteger.valueOf(sep)));
			out.println(res.mod(BigInteger.valueOf(1_000_000_007)));
		}
//		out.println(fact(BigInteger.valueOf(10)));
		output.close();
	}
	
	public static BigInteger fact(BigInteger base) {
		BigInteger res = BigInteger.ONE;
		for (BigInteger to = base; to.compareTo(BigInteger.ONE) > 0; to = to.subtract(BigInteger.ONE)) {
			res = res.multiply(to);
		}
		return res;
	}
}