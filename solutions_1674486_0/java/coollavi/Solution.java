import java.io.*;
import java.util.*;
import java.lang.*;
class myNode{
	int num;
	ArrayList<Integer> link=new ArrayList<Integer>();
	myNode(int val,ArrayList<Integer> a){
		num=val;
		link=a;
	}
}

public class Solution {
	public static void main(String args[]){
		try{
			File file=new File("C:\\Users\\tanuj\\Downloads\\output.txt");
			BufferedWriter bw=new BufferedWriter(new FileWriter(file));
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\tanuj\\Downloads\\input.txt"));
			int T=Integer.parseInt(br.readLine());
			for(int t=0;t<T;t++){
			String s="";
				
			ArrayList<myNode> d=new ArrayList<myNode>();	
			int N=Integer.parseInt(br.readLine());
			for( int j=0;j<N;j++){
			StringTokenizer st=new StringTokenizer(br.readLine());
			int m=Integer.parseInt(st.nextToken());
			ArrayList<Integer> al=new ArrayList<Integer>();
			for(int i=0;i<m;i++){
				int p=Integer.parseInt(st.nextToken());
				if(p>0 	)al.add(p);
			}
			myNode node=new myNode(j+1,al);
			d.add(node);
			
			}
			boolean visited[]=new boolean[N];
			for(int i=0;i<N;i++){
				visited[i]=false;
			}
				
			boolean diamond=isdiamond(d,visited,d.get(0));
			if(diamond)	s="Yes";
			else	s="No";
			s="Case #"+(t+1)+": "+s;
			System.out.println(s);
			bw.write(s);
			bw.newLine();
			}
			bw.close();
		}catch(Exception e){
			System.out.println(e);
		}
	}
	
	public static boolean isdiamond(ArrayList<myNode> al,boolean visited[],myNode node){
		if(visited[node.num-1]) 	return true;
		else{
			visited[node.num-1]=true;
			boolean diam=false;
			for(int i=0;i<node.link.size();i++){
				int t=node.link.get(i);
				myNode temp=al.get(t-1);
				if(isdiamond(al,visited,temp)){
					return true;
				}
			}
		}
		return false;
	}
}




