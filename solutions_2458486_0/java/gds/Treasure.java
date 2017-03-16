import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Scanner;


public class Treasure {
	static PrintStream out;
	
	public static void main(String[] args) {
		Scanner in;
		try {
			out = new PrintStream(new File("out.txt"));
		}catch(FileNotFoundException e){
			System.out.println("Could not open output file. Using System.out instead.");
			out = System.out;
		}
		try {
			in = new Scanner(new File(args[0]));
		} catch (IndexOutOfBoundsException e){
			System.out.println("Was expecting path to input file.");
			return;
		} catch (FileNotFoundException e) {
			System.out.println("Could not find the path specified.");
			return;
		}
		//get number of cases
		int cases = in.nextInt();
		for(int i=1;i<=cases;i++){
			//setup
			int[] keys;
			Chest[] chests;
			{
				Collection<Integer> keyCol = new ArrayList<Integer>();
				int numkeys = in.nextInt();
				chests = new Chest[in.nextInt()];
				int maxKey = 0;
				//set up a more easily map-based key management
				for(int key=0;key<numkeys;key++){
					int val = in.nextInt();
					keyCol.add(val);
					if(val > maxKey){
						maxKey = val;
					}
				}
				
				for(int c=0;c<chests.length;c++){
					chests[c] = new Chest(in);
					maxKey = Math.max(maxKey, chests[c].getMaxKey());
				}
				keys = new int[maxKey+1]; //+1 to accommodate starting at 1
				for(int j : keyCol){
					keys[j]++;
				}
			}
			int[] res = solve(keys,chests);
			out.print("Case #" + i + ":");
			if(res == null){
				out.println(" IMPOSSIBLE");
			}else{
				for(int j : res){
					out.print(' ');
					out.print(j+1);
				}
				out.println();
			}
		}
	}
	
	private static int[] solve(int[] keys, Chest[] chests) {
		return solve(keys,chests,new boolean[chests.length],0);
	}
	
	private static int[] solve(int[] keys, Chest[] chests, boolean[] open, int depth) {
		for(int i=0;i<chests.length;i++){
			if(!open[i] && chests[i].rewarding() && chests[i].canOpen(keys)){
				chests[i].open(keys);
				open[i] = true;
				int[] res = solve(keys,chests,open,depth+1);
				if(res != null){
					res[depth] = i;
					return res;
				}
				open[i] = false;
				chests[i].close(keys);
			}
		}
		//check for useless chests and pick the first one (lex order)
		return checkUseless(keys,chests,open,depth);
	}
	
	private static int[] checkUseless(int[] keys, Chest[] chests, boolean[] open, int depth) {
		return checkUseless(keys, chests, open, depth, 0);
	}
	
	private static int[] checkUseless(int[] keys, Chest[] chests, boolean[] open, int depth, int i) {
		for(;i<chests.length;i++){
			if(!open[i]){
				if(chests[i].canOpen(keys)){
					chests[i].open(keys);
					open[i] = true;
					int[] res = checkUseless(keys, chests, open, depth+1, i+1);
					if(res != null){
						res[depth] = i;
					}
					return res;
				}else{
					return null;
				}
			}
		}
		//nothing left to open
		return new int[depth];
	}
	
	static class Chest {
		
		private final int openKey;
		private final int[] rewardKeys;
		
		public Chest(Scanner in) {
			openKey = in.nextInt();
			rewardKeys = new int[in.nextInt()];
			for(int i=0;i<rewardKeys.length;i++){
				rewardKeys[i] = in.nextInt();
			}
		}
		
		public boolean canOpen(int[] keys){
			return keys[openKey] > 0;
		}
		
		public boolean rewarding(){
			return rewardKeys.length > 0;
		}
		
		public void open(int[] keys){
			keys[openKey]--;
			for(int i : rewardKeys){
				keys[i]++;
			}
		}
		
		public void close(int[] keys) {
			keys[openKey]++;
			for(int i : rewardKeys){
				keys[i]--;
			}
		}
		
		public int getMaxKey(){
			int max = openKey;
			for(int i : rewardKeys){
				if(i > max){
					max = i;
				}
			}
			return max;
		}
	}
}
