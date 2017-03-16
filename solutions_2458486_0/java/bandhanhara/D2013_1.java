import java.util.ArrayList;
import java.util.Collections;
import java.util.ConcurrentModificationException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


public class D2013_1 {
	public static List<String> result;
	private static boolean closed = false;
	/**
	 * @param args
	 */
	public static void main(String args[]) {
		
		Scanner scn = new Scanner(System.in);

		int T = scn.nextInt();
		int K = 0;
		int N = 0;
		int k;
		int n = 0;
		int fk = 0;
		List<Integer> foundKeys;
		for (int t = 1; t <= T; t++) {
			
			result = new ArrayList<String>();
			List<Integer> keys = new ArrayList<Integer>();
			List<Integer> chestKey = new ArrayList<Integer>();
			List<List<Integer>> chests = new ArrayList<List<Integer>>();
			
			K = scn.nextInt();
			N = scn.nextInt();
			
			for (int i=0;i<K;i++){
				k = scn.nextInt();
				keys.add(k);
			}
			
			for (int i=0;i<N;i++){
				
				n = scn.nextInt();
				k = scn.nextInt();
				chestKey.add(n);
				
				foundKeys = new ArrayList<Integer>();
				
				for(int j=0;j<k;j++){
					fk = scn.nextInt();
					
					foundKeys.add(fk);
					
				}
				
				chests.add(foundKeys);
			}
			
			for (int i=0;i<chests.size();i++) {
				int key = chestKey.get(i);
				int keyIndex = getFirstIndex(keys, key);
				if(keyIndex==-1)
					continue;
				closed = false;
				process(keys, chestKey, chests, new ArrayList<Integer>(), i);
			}

			
			if(result.isEmpty())
				System.out.println("Case #" + t + ": IMPOSSIBLE");
			else{
				Collections.sort(result);
				System.out.println("Case #" + t + ": "+result.get(0));
			}

		}
	}
	
	private static void process(List<Integer> keysp, List<Integer> chestKey, List<List<Integer>> chests, List<Integer> openedChestp, int openNow){
		if(result.isEmpty()==false){
			closed = true;
			return;
		}
		
		if(closed)
			return;
		
		List<Integer> keys = new ArrayList<Integer>();
		List<Integer> openedChest = new ArrayList<Integer>();
		openedChest.addAll(openedChestp);
		keys.addAll(keysp);

		
		openedChest.add(openNow);
		
		if(openedChest.size() == chests.size()){
			String resultStr = "";
			for (int index : openedChest) {
				resultStr +=" "+(index+1);
			}
			
			result.add(resultStr.trim());
			closed = true;
			return;
		}else{
			
			keys.remove(getFirstIndex(keys, chestKey.get(openNow)));
			
			keys.addAll(chests.get(openNow));
			
			if(keys.isEmpty()){
				closed = true;
				return;
			}
			
			for(int i=0;i<chests.size();i++){
				if(closed)
					return;
				int openedIndex = getFirstIndex(openedChest, i);
				if(openedIndex != -1)
					continue;
				
				int keyIndex = getFirstIndex(keys, chestKey.get(i));
				if(keyIndex==-1)
					continue;
				
				process(keys, chestKey, chests, openedChest, i);
			}
			
			closed = true;
		}
	}
	
	
	private static int getFirstIndex(List<Integer> keys, int key){
		for(int i=0;i<keys.size();i++){
			if(keys.get(i).intValue()==key)
				return i;
		}
		return -1;
	}
	
}


