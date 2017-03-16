package codejam.CJ2016.R1B;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class R1BC {
	
	private static class Word {
		public List<Integer> unrestrained;
		public List<Integer> unique;
		
		public Word(){
			unrestrained = new LinkedList<>();
			unique = new LinkedList<>();
		}
		
		public boolean makeUnique(int k) {
			if (unrestrained.contains(k)) {
				unrestrained.remove(Integer.valueOf(k));
				return unique.add(k);
			}
			return false;
		}
		
		public int freedom() {
			if (unique.isEmpty()) {
				return unrestrained.size()-1;
			} else {
				return unrestrained.size();
			}
		}
		
		public int count(){
			return unrestrained.size() + unique.size();
		}
	}
	
	public static void main(String[] args){
		try(Scanner in = new Scanner(System.in)) {
			int t = in.nextInt();
			for(int i=1; i<=t; i++){
				int n = in.nextInt();
				String[][] titles = new String[n][2];
				for (int k = 0; k<n; k++) for (int j = 0; j<2; j++){
					titles[k][j] = in.next();
				}
				boolean[] isUnique = new boolean[n];
				for (int k = 0; k < n; k++) {
					isUnique[k] = false;
				}
				HashMap<String, Word> firstMap = new HashMap<>();
				HashMap<String, Word> secondMap = new HashMap<>();
				for (int k = 0; k<n; k++) {
					if (!firstMap.containsKey(titles[k][0])) {
						firstMap.put(titles[k][0], new Word());
					}
					firstMap.get(titles[k][0]).unrestrained.add(k);
					if (!secondMap.containsKey(titles[k][1])) {
						secondMap.put(titles[k][1], new Word());
					}
					secondMap.get(titles[k][1]).unrestrained.add(k);
				}
				for (Word word : firstMap.values()) {
					if (word.count()==1) {
						if (!word.unrestrained.isEmpty()) {
							int k = word.unrestrained.get(0);
							word.makeUnique(k);
							isUnique[k] = true;
							secondMap.get(titles[k][1]).makeUnique(k);
						}
					}
				}
				for (Word word : secondMap.values()) {
					if (word.count()==1) {
						if (!word.unrestrained.isEmpty()) {
							int k = word.unrestrained.get(0);
							word.makeUnique(k);
							isUnique[k] = true;
							firstMap.get(titles[k][0]).makeUnique(k);
						}
					}
				}
				int freedom1 = 0;
				int freedom2 = 0;
				for (Word word : firstMap.values()) {
					freedom1 += word.freedom();
				}
				for (Word word : secondMap.values()) {
					freedom2 += word.freedom();
				}
				if (freedom2 < freedom1) {
					freedom1 = freedom2;
				}
				
				System.out.print("Case #" + i + ": ");
				System.out.print(freedom1);
				System.out.println();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
