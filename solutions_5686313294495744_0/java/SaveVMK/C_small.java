import java.io.*;
import java.util.*;
import java.math.*;

public class C_small {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-small.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			sc.nextLine();
			String[][] list = new String[n][2];
			for (int j = 0; j < n; j++) {
				list[j][0] = sc.next();
				list[j][1] = sc.next();
			}
			
			int max = 0;
			for (int j = 0; j < 1<<n; j++) {
				HashSet<String> realA = new HashSet<String>();
				HashSet<String> realB = new HashSet<String>();
				int num = j;
				int count = 0;
				for (int k = 0; k < n; k++) {
					if (num%2==1) {
						realA.add(list[k][0]);
						realB.add(list[k][1]);
						count++;
					}
					num >>= 1;
				}
				boolean poss = true;
				for (int k = 0; k < n; k++) {
					if (!realA.contains(list[k][0]) || !realB.contains(list[k][1])) {
						poss = false;
						break;
					}
				}
				if (poss) {
					if (n-count > max)
						max = n-count;
				}
			}
			
			output += "Case #" + i + ": " + max + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}