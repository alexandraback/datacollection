import static java.util.Arrays.deepToString;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class QB {

	public static void main(String[] args) throws Exception 
	{
		new QB().run();
		
	}

	void run() throws Exception 
	{
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		
		Scanner sc = new Scanner(new FileReader("B-small-attempt1.in"));
		
		FileWriter fstream = new FileWriter("out.in");
		BufferedWriter out = new BufferedWriter(fstream);
		
		
		//PrintWriter pw = new PrintWriter(new FileWriter("Asmall.out"));
		
		int ntest = Integer.valueOf(sc.nextLine());
		
		for(int test=1;test<=ntest;++test) 
		{
			int playerNum = sc.nextInt();
			int surpNum = sc.nextInt();
			int min = sc.nextInt();
			//debug(playerNum);
			int score = 0;
			int criteria = min*3 - 4;
			
			for(int i=0; i<playerNum; i++)
			{
				int current = sc.nextInt();
				if(current >= min)
				{
					if(current >= criteria + 2)
					{
						score ++;
					} else if(current >= criteria)
					{
						if(surpNum > 0)
						{
							surpNum --;
							score++;
						}
					}
				}
				
			}
			
			//debug(score);
			out.write("Case #" + test + ": ");
			out.write(score + "");
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
