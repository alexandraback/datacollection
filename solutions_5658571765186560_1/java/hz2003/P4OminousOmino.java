package QualificationRound;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class P4OminousOmino {
	public static int[] dx = {1, 0, -1, 0};
	public static int[] dy = {0, 1, 0, -1};
	public static double r2(double x0, double y0, double x, double y){ return Math.pow(x - x0, 8) + Math.pow(y - y0, 8);}
	public static double moment(int[][] a)
	{
		double x0 = 0;
		double y0 = 0;
		for(int[] p:a)
		{
			x0 += p[0];
			y0 += p[1];
		}
		x0 = x0 / (a.length + 0.0);
		y0 = y0 / (a.length + 0.0);
		double sum = 0;
		for(int[] p:a)
			sum += r2(x0, y0, p[0],p[1]);
		return sum;
	}
	public static boolean outside(int[][] t, int x, int y)
	{
		for(int i = 0; i < t.length; i++)
			if(t[i][0] == x && t[i][1] == y)
				return false;
		return true;
	}
	public static void extend(int[][] t, ArrayList<int[][]> result)
	{	
		for(int i = 0; i < t.length; i++)
		{
			int x = t[i][0];
			int y = t[i][1];
			for(int j = 0; j < dx.length; j++)
				if(outside(t, x + dx[j], y + dy[j]))
				{
					int[][] temp= Arrays.copyOf(t, t.length + 1);
					temp[t.length] =new int[]{x + dx[j], y + dy[j]};
					result.add(temp);
				}
		}
	}
	public static final double delta = 0.000001;
	private static int trackIndex = 0;
	private static boolean diff(double m, ArrayList<Double> mo)
	{
		for(int i = 0; i < mo.size(); i++)
		{
			double d = mo.get(i);
			if(Math.abs(m - d) < delta)
			{
				trackIndex = i;
				return false;
			}
		}
		
//		for(double d: mo)
//			if(Math.abs(m - d) < delta)
//				return false;
		return true;
	}
	public static ArrayList<int[][]> dereplicate(ArrayList<int[][]> r)
	{
		ArrayList<int[][]> result = new ArrayList<int[][]>();
		ArrayList<Double> mo = new ArrayList<Double>();
		for(int[][] t: r)
		{
			double m = moment(t);
			if(diff(m, mo))
			{
				result.add(t);
				mo.add(m);
			} else
			{
				System.out.println(graph(t));
				System.out.println(graph(result.get(trackIndex)));
				System.out.println(m);
				System.out.println("---------------------------------");
			}
		}
		return result;
	}
	public static ArrayList<int[][]> create(int X)
	{
		ArrayList<int[][]> result = new ArrayList<int[][]>();
		if (X == 1)
		{
			int[][] temp = {{0, 0}};
			result.add(temp);
			return result;
		}
		ArrayList<int[][]> temp = create(X - 1);
		for(int[][] t:temp)
			extend(t, result);
		
		return dereplicate(result);
	}
	public static boolean win(int x, int r, int c)
	{
		if(x >= 7)
			return false;
		if((r * c) % x != 0)
			return false;
		if( x < 3)
			return true;
		if(x == 3)
			return  !(r == 1 || c == 1);
		if(x == 4)
			return (r >= 3) && (c >= 3);
		if(x == 5)
			return (r >= 4) && (c >= 4);
		if(x == 6)
			return (r >= 4) && (c >= 4);
		
		return false;
	}
	public static String graph(int[][] t)
	{
		int minX = 0, minY = 0;
		for(int[] p:t)
			{ minX = Math.min(minX, p[0]); minY = Math.min(minY, p[1]); }
		int n = t.length;
		String result = "";
		for(int y = 0; y < n; y++)
		{
			for(int x = 0; x < n; x++)
				result += outside(t, x + minX, y + minY)? " ": "*";
			result += "\n";
		}
					
		return result;
	}
	public static void main(String[] args) {
		ArrayList<int[][]> r = create(6);
		for(int[][] t: r)
		{
			for(int[] z:t)
				System.out.print("(" + z[0] + ", " + z[1] + ")" + "\t");
			System.out.print("\n" + moment(t) + "\n");
			System.out.println(graph(t));	
		}
		System.out.println(r.size());


		for(int i = 1; i < 5; i++)
			for(int j = 1; j < 5; j++)
				for(int k = 1; k < 5; k++)
					System.out.println("" + i + " " + j + " " + k + 
							" Winner is:" + (win(i,j,k)? "GABRIEL":"RICHARD") );

		
		try{
			File fin = new File("src/QualificationRound/D-large.in");
			Scanner scan = new Scanner(fin);
			PrintWriter output = new PrintWriter("src/QualificationRound/D-large.out.txt");
			int N = scan.nextInt();
			for(int i = 0; i < N; i++)
			{
				boolean t = win(scan.nextInt(), scan.nextInt(), scan.nextInt());
				output.println("Case #" + (i + 1) + ": " + (t?"GABRIEL":"RICHARD"));
			}
			scan.close();
			output.close();
		}catch (Exception e)
		{
		}
	}
}
