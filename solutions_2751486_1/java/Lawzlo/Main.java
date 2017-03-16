import java.io.*;
import java.util.*;

public class Main {

	static Scanner sc;

	public static String solve() {
		long ans = 0;
		String name = sc.next();
		long N = sc.nextLong();

		long count = 0;
		long lastcount = 0;
		for (int i = 0; i < name.length(); i++) {
			char c = name.charAt(i);
			if (c == 'a' || c == 'e' ||  c == 'i' ||  c == 'o' ||  c == 'u') {
				if (count >= N) {
 					ans += (long) (count - N + 1) * (long) (i - lastcount - count);
					ans += (long) (count - N + 1) * (long) (name.length() - i);
					ans += (long) (i - lastcount - count) * (long) (name.length() - i);
					ans += (long) (count - N + 1) * (long) (count - N + 2) / 2;
					
					lastcount = i - (N - 1);
				}
				count = 0;
			}
			else
				count++;
		}
		if (count >= N) {
			ans += (long) (count - N + 1) * (long) (name.length() - lastcount - count);
			ans += (long) (count - N + 1) * (long) (count - N + 2) / 2;
		}

		return String.valueOf(ans);
	}

	public static void main(String[] args) throws IOException {
	
//			sc = new Scanner(new InputStreamReader(new FileInputStream("input.txt")));
			
			sc = new Scanner(System.in);
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));;
			long k = sc.nextLong();
			for (long i = 0; i < k; i++) {
				String s = "Case #" + (i + 1) + ": " + solve();
				System.out.println(s);
				bw.write(s);
				bw.newLine();
			}
			sc.close();
			bw.close();
	}
}