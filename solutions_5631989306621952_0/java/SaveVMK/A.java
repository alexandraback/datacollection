import java.io.*;
import java.util.*;
import java.math.*;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/A-small.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			String s = sc.nextLine();
			StringBuilder ans = new StringBuilder();
			for (char c : s.toCharArray()) {
				if (ans.length() == 0) {
					ans.append(c);
					continue;
				}
				if (c >= ans.charAt(0))
					ans.insert(0,c);
				else
					ans.append(c);
			}
			
			output += "Case #" + i + ": " + ans + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/A-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}