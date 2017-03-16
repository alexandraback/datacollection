import java.util.Scanner;

public class C {
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		for (int Q = 1; Q <= T; Q++)
		{
			int N = scan.nextInt();
			
			long[] D = new long[N];
			long[] H = new long[N];
			long[] M = new long[N];
			
			for (int i = 0; i < N; i++)
			{
				D[i] = scan.nextInt();
				H[i] = scan.nextInt();
				M[i] = scan.nextInt();
			}
			
			// smallest input -- at most 2 hikers
			
			int encounters;
			
			if (N == 1 && H[0] == 1)
			{
				// just one hiker -- easy
				
				encounters = 0;
			}
			else 
			{
				long m0, m1, d0, d1;
				
				if (N == 2 && H[0] == 1 && H[1] == 1)
				{
					m0 = M[0];
					m1 = M[1];
					d0 = D[0];
					d1 = D[1];
				}
				else if (N == 1 && H[0] == 2)
				{
					m0 = M[0];
					m1 = M[0] + 1;
					d0 = D[0];
					d1 = D[0];
				}
				else	
				{
					System.err.printf("UNEXPECTED CASE\n");
					return;
				}
				
				if (m0 == m1)
				{
					// two hikers, same speed
					
					encounters = 0;
				}
				else
				{
					// at most 2 encounters -- might be able to do better
					// follow the slowest one and see how many times the fastest laps you
					
					// put slowest at index 0
					
					if (m0 < m1)
					{
						long m = m1;
						m1 = m0;
						m0 = m;
						
						long d = d1;
						d1 = d0;
						d0 = d;
					}
					
					// the fastest is allowed to lap the slowest once before we start counting
					d1 -= 360;
					
					// this is beautiful but don't ask me what it means
					
					long firstMeetingPlace = (m0 - m1) * d0 + (d0 - d1) * m1;
					
					if (firstMeetingPlace <= 360 * (m0 - m1))
					{
						// find the second place
//						D[1] -= 360;
//						
//						int secondMeetingPlace = (M[0] - M[1]) * D[0] + (D[0] - D[1]) * M[1];
//						
//						if (secondMeetingPlace <= 360)
//						{
//							encounters = 2;
//						}
//						else							
//						{
//							encounters = 1;
//						}
						
						encounters = 1;
					}
					else
					{
						encounters = 0;
					}
				}
			}
			
			System.out.printf("Case #%d: %d\n", Q, encounters);
		}
		
		scan.close();
	}
}
