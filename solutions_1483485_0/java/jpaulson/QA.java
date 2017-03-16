import java.util.*;

public class QA {
	static char[] P = new char[]{'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w',
		'j','p','f','m','a','q'};
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); in.nextLine();
		Set<Character> S = new HashSet<Character>();
		for(char a='a'; a<='z'; a++) S.add(a);
		for(int i=0; i<T; i++) {
			char[] s = in.nextLine().toCharArray();
			for(int j=0; j<s.length; j++) {
				if(s[j] != ' ')
					s[j] = P[s[j]-'a'];
			}
			System.out.println("Case #"+(i+1)+": "+new String(s));
		}
	}
}