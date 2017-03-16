import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;
import java.util.Map.Entry;
import java.util.StringTokenizer;

import javax.management.RuntimeErrorException;


public class FindTreasure {

	int chestsCnt;
	ArrayList<Integer> openWith;
	ArrayList<ArrayList<Integer>> keysInside;
	int[] myKeys;
	int maxKey;
	
	boolean stop;
	Stack<Integer> opened;
	
	public FindTreasure(ArrayList<Integer> myKeys,
			ArrayList<Integer> openWith,
			ArrayList<ArrayList<Integer>> keysInside)
	{
		this.openWith = openWith;
		this.keysInside = keysInside;
		
		chestsCnt = openWith.size();
		if (chestsCnt != keysInside.size()) {
			throw new RuntimeException("wrong input");
		}		
		System.out.println("Chests: " + chestsCnt);
		
		maxKey = Math.max(Collections.max(openWith),Collections.max(myKeys));
		for (int chest = 0; chest < chestsCnt; chest += 1) {
			if (keysInside.get(chest).size() > 0) {
				maxKey = Math.max(maxKey, Collections.max(keysInside.get(chest)));
			}
		}		
		System.out.println("Max key: " + maxKey);
		
		this.myKeys = new int[maxKey+1];
		for (int key : myKeys) {
			this.myKeys[key] += 1;
		}
	}

	public static void main(String[] args) throws IOException {

		String name = "D-large";
		String path = "C:\\Users\\dbu\\Downloads\\";
		
		String text = TextReader.read(path + name + ".in");
		PrintStream out = new PrintStream(new File(path + name + ".out"));
		
		StringTokenizer tokenizer = new StringTokenizer(text);
		int T = Integer.parseInt(tokenizer.nextToken());
		System.out.println("T = " + T);
		System.out.println("======");
		for (int t = 0; t < T; t += 1) {

			System.out.println("CASE #" + (t+1));
			System.out.println();
			
			int keysCnt = Integer.parseInt(tokenizer.nextToken());
			int chestCnt = Integer.parseInt(tokenizer.nextToken());
			System.out.println("we have " + keysCnt + " keys");	
			System.out.println("need open " + chestCnt + " chests");
			
			ArrayList<Integer> myKeys = new ArrayList<Integer>();
			System.out.print("keys = ");
			for (int k = 0; k < keysCnt; k+=1) {
				int key = Integer.parseInt(tokenizer.nextToken());
				System.out.print(key + " ");
				myKeys.add(key);
			}
			System.out.println();
			
			ArrayList<ArrayList<Integer>> keysInside = new ArrayList<ArrayList<Integer>>();
			ArrayList<Integer> openWith = new ArrayList<Integer>();
			for (int i = 0; i < chestCnt; i+=1) {
				int type = Integer.parseInt(tokenizer.nextToken());
				openWith.add(type);				
				int keysInsideNo = Integer.parseInt(tokenizer.nextToken());
				System.out.print("Chest #"+(i+1)+": open with = " + type + ", keys inside = ");
				ArrayList<Integer> keysInsideChest = new ArrayList<Integer>();
				for (int j = 0; j < keysInsideNo; j += 1) {
					int key = Integer.parseInt(tokenizer.nextToken());
					keysInsideChest.add(key);
					System.out.print(key + " ");
				}
				keysInside.add(keysInsideChest);
				System.out.println();
			}

			////
			
			if (t+1==4 || t+1==13) continue;
			
			
			FindTreasure findTreasure = new FindTreasure(myKeys, openWith, keysInside);
			Stack<Integer> opened = findTreasure.find();
			
			String result = "Case #"+(t+1)+": ";
			if (opened == null) {
				result += "IMPOSSIBLE";
			} else if (opened.size() == chestCnt) {
				for (Integer c : opened) {
					result += (c+1) + " ";
				}
			} else {
				result += "IMPOSSIBLE";
			}
			out.println(result);
			System.out.println();
			System.out.println(result);
			
			System.out.println("-------");
		}
		
		out.close();
	}

	public Stack<Integer> find() {
		
		stop = false;
		opened = new Stack<Integer>();
		if (!blockedSituation1()) {
			findTreasure();		
		}
		return opened;
	}
	
	private void findTreasure() {
		if (stop) return;
		
		for (int chest = 0; chest < chestsCnt; chest += 1) {
			
			if (!opened.contains(chest))
			{
			
				int chestKey = openWith.get(chest);
				
				if (canOpenWithKey(chestKey)) {
					
					//System.out.println(chest+1);
					
					openWithKey(chestKey);
					takeKeys(chest);
					opened.push(chest);
					
					if (opened.size() == chestsCnt) {
						stop = true;
						return;
					}
					
					if (!blockedSituation()) 
					{
						findTreasure();
					} 
					
					if (stop) {
						return;
					}
					
					closeWithKey(chestKey);
					returnKeys(chest);
					opened.pop();
					
					//System.out.println("-");
					
					//System.out.println(opened.size());
				}
			}
			
		}
	}
	
	
	private boolean blockedSituation() {
//		for (int key = 0; key <= maxKey; key+=1) {
//			System.out.print(myKeys[key] + " ");
//		}
//		System.out.println();
		for (int chestValidate = 0; chestValidate < chestsCnt; chestValidate +=1) {
			if (!opened.contains(chestValidate)) {
				
//				System.out.println("validate "+(chestValidate+1));
				
				int chestKey = openWith.get(chestValidate);
				if (myKeys[chestKey] > 0) continue;
				
				boolean no = true;
				for (int chestLocked = 0; chestLocked < chestsCnt; chestLocked +=1) {
					if (!opened.contains(chestLocked) && chestLocked != chestValidate) {
						
//						System.out.println(" locked "+(chestLocked+1));
								
						
						ArrayList<Integer> list = keysInside.get(chestLocked);
						if (list.contains(chestKey)) {
							no = false;
						}
					}
				}
				if (no) {
//					System.out.println("Blocked");
					return true;
				}
			}
		}
		
		return false;
	}

	
	private boolean blockedSituation1() {
		
		int[] test = new int[maxKey+1];
		for (int key = 0; key <= maxKey; key+=1) {
			test[key] = myKeys[key];
		}		
		for (int chest = 0; chest < chestsCnt; chest +=1) {
			for (int key : keysInside.get(chest)) {
				test[key] += 1;
			}
			test[openWith.get(chest)] -= 1;
		}
		for (int key = 0; key <= maxKey; key+=1) {
			if (test[key] < 0) {
				return true;
			}
		}
		return false;
	}

	boolean canOpenWithKey(int key)
	{
		return myKeys[key] > 0;
	}
	
	void openWithKey(int key)
	{
		myKeys[key] -= 1;;
	}
	
	void closeWithKey(int key)
	{
		myKeys[key] += 1;;
	}
	
	void takeKeys(int chest)
	{	
		ArrayList<Integer> keysInChest =  keysInside.get(chest);
		for (Integer key : keysInChest) {
			myKeys[key] += 1;
		}
	}
	
	void returnKeys(int chest)
	{	
		ArrayList<Integer> keysInChest =  keysInside.get(chest);
		for (Integer key : keysInChest) {
			myKeys[key] -= 1;
		}
	}
}
