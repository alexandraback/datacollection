package codejam;
import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
public class Round1BA {
	public static void main(String[] args){
		try{
			Scanner sc=new Scanner(new File("A.in"));
			PrintStream ps=new PrintStream("A.out");
			List<List<Integer>> nodes;
			HashMap<Integer,Boolean> paths;
			int t,n,m;
			t=sc.nextInt();
			for(int ti=0;ti<t;ti++){
				nodes=new ArrayList<List<Integer>>();
				n=sc.nextInt();
				for(int ni=0;ni<n;ni++){
					nodes.add(new ArrayList<Integer>());
					m=sc.nextInt();
					for(int mi=0;mi<m;mi++)
						nodes.get(ni).add(sc.nextInt()-1);
				}
				boolean found=false;
				for(int ni=0;ni<n&&!found;ni++){
					paths=new HashMap<Integer, Boolean>();
					if(traverse(ni,ni,nodes,paths))
						found=true;
				}
				if(found)
					ps.println("Case #"+(ti+1)+": Yes");
				else
					ps.println("Case #"+(ti+1)+": No");
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public static boolean traverse(Integer startNode,Integer currentNode,List<List<Integer>> nodes,HashMap<Integer,Boolean> paths){
		for(int ai=0;ai<nodes.get(currentNode).size();ai++){
			Integer arc=nodes.get(currentNode).get(ai);
			if(paths.get(arc)==Boolean.TRUE){
				return true;
			}
			else paths.put(arc,Boolean.TRUE);
			if(traverse(startNode,arc,nodes,paths))
				return true;
		}
		return false;
	}
}
