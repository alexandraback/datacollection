import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import org.apache.commons.lang3.SerializationUtils;

public class EqualsSums {

	public static void main(String[] args) throws IOException {
		FileWriter fstream = new FileWriter("Cout.txt");
		BufferedWriter outp = new BufferedWriter(fstream);
		Scanner sc = null;
		try {
			sc = new Scanner(new File("C-small-attempt1 (1).in"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			top: {
				int N = sc.nextInt();
				HashSet<Integer> os = new HashSet<Integer>();
				for (int r = 0; r < N; r++) {
					os.add(sc.nextInt());
				}
				HashMap<Integer, HashSet<Integer>> totals = new HashMap<Integer, HashSet<Integer>>();
				HashMap<Integer, HashSet<Integer>> totalsadd = new HashMap<Integer, HashSet<Integer>>();
				totals.put(0, new HashSet());
				System.out.println("Case #" + t+":");
				for (Integer i : os) {
					for (Integer to : totals.keySet()) {
						HashSet cl = (HashSet) SerializationUtils.clone(totals
								.get(to));
						cl.add(i);
						if (totals.containsKey(to + i)) {
							String s=Arrays.toString(totals.get(
									to + i).toArray());
							System.out.println(s.substring(1,s.length()-1).replaceAll(",", ""));
							s=Arrays.toString(cl.toArray());
							System.out.println(s.substring(1,s.length()-1).replaceAll(",",""));
							break top;
						}
						if (totalsadd.containsKey(to + i)) {
							String s=Arrays.toString(totalsadd.get(
									to + i).toArray());
							System.out.println(s.substring(1,s.length()-1).replaceAll(",",""));
							s=Arrays.toString(cl.toArray());
							System.out.println(s.substring(1,s.length()-1).replaceAll(",",""));
							break top;
						}
						totalsadd.put(to + i, cl);
					}
					totals.putAll(totalsadd);
				}
				System.out.println("Impossible");
			}
		}

		outp.flush();
		fstream.close();
	}

}
