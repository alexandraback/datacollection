public class JudgeScores{
	int jc1;
	int jc2;
	int jc3;
	private boolean isSurprising = false;
	
	public JudgeScores(int jc1, int jc2, int jc3) {
		this.jc1 = jc1;
		this.jc2 = jc2;
		this.jc3 = jc3;
	}
	public JudgeScores(int jc1, int jc2, int jc3, boolean isSurprising) {
		this.jc1 = jc1;
		this.jc2 = jc2;
		this.jc3 = jc3;
		this.isSurprising = isSurprising;
	}
	
	public int getJC1(){
		return jc1;
	}
	
	public int getJC2(){
		return jc2;
	}
	
	public int getJC3(){
		return jc3;
	}
	
	public void isSurprising(boolean isSurprising){
		this.isSurprising  = isSurprising;
	}
	
	public boolean isSurprising(){
		return this.isSurprising;
	}
	
	public int getMaxScore(){
		return Math.max(Math.max(jc1, jc2), jc3);
	}
	
	public int getMinScore(){
		return Math.min(Math.min(jc1, jc2), jc3);
	}
}