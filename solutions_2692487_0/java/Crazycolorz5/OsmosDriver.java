import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class OsmosDriver {

	public static void main(String[] args) {
		try {
			File f = new File("osmos.in");
			File out = new File("osmos.out");
			FileInputStream fin;
			Scanner sin = null;
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					int a = sin.nextInt();
					int n = sin.nextInt();
					ArrayList<Integer> otherMotes = new ArrayList<Integer>();
					for(int c=0;c<n;c++)
					{
						otherMotes.add(sin.nextInt());
					}
					for(int x=0; x<otherMotes.size();x++)
					{
						if(otherMotes.get(x) < a)
						{
							a+=otherMotes.remove(x);
							x = -1;
						}					
					}
					try {
						fout.write("Case #" + (casenum+1) + ": " + getSteps(a, otherMotes) + "\n");
					} catch (IOException e1) {e1.printStackTrace();} catch (Throwable e) {
						fout.write("Case #" + (casenum+1) + ": " + (otherMotes.size()) + "\n");
					}
				}
			}
			finally {
				fout.flush();
				sin.close();
				fout.close();
			} 
		} catch(IOException e) {}
	}

/*	private static int getWeight(int a, int leastgreaterthan, ArrayList<Integer> motes) 
	{
		int count=0;
		while(a<leastgreaterthan)
		{
			for(int x=0; x<motes.size();x++)
			{
				if(motes.get(x) < a)
				{
					a+=motes.remove(x);
					x = 0;
				}					
			}
			if(a<leastgreaterthan)
			{
				a+=a-1;			
				count++;
			}
		}
		return count;
	}*/
	private static int min(int a, int b)
	{
		if(a<b)
			return a;
		else 
			return b;
	}
	private static int getSteps(int a, ArrayList<Integer> otherMotes) throws Throwable
	{
		if(a==1)
			throw new Throwable();
		while(otherMotes.size()>0)
		{
			for(int x=0; x<otherMotes.size();x++)
			{
				if(otherMotes.get(x) < a)
				{
					a+=otherMotes.remove(x);
					x = -1;
				}					
			}
			if(otherMotes.size()>0)
			{
				ArrayList<Integer> moteCopy = new ArrayList<Integer>();
				for(Integer i : otherMotes)
					moteCopy.add(i);
				//Get least greater than and # greater than
				int /*leastgreaterthan=0,*/ number=0;
				/*for(int x=0; x<otherMotes.size();x++)
				{
					//if(otherMotes.get(x) > a)
					//{
						if(leastgreaterthan==0)
						{
							leastgreaterthan = otherMotes.get(x);
						}
						else if(otherMotes.get(x)<leastgreaterthan)
						{
							leastgreaterthan = otherMotes.get(x);
						}
						number++;
					//}				
				}*/
				number = otherMotes.size();
/*				int weight=getWeight(a,leastgreaterthan); //num of absorbs to get that high
				if(weight<number)
				{
					
				}*/
				a+=a-1;
				try {
				return min(number, 1+getSteps(a, moteCopy));
				}
				catch(Throwable t)
				{
					return number;
				}
			}
		}
		return 0;
	}
	
	
}
