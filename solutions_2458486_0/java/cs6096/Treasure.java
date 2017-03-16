import java.util.*;
import java.io.*;

public class Treasure {
	public static Scanner scan = null;
	public static PrintWriter out = null;
	public static boolean bug = true;
	static{
		try {
			scan = new Scanner(new FileReader("input4.txt"));
			out = new PrintWriter(new File("output4.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args){
		int n1 = Integer.parseInt(scan.next());
		for (int z=0;z<n1;z++){
			int k = Integer.parseInt(scan.next());
			int n = Integer.parseInt(scan.next());
			
			ArrayList<Integer> keys = new ArrayList();
			int[] lock = new int[n];
			HashMap<Integer, ArrayList<Integer>> lock2 = new HashMap<>();
			
			ArrayList<Integer>[] newKeys = new ArrayList[n];
			
			for (int i=0;i<k;i++){
				keys.add(Integer.parseInt(scan.next()));
			}
			for (int i=0;i<n;i++){
				int tempLock = Integer.parseInt(scan.next());
				lock[i] = tempLock;
				
				if (lock2.containsKey(tempLock)){
					lock2.get(tempLock).add(i);
				}
				else {
					ArrayList<Integer>temp2 = new ArrayList<>();
					temp2.add(i);
					lock2.put(tempLock,temp2);
				}
				
				int temp = Integer.parseInt(scan.next());
				newKeys[i]=new ArrayList();
				for (int j=0;j<temp;j++){
					newKeys[i].add(Integer.parseInt(scan.next()));
				}
			}
			
			if (bug) System.out.println(lock2);
			
			int[] loc = new int[n];
			Arrays.fill(loc, -1);
			
			HashSet<Integer> extern = new HashSet<>();
			HashSet<Integer> covered = new HashSet<>();
			
			LinkedList<Integer> keyUsed = new LinkedList<>();
			LinkedList<Integer> sequence = new LinkedList<>();
			
			ArrayList<Integer>[] candList = new ArrayList[n];
			
			boolean found = true;
			ArrayList<Integer> keysCandid = new ArrayList<>();
			
			int ptr = -1;
			
			while (true){
				if (ptr==n-1){
					break;
				}
				if (bug) System.out.println("round ");
				if (bug) System.out.println("ptr "+ptr);
				if (bug) System.out.println("key "+keys);
				
				if (bug) System.out.println("loc "+Arrays.toString(loc));
				extern.clear();
				int degree = 0;
				for (int e: keys){
					if (lock2.containsKey(e)){
						ArrayList<Integer> g1 = lock2.get(e);
						for (int f: g1){
							if (f>loc[sequence.size()]
									&&!covered.contains(f)){
								degree++;
							}
							extern.add(f);
						}
					}
				}
				if (bug) System.out.println("extern "+extern);
				if (sequence.size()!=n&&degree==0){
					if (ptr==-1){
						found=false;
						break;
					}
					else {
						//loc[sequence.size()-1]=-1;
						keys.add(keyUsed.pollLast());
						covered.remove(sequence.pollLast());
						
						ptr--;
						continue;
					}
				}
				else if (sequence.size()==n){
					break;
				}
				
				
				
				
				
				keysCandid.addAll(extern);
				Collections.sort(keysCandid);
				
				for (int j=0;j<keysCandid.size();j++){
					if (keysCandid.get(j)>loc[sequence.size()]
							&&!covered.contains(keysCandid.get(j))){
						if (bug)System.out.println("j "+j); 
						loc[sequence.size()] = keysCandid.get(j);
						sequence.add(keysCandid.get(j));
						covered.add(keysCandid.get(j));
						keys.remove((Integer)lock[keysCandid.get(j)]);
						keyUsed.add(lock[keysCandid.get(j)]);
						keys.addAll(newKeys[keysCandid.get(j)]);
						break;
					}
				}
				
				
				ptr++;
				if (bug) System.out.println("loc "+Arrays.toString(loc));
				
				
				if (bug) System.out.println("keyUsed "+keyUsed);
				if (bug) System.out.println("sequence "+sequence);
				if (bug) System.out.println();
				
			}
			
			if (bug) System.out.println();
			
			out.print("Case #" + (z+1) +": ");
			if (found){
				if (bug) System.out.println("final configuration "+sequence);
				for (int i=0;i<sequence.size();i++){
					if (i!=0){
						out.print(" ");
					}
					out.print(sequence.get(i)+1);
				}
				out.println();
			}
			else {
				if (bug) System.out.println("impossible");
				out.println("IMPOSSIBLE");
			}
			
			out.flush();
		}
	}
}
