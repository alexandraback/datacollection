import java.util.Vector;


public class TestCaseB {

	public int googlers;
	public int surprises;
	public int minscore;
	public Vector<Integer> scores;
	
	public TestCaseB(int g, int s, int m, Vector<Integer> sc) {
		googlers = g;
		surprises = s;
		minscore = m;
		scores = sc;
		System.out.println("tc: " + g + " " + s + " " + m + " " + scores);
	}
	
}
