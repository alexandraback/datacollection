import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Formatter;
import java.util.Scanner;

import javax.swing.text.NumberFormatter;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(new File("input.txt"));
		FileWriter writer=new FileWriter("output.txt",false);
		PrintWriter output=new PrintWriter(writer);
		int t=input.nextInt();

		for(int o=1;o<=t;o++)
		{		
			int n=input.nextInt();
			int [] points=new int[n];
			int sumofponts=0;
			for(int i=0;i<n;i++)
			{
				points[i]=input.nextInt();
				sumofponts+=points[i];
			}
			int totalscore=2*sumofponts;
			double minmumscore=(double)totalscore/(double)n;
			String result="";
			for(int i=0;i<n;i++)
			{
				double minmumaudiencescore=minmumscore-points[i];
				if(minmumaudiencescore<0)
				{
					result+="0.000000 ";
					continue;
				}
				DecimalFormat dec=new DecimalFormat("##.######");
				dec.setRoundingMode(RoundingMode.FLOOR);
		//		dec.setMaximumFractionDigits(6);
				double minimumaudince=minmumaudiencescore*100/(double)sumofponts;
				String nuu=dec.format(minimumaudince);
				boolean f=true;
				for(int j=0;j<nuu.length();j++)
					if(nuu.charAt(j)=='.')
					{
						f=false;
						break;
					}
				if(f)
				{
					nuu+=".000000";
				}
				result+=nuu+" ";
				
			}
			result=result.substring(0, result.length()-1);
			output.printf("Case #%d: %s\n",o,result);

		}
		output.close();


	}

}
