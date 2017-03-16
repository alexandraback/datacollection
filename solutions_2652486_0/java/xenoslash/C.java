package round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class C {
	static int R;
	static int N;
	static int M;
	static int K;
	//key = permutation, value = possible products
	static Map<String, Set<Integer>> products;
	public static void main(String[] args) throws Exception{	
		//BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter out = new PrintWriter(System.out);
	   
		BufferedReader f = new BufferedReader(new FileReader("C-small-1-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		f.readLine();
		products = new HashMap<String, Set<Integer>>();
		StringTokenizer tkz = new StringTokenizer(f.readLine());
		R = Integer.parseInt(tkz.nextToken());
		N = Integer.parseInt(tkz.nextToken());
		M = Integer.parseInt(tkz.nextToken());
		K = Integer.parseInt(tkz.nextToken());
		out.println("Case #1:");
		genTable(0,new int[N]);
		for(int i=1;i<=R;i++){
			tkz = new StringTokenizer(f.readLine());
			int[] targetProds = new int[K];
			for(int j=0;j<K;j++){
				targetProds[j] = Integer.parseInt(tkz.nextToken());
			}
			
			String bestString = null;
			int maxCount = 0;
			Map<String, Integer> count = new HashMap<String, Integer>();
			
			for(String choices : products.keySet()){
				boolean isGood = true;
				Set<Integer> myProds = products.get(choices);
				for(int target: targetProds){
					if(!myProds.contains(target)){
						isGood = false;
						break;
					}
				}
				
				int[] sorted = new int[choices.length()];
				if(isGood){
					for(int c = 0; c<choices.length();c++){
						sorted[c] = choices.charAt(c)-'0';
					}
					Arrays.sort(sorted);
					StringBuffer realKey = new StringBuffer();
					for(int item:sorted){
						realKey.append(item);
					}
					String realKeyStr = realKey.toString();
					
					Integer occ = count.get(realKey);
					if(occ == null){
						count.put(realKeyStr, 1);
					}else{
						count.put(realKeyStr, occ + 1);
					}
					
					int finalCount = count.get(realKeyStr);
					if(finalCount > maxCount){
						maxCount = finalCount;
						bestString = realKeyStr;
					}
				}
			}
			out.println(bestString);
		}
		out.close();
	}
	
	public static void genTable(int toSet, int[] built){
		if(toSet == built.length){
			StringBuffer key = new StringBuffer();
			for(int i=0;i<built.length;i++){
				key.append(built[i]);
			}
			genProducts(0, built, 1, key.toString());
		}else{
			for(int i=2;i<=M;i++){
				built[toSet] = i;
				genTable(toSet+1,built);
			}
		}
	}
	
	public static void genProducts(int toSet, int[] nums, int result, String key){
		if(toSet == nums.length){
			Set<Integer> prods = products.get(key);
			if(prods == null){
				prods = new HashSet<Integer>();
				products.put(key, prods);
			}
			prods.add(result);
		}else{
			genProducts(toSet+1, nums, result*nums[toSet], key);
			genProducts(toSet+1, nums, result, key);
		}
		
	}
	
	
public static class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(String s) {
		try {
			br = new BufferedReader(new FileReader(s));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}

}
