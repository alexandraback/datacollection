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
		
		Scanner sc = new Scanner(new FileReader("B-small-attempt2.in"));
		//Scanner sc = new Scanner(new FileReader("input.in"));
		FileWriter fstream = new FileWriter("out.in");
		BufferedWriter out = new BufferedWriter(fstream);

		int ntest = Integer.valueOf(sc.nextLine());
		
		int[][] levelInfo;
		boolean[][] levelFinish;
		int[] levelScore;
		
		for(int test=1;test<=ntest;++test) 
		{
			int levelNum = sc.nextInt();
			levelInfo = new int[levelNum][];
			levelFinish = new boolean[levelNum][];
			levelScore = new int[levelNum];
			for(int i=0; i<levelNum; i++)
			{
				levelInfo[i] = new int[2];
				levelInfo[i][0] = sc.nextInt();
				levelInfo[i][1] = sc.nextInt();
				
				levelFinish[i] = new boolean[2];
				levelFinish[i][0] = false;
				levelFinish[i][1] = false;
				
				levelScore[i] = 0;
			}
			//debug(levelInfo);
			
			int res = calculate(levelInfo, levelFinish, levelScore);
			debug(res);
			String finalRes = "";
			if(res == -1)
			{
				finalRes = "Too Bad";
			} else
			{
				finalRes = res + "";
			}
			out.write("Case #" + test + ": ");
			out.write(finalRes);
			out.write("\n");
		}
		out.close();
		sc.close();
	
	}
	
	int calculate(int[][] info, boolean[][] finish, int[] score)
	{
		int res = -1;
		boolean possible = true;
		boolean[][] myfinish = finish;
		int[] myscore = score;
		int star = 0;
		int round = 0;
		while(possible && !checkScore(myscore))
		{
			
			int[] pos = new int[2];
			pos[0] = -1;
			pos[1] = -1;
			int starGet = 0;
			boolean innerpossible = false;
			for(int i=0; i<myscore.length; i++)
			{
				for(int j=1; j>=0; j--)
				{
					//this level is playable
					if(!myfinish[i][j] && myscore[i] < 2)
					{
						//star is enough
						if(star >= info[i][j])
						{
							if(j + 1 - myscore[i] > starGet 
									|| 
									(j + 1 - myscore[i] == starGet 
									&& innerpossible
									&& ((myscore[i] > myscore[pos[0]])
									|| (myscore[i] <= myscore[pos[0]]) && (info[i][1] - info[i][0] > info[pos[0]][1] - info[pos[0]][0])
									)
								)				
							)
							{
								starGet = j + 1 - myscore[i];
								pos[0] = i;
								pos[1] = j;
								innerpossible = true;
							}
						}
					}
				}
			}
			
			if(innerpossible)
			{
				//debug(pos[0] + "," + pos[1]);
				myfinish[pos[0]][pos[1]] = true;
				if(starGet == 2)
				{
					myfinish[pos[0]][0] = true;
				}
				star += starGet;
				
				myscore[pos[0]] = myscore[pos[0]] + starGet;
			} else
			{
				possible = false;
			}
			round ++;
		}
		
		if(!possible)
		{
			res = -1;
		} else
		{
			res = round;
		}
		
		return res;
	}
	
	boolean checkScore(int[] score)
	{
		boolean res = true;
		for(int i=0; i<score.length; i++)
		{
			if(score[i] < 2)
			{
				res = false;
				break;
			}
		}
		
		return res;
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
