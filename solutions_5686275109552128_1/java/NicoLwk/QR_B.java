import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import java.util.Map.Entry;

public class QR_B {

	public static void main(String[] args) throws IOException {
		Scanner sc2 = new Scanner(System.in);
		String inFile = sc2.nextLine();
		String outFile = inFile + ".out.txt";
		FileReader fr = new FileReader(inFile);
		Scanner sc = new Scanner(new BufferedReader(fr));
		FileWriter fw = new FileWriter(outFile);
		BufferedWriter bw = new BufferedWriter(fw);
		PrintWriter pw = new PrintWriter(bw);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++)
			new CaseB(sc, pw, i + 1);
		sc.close();
		pw.close();
	}

}

class CaseB {
	CaseB(Scanner sc, PrintWriter pw, int caseNo) {
		TreeMap<Integer, Integer> map = new TreeMap<>();
		int D = sc.nextInt();
		for (int i = 0; i < D; i++) {
			int key = sc.nextInt();
			incMapValue(map, key, 1);
		}
		int min = map.lastKey();
		int maxKey = map.lastKey();
		for (int i = maxKey - 1; i >= 1; i--) {
			int splitTotal = 0;
			for (Entry<Integer, Integer> e : map.entrySet()) {
				int number = e.getKey(), count = e.getValue();
				int split = number / i + ((number % i > 0) ? 1 : 0) - 1;
				splitTotal += split * count;
			}
			min = Math.min(min, splitTotal + i);
		}
		pw.println("Case #" + caseNo + ": " + min);
	}

	void incMapValue(TreeMap<Integer, Integer> map, int key, int inc) {
		int count = 0;
		Integer j = map.get(key);
		if (j != null)
			count = j;
		map.put(key, count + inc);
	}

}
