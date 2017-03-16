import java.io.*;
import java.util.*;

public class StandingOvation {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/A-small.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int s = sc.nextInt();
			String guests = sc.next();
			int total = 0;
			int invited = 0;
			for (int j = 0; j <= s; j++) {
				int num = guests.charAt(j)-'0';
				total += num;
				if (num == 0 && total <= j) {
					total++;
					invited++;
				}
			}
			
			output += "Case #" + i + ": " + invited + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/A-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}