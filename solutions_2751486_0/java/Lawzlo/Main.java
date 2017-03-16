import java.io.*;
import java.util.*;

public class Main {

	static Scanner sc;

	public static String solve() {
		long ans = 0;
		String name = sc.next();
		int N = sc.nextInt();

		int count = 0;
		int lastcount = 0;
		for (int i = 0; i < name.length(); i++) {
			char c = name.charAt(i);
			if (c == 'a' || c == 'e' ||  c == 'i' ||  c == 'o' ||  c == 'u') {
				if (count >= N) {
 					ans += (count - N + 1) * (i - lastcount - count);
					ans += (count - N + 1) * (name.length() - i);
					ans += (i - lastcount - count) * (name.length() - i);
					ans += (count - N + 1) * (count - N + 2) / 2;
					
					lastcount = i - (N - 1);
				}
				count = 0;
			}
			else
				count++;
		}
		if (count >= N) {
			ans += (count - N + 1) * (name.length() - lastcount - count);
			ans += (count - N + 1) * (count - N + 2) / 2;
		}

		return String.valueOf(ans);
	}

	public static void main(String[] args) {
		try {
//			sc = new Scanner(new InputStreamReader(new FileInputStream("input.txt")));
			
			sc = new Scanner(System.in);
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));;
			int k = sc.nextInt();
			for (int i = 0; i < k; i++) {
				String s = "Case #" + (i + 1) + ": " + solve();
				System.out.println(s);
				bw.write(s);
				bw.newLine();
			}
			sc.close();
			bw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}