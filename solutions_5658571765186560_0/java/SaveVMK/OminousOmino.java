import java.io.*;
import java.util.*;

public class OminousOmino {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/D-small.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int x = sc.nextInt();
			int r = sc.nextInt();
			int c = sc.nextInt();
			if ((r*c)%x==0 && (r>=x||c>=x) && r>x-2 && c>x-2 && x<=6)
				output += "Case #" + i + ": " + "GABRIEL" + "\n";
			else
				output += "Case #" + i + ": " + "RICHARD" + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/D-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}