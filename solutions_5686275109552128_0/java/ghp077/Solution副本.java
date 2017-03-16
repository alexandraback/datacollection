import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Solution {

	public static int getMinT(ArrayList<Integer> pList) {

		Collections.sort(pList);
		int max = pList.get(pList.size()-1);
		if (max <= 3) {
			return max;
		}
		int minT = max;
		for (int i = max/2; i >= 2 ; i--) {
			ArrayList<Integer> p2List = (ArrayList<Integer>) pList.clone();
			p2List.set(p2List.size()-1, i);
			p2List.add(max-i);
			int minT2 = getMinT(p2List);
			if (minT2+1 < minT) {
				minT = minT2+1;
			}
		}
		return minT;
	}
	public static void B() throws IOException {
		File inf = new File("/Users/guanhaipeng/Documents/workspace/CodeJam/src/B-small-attempt3.in");
		File outf = new File("/Users/guanhaipeng/Documents/workspace/CodeJam/src/output.txt");
		Scanner scanner = new Scanner(inf);
		BufferedWriter out = new BufferedWriter(new FileWriter(outf));
		int caseNum = scanner.nextInt();
		scanner.nextLine();
		for (int i = 1; i <= caseNum; i++) {
			// TODO
			int D = scanner.nextInt();
			ArrayList<Integer> pList = new ArrayList<>();
			int ans = 0;
			for (int j = 0; j < D; j++) {
				pList.add(scanner.nextInt());
			}
			ans = getMinT(pList);
			// TODO
			String string = "Case #" + i + ": " + ans;
			System.out.println(string);
			out.write(string + "\n");
		}
		scanner.close();
		out.flush();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		B();

	}

}
