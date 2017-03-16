//package round1a;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ManageYourEnergy {

	int[][] g;
	int R;
	int E;
	public int[] v;
	
	public ManageYourEnergy(int E, int N, int R)
	{
		this.R = R;
		this.E = E;
		v = new int[N];
		g = new int[N][E+1];
		
		for(int i =0; i<g.length; i++)
			for(int j =0; j<g[i].length; j++)
				g[i][j] = -1;
	}
	
	public int maxGain(int i, int e)
	{
		//stop
		if(i >= v.length) return 0;
		if(e < 0) return 0;
		if(e > E) e=E;
		
		if(g[i][e] > -1) return g[i][e];
		
		int max = 0;
		
		for(int j=0; j <=e; j++)
		{
			max = Math.max(max, maxGain(i+1, (e-j)+R) + v[i]*j);
		}
		
		g[i][e] = max;
		return g[i][e];
	}
	
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(new FileInputStream("/home/meha/Downloads/B-small-attempt0.in"));
        FileWriter out = new FileWriter("/home/meha/Desktop/output.out");
        int c = 1;
        for(int T = in.nextInt(); T > 0; T--, c++)
        {
        	
            int e = in.nextInt();
            int r = in.nextInt();
            int n = in.nextInt();
         
            ManageYourEnergy m = new ManageYourEnergy(e,n,r);
            
            for(int i = 0; i<n; i++)
            	m.v[i] = in.nextInt(); 
            
            String print = String.format("Case #%d: %d\n", c, m.maxGain(0, e));
            out.write(print);
            System.out.print(print);
            out.flush();
        }
	}

}
