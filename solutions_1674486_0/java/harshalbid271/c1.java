import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;


public class c1 {

	
	public static void main(String args[]) throws FileNotFoundException
	{
		Scanner in=new Scanner(new FileReader("ina.in"));
		PrintWriter pw=new PrintWriter("outA.txt");
		
		int cases=in.nextInt();
		in.nextLine();
		
		for(int counter=1;counter<=cases;counter++)
		{
			int n=in.nextInt();
			in.nextLine();
			
			Vector<Integer> arr[]=new Vector[n];
//			boolean flag=false;
			
			boolean debug=false;
			
			for(int i=0;i<n;i++)
			{
				arr[i]=new Vector<Integer>();
				
				int m=in.nextInt();
				if(m>1)
					debug=true;
				for(int k=0;k<m;k++)
				{
					arr[i].add(in.nextInt());
				}
			}
			
			boolean flag=false;
			outer:
			for(int i=0;i<n;i++)
			{
			
//				Iterator<Integer> it_i=arr[i].iterator();

				Vector<Integer> cl= (Vector<Integer>) arr[i].clone();

				for(int j=0;j<arr[i].size();j++)
				{
					int first=arr[i].elementAt(j);
					
					
//					for(int k=0;k<arr[first].size();k++)
//					{
						Iterator<Integer> it=arr[first-1].iterator();
						int next=-1;
						int previous;
						while(it.hasNext())
						{
							previous=next;
							next=it.next();
							
							if(!arr[i].contains(next))
							{
								//if(previous==-1||!arr[previous-1].contains(next))//i+1!=next&&!arr[next-1].contains(i+1))
									arr[i].add(next);
							}
							else
							{
								flag=true;
								break outer;
							}
						}
//					}
				}
				arr[i]=cl;

//				if(arr[i].contains(temp))
//					{
//						flag=true;
//						break outer;
//					}
//					else
//					{
//						arr[i].add(temp);
//						if(temp<i)
//						{
//							Iterator<Integer> ls=arr[temp].iterator();
//							while(ls.hasNext())
//							{
//								int link=ls.next();
//								
//								if(arr[i].contains(link))
//								{
//									flag=true;
//									break outer;
//								}
//								
//							}
//						}
//					}
//				}
			}
			if(flag==true)
			{
				if(debug==false)
					System.out.println("EEEEEEEERRRRRRRRRR");
				System.out.println("Case #"+counter+": Yes");
			}
			else
				System.out.println("Case #"+counter+": No");
			
		}
		pw.close();
	}
	
	public static void adder(int i, int j)
	{
		
	}
}
