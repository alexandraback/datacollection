import java.io.*;
import java.util.*;

public class Enclosure {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-small.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			if (n < m) {
				int temp = n;
				n = m;
				m = temp;
			}
			if (k == 1 || m == 1) {
				output += "Case #" + i + ": " + k + "\n";
				continue;
			}
			int degreeDia = (m+1)/2;
			int degreeAugDia = (m==n) ? m/2 : (m+1)/2;
			int numStones = Integer.MAX_VALUE;
			for (int j = 2; j <= degreeDia; j++) {
				if (2*j*j-2*j+1 >= k) {
					numStones = 4*j-4;
					break;
				} else if (2*j*j-2*j+2 + j-1 >= k) {
					numStones = 4*j-3;
					break;
				}
			}
			for (int j = 1; j <= degreeAugDia; j++) {
				if (2*j*j + j-1 >= k) {
					if (4*j-2 < numStones)
						numStones = 4*j-2;
					else if (4*j-1 + j-1 < numStones)
						numStones = 4*j-1;
					break;
				}
			}
			if (numStones <= m*n) {
				output += "Case #" + i + ": " + numStones + "\n";
				continue;
			}
			int currWidth = (m==n) ? m-1+m%2 : m+m%2;
			int currHeight = m-1+m%2;
			int[] cornerLengths = {(m-1)/2, (m-1)/2, (m-1)/2, (m-1)/2};
			int numIntersected = (m==n && currHeight == m) ? 2*degreeDia*degreeDia-2*degreeDia+1 : 2*degreeAugDia*degreeAugDia;
			numStones = (m==n && currHeight == m)? 4*degreeDia-4 : 4*degreeAugDia-2;
			while (currHeight < m) {
				if (numIntersected + cornerLengths[0] >= k) {
					break;
				}
				numStones += 2;
				numIntersected += currWidth;
				currHeight++;
			}
			while (currWidth < n) {
				if (numIntersected + cornerLengths[0] >= k) {
					break;
				}
				numStones += 2;
				numIntersected += currHeight;
				currWidth++;
			}
			if (numIntersected >= k) {
				output += "Case #" + i + ": " + numStones + "\n";
				continue;
			} else if (numIntersected + cornerLengths[0] >= k) {
				output += "Case #" + i + ": " + (numStones+1) + "\n";
				continue;
			}
			while (true) {
				Arrays.sort(cornerLengths);
				numStones++;
				numIntersected += cornerLengths[3];
				cornerLengths[3]--;
				if (numIntersected >= k) {
					output += "Case #" + i + ": " + numStones + "\n";
					break;
				}
			}
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}