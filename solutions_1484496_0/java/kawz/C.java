package gcj2012.round1B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * 2012 Code Jam Round 1B
 * 
 * @author kawabon
 * 
 */
public class C {
	public static void main(String[] args) throws Exception {
		C main = args.length > 0 ? new C(args[0]) : new C(C.class.getSimpleName() + ".in");
		main.solve();
	}

	String[] array;

	private final BufferedReader in;

	public C(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			List<Integer> ints = getIntegers();
			int n = ints.remove(0);
			Collections.sort(ints);
			String ans = solveOne(n, ints);
			System.out.println("Case #" + c + ":" + ans);
		}
	}

	private String solveOne(int n, List<Integer> ints) {
		array = new String[20 * 100000];
		double max = Math.pow(2, 20);
		String answer = "\nImpossible";
		for (int i = 1; i < max; i++) {
			int location = 0;
			StringBuilder set = new StringBuilder();
			int position = i;
			int offset = 0;

			while (position > 0) {
				if (position % 2 == 1) {
					location += ints.get(offset);
					set.append(" ");
					set.append(ints.get(offset));
				}
				offset++;
				position = position / 2;
			}
			if (array[location] != null) {
				answer = "\n" + array[location].substring(1) + "\n" + set.toString().substring(1);
				break;
			} else {
				array[location] = set.toString();
			}

		}

		return answer;
	}

	/*
	 * File processing
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
	}

	private List<Integer> getIntegers() throws Exception {
		List<Integer> list = new ArrayList<Integer>();
		for (String s : getStrs()) {
			list.add(Integer.valueOf(s));
		}
		return list;
	}

	private List<String> getStrs() throws Exception {
		return Arrays.asList(in.readLine().split(" "));
	}

}
