import java.util.ArrayList;


public class TestCase {
	private int scoreCount;
	private int suprisingCount;
	private int pScore;
	private ArrayList<Triplet> triplets;
	
	public TestCase(String s) {
		String[] result = s.split(" ");
		scoreCount = Integer.parseInt(result[0]); // N
		suprisingCount = Integer.parseInt(result[1]); // S
		pScore = Integer.parseInt(result[2]); // P
		triplets = new ArrayList<Triplet>(scoreCount);
		for (int i = 0; i < scoreCount; i ++) {
			triplets.add(new Triplet(Integer.parseInt(result[i+3])));
		}
	}

	public int getScoreCount() {
		return scoreCount;
	}

	public int getSuprisingCount() {
		return suprisingCount;
	}

	public int getpScore() {
		return pScore;
	}

	public ArrayList<Triplet> getTriplets() {
		return triplets;
	}
	
}
