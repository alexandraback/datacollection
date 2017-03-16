import java.io.*;
import java.util.*;
import java.text.*;

class P3
{
	public static void main (String [] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-small-attempt0.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int numCases = Integer.parseInt(st.nextToken());
		
		for (int caseIndex = 0; caseIndex < numCases; caseIndex++)
		{
			out.print("Case #" + (caseIndex+1) + ": ");
			
			st = new StringTokenizer(in.readLine());
			
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			//System.out.println(N + " " + M);
			
			long[] a = new long[N];
			int[] A = new int[N];
			
			long[] b = new long[M];
			int[] B = new int[M];
			
			st = new StringTokenizer(in.readLine());
			
			for (int i = 0; i < N; i++)
			{
				a[i] = Long.parseLong(st.nextToken());
				A[i] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(in.readLine());
			
			for (int i = 0; i < M; i++)
			{
				b[i] = Long.parseLong(st.nextToken());
				B[i] = Integer.parseInt(st.nextToken());
			}			
			
			//System.out.println(Arrays.toString(A));
			//System.out.println(Arrays.toString(B));
			
			long max = 0;
			
			// Choose 1 Ai
			for (int i = 0; i < N; i++)
			{
				long remain = a[i];
				long curSum = 0;
				
				if (a[i] > max)
				{
					for (int j = 0; j < M; j++)
					{
						if (B[j] == A[i])
						{
							if (b[j] >= remain)
							{
								curSum += remain;
								remain = 0;
								break;
							}
							else
							{
								remain -= b[j];
								curSum += b[j];
							}
						}
					}
					
					if (curSum > max)
						max = curSum;
					
				}
			}
			
			// Choose 2 Ai's
			if (N >= 2)
			{	
				for (int i = 0; i < N; i++)
				{
					for (int j = i+1; j < N; j++)
					{
					
						if (A[i] != A[j])
						{
							for (int k = 0; k < M; k++)
							{
							long curSum = 0;
							long remain = a[i];
							
							// For Ai
							for (int l = 0; l < k; l++)
							{
								if (B[l] == A[i])
								{
									if (b[l] >= remain)
									{
										curSum += remain;
										remain = 0;
										break;
									}
									else
									{
										remain -= b[l];
										curSum += b[l];
									}
								}
							}
							
								// For Aj
								remain = a[j];
								for (int l = k; l < M; l++)
								{
									if (B[l] == A[j])
									{
										if (b[l] >= remain)
										{
											curSum += remain;
											remain = 0;
											break;
										}
										else
										{
											remain -= b[l];
											curSum += b[l];
										}
									}
								}

								if (curSum > max)
									max = curSum;
								
								//System.out.println(i + " " + j + " Stop at " + k + " with " + curSum);
							}
						}
						else
						{
							long remain = a[i] + a[j];
							long curSum = 0;
							
							for (int k = 0; k < M; k++)
							{
								if (B[k] == A[i])
								{
									if (b[k] >= remain)
									{
										curSum += remain;
										remain = 0;
										break;
									}
									else
									{
										remain -= b[k];
										curSum += b[k];
									}
								}
							}
							
							if (curSum > max)
								max = curSum;
						}
					}
				}
			}
			
			if (N == 3)
			{
				for (int i = 0; i < M; i++)
				{
					for (int j = i+1; j < M; j++)
					{
						long curSum = 0;
						long remain = a[0];
						
						// For A0
						for (int k = 0; k < i; k++)
						{
							if (B[k] == A[0])
							{
								if (b[k] >= remain)
								{
									curSum += remain;
									remain = 0;
									break;
								}
								else
								{
									remain -= b[k];
									curSum += b[k];
								}
							}
						}
						
						// For A1
						remain = a[1];
						for (int k = i; k < j; k++)
						{
							if (B[k] == A[1])
							{
								if (b[k] >= remain)
								{
									curSum += remain;
									remain = 0;
									break;
								}
								else
								{
									remain -= b[k];
									curSum += b[k];
								}
							}
						}
						
						// For A2
						remain = a[2];
						for (int k = j; k < M; k++)
						{
							if (B[k] == A[2])
							{
								if (b[k] >= remain)
								{
									curSum += remain;
									remain = 0;
									break;
								}
								else
								{
									remain -= b[k];
									curSum += b[k];
								}
							}
						}
						
						if (curSum > max)
							max = curSum;
						
					}
				}
			}
			
			out.print(max);
			
			out.println();
		}
		
		out.close();
		
	}
}