import java.util.*;

public class A {

	public static void main(String[] args) {
		A a = new A();
		a.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			String s = in.nextLine();
			ArrayDeque<Character> q = new ArrayDeque<>();
			q.add(s.charAt(0));
			for (int i=1; i<s.length(); i++) {
				char front = q.getFirst();
				char next = s.charAt(i);
				if (next >= front) {
					q.addFirst(next);
				}
				else {
					q.add(next);
				}
			}
			StringBuilder build = new StringBuilder();
			for (Character c : q) {
				build.append(c);
			}
			System.out.printf("Case #%d: %s\n",a+1,build.toString());
		}
	}
}