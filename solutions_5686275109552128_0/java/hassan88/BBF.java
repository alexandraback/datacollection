import java.io.*;
import java.util.*;

public class BBF {
	static int[] best = {0,0,0,0,2,2,3,3,4,3};
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("B-small-attempt2.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("B-small2.out"));
		int cases = Integer.parseInt(br.readLine().trim());
		for (int c = 1; c <= cases; c++) {
			int D = Integer.parseInt(br.readLine().trim());
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line);
			
			TreeMap <Integer, Integer> elements = new TreeMap<Integer, Integer>();
			for(int i = 0;i < D;i++) {
				int curr = Integer.parseInt(st.nextToken());
				add(elements, curr, 1);
			}
			int ma = elements.lastKey(), res= getBest(elements, 0);
			if(res > ma)
				throw new IOException();
			out.println("Case #" + c + ": " + res);
		}
		out.close();
	}
	public static int getBest(TreeMap <Integer, Integer> elements, int soFar) {
		int max = elements.lastKey();
		if(soFar==9)return max==0?9:100;
		//if(max==9 && elements.get(9) >= 4)return 9;
		if(max <= 3)
			return max;
		TreeMap<Integer, Integer> cl = clone(elements);
		cl = firstOp(cl);
		int res = Integer.MAX_VALUE;
		if(max==9) {
			TreeMap<Integer, Integer> cl1 = clone(elements);
			int first = 4, second = 5;
			remove(cl1, max);
			add(cl1, first, 1);
			add(cl1, second, 1);
			res = Math.min(res, getBest(cl1, soFar+1)+1);
		}
		int first = best[max], second = max-first;
		remove(elements, max);
		add(elements, first, 1);
		add(elements, second, 1);
		res = Math.min(res, getBest(elements, soFar+1)+1);		
		return Math.min(getBest(cl, soFar+1)+1, res);
	}
	public static TreeMap<Integer, Integer> firstOp(TreeMap<Integer, Integer> elements) {
		Set<Integer> keys = elements.keySet();
		TreeMap<Integer, Integer> ret = new TreeMap<Integer, Integer>();
		for(int k:keys) {
			if(k==1)continue;
			add(ret, k-1, elements.get(k));
		}
		return ret;
	}
	public static void remove(TreeMap<Integer, Integer> elements, int key) {
		int cnt = elements.get(key);
		if(cnt == 1)
			elements.remove(key);
		else
			elements.put(key, cnt-1);
	}
	public static void add(TreeMap<Integer, Integer> elements, int key, int cnt) {
		if(elements.containsKey(key))
			cnt += elements.get(key);
		elements.put(key, cnt);
	}
	public static TreeMap<Integer, Integer> clone(TreeMap<Integer, Integer> inp) {
		TreeMap<Integer, Integer> ret = new TreeMap<Integer, Integer>();
		Set<Integer> keys = inp.keySet();
		for(int k:keys) 
			ret.put(k, inp.get(k));
		return ret;
	}
}