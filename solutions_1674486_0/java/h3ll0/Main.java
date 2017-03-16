import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

class NodeRelation{
	final int N;
	HashMap<Integer, List<Integer>> hm = null;
	public NodeRelation(int N){
		this.N = N;
		hm = new HashMap<Integer, List<Integer>>();
	}
	public void add(int node, int parent){
		if(hm.containsKey(node)){
			List<Integer>list = hm.get(node);
			list.add(parent);
		}else{
			List<Integer>list = new ArrayList<Integer>();
			list.add(parent);
			hm.put(node, list);
		}
	}
	
	public String isDiamond(){
		HashSet<Integer> parentList = new HashSet<Integer>();
		Queue<Integer> q = new LinkedList<Integer>(); 
		boolean hasDiamond = false;
		for(int i=1;(i<=N)&&(!hasDiamond);i++){
			q.clear(); parentList.clear();
			q.add(i);
			while(!q.isEmpty()){
				int v = q.remove();
				if(hm.containsKey(v)){
					List<Integer>list = hm.get(v);
					for(int p:list){
						q.add(p);
					}
				}
				if(!parentList.contains(v)){
					parentList.add(v);
				}else{
					hasDiamond = true;
					break;
				}
			}
		}
		String out = hasDiamond==true?"Yes":"No";
		return out;
	}
}

public class Main{
	public static void main(String []args){
		try{
			//Scanner sc = new Scanner(new FileReader("input.txt"));
			BufferedReader br = new BufferedReader(new FileReader("input.txt"));
			int T = Integer.parseInt(br.readLine());//sc.nextInt();
			NodeRelation nr = null;
			for(int i=0;i<T;i++){
				int N = Integer.parseInt(br.readLine());//sc.nextInt();
				nr = new NodeRelation(N);
				for(int j=1;j<=N;j++){
					StringTokenizer st = new StringTokenizer(br.readLine(), " \t");
					int M = Integer.parseInt(st.nextToken());
					for(int k=0;k<M;k++)
						nr.add(j, Integer.parseInt(st.nextToken()));
				}
				System.out.println("Case #"+(i+1)+": "+nr.isDiamond());
			}
			br.close();
		}catch(Exception e){
			
		}
	}
	
}
