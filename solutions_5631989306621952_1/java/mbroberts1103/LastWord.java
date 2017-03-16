import java.util.Scanner;


public class LastWord {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int runs = Integer.parseInt(sc.nextLine().trim());
		for(int run = 1 ; run <= runs ; run++) {
			System.out.print("Case #" + run + ": ");
			
			String S = sc.nextLine();
			String newS = S.charAt(0) + "";
			for(int i = 1 ; i < S.length() ; i++) {
				if(S.charAt(i) >= newS.charAt(0)) {
					newS = S.charAt(i) + newS;
				} else {
					newS += S.charAt(i);
				}
			}
			
			System.out.println(newS);
		}
		
		sc.close();
	}
}
