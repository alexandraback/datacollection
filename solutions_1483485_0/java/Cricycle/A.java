import java.util.*;

public class A {
	private static char[] to = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		in.nextLine();
		for(int i = 1; i <= t; ++i) {
			String line = in.nextLine();
			System.out.printf("Case #%d: %s\n", i, convert(line));
		}
	}
	
	public static String convert(String line) {
		for(int i = 0; i < to.length; ++i) {
			line = line.replaceAll("" + (char)(i + 'a'), "" + (char)(to[i] + 'A' -'a'));
		}
		for(int i = 0; i < 26; ++i) {
			line = line.replaceAll("" + (char)(i + 'A'),"" + (char)(i + 'a'));
		}
		return line;
	}
}