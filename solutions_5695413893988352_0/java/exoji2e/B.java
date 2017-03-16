import java.util.Scanner;
import java.math.BigInteger;
public class B {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i = 1; i<=N; i++) {
			
			String s1 = sc.next();
			String s2 = sc.next();
			
			
			
			char[] reals1 = new char[s1.length()];
			char[] reals2 = new char[s1.length()];
			boolean fail = false;
			int who = 0;
			for(int j = 0; j<s1.length(); j++) {
				if(fail) {
					if(who == 1) {
						if(s1.charAt(j) == '?') {
							reals1[j] = '0';
						} else {
							reals1[j] = s1.charAt(j);
						}
						if(s2.charAt(j) == '?') {
							reals2[j] = '9';
						} else {
							reals2[j] = s2.charAt(j);
						}
					} else {
						if(s1.charAt(j) == '?') {
							reals1[j] = '9';
						} else {
							reals1[j] = s1.charAt(j);
						}
						if(s2.charAt(j) == '?') {
							reals2[j] = '0';
						} else {
							reals2[j] = s2.charAt(j);
						}
					}
					
				} else if(s1.charAt(j) == '?' && s2.charAt(j) == '?') {
					reals1[j] = '0';
					reals2[j] = '0';
				} else if(s1.charAt(j) == '?') {
					reals1[j] = s2.charAt(j);
					reals2[j] = s2.charAt(j);
				} else if(s2.charAt(j) == '?') {
					reals1[j] = s1.charAt(j);
					reals2[j] = s1.charAt(j);
				} else if(s1.charAt(j) == s2.charAt(j)){
					reals1[j] = s1.charAt(j);
					reals2[j] = s1.charAt(j);
				} else if(s1.charAt(j) > s2.charAt(j)){
					fail = true;
					who = 1;
					reals1[j] = s1.charAt(j);
					reals2[j] = s2.charAt(j);
				} else {
					fail = true;
					who = 2;
					reals1[j] = s1.charAt(j);
					reals2[j] = s2.charAt(j);
				}
			}
			
			int where = 0;
			for(int j = 0; j<s1.length(); j++) {
				if(s1.charAt(j) != '?' && s2.charAt(j) != '?') {
					if(s1.charAt(j) != s2.charAt(j)) {
						if(s1.charAt(j) > s2.charAt(j)) {
							where = j;
							who = 1;
						} else {
							where = j;
							who = 2;
						}
						break;
					}
				}
			}
			boolean failed = !(where>0);
			if(!failed) {
				char[] reals3 = new char[s1.length()];
				char[] reals4 = new char[s1.length()];
				for(int j = 0; j<where-1; j++) {
					if(s1.charAt(j) == '?' && s2.charAt(j) == '?') {
						reals3[j] = '0';
						reals4[j] = '0';
					} else if(s1.charAt(j) == '?') {
						reals3[j] = s2.charAt(j);
						reals4[j] = s2.charAt(j);
					} else if(s2.charAt(j) == '?') {
						reals3[j] = s1.charAt(j);
						reals4[j] = s1.charAt(j);
					} else if(s1.charAt(j) == s2.charAt(j)){
						reals3[j] = s1.charAt(j);
						reals4[j] = s1.charAt(j);
					}
				}
				if(who == 1) {
					if(s1.charAt(where-1) == '?' && s2.charAt(where-1) == '?') {
						reals3[where-1] = '0';
						reals4[where-1] = '1';
					} else if(s1.charAt(where-1) == '?' && s2.charAt(where-1) > '0') {
						reals3[where-1] = (char)((int)(s2.charAt(where-1)) - 1);
						reals4[where-1] = s2.charAt(where-1);
					} else if(s2.charAt(where-1) == '?' && s1.charAt(where-1) < '9') {
						reals3[where-1] = s1.charAt(where-1);
						reals4[where-1] = (char)((int)(s1.charAt(where-1)) + 1);
					} else {
						failed = true;
					}	
				} else {
					if(s1.charAt(where-1) == '?' && s2.charAt(where-1) == '?') {
						reals3[where-1] = '1';
						reals4[where-1] = '0';
					} else if(s1.charAt(where-1) == '?' && s2.charAt(where-1) < '9') {
						reals3[where-1] = (char)((int)(s2.charAt(where-1)) + 1);
						reals4[where-1] = s2.charAt(where-1);
					} else if(s2.charAt(where-1) == '?' && s1.charAt(where-1) > '0') {
						reals3[where-1] = s1.charAt(where-1);
						reals4[where-1] = (char)((int)(s1.charAt(where-1)) - 1);
					} else {
						failed = true;
					}
				}
				if(!failed) {
					if(who == 1) {
						who = 2;
					} else {
						who = 1;
					}
					reals3[where] = s1.charAt(where);
					reals4[where] = s2.charAt(where);
					for(int j = where+1; j<s1.length(); j++) {
						if(who == 1) {
							if(s1.charAt(j) == '?') {
								reals3[j] = '0';
							} else {
								reals3[j] = s1.charAt(j);
							}
							if(s2.charAt(j) == '?') {
								reals4[j] = '9';
							} else {
								reals4[j] = s2.charAt(j);
							}
						} else {
							if(s1.charAt(j) == '?') {
								reals3[j] = '9';
							} else {
								reals3[j] = s1.charAt(j);
							}
							if(s2.charAt(j) == '?') {
								reals4[j] = '0';
							} else {
								reals4[j] = s2.charAt(j);
							}
						}
					}
					/*StringBuilder sb = new StringBuilder();
					sb.append(reals1);
					sb.append(' ');
					sb.append(reals2);
					sb.append(' ');
					sb.append(reals3);
					sb.append(' ');
					sb.append(reals4);
					System.out.println(sb);*/
					BigInteger diff1 = diff(reals1,reals2);
					BigInteger diff2 = diff(reals3,reals4);
					if(diff1.compareTo(diff2) > 0) {
						reals1 = reals3;
						reals2 = reals4;
					} else if(diff1.compareTo(diff2) == 0) {
						StringBuilder sb1 = new StringBuilder();
						sb1.append(reals1);
						StringBuilder sb3 = new StringBuilder();
						sb3.append(reals3);
						BigInteger a = new BigInteger(sb1.toString());
						BigInteger b = new BigInteger(sb3.toString());
						if(a.compareTo(b) > 0) {
							reals1 = reals3;
							reals2 = reals4;
						} if (a.compareTo(b) == 0) {
							StringBuilder sb2 = new StringBuilder();
							sb2.append(reals2);
							StringBuilder sb4 = new StringBuilder();
							sb4.append(reals4);
							BigInteger c = new BigInteger(sb2.toString());
							BigInteger d = new BigInteger(sb4.toString());
							if(c.compareTo(d) > 0) {
								reals1 = reals3;
								reals2 = reals4;
							}
						}
					}
				}
			}
			
			StringBuilder out = new StringBuilder();
			out.append(reals1);
			out.append(' ');
			out.append(reals2);
			
			
			
			System.out.println("Case #" + i + ": " + out.toString());
			
		}
	}
	public static BigInteger diff(char[] s1, char[] s2) {
		StringBuilder sb1 = new StringBuilder();
		sb1.append(s1);
		StringBuilder sb2 = new StringBuilder();
		sb2.append(s2);
		BigInteger a = new BigInteger(sb1.toString());
		BigInteger b = new BigInteger(sb2.toString());
		if(a.compareTo(b) < 0) 
			return b.subtract(a);
		else
			return a.subtract(b);
	}
}