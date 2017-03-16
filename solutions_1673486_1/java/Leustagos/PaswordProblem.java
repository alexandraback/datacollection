package round1.a;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

import common.ClockWatch;
import common.ISolver;
import common.QuestionHandler;

public class PaswordProblem implements ISolver {

	@Override
	public String solve(BufferedReader input, String problem) throws IOException {
		Scanner scan = new Scanner(problem);
		int typed = scan.nextInt();
		int all = scan.nextInt();
		int toType = all - typed;

		double[] pTypedWrong = new double[typed];
		Scanner scanProbs = new Scanner(input.readLine());
		for (int i=0; i<typed;++i) {
			pTypedWrong[i] = Double.parseDouble(scanProbs.next());
		}

		List<Double> allProp = new ArrayList<Double>();

		// keep typing
		double curP = 1;
		for (int i=0; i<typed;++i) {
			curP *= pTypedWrong[i];
		}
		allProp.add(curP*(toType + 1) + (1-curP)*(toType + all + 2));

		// backstrokes
		curP = 1;
		for (int i=0; i<typed;++i) {

			int backs = typed - i;
			allProp.add(curP*(2*backs + toType + 1) + (1-curP)*(2*backs + toType + all + 2));
			curP *= pTypedWrong[i];

		}

		// enter
		allProp.add((double)(all+2));

		Collections.sort(allProp);
		return String.valueOf(allProp.get(0));
	}

	@Override
	public void addCase(BufferedReader input, String problem, String answer) throws IOException {
		String myAnswer = solve(input, problem);
		if (Math.abs(Double.parseDouble(myAnswer) - Double.parseDouble(answer)) >= 1e-6) {
			throw new RuntimeException("Invalid prediction for '" + problem
					+ "'. Expected '" + answer + "' got '" + myAnswer + "'");
		}
	}













	public static void main(String[] args) throws Exception {
		ClockWatch watch = new ClockWatch();
		watch.tic();
		QuestionHandler questionHandler = new QuestionHandler(
				new PaswordProblem());
		//		questionHandler.addResource("sample.in", "sample.out");

		//		System.out.println("Sample input:");
		//		questionHandler.solve("sample.in", "sample.out");

//		System.out.println("Small input:");
//		questionHandler.solve("small.in", "small.out");

				System.out.println("Large input:");
				questionHandler.solve("large.in", "large.out");
		watch.printToc();
	}
}
