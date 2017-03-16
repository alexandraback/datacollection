import java.io.*;
import java.util.*;

class A
{
	public static void main(String[] args) 
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
			int T = Integer.parseInt(br.readLine());

			for(int i=0; i<T; i++)
			{
				int N = Integer.parseInt(br.readLine());
				ArrayList<ArrayList<Integer>> A = new ArrayList<ArrayList<Integer>>();

				for(int j=0; j<N; j++) {
					String[] line = br.readLine().split(" ");
					ArrayList<Integer> SA = new ArrayList<Integer>();
					int M = Integer.parseInt(line[0]);
					for(int k=1; k<=M; k++)
						SA.add(Integer.parseInt(line[k]) - 1);
					A.add(SA);
				}

				boolean res = false;
				for(int j=0; j<N && !res; j++) {
					Queue<Integer> Q = new PriorityQueue<Integer>();
					Q.offer(j);

					boolean[] V = new boolean[N];
					while(Q.size() > 0 && !res) {
						int x = Q.poll();
						ArrayList<Integer> SA = A.get(x);
						for(int k=0; k<SA.size(); k++) {
							int y = SA.get(k);
							if(V[y]) {
								res = true;
								break;
							} else {
								V[y] = true;
								Q.offer(y);
							}
						}
					}
				}

				pw.printf("Case #%d: %s\n", i+1, (res?"Yes":"No"));
				pw.flush();
			}
		}
		catch(Exception e)
		{ 
			e.printStackTrace();
		}
	}
}
