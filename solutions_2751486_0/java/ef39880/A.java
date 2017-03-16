package round1C2013;

import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		int T = si();
		for (int i = 0; i < T; i++) {
			pcon = 0;
			String str = scan.next();
			int L = str.length();
			int n = si();

			int p = 0,prep = 0;
			int sum = 0;
			while((p=conSearch(str,n))!=-1){
				sum+=(p-prep+1)*(L-p-n+1);
				prep = p+1;
			}
			out.println("Case #"+(i+1)+": "+sum);
		}
		out.flush();
	}

	static int si() {
		return Integer.parseInt(scan.next());
	}

	static int pcon = 0;

	static int conSearch(String str,int n){
		for (int i = pcon; i < str.length()-n+1 ; i++) {
			boolean flag = true;
			for (int j = i; j < i+n; j++) {
				if(isVowel(str.charAt(j))) flag = false;
			}
			if(flag){
				pcon = i+1;
				return i;
			}
		}
		pcon = str.length();
		return -1;
	}

	static boolean isVowel(char a){
		return a=='a' | a=='i' | a=='u' | a=='e' | a=='o';
	}
}
