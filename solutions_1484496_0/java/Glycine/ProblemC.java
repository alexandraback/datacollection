package glycine.gcj2012.rb;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class ProblemC {

	private static class NumSet {
		public Long sum = new Long(0);
		public List<Long> numSet = new ArrayList<Long>();

		public NumSet(Long sum, List<Long> numSet) {
			this.sum = sum;
			this.numSet.addAll(numSet);
		}

		public NumSet() {

		}

		public void add(Long v) {
			this.sum += v;
			this.numSet.add(v);
		}
	}

	private static NumSet subFunc(Map<Long, NumSet> numSetSet, Long newNum) {
		Map<Long, NumSet> newNumSetSet = new HashMap<Long, NumSet>();
		Set<Long> keySet = numSetSet.keySet();
		for (Long key : keySet) {
			NumSet elem = numSetSet.get(key);
			NumSet newElem = new NumSet(elem.sum, elem.numSet);
			newElem.add(newNum);
			if (keySet.contains(newElem.sum)) {
				return newElem;
			}
			newNumSetSet.put(newElem.sum, newElem);
		}
		NumSet numSet = new NumSet();
		numSet.add(newNum);
		if (keySet.contains(numSet.sum))
			return numSet;
		numSetSet.putAll(newNumSetSet);
		return null;
	}

	private static List<NumSet> solve(List<Long> numList) {
		Map<Long, NumSet> numSetSet = new HashMap<Long, NumSet>();
		List<NumSet> result = new ArrayList<NumSet>();

		Long minNum = numList.get(0);
		NumSet initVal = new NumSet();
		initVal.add(minNum);
		numSetSet.put(minNum, initVal);

		for (int i = 1; i < numList.size(); ++i) {
			NumSet numSet = subFunc(numSetSet, numList.get(i));
			if (numSet != null) {
				result.add(numSet);
				result.add(numSetSet.get(numSet.sum));
				break;
			}
		}
		if (result.size() == 0) {
			return null;
		} else {
			return result;
		}
	}

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);
		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			String[] tokens = line.split(" ");
			int num = Integer.parseInt(tokens[0]);
			List<Long> numList = new ArrayList<Long>(num);
			for (int j = 0; j < num; ++j) {
				numList.add(new Long(tokens[j + 1]));
			}
			Collections.sort(numList);
			List<NumSet> result = solve(numList);
			if (result != null) {
				System.out.println("Case #" + (i + 1) + ":");
				NumSet first = result.get(0);
				for (int j = 0; j < first.numSet.size() - 1; ++j) {
					System.out.print(first.numSet.get(j) + " ");
				}
				System.out.println(first.numSet.get(first.numSet.size() - 1));
				NumSet second = result.get(1);
				for (int j = 0; j < second.numSet.size() - 1; ++j) {
					System.out.print(second.numSet.get(j) + " ");
				}
				System.out.println(second.numSet.get(second.numSet.size() - 1));
			} else {
				System.out.println("Case #" + (i + 1) + ":");
				System.out.println("Impossible");
			}
		}
	}
}
