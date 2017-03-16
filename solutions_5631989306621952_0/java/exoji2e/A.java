import java.util.LinkedList;
import java.util.Scanner;
public class A {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i = 1; i<=T; i++) {
			String s = sc.next();
			LinkedList<Character> seq = new LinkedList<Character>();
			seq.add(s.charAt(0));
			for(int j = 1; j<s.length(); j++) {
				char c = s.charAt(j);
				if(c>=seq.getFirst()) {
					seq.addFirst(c);
				} else {
					seq.addLast(c);
				}
			}
			char[] cA = new char[seq.size()];
			int k = 0;
			for(char c:seq) {
				cA[k++] = c;
			}
			System.out.println("Case #" + i + ": " + new String(cA));
		}
	}
}