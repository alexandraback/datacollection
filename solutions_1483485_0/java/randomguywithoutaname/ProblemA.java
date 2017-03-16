import java.util.Scanner;


class ProblemA {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		char[] mappings = "yhesocvxduiglbkrztnwjpfmaq".toCharArray();
		
		int T = Integer.parseInt(in.nextLine());
		int I = 0;
		while (T --> 0) {
			char[] str = in.nextLine().toCharArray();
			for (int i = 0; i < str.length; ++i)
				str[i] = (str[i] == ' ') ? ' ' : mappings[str[i]-'a'];
			System.out.printf("Case #%d: %s\n", ++I, new String(str));
		}
	}
}
