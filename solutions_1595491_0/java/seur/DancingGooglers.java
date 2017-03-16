
public class DancingGooglers {
	static String test = "4\n3 1 5 15 13 11\n3 0 8 23 22 21\n2 1 1 8 0\n6 2 8 29 20 8 18 18 21";
	static String val = "100\n3 1 5 15 13 11\n3 0 8 23 22 21\n2 0 8 21 24\n3 0 6 15 15 14\n3 0 0 17 8 1\n2 1 9 20 26\n3 0 1 18 18 23\n3 0 9 5 23 24\n2 2 7 28 11\n3 0 5 13 5 30\n1 0 1 0\n3 0 8 7 17 21\n1 0 7 2\n1 1 4 7\n2 0 5 27 3\n3 0 9 24 5 23\n1 1 1 15\n1 0 10 27\n1 0 3 30\n2 2 6 28 12\n2 0 8 21 28\n3 1 8 30 3 5\n1 0 10 30\n3 3 6 5 13 22\n3 0 0 30 30 30\n1 0 8 20\n2 0 3 20 16\n3 1 2 3 9 2\n1 0 10 26\n3 0 6 14 8 14\n3 2 1 2 13 18\n1 1 2 22\n2 1 6 20 24\n3 1 10 26 0 27\n2 0 5 12 11\n3 3 5 22 17 12\n1 0 0 15\n2 0 6 23 14\n3 2 2 22 7 15\n3 2 1 24 0 11\n3 0 1 28 14 25\n2 2 6 15 20\n1 0 2 3\n2 0 8 21 20\n3 0 5 0 12 0\n3 0 5 25 25 7\n3 0 9 27 22 3\n2 1 4 11 15\n1 0 9 1\n2 1 9 8 27\n3 3 4 4 17 15\n2 0 1 3 18\n2 1 10 25 30\n1 0 1 13\n3 3 0 20 26 5\n3 2 10 4 9 18\n1 0 10 30\n3 1 4 9 9 9\n3 1 9 24 23 23\n3 2 10 9 12 4\n1 0 4 24\n2 1 10 30 23\n3 0 2 6 22 1\n2 0 10 21 2\n1 0 3 5\n1 1 0 26\n3 1 3 5 9 5\n3 0 4 8 8 9\n2 0 6 6 15\n2 2 2 15 9\n2 0 3 21 5\n2 1 7 27 28\n3 0 8 9 3 21\n3 1 3 6 5 30\n2 2 0 24 2\n2 0 10 2 15\n3 2 2 7 1 15\n1 0 4 8\n1 0 10 17\n1 0 10 23\n1 0 4 5\n1 0 8 12\n2 0 2 2 2\n3 0 4 8 6 4\n1 1 4 28\n2 2 1 9 10\n1 1 6 8\n1 1 2 21\n1 0 6 14\n3 1 10 30 28 4\n3 1 6 15 15 14\n2 0 7 10 17\n3 2 2 3 3 3\n2 0 7 17 17\n3 1 6 14 24 14\n2 2 0 18 26\n3 0 0 0 0 0\n3 0 3 5 5 0\n1 0 6 14\n2 1 6 14 14\n";
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String[][] cases = CaseReader.getCases(val, 1);
		for (int i = 0;i < cases.length;i++)
		{
			parseCase(i + 1, cases[i][0]);
		}
	}
	
	static void parseCase(int caseNum, String caseString) {
		String[] args = caseString.split(" ");
		int googleCount = Integer.parseInt(args[0]);
		int surprises = Integer.parseInt(args[1]);
		int lowest = Integer.parseInt(args[2]);
		int[] googleScores = new int[googleCount];
		for (int i = 0;i < googleCount;i++)
		{
			googleScores[i] = Integer.parseInt(args[i + 3]);
		}
		int countAbove = getCasesWhereAbove(lowest, surprises, googleScores);
		System.out.println("Case #" + caseNum + ": " + countAbove);
	}
	
	static int getCasesWhereAbove(int minimum, int surpriseCount, int[] scores) {
		int count = 0, currentSurprises = 0;
		for (int i = 0;i < scores.length;i++) {
			if ((scores[i] + 2) / 3 >= minimum) { // This one naturally works, so it's fine.
				count++;
			} else if (scores[i] >= minimum && (scores[i] + 4) / 3 >= minimum && currentSurprises < surpriseCount) {
				count++;
				currentSurprises++;
			}
		}
		return count;
	}

}
