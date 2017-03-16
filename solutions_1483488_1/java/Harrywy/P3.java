package qualificationRound;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class P3 {
	public static int recycle(int j, int b) {
		int ret = 0;
		String old = Integer.toString(j);
		int size = old.length();
		HashSet<String> app = new HashSet<String>();
		for (int i = 1; i < size; ++i) {
			String tmp = old.substring(i) + old.substring(0, i);
			int num = Integer.parseInt(tmp);			
			if (num <= b && num > j && !app.contains(tmp)) {				
				ret++;
				app.add(tmp);
			}
		}
		return ret;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		FileWriter fw = new FileWriter("out.txt");
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; ++i) {
			String line = br.readLine();
			String A = line.split(" ")[0];
			String B = line.split(" ")[1];
			int a = Integer.parseInt(A);
			int b = Integer.parseInt(B);
			int num = 0;
			for (int j = a; j <= b; ++j) {
				num += recycle(j, b);
			}
			fw.append("Case #" + i + ": " + num + "\n");
		}
		br.close();
		fw.close();
	}
}
