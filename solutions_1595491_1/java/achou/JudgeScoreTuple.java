
public class JudgeScoreTuple {

	
	private JudgeScores j1;
	private JudgeScores j2;

	public JudgeScoreTuple(JudgeScores j1, JudgeScores j2) {
		this.j1 = j1;
		this.j2 = j2;
	}
	
	public JudgeScores getSurprise(){
		if(this.j1.isSurprising())
			return j1;
		else
			return j2;
	}
	
	public JudgeScores getNonSurprise(){
		if(this.j1.isSurprising())
			return j2;
		else
			return j1;
	}
}
