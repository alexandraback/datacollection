import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;


public class CookieClickerAlpha {

	/**
	 * @param args
	 */
	public static final double r = 2.0;
	
	public static void main(String[] args) {
		//Open The file
				BufferedReader br=null;
				try {
					br = new BufferedReader(new FileReader("B-large.in"));
					//br = new BufferedReader(new InputStreamReader(System.in));
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				//FileWriter fstream = new FileWriter("out.txt");
				//BufferedWriter out = new BufferedWriter(fstream);
				
				//Get the test case number
				int casenum = readLineAsInt(br);
				
				//Process each case
				for(int j = 1; j <= casenum; j++)
				{
					//Read the selected row
					String[] s = new String[3];
					try {
						s = br.readLine().split(" ");
					} catch (IOException e) {
						e.printStackTrace();
					}
					
					//Parse the selected row into numbers
					Double c = Double.parseDouble(s[0]);
					Double f = Double.parseDouble(s[1]);
					Double x = Double.parseDouble(s[2]);
					
					int numberOfBuys = (int)(x/c-r/f);
					
					Double minTime = 0.0;
					Double denominator = r;
					for(int i=0;i<numberOfBuys;i++)
					{
						minTime+=c/denominator;
						denominator+=f;
					}
					minTime+=x/denominator;
					System.out.printf("Case #%d: %.7f\n",j,minTime);
										
					//System.out.println("Case #"+(j+1)+": "+getProbability(numDiamonds, x, y));
				}
				try {
					br.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
	}
	
	@SuppressWarnings("finally")
	public static int readLineAsInt(BufferedReader br)
	{
		int val = 0;
		try {
			val = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			return val;
		}
	}
	
	public static void printStringArray(String[] s)
	{
		for(String str:s)
		{
			System.out.print(str+", ");
		}
		System.out.println("");
	}

	
}
