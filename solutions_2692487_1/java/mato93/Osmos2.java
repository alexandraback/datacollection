package Round_1B;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Osmos2
{
	public static int min(int a, int b)
	{
		if(a<=b) 
		{
			//System.out.println("absorbed");
			return a;
		}
		//System.out.println("deleted");
		return b;
	}
	
	public static int absorb(ArrayList<Integer> motes,long mote)
	{
		
		if(!motes.isEmpty())
		{
			int actualMote = motes.get(0);
			
			if (mote>actualMote) 
			{
				//System.out.println("Som "+mote+" a zeriem "+actualMote);
				motes.remove(0);
				return absorb(motes,mote+actualMote);
			} else
			{
				ArrayList<Integer> motes2 = new ArrayList<Integer>();
				for(int i=0; i<motes.size(); i++)
					motes2.add(new Integer(motes.get(i)));
				long mote2 = mote;
				
				int cost = 0;
				while(mote <= actualMote)
				{
					cost++;
					mote += mote-1;
				}
				
				motes.remove(0);
				//System.out.println("Skok do rekurzie 1, som "+mote);
				int absorb = cost+absorb(motes,mote+actualMote);
				//System.out.println("Som spat z rekurzie 1");
				
				
				motes2.remove(motes2.size()-1); // remove the last
				//System.out.println("Skok do rekurzie 2, som"+mote);
				int delete = 1 + absorb(motes2,mote2);
				//System.out.println("Som spat z rekurzie 2");
				
				return min(absorb,delete);
			}

		}
		return 0;
		
		/*System.out.println("Mote = "+mote);
		for(int i=0; i<motes.size(); i++) System.out.println(motes.get(i));
		System.out.println("\n");*/
	}
	
	
	public static void main(String[] args) 
	{
		try{
			String readFrom = "1B/A-large.in";
			Scanner sc = new Scanner(new File(readFrom));
			FileWriter out = new FileWriter(new File("1B/A-large.out"));
			
			
			int answer;
			int testCases = sc.nextInt();
			int mote;
			ArrayList<Integer> motes = new ArrayList<Integer>();
				int numOfMotes;
				
			for(int k=1; k<=testCases; k++)
			{
				motes.clear();
				mote = sc.nextInt();
				numOfMotes = sc.nextInt();
				
				
				for(int i=1; i<=numOfMotes; i++)
					motes.add(sc.nextInt());
				
				Collections.sort(motes);
				if (mote == 1)  answer = numOfMotes;
				else   			answer = absorb(motes,(long)mote);
				
				//System.out.println("Case #"+k+": "+answer);
				out.write("Case #"+k+": "+answer+"\n");
			}

			out.close();
		}catch(IOException e)
		{
			System.out.println("IO error");
		}

	}

}
