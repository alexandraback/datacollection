import java.util.Scanner;
public class C {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = "3 2 3 2 7 2 3 2 3";
		for(int i = 1; i<=n; i++) {
			int N = sc.nextInt();
			int J = sc.nextInt();
			System.out.println("Case #" + i + ":");
			int out = 0;
			int m = 0;
			while(out<J) {
				if((ones(m) + 2)%6 == 0 && ok268(m)) {
					out++;
					char[] numb = convert(next(N-2,m));
					String numbS = new String(numb);
					System.out.println('1' + numbS + "1 " + s);
				}
				m++; //pretty stupid, but we just need 500 so its fine.
			}
		}
		
	}
   
	public static int ones(int m) {
		int i = 0;
		while(m>0) {
			if(m%2 == 1) i++;
			m = m/2;
		}
		return i;
		
	}
	public static boolean ok268(int m) {
		int mod3 = 0;
		boolean neg = true;
		while(m>0) {
			if(m%2 == 1) {
				if(neg) mod3 = mod3-1;
				else mod3 = mod3+1;
			}
			m = m/2;
			neg = !neg;
		}
		return mod3==0;
	}
	public static boolean[] next(int size, int j) {
		boolean[] c = new boolean[size];
		int ind = size-1;
		while(j>0) {
			if(j%2 == 0) {
				c[ind--] = false;
			} else {
				c[ind--] = true;
			}
			j = j/2;
		}
		return c;
	}
	public static char[] convert(boolean[] b) {
		char[] c = new char[b.length];
		for(int i = 0; i<b.length; i++) {
			if(b[i]) {
				c[i] = '1';
			} else {
				c[i] = '0';
			}
		}
		return c;
	}
}