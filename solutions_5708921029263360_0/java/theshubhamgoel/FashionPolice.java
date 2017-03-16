import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class FashionPolice {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			int j, p, s, k;
			StringTokenizer st = new StringTokenizer(br.readLine());
			j = Integer.parseInt(st.nextToken());
			p = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());

			int count = 0;
			HashMap<String, Integer> hmap1 = new HashMap<>();
			HashMap<String, Integer> hmap2 = new HashMap<>();
			HashMap<String, Integer> hmap3 = new HashMap<>();
			for (int l1 = 1; l1 <= j; l1++) {
				for (int l2 = 1; l2 <= p; l2++) {
					for (int l3 = 1; l3 <= s; l3++) {
						// checking pair count
						
						if (hmap1.get(l1 + " " + l2) != null) {
							if (hmap1.get(l1 + " " + l2) >= k) {
								continue;
							}
						} else {
							hmap1.put(l1 + " " + l2, 0);
						}

						if (hmap2.get(l2 + " " + l3) != null) {
							if (hmap2.get(l2 + " " + l3) >= k) {
								continue;
							}
						} else {
							hmap2.put(l2 + " " + l3, 0);
						}
						
						if (hmap3.get(l1 + " " + l3) != null) {
							if (hmap3.get(l1 + " " + l3) >= k) {
								continue;
							}
						} else {
							hmap3.put(l1 + " " + l3, 0);
						}


						hmap1.put(l1 + " " + l2, hmap1.get(l1 + " " + l2) + 1);
						hmap2.put(l2 + " " + l3, hmap2.get(l2 + " " + l3) + 1);
						hmap3.put(l1 + " " + l3, hmap3.get(l1 + " " + l3) + 1);
						pw.println(l1 + " " + l2 + " " + l3);
						count++;
					}
				}
			}

			System.out.println("Case #" + (i + 1) + ": " + count);
			pw.flush();
		}
	}
}
