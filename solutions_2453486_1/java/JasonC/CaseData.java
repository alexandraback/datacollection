package google;

public class CaseData {

	public String[][] line1;
	
	public CaseData()
	{
		line1 = new String[4][4];
		
	}
	public void pushdata(int nub,String temp)
	{
		
		line1[nub/4][nub%4] = temp;
	
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
