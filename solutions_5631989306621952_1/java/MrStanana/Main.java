import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
	public static void main(String[] args) throws IOException {
		String file = "A-large.in";
		BufferedReader br = new BufferedReader(new FileReader(file));
		BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
		int n = Integer.parseInt(br.readLine());
		String[] ss = new String[n];
		for (int i = 0; i < n; i++)
			ss[i] = br.readLine();
		br.close();
		for (int i = 0; i < n; i++) {
			StringBuilder sb = new StringBuilder();
			sb.append(ss[i].charAt(0));
			for (int j = 1; j < ss[i].length(); j++) {
				if (ss[i].charAt(j) >= sb.charAt(0))
					sb.insert(0, ss[i].charAt(j));
				else
					sb.append(ss[i].charAt(j));
			}
			bw.write("Case #" + (i + 1) + ": " + sb.toString());
			bw.newLine();
		}
		bw.close();
	}
}
