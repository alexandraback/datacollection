import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class TheLastWord {

	static String smallIn = "small_input1AA.txt";
	static String largeIn = "large_input1AA.txt";
	static String smallOut = "small_output1AA.txt";
	static String largeOut = "large_output1AA.txt";
	public static void main(String[] args) {
		Path p = Paths.get(smallIn);
		try {
			Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(Files.newInputStream(p))));
			int test = sc.nextInt();
			sc.nextLine();
			StringBuilder sb = new StringBuilder();
			for(int t = 1; t <= test; t++) {
				String s = sc.nextLine();
				char head = s.charAt(0);
				String build = s.substring(0, 1);
				for(int i = 1; i < s.length(); i++) {
					char c = s.charAt(i);
					if(c >= head) {
						build = c + build;
						head = c;
					} else {
						build += c;
					}
				}
				sb.append("Case #" + t +": " + build);
				if(t != test) {
					sb.append("\n");
				}
			}
			writer(sb.toString());
			sc.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void writer(String str) {
		Path p = Paths.get(smallOut);
		try {
			Files.write(p, str.getBytes());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
