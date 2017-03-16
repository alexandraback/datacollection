import java.util.*;
import java.io.*;

public class C  {
	public static void main (String [] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("C-small-0.in"));
			PrintWriter pw = new PrintWriter("C-small-0.out");
			int inputNo;
			inputNo = Integer.parseInt(br.readLine());

			for (int i = 1; i <= inputNo; i++) {
				Integer[] set = new Integer[20];
				Scanner sc = new Scanner(br.readLine());
				sc.nextInt();
				for (int j = 0; j < 20; j++) {
					set[j] = sc.nextInt();
				}
				// get one input here
				pw.println("Case #" + i + ": " + processInput(set));
			}

			br.close();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static String processInput(Integer[] set) {
		String result = "";
		HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
		ArrayList<Integer> first = new ArrayList<Integer>();
		ArrayList<Integer> second = new ArrayList<Integer>();
		int n = set.length;
		for (int i = 0; i < (1<<n); i++) {
			ArrayList<Integer> subset = new ArrayList<Integer>();
			for (int k = 0; k < n; k++) {
				if ((i&(1<<k)) > 0)
					subset.add(set[k]);
			}

			int sum = 0;
			for (int s: subset) {
				sum+=s;
			}
			if (!map.containsKey(sum)) {
				map.put(sum, subset);
			} else {
				first = subset;
				second = map.get(sum);
				break;
			}
		}
		if (first.isEmpty()) result += "\nImpossible";
		else {
			for (int s: first) {
				if (second.contains(s)) {
					first.remove(s);
					second.remove(s);
				}
			}
			result += "\n";
			for (int s: first) {
				result += s + " ";
			}
			result += "\n";
			for (int s: second) {
				result += s + " ";
			}
		}

		return result;
	}
}
