package question;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import utils.FileTools;

class IntPair {
	IntPair(String[] str) {
		v1 = Integer.parseInt(str[0]);
		v2 = Integer.parseInt(str[1]);
	}

	int v1;
	int v2;
}

class Comp implements Comparator {

	public int compare(Object o1, Object o2) {
		IntPair i1 = ((IntPair) o1);
		IntPair i2 = ((IntPair) o2);
		if (i1.v1 < i2.v1) {
			return -1;
		} else if (i1.v1 > i2.v1) {
			return 1;
		} else {
			if (i1.v2 < i2.v2) {
				return -1;
			} else if (i1.v2 == i2.v2) {
				return 0;
			} else
				return 1;
		}
	}
}

public class Qualification3 {
	public static void main(String[] args) {
		try {
			FileTools ft = new FileTools("B-small-attempt1.in");
			int T = Integer.parseInt(ft.in.readLine());
			String line;
			int l = 0;
			String[] str;
			IntPair ip;
			int target;
			while ((line = ft.in.readLine()) != null) {
				List<IntPair> list = new ArrayList<IntPair>();
				ft.out.write("Case #" + (++l) + ": ");
				int num = Integer.parseInt(line);
				for (int i = 0; i < num; i++) {
					line = ft.in.readLine();
					ip = new IntPair(line.split(" "));
					list.add(ip);
				}
				Collections.sort(list, new Comp());
				int star = 0;
				int times = 0;
				boolean done;
				boolean succ;

				while (true) {
					done = true;
					succ = false;
					target = -1;
					int max = -1;
					// 对比v2
					for (int i = 0; i < list.size(); i++) {
						ip = list.get(i);
						if (ip.v1 > star) {
							break;
						}
						if (ip.v2 <= star && ip.v2 != -1) {
							if (ip.v1 == -1) {
								++star;
								ip.v2 = -1;
							} else {
								ip.v1 = -1;
								ip.v2 = -1;
								star += 2;
							}
							++times;
							succ = true;
							break;
						}
					}
					if (succ)
						continue;
					for (int i = 0; i < list.size(); i++) {
						ip = list.get(i);
						if (done && ip.v2 > -1) {
							done = false;
						}
						if (ip.v1 == -1)
							continue;
						if (ip.v1 > star) {
							break;
						}
						if (ip.v2 > max) {
							target = i;
							max = ip.v2;
						}
					}
					if (target != -1) {
						list.get(target).v1 = -1;
						++star;
						++times;
					} else
						break;
				}
				String res = Integer.valueOf(times).toString();
				if (!done) {
					res = "Too Bad";
				}
				ft.out.write(res);
				System.out.println("Case #" + l + ": " + res);
				ft.out.newLine();
			}
			ft.out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
