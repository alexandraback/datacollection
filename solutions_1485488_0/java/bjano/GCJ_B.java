import java.io.*;
import java.util.*;

public class GCJ_B {

	public static int timeToMove(int rfrom,int cfrom, int rto, int cto, int[][] f,int[][] c, int wh, boolean wdown) {
		if (rto < 0) return -1;
		if (cto < 0) return -1;
		if (rto >= c.length) return -1;
		if (cto >= c[0].length) return -1;
		int cnow = c[rfrom][cfrom];
		int fnext = f[rto][cto];
		if (fnext + 50 > cnow) return -1;
		if (f[rto][cto] + 50 > c[rto][cto]) return -1;
		if (f[rfrom][cfrom] + 50 > c[rto][cto]) return -1;
		if ( wh + 50 > c[rto][cto])
		{
			if (!wdown) return -1;
			int wait =  (wh - (c[rto][cto] - 50));
			wh = c[rto][cto] - 50;
			return wait + ((wh >= f[rfrom][cfrom] + 20) ?  10 : 100); 
		}
		
		return (wh >= f[rfrom][cfrom] + 20) ?  10 : 100;		
	}

	public static void afterTide(int[][] et,int[][] f,int[][] c,int wh) {
		boolean ch = true;
		while (ch)
		{
			ch = false;
			for (int i=0;i<et.length;i++)
				for (int j=0;j<et[0].length;j++)
					if (et[i][j] != -1)
					{
						int wcurr = wh - et[i][j];
						int ro[] = {-1,+1,0,0};
						int co[] = {0,0,-1,+1};
						for (int dir=0;dir<4;dir++)
						{
							int rto = ro[dir] + i;
							int cto = co[dir] + j;
							int ttm = timeToMove(i,j,rto,cto,f,c,wcurr,true);
							if (ttm > -1)
								if ((ttm + et[i][j] < et[rto][cto]) || (et[rto][cto] == -1))
								{
									ch = true;
									et[rto][cto] = et[i][j] + ttm;
								}
						}
					}
		}
	}	
	public static void beforeTide(int[][] et,int[][] f,int[][] c,int wh) {		
		for (int i=0;i<et.length;i++)
			for (int j=0;j<et[0].length;j++)
				et[i][j] = -1;
		et[0][0] = 0;
		
		
		boolean ch = true;
		while (ch)
		{
			ch = false;
			for (int i=0;i<et.length;i++)
				for (int j=0;j<et[0].length;j++)
					if (et[i][j] != -1)
				{
						int ro[] = {0,-1,+1,0};
						int co[] = {1,0,0,-1};
						for (int dir=0;dir<4;dir++)
						{
							int rto = ro[dir] + i;
							int cto = co[dir] + j;
							if (timeToMove(i,j,rto,cto,f,c,wh,false) != -1)
							{
								if (et[rto][cto] == -1) ch = true;
								et[rto][cto] = 0;
							}
						}
				}
		}
	}
	
	public static void main(String[] args) throws Exception {
		String fname = "B-small";
		Scanner scanner = new Scanner(new File(fname+".in"));
		PrintWriter writer = new PrintWriter(new FileWriter(fname+".out"));
		
		int tt = Integer.parseInt(scanner.next());
//		System.out.println(tt);
		for (int ii=1;ii<=tt;ii++)
		{
			int h = Integer.parseInt(scanner.next());
			int n = Integer.parseInt(scanner.next()); // num of lines
			int m = Integer.parseInt(scanner.next()); //        cols
			int  c[][] = new int[n][m];
			int  f[][] = new int[n][m];
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					c[i][j] = Integer.parseInt(scanner.next());
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					f[i][j] = Integer.parseInt(scanner.next());
			int et[][] = new int[n][m];
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					et[i][j] = -1;
			beforeTide(et,f,c,h);
			System.out.println(et[0][0]);
			afterTide(et,f,c,h);	
			
			writer.printf("Case #%d: %f\n",ii,(double)(et[n-1][m-1])/10.0);
		}		
		writer.close();
		scanner.close();
	}

}
