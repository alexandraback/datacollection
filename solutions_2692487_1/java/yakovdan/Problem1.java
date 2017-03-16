
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;


public class Problem1 {

	
	
	public static int minUntilEdible(int armin, int mote)
	{
		int count=0;
		if (mote==1)
			return 500;
		if (armin==1)
			return 500;
			
		
		while (armin <= mote)
		{
			armin += armin-1;
			count++;
		}
		return count;
	}
	
	
	public static int newArmin(int count,int armin)
	{
		int i=0;
		while (i<count)
		{
			armin+=armin-1;
			i++;
		}
		return armin;
	}
	
	public static boolean Solvable(int [] motes, int armin,int k)
	{
		int size=armin;
		int i=k;
		if (i >=motes.length)
			return false;
		
		while (i < motes.length)
		{
			if (size <= motes[i])
				return false;
			size+=motes[i];
			i++;
		}
		return true;
		
	}
	
	public static int solve(int [] motes,int armin, int k)
	{
		int count=0;
		int i=k;
		int len = motes.length;
		if (Solvable(motes, armin, k))
			return 0;
		while (i < len)
		{
			if (armin > motes[i])
			{
				armin+=motes[i];
				i++;
			}
			else
			{
				int edible = minUntilEdible(armin, motes[i]);
				int armin2=newArmin(edible, armin);
				int count2 = solve(motes,armin2+motes[i],i+1);
				int count3=0;
				if (i == len-1)
					count3=1;
				else
					count3 = solve(motes,armin,i+1)+1;
				if (count2+edible <= count3)
					return count2+edible;
				else
					return count3;
				
					
			}
		}
		
		
		return count;
	}
	
	public static String Solver(int armin, int len, int [] motes)
	{
		Arrays.sort(motes);
		int count=0;
		int i=0;
		if (Solvable(motes, armin,0))
			return " 0";
		count = solve(motes, armin, 0);
		
		
		return " "+count;
	}
	
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		
		boolean outputToFile = true;
	
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter bw=null;
		if (outputToFile)
			bw = new BufferedWriter(new FileWriter("out20.txt"));
		
		int cases = Integer.parseInt(br.readLine());
		
		
		int casenum=-1;
		
		
		for (int j=0;j < cases;++j)
		{
			String [] arr = br.readLine().split(" ");
			int armin, len;
			int [] motes=null;
			String [] strmotes;
			armin = Integer.parseInt(arr[0]);
			len = Integer.parseInt(arr[1]);
			strmotes = br.readLine().split(" ");
			motes = new int[len];
			for (int i=0;i < len;i++)
				motes[i]=Integer.parseInt(strmotes[i]);
			
			
			
			if (casenum > 0 && casenum != j+1)
				continue;
			
		
		
			
			
			
			if (outputToFile)
				bw.write("Case #"+(j+1)+": "+Solver(armin,len,motes)+"\n");
			else
				System.out.println("Case #"+(j+1)+": "+Solver(armin,len,motes));
		}
		
		br.close();
		if (bw!=null)
			bw.close();
	}
	
}
