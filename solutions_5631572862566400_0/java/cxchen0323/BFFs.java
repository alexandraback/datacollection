package codejam.round1a;

import java.io.*;
import java.util.*;

/**
 * @author Cheng Chen
 * @since Apr 15, 2016
 */

public class BFFs {
	
	public static void main(String[] args) throws Exception {
		int casetotal = 0;
		int casenumber = 1;
		int totalline = 0;
		String line = "";
		
		try (FileReader fr = new FileReader("data/C-small-attempt0.in"); BufferedReader br = new BufferedReader(fr); FileWriter fw = new FileWriter("data/C-small-attempt0.out"); PrintWriter bw = new PrintWriter(fw);) {
			while ((line = br.readLine()) != null) {
				if (totalline == 0) {
					casetotal = Integer.parseInt(line);
					totalline++;
					continue;
				}
				
				if (casenumber > casetotal) {
					System.out.println("###Error: The casenumber has problem!!!");
					System.out.println("###Error: This error happened in line number" + totalline);
					System.exit(0);
				}
				
				/**
				 * processing
				 */
				int N=Integer.parseInt(line);
				
				line=br.readLine();
				String[] arrS=line.split(" ",N);
				int childno=1;
				int[] bffs=new int[N+1];
				for(String s:arrS){
					int bff=Integer.parseInt(s);
					bffs[childno]=bff;
					childno++;
				}
				BFFs bf=new BFFs();
				int number=bf.getLargestBFFCircle(N,bffs);
				bw.println("Case #"+casenumber+": "+number);
				casenumber++;
				
				totalline++;
			}
		}
		
	}
	
	
	private int getLargestBFFCircle(int N, int[] bffs) {
	      HashMap<Integer,ChildNode> map=new HashMap<Integer,ChildNode>();
	      for(int i=1;i<=N;i++){
	      	ChildNode child=new ChildNode(i);
	      	map.put(i, child);
	      }
		
	      for(int i=1;i<=N;i++){
	      	ChildNode child=map.get(i);
	      	ChildNode bff=map.get(bffs[i]);
	      	child.bff=bff;
	      	bff.addWhoseBff(child);
	      }
	      
	      boolean[] visited=new boolean[N+1];
	      int max=0;
	      for(int i=1;i<=N;i++){
	      	if(visited[i]==false){
	      		int pathNumber=findPath(map.get(i), visited);
	      		max=Math.max(max, pathNumber);
	      	}
	      }
		
		return max;
      }
	

	private int findPath(ChildNode child, boolean[] visited) {
	      int path=0;
	      ChildNode curr=child;
	      ChildNode start=null;
	      ChildNode preone=null;
	      while(!visited[curr.number]){
		      visited[curr.number]=true;
		      ChildNode bff=curr.bff;
		      if(bff==preone){
		      	start=curr;
		      	path++;
		      	break;
		      }
		      preone=curr;
		      curr=bff;
		      path++;
	      }
	      
	      if(start==null)
	      	return path;
	      path--;
	      LinkedList<ChildNode> q=new LinkedList<ChildNode>();
	      q.offer(start);
	      ChildNode lastone=start;
	      while(!q.isEmpty()){
	      	curr=q.poll();
	      	for(ChildNode bf:curr.whosebffs){
	      		if(!visited[bf.number])
	      			q.offer(bf);
	      	}
	      	
	      	if(curr==lastone){
	      		path++;
	      		lastone=q.peekLast();
	      	}
	      		
	      }
	      
	      return path;
      }


	class ChildNode{
		private int number;
		private ChildNode bff;
		private HashSet<ChildNode> whosebffs;
		
		public ChildNode(int number){
			this.number=number;
			whosebffs=new HashSet<ChildNode>();
		}
		
		public void addWhoseBff(ChildNode bf){
			whosebffs.add(bf);
		}
		
		public String toString(){
			StringBuilder sb=new StringBuilder();
			sb.append("Number:").append(number).append("\n");
			sb.append("BFF:").append(bff.number).append("\n");
			sb.append("Whose BFF:");
			for(ChildNode bf:whosebffs)
				sb.append(bf.number).append(",").append("\n");
			return sb.toString();
		}
	}
}
