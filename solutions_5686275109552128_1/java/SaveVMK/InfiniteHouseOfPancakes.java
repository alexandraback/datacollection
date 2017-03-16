import java.io.*;
import java.util.*;

public class InfiniteHouseOfPancakes {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/B-large.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int d = sc.nextInt();
			int[] diners = new int[d];
			int maxPancakes = 0;
			for (int j = 0; j < d; j++) {
				diners[j] = sc.nextInt();
				if (diners[j] > maxPancakes)
					maxPancakes = diners[j];
			}
			int lowest = 1000;
			for (int j = 1; j <= maxPancakes; j++) {
				int num = j;
				for (int k = 0; k < d; k++) {
					num += Math.ceil(diners[k]/(double)j)-1;
				}
				if (num < lowest)
					lowest = num;
			}
			
			output += "Case #" + i + ": " + lowest + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/B-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}