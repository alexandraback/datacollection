import java.util.Scanner;

public class A {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %s\n", i + 1, exec());
	}
	
	private static String GOOGLERESE = " abcdefghijklmnopqrstuvwxyz";
	private static String ENGLISH =    " yhesocvxduiglbkrztnwjpfmaq";
	
	public static String exec() {
		String in = sc.nextLine();
		StringBuilder sb = new StringBuilder(in.length());
		for (char c : in.toCharArray()) {
			int idx = GOOGLERESE.indexOf(c);
			sb.append(ENGLISH.charAt(idx));
		}
		return sb.toString();
	}
}
