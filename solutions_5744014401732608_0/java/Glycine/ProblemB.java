package gcj2016.c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ProblemB {
	private Map<Long, List<String>> results = new HashMap<>();
	private Map<Long, Long> patternNum = new HashMap<>();

	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File(args[0])));
		int lineNum = Integer.parseInt(reader.readLine());
		ProblemB problemB = new ProblemB();
		for (int i = 0; i < lineNum; ++i) {
			String[] tokens = reader.readLine().split(" ");
			long buildNum = Long.parseLong(tokens[0]);
			long pathNum = Long.parseLong(tokens[1]);
			List<String> result = problemB.solve(buildNum, pathNum);

			if (result != null) {
				System.out.println("Case #" + (i + 1) + ": POSSIBLE");
				for (String elem : result) {
					System.out.println(elem);
				}
			} else {
				System.out.println("Case #" + (i + 1) + ": IMPOSSIBLE");
			}
		}
		reader.close();
	}

	public ProblemB() {
		List<String> lines = new ArrayList<>();
		lines.add("01");
		lines.add("00");
		results.put(2L, lines);
		// resultsを埋めている
		for (long i = 3; i <= 50; ++i) {
			subFunc2(i);
		}
		for (long i = 2; i <= 50; ++i) {
			patternNum.put(i, (long) Math.pow((double) 2, (double) (i - 2L)));
		}
	}

	private List<String> solve(long buildNum, long pathNum) {
		if (patternNum.get(buildNum) < pathNum) {
			// Impossible
			return null;
		}

		List<Long> patternSet = getPatternSet(pathNum);
		/*
		for (Long pattern : patternSet) {
			System.out.print(pattern + " ");
		}
		System.out.println("");
		*/
		return genResult(buildNum, patternSet);
	}

	private List<String> genResult(long buildNum, List<Long> patternSet) {
		// まず雛形を作る
		char[][] result = new char[(int) buildNum][(int) buildNum];
		for (int i = 0; i < buildNum; ++i) {
			for (int j = 0; j < buildNum; ++j) {
				result[i][j] = '0';
			}
		}

		// 1パスを埋める
		for (int i = 0; i + 1 < buildNum; ++i) {
			result[i][i + 1] = '1';
		}

		// 最大のパターンのものをマージする
		List<String> maxPattern = results.get(patternSet.get(0));
		for (int i = 0; i < maxPattern.size(); ++i) {
			String str = maxPattern.get(i);
			int yIndex = (int) buildNum - str.length() + i;
			for (int j = 0; j < str.length(); ++j) {
				char c = str.charAt(j);
				int xIndex = (int) buildNum - str.length() + j;
				result[yIndex][xIndex] = c;
			}
		}

		/*
		for (int i = 0; i < result.length; ++i) {
			for (int j = 0; j < result[i].length; ++j) {
				System.out.print(result[i][j]);
			}
			System.out.println("");
		}*/

		// 他の解のものをマージする
		for (int i = 1; i < patternSet.size(); ++i) {
			int index = (int) (buildNum - patternSet.get(i).longValue());
			result[0][index] = '1';
		}

		// 解を生成する
		List<String> r = new ArrayList<>();
		for (int i = 0; i < result.length; ++i) {
			r.add(new String(result[i]));
		}
		return r;
	}

	private List<String> subFunc(long buildNum) {
		if (results.containsKey(buildNum)) {
			return results.get(buildNum);
		} else {
			for (long i = 2; i <= buildNum; ++i) {
				if (results.containsKey(i)) {
					continue;
				}
				subFunc2(i);
			}
			return results.get(buildNum);
		}
	}

	private void subFunc2(long buildNum) {
		// buildNum-1まではある前提
		List<String> result = new ArrayList<>();
		List<String> prevResult = results.get(buildNum - 1L);
		// 最初の行
		StringBuilder strBuilder = new StringBuilder();
		strBuilder.append("0");
		for (long i = 1; i < buildNum; ++i) {
			strBuilder.append("1");
		}
		result.add(strBuilder.toString());
		// 残りの行
		for (String str : prevResult) {
			result.add("0" + str);
		}
		results.put(buildNum, result);
	}

	private List<Long> getPatternSet(long pathNum) {
		List<Long> result = new ArrayList<>();
		long temp = pathNum;
		for (long i = 50L; i >= 2L; --i) {
			if (temp >= patternNum.get(i)) {
				result.add(i);
				temp = temp - patternNum.get(i);
			}
		}
		return result;
	}
}
