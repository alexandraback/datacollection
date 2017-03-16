import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Brattleship {
	
	private static String analyzeTestCase(TestCase tc) {
		int score;
		
		if(tc.getC() == tc.getW())
			score = tc.getW() + tc.getR() - 1;
		else if(tc.getW() == 1)
			score = tc.getC() * tc.getR();
		else {
			int checks = (int)(tc.getC() / tc.getW());
			//int finSpots = tc.getC() - tc.getW() * (checks - 1);
			int finSpots = tc.getW() + 1;
			score = checks * (tc.getR() - 1) + checks - 1 + ((tc.getC() % tc.getW() == 0) ? tc.getW() : finSpots);
		}
		
		
		
		String result = Integer.toString(score);
			
		return "Case #" + Integer.toString(tc.getTestCase()) + ": " + result;
	}
	
	public static void main(String[] args) {

		int t, r, c, w;

		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();

		List<TestCase> cases = new ArrayList<TestCase>(t);
		List<String> output = new ArrayList<String>(t);

		for(int i = 0; i < t; ++i) {
			r = sc.nextInt();
			c = sc.nextInt();
			w = sc.nextInt();

			TestCase tc = new TestCase(i + 1, r, c, w);

			cases.add(tc);
		}

		for(TestCase tc: cases)
			output.add(analyzeTestCase(tc));

		for(String str: output)
			System.out.println(str);

	}

}
