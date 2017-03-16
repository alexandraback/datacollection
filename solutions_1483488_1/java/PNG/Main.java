import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

	private static final int[][] cache;
	private static final int A = 0, B = 2000000;

	static {
		try {
			File f = new File("cache");
			if (f.exists()) {
				cache = (int[][]) new ObjectInputStream(new FileInputStream(f)).readObject();
			} else {
				cache = new int[B+1][];
				for (int j = 12; j < B; j++) {
					int permutation = String.valueOf(j).length();
					HashMap<Integer, Boolean> hit = new HashMap<Integer, Boolean>();
					for (int z = 1; z < permutation; z++) {
						int div = (int) Math.pow(10, z);
						if (j % div >= div / 10) {
							int newnum = j / div + j % div * (int) Math.pow(10, permutation - z);
							if (newnum >= A && newnum <= B && newnum > j) {
								if (hit.get(newnum) == null) {
									hit.put(newnum, true);
								}
							}
						}
					}
					ArrayList<Integer> l = new ArrayList<Integer>(hit.keySet());
					Collections.sort(l);
					int[] vals = new int[l.size()];
					for (int i = 0; i < l.size(); i++) {
						vals[i] = l.get(i);
					}
					cache[j] = vals;
				}

				new ObjectOutputStream(new FileOutputStream(f)).writeObject(cache);
			}
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input"));
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		for (int i = 0; i < cases; i++) {
			s.nextLine();
			int a = s.nextInt();
			if (a < 12) {
				a = 12;
			}
			int b = s.nextInt();

			int answer = 0;

			for (int j = a; j < b; j++) {
				int[] vals = cache[j];
				for (int val : vals) {
					if (val < 0) {
						continue;
					}
					if (val > b) {
						break;
					}
					answer++;
				}
			}

			w.write("Case #");
			w.write(String.valueOf(i + 1));
			w.write(": ");

			w.write(String.valueOf(answer));

			w.write("\n");
		}
		w.close();
	}

}
