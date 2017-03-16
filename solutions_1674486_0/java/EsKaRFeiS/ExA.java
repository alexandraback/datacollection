package t2012.round1c;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class ExA {
	
	
	
	public void exec(String filename, String out_filename)
	{
		try{
		
			FileInputStream fis = new FileInputStream(filename); 
			Scanner s = new Scanner(fis);
			
			FileWriter output_fstream = new FileWriter(out_filename);
			BufferedWriter out = new BufferedWriter(output_fstream);

			// Something in between
			
			// The problem
			int T = Integer.parseInt(s.nextLine());
			for(int testNum = 1; testNum <=T; testNum++)
			{
				//System.out.println("New test");
				String line = s.nextLine();
				String[] words = line.split(" ");
				int N = Integer.parseInt(words[0]);

				ArrayList[] ins = new ArrayList[N];
				int[] nins = new int[N];
				for(int i = 0; i < N; i ++)
				{
					
					String[] w2 = s.nextLine().split(" ");
					nins[i] = Integer.parseInt(w2[0]);
					ins[i] = new ArrayList<Integer>();
					for(int j = 0; j < nins[i]; j++)
					{
						int newInherit = Integer.parseInt(w2[j+1])-1;
						//System.out.println(i+" inherits from "+newInherit);
						ins[i].add(newInherit);
					}
				}
				boolean found = false;
				for(int i = 0; i < N && !found; i++)
				{
					int[] inherit = new int[N];
					for(int j = 0; j < N; j++)
					{
						inherit[i] = 0;
					}
					//System.out.println("Finding inherits for "+i);
					findInherits(inherit, i, nins, ins);
					for(int j = 0; j < N; j++)
					{
						if(j!=i && inherit[j]>1)
							found = true;
					}
					
				}
				out.write("Case #"+testNum+": ");
				
				if(found)
					out.write("Yes");
				else
					out.write("No");
				
				out.write("\n");
				
			}
			
			// End the problem
			out.close();
			output_fstream.close();
		
		}catch(Exception e)
		{
			System.out.println("ERROR");
			e.printStackTrace();
		}
		
	}
	private void findInherits(int[] inherit, int i, int[] nins, ArrayList[] ins) {

		inherit[i]++;
		//System.out.println("Marked "+i);
		if(nins[i] == 0)
			return;
		Iterator it = ins[i].iterator();
		while(it.hasNext())
		{
			int j = (Integer) it.next();
			findInherits(inherit, j, nins, ins);
		}
		
	}
	public static void main(String args[])
	{
		String PATH= "/home/pau/development/workspace/CodeJam/testfiles/2012/R1C/";
		ExA a = new ExA();
		a.exec(PATH + "AS.in", PATH + "AS.out");
		//a.exec(PATH + "AL.in", PATH + "AL.out");
	}

}
