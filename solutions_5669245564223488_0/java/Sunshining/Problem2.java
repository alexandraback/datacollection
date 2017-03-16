package round1c;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;


@SuppressWarnings("unused")
public class Problem2 implements Solution{
	
	String[] words;
	
	@Override
	public String execute(BufferedReader in, PrintWriter log)
			throws IOException {
		// TODO Auto-generated method stub
		in.readLine();
		String line=in.readLine();
		words = line.split("\\s+");
		
		long result=process();
		return " "+Long.toString(result);
	}
	
	long process() {
		if (!trim()) return 0;
		
		int[] permutation = new int[words.length];
		int[] finishedState = new int[words.length];
		for (int i=0;i<permutation.length;++i){
			permutation[i]=i;
			finishedState[i]=permutation.length-1-i;
		}
		
		long count=0;
		while (true) {
			if (isAValidTrain(permutation)) count++;
			if (Arrays.equals(permutation, finishedState))break;
			nextLarge(permutation);
		}
			
		return count;
	}
	
	long count=0;

	void backTrack() {
		
	}
	
	
	boolean isAValidTrain(int[] permutation) {
		StringBuilder str = new StringBuilder();
		for (int i=0;i<words.length;++i) {
			str.append(words[permutation[i]]);
		}
		String train=str.toString();
		
		Map<Character, TreeSet<Integer>> table = new HashMap<Character, TreeSet<Integer>>();
		for (int i = 0;i<train.length();++i) {
			if (!table.containsKey(train.charAt(i))) {
				TreeSet<Integer> indexSet = new TreeSet<Integer>();
				indexSet.add(i);
				table.put(train.charAt(i), indexSet);
			} else {
				table.get(train.charAt(i)).add(i);
			}
		}
		
		Set<Character> keys=table.keySet();
		for (char key : keys) {
			TreeSet<Integer> indexSet = table.get(key);
			int small = indexSet.first();
			int large = indexSet.last();
			if (indexSet.size()-1 !=large-small) return false;
		}
		
		return true;
	}
	
	void nextLarge(int[] permutation) {
		int cur = permutation.length-1;
		while (cur >0) {
			if (permutation[cur-1]>permutation[cur]) cur--;
			else break;
		}
		
		// insertion
		for (int i=permutation.length-1; i>=cur;--i) {
			if (permutation[i]>permutation[cur-1]) {
				int tmp = permutation[cur-1];
				permutation[cur-1]=permutation[i];
				permutation[i]=tmp;
				break;
			}
		}
		
		int i = permutation.length-1;
		int j = cur;
		while (i>j) {
			int tmp = permutation[i];
			permutation[i]=permutation[j];
			permutation[j]=tmp;
			i--;
			j++;
		}
		
	}
	
	boolean trim() {
		trimBoundary();
		
		ArrayList<Set<Character>> list = new ArrayList<Set<Character>>();
		String[] trimmedWords=new String[words.length];
		for (int i = 0;i<words.length;++i) {
			if (!isWordValid(words[i])) return false;
			StringBuilder tmp = new StringBuilder();
			tmp.append(words[i].charAt(0));
			if (words[i].length()>1) {
				tmp.append(words[i].charAt(words[i].length()-1));
				Set<Character> count = new HashSet<Character>();
				for (int j=1; j<words[i].length()-1;++j) {
					count.add(words[i].charAt(j));
				}
				list.add(count);
			}
			trimmedWords[i]=tmp.toString();
		}
		
		
		words=trimmedWords;
		return isTrainComponentsValid(list);
	}
	
	boolean isWordValid(String word) {
		if (word.length()<=2)  return true;
		
		Map<Character, TreeSet<Integer>> indexSet = new HashMap<Character, TreeSet<Integer>>();
		for (int i=1;i<word.length()-1;++i) {
			TreeSet<Integer> index = new TreeSet<Integer>();
			if (!indexSet.containsKey(word.charAt(i))) {
				
				index.add(i);
				indexSet.put(word.charAt(i), index);
			}else {
				indexSet.get(word.charAt(i)).add(i);
			}
		}
		
		Set<Character> keys = indexSet.keySet();
		for (char key : keys) {
			TreeSet<Integer> set=indexSet.get(key);
			int small = set.first();
			int large = set.last();
			if (large-small!=set.size()-1) return false;
		}
		return true;
	}
	
	boolean isTrainComponentsValid(ArrayList<Set<Character>> list) {
		Set<Character> boundarySet = new HashSet<Character>();
		for (int i=0;i<words.length;++i) {
			boundarySet.add(words[i].charAt(0));
			if (words.length>1) boundarySet.add(words[i].charAt(words[i].length()-1));
		}
		
		for (int i=0;i<list.size();++i) {
			Set<Character> setI = list.get(i);
			for (char c:setI) {
				if (boundarySet.contains(c)) return false;
			}
		}
		
		
		
		
		Set<Character> table = new HashSet<Character>();
		for (int i=0;i<list.size();++i) {
			Set<Character> component = list.get(i);
			for (char c : component) {
				if (table.contains(c)) return false;
				table.add(c);
			}
		}
		
		return true;
	}
	
	void trimBoundary() {
		String[] trimmedWords = new String[words.length];
		
		for(int i=0;i<words.length;++i) {
			trimmedWords[i]=trimOneWord(words[i]);
		}
		
		words=trimmedWords;
	}
	
	String trimOneWord(String word) {
		if (word.length()==1) return word;
		int i = 1;
		for (; i<word.length()&&word.charAt(i)==word.charAt(i-1);++i);
		
		if (i==word.length()) return word.substring(0, 1);
		
		int j = word.length()-1;
		for (;j>0&&word.charAt(j)==word.charAt(j-1);--j);
		
		StringBuilder trimmedWord=new StringBuilder();
		trimmedWord.append(word.charAt(0));
		for (int k=i;k<j;++k){
			trimmedWord.append(word.charAt(k));
		}
		trimmedWord.append(word.charAt(word.length()-1));
		
		return trimmedWord.toString();
	}
}
