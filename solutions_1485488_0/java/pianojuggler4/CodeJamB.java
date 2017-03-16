import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class CodeJamB
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int cases = in.nextInt();
		for(int casenum = 1;casenum <= cases;casenum++)
		{
			int H = in.nextInt();
			int N = in.nextInt();
			int M = in.nextInt();

			int ceil[][] = new int[N][M];
			int floor[][] = new int[N][M];

			double time[][] = new double[N][M];

			for(int n = 0;n < N;n++)
			{
				for(int m = 0;m < M;m++)
				{
					ceil[n][m] = in.nextInt();
					time[n][m] = Double.MAX_VALUE;
				}
			}

			for(int n = 0;n < N;n++)
			{
				for(int m = 0;m < M;m++)
				{
					floor[n][m] = in.nextInt();
				}
			}

			time[0][0] = 0.0;

			for(int n = 0;n < N;n++)
			{
				for(int m = 0;m < M;m++)
				{
					if(ceil[n][m] - floor[n][m] < 50)
					{
						time[n][m] = -1;
						continue;
					}
					// North
					if(n > 0)
					{
						if(floor[n - 1][m] + 50 < ceil[n][m] && floor[n][m] + 50 < ceil[n - 1][m])
						{
							double water = H - 10 * time[n - 1][m];

							if(water + 50 <= ceil[n][m])
							{
								if(time[n-1][m] == 0.0)
									time[n][m] = 0;
								double movetime = 1;
								if(water - floor[n - 1][m] < 20)
									movetime = 10;
								
								if(time[n - 1][m] + movetime < time[n][m])
									time[n][m] = time[n - 1][m] + movetime;
							}
							else
							{
								double t = ((water+50)-ceil[n][m])/10.0;
								double movetime = 1;
								if(water - 10*t - floor[n - 1][m] < 20)
									movetime = 10;
								
								if(time[n - 1][m] + t + movetime < time[n][m])
									time[n][m] = time[n - 1][m] + t + movetime;
							}
						}
					}
					// West
					if(m > 0)
					{
						if(floor[n][m-1] + 50 < ceil[n][m] && floor[n][m] + 50 < ceil[n][m-1])
						{	
							double water = H - 10 * time[n][m-1];

							if(water + 50 <= ceil[n][m])
							{
								if(time[n][m-1] == 0.0)
									time[n][m] = 0;
								double movetime = 1;
								if(water - floor[n][m-1] < 20)
									movetime = 10;
								
								if(time[n][m-1] + movetime < time[n][m])
									time[n][m] = time[n][m-1] + movetime;
							}
							else
							{
								double t = ((water+50)-ceil[n][m])/10.0;
								double movetime = 1;
								if(water - 10*t - floor[n][m-1] < 20)
									movetime = 10;
								
								if(time[n][m-1] + t + movetime < time[n][m])
									time[n][m] = time[n][m-1]+ t + movetime;
							}
						}
					}
				}
			}
			
			boolean change = true;
			
			while(change)
			{
				change = false;
				for(int n = 0;n < N;n++)
				{
					for(int m = 0;m < M;m++)
					{
						if(ceil[n][m] - floor[n][m] < 50)
						{
							time[n][m] = -1;
							continue;
						}
						// North
						if(n > 0)
						{
							if(floor[n - 1][m] + 50 < ceil[n][m] && floor[n][m] + 50 < ceil[n - 1][m])
							{
								double water = H - 10 * time[n - 1][m];

								if(water + 50 <= ceil[n][m])
								{
									if(time[n-1][m] == 0.0)
										time[n][m] = 0;
									double movetime = 1;
									if(water - floor[n - 1][m] < 20)
										movetime = 10;
									
									if(time[n - 1][m] + movetime < time[n][m])
									{
										time[n][m] = time[n - 1][m] + movetime;
										change = true;
									}
								}
								else
								{
									double t = ((water+50)-ceil[n][m])/10.0;
									double movetime = 1;
									if(water - 10*t - floor[n - 1][m] < 20)
										movetime = 10;
									
									if(time[n - 1][m] + t + movetime < time[n][m])
									{
										time[n][m] = time[n - 1][m] + t + movetime;
										change = true;
									}
								}
							}
						}
						// West
						if(m > 0)
						{
							if(floor[n][m-1] + 50 < ceil[n][m] && floor[n][m] + 50 < ceil[n][m-1])
							{	
								double water = H - 10 * time[n][m-1];

								if(water + 50 <= ceil[n][m])
								{
									if(time[n][m-1] == 0.0)
										time[n][m] = 0;
									double movetime = 1;
									if(water - floor[n][m-1] < 20)
										movetime = 10;
									
									if(time[n][m-1] + movetime < time[n][m])
									{
										time[n][m] = time[n][m-1] + movetime;
										change = true;
									}
								}
								else
								{
									double t = ((water+50)-ceil[n][m])/10.0;
									double movetime = 1;
									if(water - 10*t - floor[n][m-1] < 20)
										movetime = 10;
									
									if(time[n][m-1] + t + movetime < time[n][m])
									{
										time[n][m] = time[n][m-1]+ t + movetime;
										change = true;
									}
								}
							}
						}
						// South
						if(n < N-1)
						{
							if(floor[n + 1][m] + 50 < ceil[n][m] && floor[n][m] + 50 < ceil[n + 1][m])
							{
								double water = H - 10 * time[n + 1][m];

								if(water + 50 <= ceil[n][m])
								{
									if(time[n+1][m] == 0.0)
										time[n][m] = 0;
									double movetime = 1;
									if(water - floor[n + 1][m] < 20)
										movetime = 10;
									
									if(time[n + 1][m] + movetime < time[n][m])
									{
										time[n][m] = time[n + 1][m] + movetime;
										change = true;
									}
								}
								else
								{
									double t = ((water+50)-ceil[n][m])/10.0;
									double movetime = 1;
									if(water - 10*t - floor[n + 1][m] < 20)
										movetime = 10;
									
									if(time[n + 1][m] + t + movetime < time[n][m])
									{
										time[n][m] = time[n + 1][m] + t + movetime;
										change = true;
									}
								}
							}
						}
						// East
						if(m < M-1)
						{
							if(floor[n][m+1] + 50 < ceil[n][m] && floor[n][m] + 50 < ceil[n][m+1])
							{	
								double water = H - 10 * time[n][m+1];

								if(water + 50 <= ceil[n][m])
								{
									if(time[n][m+1] == 0.0)
										time[n][m] = 0;
									double movetime = 1;
									if(water - floor[n][m+1] < 20)
										movetime = 10;
									
									if(time[n][m+1] + movetime < time[n][m])
									{
										time[n][m] = time[n][m+1] + movetime;
										change = true;
									}
								}
								else
								{
									double t = ((water+50)-ceil[n][m])/10.0;
									double movetime = 1;
									if(water - 10*t - floor[n][m+1] < 20)
										movetime = 10;
									
									if(time[n][m+1] + t + movetime < time[n][m])
									{
										time[n][m] = time[n][m+1]+ t + movetime;
										change = true;
									}
								}
							}
						}
					}
				}
			}
			
//			for(int n = 0;n < N;n++)
//			{
//				for(int m = 0;m < M;m++)
//				{
//					System.out.print(time[n][m]+"\t");
//				}
//				System.out.println();
//			}
//			System.out.println();System.out.println();
			out.write("Case #" + casenum + ": " + time[N - 1][M - 1] + "\n");
		}
		in.close();
		out.close();
	}
}