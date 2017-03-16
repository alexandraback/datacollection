import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RecycledNumbers {

	public static void main(String[] args) throws IOException {
		String msg = "";
		BufferedReader br = null;
		String sCurrentLine = null;
		Map<String, String> map = new HashMap<String, String>();
		br = new BufferedReader(new FileReader("test"));
		sCurrentLine = br.readLine();
		int x = 0;
		if (sCurrentLine != null) {
			while ((sCurrentLine = br.readLine()) != null) {
				int sum = 0;
				msg = "";
				x++;
				int a = Integer.parseInt(sCurrentLine.split(" ")[0]);
				int b = Integer.parseInt(sCurrentLine.split(" ")[1]);
				for (int n = a; n < b; n++) {
					// for (int m = n + 1; m <= b; m++) {
					sum += fetchUniquePairs(n, a, b);
					// }
				}
				msg += "Case #" + x + ": " + sum;
				System.out.println(msg);
			}
		}

	}

	private static int fetchUniquePairs(int n, int a, int b) {
		List<Integer> uniquePairs = new ArrayList<Integer>();
		int dupN = n;
		int i = 0;
		while (dupN > 0) {
			dupN = dupN / 10;
			i++;
		}
		dupN = n;
		for (int j = 0; j < i - 1; j++) {
			int mod = dupN % 10;
			int add = mod * (int) Math.pow(10, i - 1);
			dupN = (dupN / 10);
			dupN += add;
			if (dupN <= b && dupN > n)
				if (!uniquePairs.contains(dupN))
					uniquePairs.add(dupN);
		}
		return uniquePairs.size();
	}
}
