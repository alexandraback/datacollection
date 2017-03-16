import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;

public class Mote {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"/Users/narok119/Desktop/A-large.in")));
		int caseCount = 1;
		String txt = reader.readLine();
		while ((txt = reader.readLine()) != null) {
			int eater = Integer.parseInt(txt.split(" ")[0]);
			int n = Integer.parseInt(txt.split(" " + "")[1]);
			ArrayList<Integer> list = new ArrayList<Integer>(n);
			ArrayList<Integer> giveUp = new ArrayList<Integer>();
			int result = 0;
			String[] others = reader.readLine().split(" ");
			for (int i = 0; i < n; i++) {
				list.add(Integer.parseInt(others[i]));
			}
			Collections.sort(list);
			int count = 0;
			for (int i : list) {
				if (eater > i) {
					eater += i;
				} else {
					if (count == list.size() - 1) {
						result++;
						break;
					} else if (eater == 1) {
						result++;
						continue;
					}
					giveUp.add(result + list.size() - count);
					while (eater <= i) {
						eater += (eater - 1);
						result++;
					}
					eater += i;
				}
				count++;
			}

			if (!giveUp.isEmpty()) {
				Collections.sort(giveUp);
				result = giveUp.get(0) < result ? giveUp.get(0) : result;
			}
			System.out.println("Case #" + caseCount++ + ": " + result);
		}
	}

}
