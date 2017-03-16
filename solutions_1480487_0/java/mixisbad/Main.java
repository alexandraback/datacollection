import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.nio.charset.Charset;
import java.text.DecimalFormat;
import java.util.LinkedList;
import java.util.List;

public class Main {

	/**
	 * @param args
	 */

	public static void main(String[] args) {
		try {

			FileInputStream fIn = new FileInputStream("input.txt");

			Charset cs = Charset.forName("UTF-8");
			InputStreamReader iRd = new InputStreamReader(fIn, cs);
			BufferedReader bRd = new BufferedReader(iRd);

			String str = bRd.readLine();

			Integer tCase = Integer.parseInt(str);

			Writer output = null;
			File file = new File("output.txt");
			output = new BufferedWriter(new FileWriter(file));

			for (int i = 0; i < tCase; ++i) {
				String inLine = bRd.readLine();
				String[] nums = inLine.split(" ");

				String show = nums[0];
				//String all = nums[1];

				Integer showNum = Integer.parseInt(show);
				Integer scores[] = new Integer[showNum];
				float sum = 0;
				
				for (int j = 0; j < showNum; ++j) {
					scores[j] = Integer.parseInt(nums[j+1]);
					sum += scores[j];
				}
				//Integer allNum = Integer.parseInt(all);
				//Integer penalty = allNum + 1;

				
				
				output.write("Case #"+(i+1) + ":");
				
				DecimalFormat df = new DecimalFormat();
				df.setMinimumFractionDigits(1);
				df.setMaximumFractionDigits(6);
				
				float point,fraction,average,total,average2,smallLeft,totalLeft;
				int high = 0 , low;
				
				total = sum*2;
				smallLeft = 0;
				average = (total/showNum.floatValue());
				
				System.out.println("average : " + average);
				
				for (int j = 0; j < showNum; ++j) {
					
					if(scores[j] > average)
						{
						total -= scores[j];
						++high;
						}
					else
					{
						smallLeft += scores[j];
					}
					
				}
				
				low = showNum - high;
				
				average2 = total/low;
				
				totalLeft =  total - smallLeft;
				
				System.out.println("average2 : " + average2);
				System.out.println("total : " + total);
				System.out.println("totalLeft : " + totalLeft);
				
				for (int j = 0; j < showNum; ++j) {
					if(scores[j] > average)
					{
						fraction = 0.0f;
					}
					else
					{
						fraction = average2 - scores[j];
						fraction = (fraction*100)/totalLeft;
					}
					
					output.write(" " + df.format(fraction));
				}
				
				output.write("\n");
				
				
				//output.write("Case #"+(i+1) + ": "+df.format(leastValue) + "\n");

			}

			output.close();
			
			

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
