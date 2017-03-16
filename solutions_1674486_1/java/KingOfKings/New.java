import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class New {
	static Scanner sc;
	public static void main(String a[]) throws FileNotFoundException
	{
		int n,i;
		String res;
		sc= new Scanner(new FileInputStream("d:\\test\\a.in"));
		PrintStream out=new PrintStream(new FileOutputStream("d:\\test\\a.out"));
		
		n=sc.nextInt();
		sc.nextLine();
		for(i=1;i<=n;i++)
		{
			res=process();
			out.println("Case #"+i+": "+res);
			System.out.println("Case #"+i+": "+res);
			
		}
	}
	static String process()
	{
		int n,m,i,j,r;
		boolean flag=false;
		n=sc.nextInt();
		Node node[] = new Node[n];
		for(i=0;i<n;i++)
			node[i]=new Node();
		for(i=0;i<n;i++)
		{
			m=sc.nextInt();
			
			for(j=0;j<m;j++)
			{
				
				r=sc.nextInt();
				if(flag) continue;
				r=r-1;
				if(node[i].addParent(r,node)|| node[r].addChild(i, node)) flag=true;
			}
		/*	m=node[i].parent.size();
		System.out.println("Node:"+i);
			System.out.print("Parent : ");
			for(j=0;j<m;j++) System.out.print(node[i].parent.get(j)+" : ");
			System.out.println();
			System.out.print("Child : ");
			m=node[i].child.size();
			for(j=0;j<m;j++) System.out.print(node[i].child.get(j)+" : ");
			System.out.println();*/
				
		}
		if(flag) return "Yes";
		return "No";
	}
}
class Node
{
	public ArrayList<Integer> child = new ArrayList<Integer>();
	public ArrayList<Integer> parent = new ArrayList<Integer>();
	public boolean addChild(int item,Node node[])
	{
		int n,i;
		if(child.contains(item)) return true;
		child.add(item);
		n=parent.size();
		for(i=0;i<n;i++) if(node[parent.get(i)].addChild(item, node)) return true;
		return false;
	}
	public boolean addParent(int item,Node node[])
	{
		int n,i;
		n=child.size();
		parent.add(item);
		for(i=0;i<n;i++)
			if(node[item].addChild(child.get(i), node)) return true;
		return false;
	}
	
}