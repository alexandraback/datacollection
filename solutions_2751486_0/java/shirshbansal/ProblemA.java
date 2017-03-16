import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int t;
		Scanner scan = new Scanner(System.in);
		t = scan.nextInt();
		scan.nextLine();
		for(int i = 0; i < t; i++) {
			String input = scan.nextLine();
			String in[] = input.split(" ");
//			System.out.println(in[0] + " " + in[1]);
			String name = in[0];
			int n = Integer.parseInt(in[1]);
			int ans = 0;
			int len[] = new int[name.length()+1];
			for(int j = name.length()-1; j >= 0; j--) {
				if(name.charAt(j) != 'a' && name.charAt(j) != 'e' && name.charAt(j) != 'i' && name.charAt(j) != 'o' && name.charAt(j) != 'u') {
					len[j] = len[j+1]+1;
				}
			}
			int prev = 0;
			for(int j = 0; j < name.length(); j++) {
				if(len[j] >= n) {
					int countStr = (name.length() - j - n + 1);
					ans = ans + (countStr * (j-prev+1));
					prev = j+1;
				}
			}
			System.out.println("Case #"+(i+1)+": "+ans);
		}
	}
}
