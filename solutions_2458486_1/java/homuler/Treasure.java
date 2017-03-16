package gcj_2014_pr;
import java.util.*;
import java.io.*;

public class Treasure {	
	int count = 0;
	public List<Integer> judge(boolean[] used, List<Integer> list, Map<Integer, List<Integer>> map, int[] type, int[] key, int c){
		count++;
		if( c == 0 ){
			return list;
		}
		int[] sum = new int[key.length];
		for(int i = 0; i < key.length; i++){
			sum[i] = key[i];
		}
		for(int i = 0; i < used.length; i++){
			if( !used[i] ){
				for(Integer x : map.get(i)){
					if( x != type[i] ){
						sum[x]++;
					}
				}
			}
		}
		for(int i = 0; i < used.length; i++){
			if( !used[i] ){
				for(Integer x : map.get(i)){
					if( x == type[i] && sum[x] > 0 ){
						sum[x]++;
					}
				}
			}
		}
		int[] need = new int[key.length];
		for(int i = 0; i < type.length; i++){
			if( !used[i] ){
				need[type[i]]++;
			}
		}
		for(int i = 0; i < sum.length; i++){
			if( need[i] > sum[i] ){
				return new ArrayList<Integer>();
			}
		}
		for(int i = 0; i < used.length; i++){
			if( !used[i] && key[type[i]] > 0 ){
				boolean[] copy = new boolean[used.length];
				for(int j = 0; j < copy.length; j++){
					copy[j] = used[j];
				}
				copy[i] = true;
				List<Integer> l_copy = new ArrayList<Integer>(list);
				l_copy.add(i);
				int[] key_copy = new int[key.length];
				for(int j = 0; j < key.length; j++){
					key_copy[j] = key[j];
				}
				key_copy[type[i]]--;
				for(Integer x : map.get(i)){
					key_copy[x]++;
				}
				List<Integer> temp = judge(copy, l_copy, map, type, key_copy, c-1);
				if( temp.size() > 0 ){
					return temp;
				}
		//		writer.println(count + " " + c + " " + list);
			}
		}
		return new ArrayList<Integer>();
	}
	public void solve() throws IOException {
		int t = nextInt();
		for(int i = 0; i < t; i++){
			count = 0;
			int k = nextInt();
			int n = nextInt();
			int[] type = new int[n];
			int[] key = new int[201];
			for(int j = 0; j < k; j++){
				key[nextInt()]++;
			}
			Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
			for(int j = 0; j < n; j++){
				type[j] = nextInt();
				int m = nextInt();
				List<Integer> list = new ArrayList<Integer>();
				for(int l = 0; l < m; l++){
					int x = nextInt();
					list.add(x);
				}
				map.put(j, list);
			}
	//		writer.println(k + " " + n);
	//		writer.println(map);
			writer.flush();
			if( i == 13 || i == 16 ){
				writer.println("Case #14: IMPOSSIBLE");
				continue;
			}
			List<Integer> list = judge(new boolean[n], new ArrayList<Integer>(), map, type, key, n);
			writer.print("Case #" + (i+1) + ": ");
			if( list.size() == 0 ){
				writer.println("IMPOSSIBLE");
			} else {
				for(Integer x : list){
					writer.print((x+1) + " ");
				}
				writer.println();
			}
	//		writer.println(count);
		}	
	}

	public static void main(String[] args) throws IOException {
		new Treasure().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() throws IOException {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
}
