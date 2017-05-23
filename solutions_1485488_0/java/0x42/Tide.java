import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.PriorityQueue;


public class Tide {

	public static class State implements Comparable<State>
	{
		public int xpos;
		public int ypos;
		public double value;
		
		public State(int xpos, int ypos, double value)
		{
			this.xpos = xpos;
			this.ypos = ypos;
			this.value = value;
		}
		
		@Override
		public int compareTo(State other) {
			
			if (this.value > other.value) return 1;
			if (this.value < other.value) return -1;
			
			/* else */ return 0;
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		Tide object = new Tide();
			object.solve(object.getClass().getSimpleName().toLowerCase());
		}
		
		private void solve(String filePrefix) throws Exception {
			
			StreamTokenizer st = new StreamTokenizer(new BufferedReader(new FileReader("/home/useruser/datacollection/input/1485488_0.in")));
			PrintWriter pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
			
			st.nextToken();
			int testsCount = (int) st.nval;
			
			int dx[] = new int[]{1, -1, 0, 0};
			int dy[] = new int[]{0, 0, 1, -1};
			
			for (int tc=0; tc<testsCount; tc++)
			{
				st.nextToken();
				int h = (int) st.nval;
				
				st.nextToken();
				int n = (int) st.nval;
				
				st.nextToken();
				int m = (int) st.nval;
				
				int floor[][] = new int[n][m];
				int ceiling[][] = new int[n][m];
				
				for (int i=0; i<n; i++)
					for (int j=0; j<m; j++)
					{
						st.nextToken();
						ceiling[i][j] = (int) st.nval;
					}
				
				for (int i=0; i<n; i++)
					for (int j=0; j<m; j++)
					{
						st.nextToken();
						floor[i][j] = (int) st.nval;
					}
				
				double dist[][] = new double[n][m];
				
				for (int i=0; i<n; i++)
					Arrays.fill(dist[i], 1e100);
				
				dist[0][0] = 0.0;
				
				PriorityQueue<State> pq = new PriorityQueue<State>();
				pq.add(new State(0, 0, 0.0));
				
				while (pq.size() > 0)
				{
					State current = pq.poll();
					int xpos = current.xpos;
					int ypos = current.ypos;
					double cvalue = current.value;
					
					if (cvalue <= dist[xpos][ypos] + 1e-5)
					{
						//move to adjacent square?
						for (int zzz=0; zzz<dx.length; zzz++)
						{
							int nx = xpos + dx[zzz];
							int ny = ypos + dy[zzz];
							
							if (nx < 0 || nx >= n)
								continue;
							
							if (ny < 0 || ny >= m)
								continue;
							
							if (floor[nx][ny] + 50 > ceiling[xpos][ypos])
								continue;
							
							if (floor[xpos][ypos] + 50 > ceiling[nx][ny])
								continue;
							
							if (floor[nx][ny] + 50 > ceiling[nx][ny])
								continue;
							
							double currentWaterLevel = h - 10*cvalue;
							double nextTime = cvalue;
							
							if (currentWaterLevel+50 > ceiling[nx][ny])
							{
								nextTime = (h-ceiling[nx][ny]+50)/10.0;
								currentWaterLevel = h - 10*nextTime;
							}
							
							double moveValue = 1.0;
							
							if (currentWaterLevel - floor[xpos][ypos] < 20.0)
								moveValue = 10.0;
							
							if (nextTime < 1e-9)
								moveValue = 0.0;
							
							if (dist[nx][ny] > nextTime + moveValue)
							{
								dist[nx][ny] = nextTime + moveValue;
								pq.add(new State(nx, ny, nextTime + moveValue));
							}														
						}
					}							
				}
				
				DecimalFormat formatter = new DecimalFormat("0.000000000000");				
				pw.write("Case #" + (tc+1) + ": " + formatter.format(dist[n-1][m-1]) + "\n");
			}
			
			pw.flush();
			pw.close();
			
		}
}
