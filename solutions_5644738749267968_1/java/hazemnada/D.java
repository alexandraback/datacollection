import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("D-large.in"));
		PrintWriter writer = new PrintWriter("Dlarge.out");
		int tCases = Integer.parseInt(buf.readLine().trim());
		for (int t = 1; t <= tCases; t++) {
			int n = Integer.parseInt(buf.readLine().trim());
			ArrayList<Double> l1 = new ArrayList<Double>();
			ArrayList<Double> l2 = new ArrayList<Double>();
			StringTokenizer str = new StringTokenizer(buf.readLine());
			for (int i = 0; i < n; i++)
				l1.add(Double.parseDouble(str.nextToken()));
			str = new StringTokenizer(buf.readLine());
			for (int i = 0; i < n; i++)
				l2.add(Double.parseDouble(str.nextToken()));
			Collections.sort(l1);
			Collections.sort(l2);

//			System.out.println(l1.toString());
//			System.out.println(l2.toString());
			ArrayList<Double> l11 = (ArrayList<Double>) l1.clone();
			ArrayList<Double> l22 = (ArrayList<Double>) l2.clone();
			Collections.sort(l11);
			Collections.sort(l22);

			int cnt1 = 0;
//			System.out.println(l1.toString());
//			System.out.println(l2.toString());
			
			while (l11.size() > 1) {
				int index = l22.size() - 1;
				if (l22.get(index) < l11.get(index)) {
					cnt1++;
					l22.remove(0);
					l11.remove(index);
				} else {
					l22.remove(index);
					l11.remove(index);
				}
			}
			if (l11.get(0) > l22.get(0))
				cnt1++;
			int cnt2 = 0;
			while (l2.size() > 1) {
				int index = l2.size()-1;
				if (l1.get(0) < l2.get(0)) {
					l1.remove(0);
					l2.remove(index);
				} else {
					cnt2++;
					l1.remove(0);
					l2.remove(0);
				}
			}
			if (l1.get(0) > l2.get(0))
				cnt2++;
			writer.printf("Case #%d: %d %d\n", t, cnt2, cnt1);
		}
		writer.close();
	}
}
