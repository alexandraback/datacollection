import java.util.LinkedList;
import java.util.Scanner;

public class C {
	static int n;
	static int[] bff;
	
	
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int tc = sc.nextInt();
		int max;
		
		for(int i=0; i<tc; ++i){
			n = sc.nextInt();
			
			bff = new int[n];
			
			for(int a=0; a<n; ++a){
				bff[a] = sc.nextInt()-1;
			}
			
			int maxSKG2 = 0;
			int maxSKO2 = 0;
			
			LinkedList<Integer> nodesSK = new LinkedList<>();
			LinkedList<Integer> nodes2SK = new LinkedList<>();
			LinkedList<Integer> nodesNotSK = new LinkedList<>();
			
			LinkedList<LinkedList<Integer>> listSk = new LinkedList<>();
			LinkedList<LinkedList<Integer>> list2Sk =new LinkedList<>();
			
			for(int a=0; a<n; ++a){
				if(nodesSK.contains(a)){
					continue;
				}
				
				LinkedList<Integer> l = getSK(a);
				
				if(l != null){
					if(l.size() == 2){
						list2Sk.add(l);
						nodes2SK.addAll(l);
						nodesSK.addAll(l);
					}
					else{
						maxSKG2 = Math.max(maxSKG2, l.size());
						listSk.add(l);
						nodesSK.addAll(l);
					}
				}
			}
			
			for(int a=0; a<n; ++a){
				if(nodesSK.contains(a) == false){
					nodesNotSK.add(a);
				}
			}
			
			maxSKO2 = nodes2SK.size();
			
			//alle kinder ohne bff
			LinkedList<Integer> nodesWS = new LinkedList<>();
			LinkedList<Integer> nodesWSV = new LinkedList<>();
			
			int[] maxIndepTo2SK = new int[n];
			
			
			boolean found = false;
			for(int a=0; a<n; ++a){
				found = false;
				
				for(int b=0; b<n; ++b){
					if(bff[b] == a){
						found = true;
						break;
					}
				}
				
				if(found == false){
					nodesWS.add(a);
				}
			}
			
			if(nodesWS.isEmpty()){
				max = Math.max(maxSKG2, maxSKO2);
			}
			else{
				int curCount;
				int cur;
				int next;
				
				for(Integer s : nodesWS){
					if(nodesWSV.contains(s)){
						continue;
					}
					
					nodesWSV.add(s);
					curCount = 1;
					cur = s;
					
					while(true){
						next = bff[cur];
						
						if(nodesNotSK.contains(next)){
							nodesWSV.add(next);
							curCount++;
							cur = next;
						}
						else if(nodes2SK.contains(next)){							
							maxIndepTo2SK[next] = Math.max(maxIndepTo2SK[next], curCount);
							break;
						}
						else{
							break;
						}
					
					}
				}
				
				int count = 0;
				for(int a=0; a<n; ++a){
					count += maxIndepTo2SK[a];
				}
				
				max = Math.max(maxSKG2, maxSKO2+count);
			}
			
			
			System.out.printf("Case #%d: %d%n", i+1, max);
			
		}
		
		sc.close();
	}
	
		
	public static LinkedList<Integer> getSK(int i){
		LinkedList<Integer> nodes = new LinkedList<>();
		
		nodes.add(i);
		
		int next = i;
		
		while(true){
			next = bff[next];
			if(nodes.contains(next)){
				if(next == i){
					return nodes;
				}
				else{
					return null;
				}
			}
			nodes.add(next);
		}
	}
	
}




