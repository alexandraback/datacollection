package round1.b;

import java.io.BufferedReader;
import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;

import common.ClockWatch;
import common.ISolver;
import common.QuestionHandler;

public class KingdomRush implements ISolver {

	class Data {
		int one;
		int two;
		int level;
		int stars = 2;
	}
	
	@Override
	public String solve(BufferedReader input, String problem) throws Exception {
		Scanner scan = new Scanner(problem);
		
		Set<Data> all = new LinkedHashSet<KingdomRush.Data>();
		int steps = 0;
		int stars = 0;
		
		int levels = scan.nextInt();
		
		for (int i=0; i<levels;++i) {
			Scanner caseScan = new Scanner(input.readLine());
			Data data = new Data();
			data.level = i;
			data.one = caseScan.nextInt();
			data.two = caseScan.nextInt();
			all.add(data);
		}
		
		while (!all.isEmpty()) {
			Data best = find2Star(stars, all);
			if (best != null) {
				++steps;
				stars += best.stars;
				all.remove(best);
				continue;
			}
			best = find1Star(stars, all);
			if (best != null) {
				++steps;
				stars += 1;
				--best.stars;
				continue;
			}
			return "Too Bad";
		}
		
		return String.valueOf(steps);
	}

	private Data find1Star(int stars, Set<Data> all) {
		Data sel = null;
		for (Data d : all) {
			if (d.stars == 2) {
				if (d.one <= stars) {
					if (sel == null || d.two > sel.two) {
						sel = d;
					}
				}
			}
		}
		return sel;
	}

	private Data find2Star(int stars, Set<Data> all) {
		for (Data d : all) {
			if (d.two <= stars) {
				return d;
			}
		}
		return null;
	}

	@Override
	public void addCase(BufferedReader input, String problem, String answer) throws Exception {
		String myAnswer = solve(input, problem);
		if (!myAnswer.equals(answer)) {
			throw new RuntimeException("Invalid prediction for '" + problem
					+ "'. Expected '" + answer + "' got '" + myAnswer + "'");
		}
	}

	public static void main(String[] args) throws Exception {
		ClockWatch watch = new ClockWatch();
		QuestionHandler questionHandler = new QuestionHandler(
				new KingdomRush());
//		questionHandler.addResource("sample.in", "sample.out");

//		watch.tic();
//		 System.out.println("Sample input:");
//		 questionHandler.solve("sample.in", "sample.out");

//		System.out.println("Small input:");
//		questionHandler.solve("small.in", "small.out");

		System.out.println("Large input:");
		questionHandler.solve("large.in", "large.out");
		watch.printToc();
	}
}
