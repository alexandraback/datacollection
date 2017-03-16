import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.InputStream;
import java.util.Scanner;

public class Problem1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception
	{
		FileInputStream is = new FileInputStream("in.txt");
		Scanner sc = new Scanner(is);
		
		FileWriter fw = new FileWriter("out.txt");
		
		int testCasesNumber = sc.nextInt();
		for(int i=0;i<testCasesNumber;i++)
		{
			fw.write("Case #"+(i+1)+": "+(new TestCase()).solve(sc)+"\n");
			System.out.println(i);
		}
		fw.close();
	}
	
	static class TestCase
	{
		double r;
		double t;
				
		public String solve(Scanner sc)
		{
			r = sc.nextDouble();
			t = sc.nextDouble();
			
			double max = Math.sqrt(t);
			double min = 1;
			double k = Math.floor((max+min)/2);
			while(true)
			{
				double x = (2*r+2*k-1)*k;
				if(x<=t)
				{
					x = (2*r+2*k+1)*(k+1);
					if(x>t)
					{
						return Math.round(k)+"";
					}
					else
					{
						min = k;
					}
				}
				else
				{
					max = k;
				}
				if(max-min==1)
				{
					return Math.round(k+1)+""; 
				}
				k = Math.floor((max+min)/2);
			}
		}
	}

}
