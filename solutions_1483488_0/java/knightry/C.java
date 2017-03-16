import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class C {
	
	C() {
		Scanner in=new Scanner(System.in);
		for (int T=in.nextInt(),TC=1; T-->0; ++TC) {
			int A=in.nextInt(),B=in.nextInt();
			int cnt=0;
			for (int m=2; m<=B; ++m)
				cnt+=count(A,m);
			System.out.printf("Case #%d: %d%n", TC,cnt);
		}
	}
	
	int count(int A, int m) {
		String s = Integer.toString(m); // 345
		Set<Integer> set=new TreeSet<Integer>();
		for (int i=1; i<s.length(); ++i) {
			if (s.charAt(i)!='0') {
				String t = s.substring(i)+s.substring(0,i);
				int n = new Integer(t);
				if (A<=n && n<m)
					set.add(n);
			}
		}
		return set.size();
	}

	public static void main(String[] args) {
		new C();
	}

}
