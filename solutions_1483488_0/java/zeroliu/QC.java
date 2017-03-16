import static java.util.Arrays.deepToString;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class QC {

	public static void main(String[] args) throws Exception 
	{
		new QC().run();
		
	}

	int calculateDigit(int num)
	{
		int res = 0;
		
		while(num>0)
		{
			res++;
			num = num/10;
		}
		
		return res;
	}
	
	void run() throws Exception 
	{
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		
		Scanner sc = new Scanner(new FileReader("C-small-attempt1.in"));
		
		FileWriter fstream = new FileWriter("out.in");
		BufferedWriter out = new BufferedWriter(fstream);

		int ntest = Integer.valueOf(sc.nextLine());
		
		
		
		for(int test=1;test<=ntest;++test) 
		{
			int min = sc.nextInt();
			int max = sc.nextInt();
			int score = 0;

			for(int i=min; i<=max; i++)
			{
				int digit = calculateDigit(i);
				List<Integer> list = new ArrayList<Integer>();
				for(int j=1; j<digit; j++)
				{
					
					int head = (int) (i/(Math.pow(10, j)));
					int tail = (int) (i%(Math.pow(10, j)));
					
					int mix = (int) (tail*Math.pow(10,(digit-j)) + head);
					//debug(i+ " " +head+" "+tail);
					if(list.indexOf(mix) == -1 && mix <= max && mix > i && calculateDigit(mix) == calculateDigit(i))
					{
						//debug(i + " " +mix);
						list.add(mix);
						score++;
					}
				}
				
			}
		
			out.write("Case #" + test + ": ");
			out.write(score+"");
			debug(score);
			out.write("\n");
		}
		out.close();
		sc.close();
	
	}
	
	void debug(Object...os) 
	{
		System.err.println(deepToString(os));
	} 
	
	void debugArray(Object[]...os) 
	{
		System.err.println(deepToString(os));
	} 
}
