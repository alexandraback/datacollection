import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.naming.ldap.HasControls;


public class Algorithm 
{
	private static int[] solution= new int[1000];
	private static int targetX;
	private static int targetY;
	
	private static final int WEST=1;
	private static final int NORTH=2;
	private static final int EAST=3;
	private static final int SOUTH=4;
	
	public static String solve(int x, int y)
	{
		solution= new int[1000];
		
		targetX=x;
		targetY=y;
		
		int currentDepth = 1;
		
		while (!canSolve(0, 0, 1, currentDepth)) currentDepth++;
		
		return generateSolutionString();
	}
	
	private static boolean canSolve(int x, int y, int jumpSize, int maxDepth)
	{
		if (x==targetX && y==targetY) return true;
		if (jumpSize>maxDepth) return false;
		
		int distance = abs(x-targetX)+abs(y-targetY);
		int jumpdistance = 0;
		for (int i=jumpSize;i<=maxDepth;i++) jumpdistance+=i;
		if (distance>jumpdistance) return false;
		
		solution[jumpSize]=WEST;
		if (canSolve(x-jumpSize, y, jumpSize+1, maxDepth)) return true;
		solution[jumpSize]=0;
		
		solution[jumpSize]=EAST;
		if (canSolve(x+jumpSize, y, jumpSize+1, maxDepth)) return true;
		solution[jumpSize]=0;
		
		solution[jumpSize]=NORTH;
		if (canSolve(x, y+jumpSize, jumpSize+1, maxDepth)) return true;
		solution[jumpSize]=0;
		
		solution[jumpSize]=SOUTH;
		if (canSolve(x, y-jumpSize, jumpSize+1, maxDepth)) return true;
		solution[jumpSize]=0;
		
		return false;
	}
	
	private static int abs(int n)
	{
		if (n<0) return -n;
		return n;
	}
	
	private static String generateSolutionString()
	{
		String s = "";
		int i=1;
		while (solution[i]!=0)
		{
			if (solution[i]==NORTH) s+="N";
			if (solution[i]==EAST) s+="E";
			if (solution[i]==SOUTH) s+="S";
			if (solution[i]==WEST) s+="W";
			i++;
		}
		return s;
	}
	
	
	
	
	public static void main(String[] args)
	{
		
		try 
		{
			File f = new File("D:\\Users\\m.schadd\\Desktop\\Google\\Pogo.txt");
					
			Scanner s = new Scanner(f);
			int testCases = Integer.parseInt(s.nextLine());
			
			//System.out.println("Found "+testCases+" testcases");
			PrintWriter printer = new PrintWriter("out.txt");
			
			for (int i=0;i<testCases;i++)
			{
				String l = s.nextLine();
				String[] tok = l.split(" ");
				int x = Integer.parseInt(tok[0]);
				int y = Integer.parseInt(tok[1]);
				
				
				String solution = solve(x,y);
				System.out.println("Case #"+(i+1)+": "+solution);
				printer.write("Case #"+(i+1)+": "+solution+"\n");
				
			}
			
			printer.close();
			
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		} 
		
	}


}
