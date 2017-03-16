import java.io.*;
import java.util.*;

public class CookieClicker {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/B-large.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			double c = sc.nextDouble();
			double f = sc.nextDouble();
			double x = sc.nextDouble();
			double cps = 2.0;
			double seconds = 0.0;
			double lowestTime = seconds + x/cps;
			while (true) {
				seconds += c/cps;
				cps += f;
				if (seconds + x/cps < lowestTime)
					lowestTime = seconds + x/cps;
				else
					break;
			}
			output += "Case #" + i + ": " + String.format("%.7f", lowestTime) + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/B-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}