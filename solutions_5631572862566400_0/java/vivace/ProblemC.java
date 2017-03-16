import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

class Node
{
	public int id;
	public int bf;
	public Node next;
	public Node last;
	
	public Node(int i, int b, Node n, Node l)
	{
		id=i;
		bf=b;
		next=n;
		last=l;
	}
}
public class ProblemC {
	
	
	public static int backwards(ArrayList<Object> comp, Node[] bf, int[] oplen, int a, Node[] chains, int c)
	{
		ArrayList<Object> clone=comp;
		Node star=new Node(bf[oplen[a]].id,bf[oplen[a]].bf,null,null);
		clone.remove((Object)star.id);
		int options=0;
		for(Object i:clone)
		{
			if(bf[(int) i].bf==star.id)
				options++;
		}
		if(options==0)
			return 0;
		oplen=new int[options];
		int count=0;
		for(Object i:comp)
		{
			if(bf[(int)i].bf==star.id)
			{
				oplen[count]=(int)i;
			}
		}
		for(int y=0;y<options;y++)
		{
			oplen[y]=backwards(comp, bf, oplen, y, chains, c)+1;
		}
		int greatest=0;
		for(int f=0;f<oplen.length;f++)
			if(oplen[f]>greatest)
				greatest=oplen[f];
		return greatest;
	}
	static Scanner in=new Scanner(System.in);
	public static void main(String[] args) throws FileNotFoundException {
		
		java.io.PrintStream out=new java.io.PrintStream("C:/users/Josh/documents/output.txt");
		int run=in.nextInt();
		for(int p=0;p<run;p++)
		{
			Node[] bff=new Node[in.nextInt()];
			for(int c=0;c<bff.length;c++)
				bff[c] = new Node(c,in.nextInt()-1,null,null);
			Node[]chains=new Node[bff.length];
			for(int c=0;c<chains.length;c++)
			{
				chains[c]=new Node(c,bff[c].bf,null,null);
			}
			int chainlen[]=new int[bff.length];
			for(int c=0;c<bff.length;c++)
			{
				ArrayList<Object> comp=new ArrayList();
				for(int d=0;d<bff.length;d++)
				{
					comp.add(d);
				}
				comp.remove((Object)c);
		here:	for(int d=0;d<bff.length;d++)
				{
					if(comp.contains(chains[c].bf))
					{
						chains[c].next=new Node(chains[c].bf,bff[chains[c].bf].bf,null,chains[c]);
						chains[c]=chains[c].next;
						comp.remove((Object)chains[c].id);
					}
					else
					{
						if(chains[c].bf==chains[c].last.id)
						{
							int options=0;
							for(Object i:comp)
							{
								if(bff[(int)i].bf==chains[c].id)
									options++;
							}
							if(options==0)
							{
								int leng=0;
								while(chains[c]!=null)
								{
									leng++;
									chains[c]=chains[c].last;
								}
								chainlen[c]=leng;
								break here;
							}
							int oplen[]=new int[options];
							int count=0;
							for(Object i:comp)
							{
								if(bff[(int)i].bf==chains[c].id)
								{
									oplen[count]=(int)i;
								}
							}
							for(int a=0;a<options;a++)
							{
								oplen[a]=(int)backwards(comp, bff, oplen, a, chains, c);
							}
							int leng=1;
							while(chains[c]!=null)
							{
								leng++;
								chains[c]=chains[c].last;
							}
							int greatest=0;
							for(int f=0;f<oplen.length;f++)
								if(oplen[f]>greatest)
									greatest=oplen[f];
							leng+=greatest;
							chainlen[c]=leng;
							break here;
							
						}
						else
						{
							//check if first is bff
							Node cur=chains[c];
							while(cur.last!=null)
							{
								cur=cur.last;
								if(cur.id==chains[c].bf)
								{
									if(cur.last!=null)
									{
										chains[c]=chains[c].last;
									}
									else
									{
										int leng=0;
										while(chains[c]!=null)
										{
											leng++;
											chains[c]=chains[c].last;
										}
										chainlen[c]=leng;
										break here;
									}
									
								}
							}
						}
					}
				}
			}
			int great=0;
			for(int c=0;c<chainlen.length;c++)
			{
				if(chainlen[c]>great)
					great=chainlen[c];
			}
			out.println("Case #"+(p+1)+": "+great);
		}

	}

}
