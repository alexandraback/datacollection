import java.io.*;
public class Password {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		BufferedReader br = new BufferedReader(new FileReader("small1.in"));
		PrintWriter pr = new PrintWriter(new FileWriter("output.txt"));
		int T = Integer.parseInt(br.readLine());
		String[] temp;
		double min;
		double[] pVals;
		
		for(int CASE = 1; CASE<=T; CASE++)
		{
			temp = br.readLine().split(" ");
			int typed = Integer.parseInt(temp[0]);
			int length = Integer.parseInt(temp[1]);
			temp = br.readLine().split(" ");
			pVals = new double[temp.length];
			
			for(int i = 0; i<temp.length; i++)
			{
				pVals[i] = Double.parseDouble(temp[i]);
			}
			
			min = length+2;
			
			for(int i = 0; i<typed; i++)
			{
				double attempt = i;
				int newTyped = typed - i;
				double pRight = 1;
				
				for(int j = 0; j<newTyped; j++)
				{
					pRight *= pVals[j];
				}
				
				attempt+= (length + 1 - newTyped)*pRight + (2+ 2*length - newTyped)*(1-pRight); //magic
				
				if(attempt <= min)
					min = attempt;
			}
			
			pr.println("Case #" + CASE + ": " + min);
		}
		
		pr.close();
		br.close();
	}

}
