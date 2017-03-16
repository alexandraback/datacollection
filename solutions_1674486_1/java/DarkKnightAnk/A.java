/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Google Code Jam <year>
 * <Round>
 * <Name>
 * @author DarkKnightAnk
 */

import java.io.*;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

//public class OMG extends Object;


public class A {

	public static void main(String[] args) {
		try
		{
			FileWriter fout = new FileWriter("out");
			BufferedWriter out = new BufferedWriter(fout);
			try
			{
				Scanner in = new Scanner(new File("in"));
				int T = in.nextInt();
				for(int i=1; i<=T; ++i)
				{
					int N = in.nextInt();
					Integer mat[][] = new Integer [N][N];
					for(int j=0; j<N; ++j)
						for(int k=0; k<N; ++k)
							mat[j][k] = 0;
					for(int j=0; j<N; ++j)
					{
						int X = in.nextInt();
						int temp =0;
						for(int k=0; k<X; ++k)
						{
							temp = in.nextInt();
							mat[j][temp-1] = 1;							
						}
					}
					//for(int j=0; j<N; ++j)
					//{
				//		for(int k=0;k<N; ++k)
			//				System.out.print(mat[j][k] + " ");
		//				System.out.println();
	//				} 
					
					//Run BFS;
					Queue<Integer> store = new LinkedList<Integer>();
					boolean visit[] = new boolean [N];
					boolean extra[] = new boolean [N];
					for(int j=0; j<N; ++j)
					{
						visit[j] = false;
						extra[j] = false;
					}
					store.clear();
					store.add(0);
					visit[0] = true;
					boolean set = true;
					boolean ans = false;
					main:while(set)
					{
						while(!store.isEmpty())
						{
							Integer curr = (Integer) store.remove();
							for(int j=curr; j<N; ++j)
							{
								if(j==curr)
									continue;
								if(mat[curr][j] == 1)
								{
									//System.out.println("Checking from " + curr + " " + j);
									
									store.add(j);
									if(visit[j])
									{
										ans = true;
										break main;
									}
									visit[j] = true;
								}
							}
							//System.out.println(store.size());
						}
						//for(int j=0; j<N; ++j)
						//	System.out.print(visit[j] + " ");
						//System.out.println();
						set = false;
						for(int j=0; j<N; ++j)
							if(visit[j])
								extra[j] = true;
						for(int j=0; j<N; ++j)
							visit[j] = false;
						for(int j=0; j<N; ++j)
							if(!extra[j])
							{
								store.add(j);
								visit[j] = true;
								set = true;
								break;
							}
					}
					if(ans)
					{
						out.write("Case #" + i + ": Yes");
					}
					else
					{
						out.write("Case #" + i + ": No");
					}
					
					out.newLine();
				}
				out.close();
			}catch(FileNotFoundException e)
			{
			System.out.println("ERROR: File Not Found!");
			}
		}catch(IOException x)
		{
			System.out.println("ERROR: Can't create output file");
		}
    }
}
