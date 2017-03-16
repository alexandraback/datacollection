package pl.mpisarek.gcj2016.round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ProblemC {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		String input = args[0];
		String output = input.replace(".in", ".out");
		StringBuffer sb = new StringBuffer();

		try (BufferedReader br = new BufferedReader(new FileReader(input))) {
			String line = br.readLine();
			int number = Integer.valueOf(line);
			int i = 1;

			while ((line = br.readLine()) != null && i <= number) {
				List<String> topics = new ArrayList<>();
				int n = Integer.valueOf(line);
				for (int k = 0; k < n; k++) {
					topics.add(br.readLine());
				}
				sb.append(process(topics, i++));
				sb.append("\n");
			}
		}

		try (BufferedWriter bw = new BufferedWriter(new FileWriter(output))) {
			bw.append(sb);
		}

		System.out.println("FInished");
	}

	private static String process(List<String> topics, int caseNum) {
		StringBuffer sb = new StringBuffer("Case #");
		sb.append(caseNum).append(": ");

		List<String> first = new ArrayList<>();
		List<String> second = new ArrayList<>();
		Map<String, Integer> fQuant = new HashMap<>();
		Map<String, Integer> sQuant = new HashMap<>();

		for (String top : topics) {
			final String[] split = top.split(" ");
			final String t1 = split[0];
			first.add(t1);
			Integer q1 = fQuant.get(t1);
			if (q1 == null)
				q1 = 0;
			fQuant.put(t1, ++q1);

			final String t2 = split[1];
			second.add(t2);
			Integer q2 = sQuant.get(t2);
			if (q2 == null)
				q2 = 0;
			sQuant.put(t2, ++q2);
		}

		int result = 0;
		for (int i = 0; i < topics.size(); i++) {
			if (fQuant.get(first.get(i)) > 1 && sQuant.get(second.get(i)) > 1) {
				// fQuant.put(first.get(i), fQuant.get(first.get(i)) - 1);
				// sQuant.put(second.get(i), sQuant.get(second.get(i)) - 1);
				result++;
			}
		}

		sb.append(result);
		return sb.toString();
	}
}
