import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class TheLastWord {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();

		for (int i = 1; i <= t; ++i) {
			String S = in.next();
			char firsLetter = S.charAt(0);
			String lastWord = "" + firsLetter;
			for(int j = 1; j < S.length(); j++){
				if(firsLetter <= S.charAt(j)){
					lastWord = S.charAt(j) + lastWord;
					firsLetter = S.charAt(j);
				}else{
					lastWord = lastWord + S.charAt(j);
				}
			}
			System.out.println("Case #" + i + ": " + lastWord);
		}

		in.close();
	}
	
}
