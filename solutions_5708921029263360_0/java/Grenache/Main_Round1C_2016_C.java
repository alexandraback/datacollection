import java.util.*;


public class Main_Round1C_2016_C {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		for (int casei = 1; casei <= t; casei++) {
			int j = sc.nextInt();
			int p = sc.nextInt();
			int s = sc.nextInt();
			int k = sc.nextInt();

			Map<String, Integer> hm = new HashMap<>();
			List<String> ret = new ArrayList<>();
			for (int i1 = 1; i1 <= j; i1++) {
				for (int i2 = 1; i2 <= p; i2++) {
					for (int i3 = 1; i3 <= s; i3++) {
						String s1 = i1 + ":" + i2 + ":" + 0;
						String s2 = i1 + ":" + 0 + ":" + i3;
						String s3 = 0 + ":" + i2 + ":" + i3;

						if ((!hm.containsKey(s1) || hm.get(s1) < k)
								&& (!hm.containsKey(s2) || hm.get(s2) < k)
							&& (!hm.containsKey(s3) || hm.get(s3) < k)) {
							if (!hm.containsKey(s1)) {
								hm.put(s1, 1);
							} else {
								hm.put(s1, hm.get(s1) + 1);
							}
							if (!hm.containsKey(s2)) {
								hm.put(s2, 1);
							} else {
								hm.put(s2, hm.get(s2) + 1);
							}
							if (!hm.containsKey(s3)) {
								hm.put(s3, 1);
							} else {
								hm.put(s3, hm.get(s3) + 1);
							}

							ret.add(i1 + " " + i2 + " " + i3);
						} else {
							continue;
						}
					}
				}
			}

			System.out.printf("Case #%d: %d\n", casei, ret.size());
			for (int i = 0; i < ret.size(); i++) {
				System.out.println(ret.get(i));
			}
		}

		sc.close();
	}
}
