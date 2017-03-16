package round1;

import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			char[] S = s.next().toCharArray();
			String str = ""+S[0];
			for (int j = 1; j < S.length; j++) {
				if (str.charAt(0)>S[j]){
					str+=S[j];
				}else{
					str=S[j]+str;
				}
			}
			System.out.println("Case #" + (i+1) + ": " + str);
		}
		s.close();
	}
}
