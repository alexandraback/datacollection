import java.util.*;
import java.io.*;

public class Treasure {
	private int chests;
	private int currMov;
	private int[] myKeys;
	private ArrayList<Integer>[] myChests;
	private int[] chestTypes;
	private int[] moves;
	private boolean[] visited;
	
	private int[] powers = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
			       2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
	private boolean[] seen;
	private int value;
	
	public Treasure(){}
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("file")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int cases = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<= cases; i++){
			st = new StringTokenizer(in.readLine());
			Treasure myMap = new Treasure();
			int startKeys = Integer.parseInt(st.nextToken());
			int chests = Integer.parseInt(st.nextToken());
			
			myMap.chests = chests;
			
			myMap.myKeys = new int[201];
			st = new StringTokenizer(in.readLine());
			for(int j=0; j < startKeys; j++)
				myMap.myKeys[Integer.parseInt(st.nextToken())]++;
			
			myMap.myChests = new ArrayList[chests];
			myMap.chestTypes = new int[chests];
			for(int j=0; j < chests; j++){
				myMap.myChests[j] = new ArrayList<Integer>();
				st = new StringTokenizer(in.readLine());
				myMap.chestTypes[j] = Integer.parseInt(st.nextToken());
				int numKeys = Integer.parseInt(st.nextToken());
				for(int k=0; k < numKeys; k++)
					myMap.myChests[j].add(Integer.parseInt(st.nextToken()));
			}
			
			myMap.moves = new int[chests];
			myMap.visited = new boolean[chests];
			myMap.currMov = 0;
			myMap.seen = new boolean[1100000];
			myMap.value = 0;
			
			
			
			out.print("Case #" + i + ":");
			if(myMap.traverse()){
				for(int j=0; j < chests; j++)
					out.print(" " + (myMap.moves[j]+1) );
			}
			else
				out.print(" IMPOSSIBLE");
			out.println();
		}
		out.close();
	}
	
	private boolean traverse(){
		//System.out.println(currMov);
		seen[value] = true;
		if(currMov == chests) return true;
		for(int i=0; i < chests; i++){
			if(!visited[i] && myKeys[chestTypes[i]] > 0 && !seen[value+powers[i]]){
				//we'll visit
				visited[i] = true;
				myKeys[chestTypes[i]]--;
				for(Integer key: myChests[i])
					myKeys[key]++;
				moves[currMov] = i;
				currMov++;
				value += powers[i];
				if(traverse())
					return true;
				//else revert
				visited[i] = false;
				myKeys[chestTypes[i]]++;
				for(Integer key: myChests[i])
					myKeys[key]--;
				currMov--;
				value -= powers[i];
			}
		}
		return false;
	}
}
