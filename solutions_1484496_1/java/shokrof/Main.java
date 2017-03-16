import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(new File("input.txt"));
		FileWriter writer=new FileWriter("output.txt",false);
		PrintWriter output=new PrintWriter(writer);
		int t=input.nextInt();
		
		for(int o=1;o<=t;o++)
		{		
			HashMap<Long,ArrayList<Long> > sums=new HashMap<Long, ArrayList<Long>>();
			int n=input.nextInt();
			long [] numbers=new long[n];
			for(int i=0;i<n;i++)
			{
				numbers[i]=input.nextLong();
				ArrayList<Long> temp=new ArrayList<Long>();
				temp.add(numbers[i]);
				sums.put(numbers[i], temp);
			}
			ArrayList<ArrayList<Long>> prev=new ArrayList<ArrayList<Long>>();
			boolean found=false;
			ArrayList<Long> set1 = null;
			ArrayList<Long> set2 = null;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
				{
					ArrayList< Long> te=new ArrayList<Long>();
					te.add(numbers[i]);
					te.add(numbers[j]);
					if(!sums.containsKey(numbers[i]+numbers[j]))
					{

						sums.put(numbers[i]+numbers[j], te);
						prev.add(te);
					}
					else
					{

						set1=te;
						set2=sums.get(numbers[i]+numbers[j]);
						boolean right=true;
						for(int d=0;d<set1.size();d++)
							if(set2.contains(set1.get(d)))
							{
								right=false;
								break;
							}
						if(right)
						{
							found=true;
							i=n;
							j=n;
						}
					}
				}
			if(!found)
			{
				ArrayList<ArrayList<Long>> curr;
				for(int q=2;q<n-1;q++)
				{
					curr=new ArrayList<ArrayList<Long>>();
					for(int i=0;i<n&&!found;i++)
					{
						for(int j=0;j<prev.size()&&!found;j++)
						{
							if(prev.get(j).contains(numbers[i]))
								continue;
							else
							{
								long sum=numbers[i];
								for(int k=0;k<prev.get(j).size();k++)
									sum+=prev.get(j).get(k);
								ArrayList<Long> tem=new ArrayList<Long>(prev.get(j));
								tem.add(numbers[i]);
								if(!sums.containsKey(sum))
								{

									curr.add(tem);
									sums.put(sum, tem);
								}
								else
								{
									set1=tem;
									set2=sums.get(sum);

									boolean right=true;
									for(int d=0;d<set1.size();d++)
										if(set2.contains(set1.get(d)))
										{
											right=false;
											break;
										}
									if(right)
									{
										found=true;
										i=n;
										j=n;
										break;
									}
								}
							}
						}
					}
					prev=curr;

				}
			}
			if(found)
			{
				output.printf("Case #%d:\n",o);
				for(int i=0;i<set1.size()-1;i++)
					output.print(set1.get(i)+" ");
				output.print(set1.get(set1.size()-1));
				output.println();

				for(int i=0;i<set2.size()-1;i++)
					output.print(set2.get(i)+" ");
				output.print(set2.get(set2.size()-1));
				output.println();
			}
			else
				output.printf("Case #%d: Impossible\n",o);
		}
		output.close();


	}

}
