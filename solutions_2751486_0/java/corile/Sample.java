import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;


public class Sample {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br=null;
		try {
			br = new BufferedReader(new FileReader("A-small-attempt0.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//FileWriter fstream = new FileWriter("out.txt");
		//BufferedWriter out = new BufferedWriter(fstream);
		
		int casenum = 0;

		casenum = Integer.parseInt(br.readLine());

		for(int j = 0; j < casenum; j++)
		{
			String[] s = null;

			s = br.readLine().split(" ");
			String name = s[0];
			int n = Integer.parseInt(s[1]);
			
			int nvalue = 0;
			int oneCount = 0;
			int distanceFromBunch = 0;
			boolean bunchExists=false;
			int total=0;
			for(int i=0;i<name.length();i++)
			{
				total++;
				distanceFromBunch++;
				char cur = name.charAt(i);
				if(!isVowel(cur))
					oneCount++;
				else
					oneCount=0;
				if(oneCount>=n)
				{
					bunchExists=true;
					distanceFromBunch=0;
				}
				
				
				if(bunchExists)
				{
					nvalue += (total-distanceFromBunch-n+1);
				}
			}
			System.out.println("Case #"+(j+1)+": "+nvalue);

		}
		br.close();


	}
	
	private static boolean isVowel(char ch)
	{
		return ((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'));
	}

}
