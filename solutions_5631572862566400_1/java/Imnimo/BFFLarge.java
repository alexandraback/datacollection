import java.io.File;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;


public class BFFLarge {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("C-large (1).in"));
		
		int numCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=numCases;c++) {
			int n = Integer.parseInt(s.nextLine());
			
			int[] bff = new int[n+1];
			
			HashMap<Integer,HashSet<Integer>> bffInv = new HashMap<>();
			int[] parent = new int[n+1];
			String friendLine = s.nextLine();
			String[] friendArr = friendLine.split("\\s+");
			for(int i = 1;i<=n;i++) {
				int friendID = Integer.parseInt(friendArr[i-1]);
				
				bff[i] = friendID;
				if(!bffInv.containsKey(friendID)) {
					bffInv.put(friendID, new HashSet<Integer>());
				}
				bffInv.get(friendID).add(i);
			}
			int depth = fillParents(bff,bffInv,parent);
			int loop = getLongestLoop(bff);
			//int ans = countPerms(bff);
			//if(Math.max(loop,depth)!=ans) {
			//	System.out.println(depth + " " + loop + " " + ans + " " + Arrays.toString(bff));
			///	System.exit(1);
			//}
			System.out.println("Case #" + c + ": " + Math.max(loop,depth));
		}
	}
	public static int fillParents(int[] bff, HashMap<Integer,HashSet<Integer>> bffInv, int[] parent) {
		//System.out.println("\n============\n" + Arrays.toString(bff) );
		HashSet<Integer> pairs = new HashSet<Integer>();
		for(int i = 1;i<bff.length;i++) {
			if(bffInv.containsKey(i) && bffInv.get(i).contains(bff[i])) {
				pairs.add(i);
			}
		}
		int totalDepth = 0;
		for(int i : pairs) {
			
			int maxDepth = 1;
			
			LinkedList<Pair> queue = new LinkedList<>();
			HashSet<Integer> checked = new HashSet<Integer>();
			for(int child : bffInv.get(i)) {
				if(!pairs.contains(child)){
					queue.add(new Pair(child,2));
					checked.add(child);
				}
			}
			checked.add(i);
		
			while(!queue.isEmpty()) {
				Pair child = queue.pop();
				//System.out.println(child.id + " " + child.depth);
				if(child.depth>maxDepth) {
					maxDepth = child.depth;
				}
				
				parent[child.id] = i;
				
				
				if(bffInv.containsKey(child.id)) {
					for(int grand : bffInv.get(child.id)) {
						if(!checked.contains(grand)) {
							checked.add(grand);
							queue.add(new Pair(grand,child.depth+1));
						}
					}
					
				}
			}
			totalDepth+=maxDepth;
			//System.out.println("max depth of " + i + " = " + maxDepth);
		}
		//System.out.println(pairs);
		//System.out.println(Arrays.toString(parent));
		//System.out.println(totalDepth );
		return totalDepth;
	}
	
	public static int getLongestLoop(int[] bff) {
		int max = 0;
		for(int start = 1;start<bff.length;start++) {
			boolean[] marked = new boolean[bff.length];
			int length = 0;
			int index = start;
			while(!marked[index]) {
				marked[index] = true;
				index = bff[index];
				length++;
			}
			if(index == start && length > max) max = length;
		}
		return max;
	}
	
	public static int countPerms(int[] bff) {
		
		int max = 0;
		for(int start = 1;start<bff.length;start++) {
			boolean[] marked = new boolean[bff.length];
			int[] seq = new int[bff.length];
			seq[0] = start;
			marked[start] = true;
			//seq[1] = bff[start];
			//marked[bff[start]] = true;
			
			int val = getMax(seq,bff,marked,1);
			if(val>max) {
				max = val;
			}
		}
		return max;
	}
	
	public static boolean check(int[] soFar, int[] bff, int count) {
		boolean result = true;
		for(int i = 0;i<count;i++) {
			int child = soFar[i];
			int friend = bff[child];
			if(friend != soFar[(i+1)%count] && friend != soFar[(i-1+count)%count]) {
				/*System.out.println("INVALID");
				System.out.println(Arrays.toString(soFar));
				System.out.println(Arrays.toString(bff));
				System.out.println(count);
				System.exit(1);*/
				result = false;
			}
		}
		return result;
	}
	
	public static int getMax(int[] soFar, int[] bff, boolean[] marked, int count) {
		
		//System.out.println(Arrays.toString(soFar) + " " + count);
		
		int lastFriend = soFar[count-1];
		
			if(count > 1 && soFar[count-2] != bff[lastFriend]) { //if the last guy is not sitting next to their bff
				if(!marked[bff[lastFriend]]) { //if the bff hasn't already been added
					count++;
					soFar[count-1] = bff[lastFriend]; 
					marked[bff[lastFriend]] = true;
					
					int result = getMax(soFar,bff,marked,count);
					soFar[count-1] = 0;
					marked[bff[lastFriend]] = false;
					return result;
				} else {
					if(bff[lastFriend] == soFar[0]) {
						//System.out.println("SUCCESS RETURNING " + count);
						if(check(soFar,bff,count)) {
							//System.out.println("VALID " + Arrays.toString(soFar) + " " + count);
							return count;
						} else {
							//System.out.println("INVALID " + Arrays.toString(soFar) + " " + Arrays.toString(bff) + " " + count);
							return 0;
						}
					} else {
						//System.out.println("NO FRIEND FOR " + lastFriend);
						return 0;
					}
				}
			} else { //the last guy is already sitting next to their bff
				
				
				int max = 0;
				if(check(soFar,bff,count)) {
					max = count;
				}
				for(int i = 1;i<bff.length;i++) {
					if(!marked[i]) {
						count++;
						soFar[count-1] = i;
						marked[i] = true;
						int val = getMax(soFar,bff,marked,count);
						marked[i] = false;
						count--;
						soFar[count] = 0;
						if(val > max) {
							max = val;
						}
					}
				}
				//System.out.println("SUCESS RETURNING " + max);
				return max;
			}
		
		
		
		
	}
	
}
class Pair {
	int id, depth;
	public Pair(int id, int depth) {
		this.id = id;
		this.depth = depth;
	}
}
