package Round1A;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
	static Scanner scan;
	static PrintWriter writer;

	public static void main(String[] args) {
		File file = new File("D://C-small-attempt1.in");
		File out = new File("D://outC.txt");
		try {
			scan = new Scanner(file);
			writer = new PrintWriter(out);
			int T = scan.nextInt();
			for (int t = 1; t <= T; t++) {
				writer.print("Case #" + t + ": ");
				int n = scan.nextInt();
				int[] A = new int[11];
				for(int i=1; i<=n; i++) {
					int b = scan.nextInt();
					A[i] = b;
				}
				int max = 0;
				for(int i=1; i<=n;i++) {
					List<Integer> list = new ArrayList<>();
					list.add(i);
					while(true)
					{
						int last = list.get(list.size() -1);
						int bl = A[last];
						if(!list.contains(bl)) {
							list.add(bl);
						} else {
							int index = list.indexOf(bl);
							if(index == 0) {
								int size = list.size();
								if(size > max) {
									max = size;
								}
								break;
							} else if (index == list.size() -2) {
								int size = list.size();
								List<Integer> l = getBestFriendOf(last, list, A, n);
								if(l.size() > 0) {
									size += 1;
								}
								if(size > max) {
									max = size;
								}
								break;
							} else {
								int size = list.size() - index;
								if(size > max) {
									max = size;
								}
								break;
							}
						}
					}
				}
				writer.println(max);
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			scan.close();
			writer.close();
		}
	}
	
	public static List<Integer> getBestFriendOf(int b, List<Integer> mark, int[] A, int n) {
		List<Integer> ret = new ArrayList<Integer>();
		for(int i=1; i<=n; i++) {
			if(!mark.contains(i) && A[i] == b) {
				ret.add(i);
			}
		}
		return ret;
	}
}
