import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;


public class Main {
	public static void main(String args[]) throws IOException{
		new Problem();
	}
}
class Problem {
	int cases=0;
	
	public Problem() throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("in.txt"));
		FileOutputStream out=new FileOutputStream("out.txt"); 
		cases=Integer.parseInt(in.readLine());
		String str[];
		int c=0;
		//for each case
		for(int i=0;i<cases;i++){
			boolean flag=false;
			c=Integer.parseInt(in.readLine());

			Node[] node=new Node[c];
			boolean[] done=new boolean[c];
			for(int j=0;j<c;j++){
				node[j]=new Node();
				done[j]=false;
				
				str=in.readLine().split(" ");
				
				int nc=Integer.parseInt(str[0]);
				
				int temp[]=new int[nc];
				for(int k=0;k<nc;k++){
					temp[k]=Integer.parseInt(str[k+1])-1;
					
				}
				node[j].id=j;
				node[j].rel=temp;
			}
			//data ready
			System.out.println("/******************/\n");
			System.out.println(c+"\n");
			for(int t=0;t<c;t++)
			{
				System.out.println(node[t].id+":");
				for(int y=0;y<node[t].rel.length;y++)
					System.out.println("'"+node[t].rel[y]+"'");
			}
			for(int l=0;l<c&&!flag;l++){
				Queue<Integer> list=new LinkedList();
				HashMap<Node,String> hash=new HashMap<Node,String>();
				System.out.println(node[l].rel.length);
				for(int m=0;m<node[l].rel.length;m++)
				{
					hash.put(node[node[l].rel[m]], null);
					System.out.println("\nput:"+node[l].rel[m]);
					list.add(node[l].rel[m]);
				}
				while(!list.isEmpty()&&!flag){
					int next;
					next=list.remove();
					System.out.println("\nremove:"+next);
					
					for(int m=0;m<node[next].rel.length;m++)
					{
						System.out.println("\nget:"+node[next].rel[m]);
						if(!hash.containsKey(node[node[next].rel[m]]))
						{
							hash.put(node[node[next].rel[m]], null);
						    list.add(node[next].rel[m]);
						}
						else
						{
							System.out.println(true);
							flag=true;
							break;
						}
						
					}
				}
			}
			String ans=new String("Case #"+(i+1)+":");
			if(flag)
				ans+=" Yes\n";
			else
				ans+=" No\n";
			out.write(ans.getBytes());
		}
		
	}
}
class Node{
	int id;
	int rel[]; 
}