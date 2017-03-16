import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeSet;

public class Zad2 {
	
	static class TrieNode{
		TrieNode next[];
		boolean end[];
		
		public TrieNode() {
			next = new TrieNode[26];
			end = new boolean[26];
		}
		
	}
	
	public static void insert(TrieNode root, char c[], int ix){
		if(root.next[c[ix] - 'a'] == null)
			root.next[c[ix] - 'a'] = new TrieNode();
		
		if(ix + 1 == c.length) {
			root.end[c[ix] - 'a'] = true;
			return;
		}
		insert(root.next[c[ix]-'a'], c, ix + 1);
	}
	
	public static void contains(TrieNode r, int ix, char[] str, ArrayList<Integer> lens){
		
		if(ix == str.length) return ;
		
		char c = str[ix];
		
		if(c == '1'){
			for (int i = 0; i < 26; i++) {
				if(r.next[i] != null){
					if(r.end[i] == true)
						lens.add(ix);
					contains(r.next[i], ix + 1, str, lens);
				}
				
			}
		}
		else {
			if(r.next[c-'a'] != null){
				if(r.end[c-'a'] == true){
					lens.add(ix);
				}
				contains(r.next[c-'a'], ix + 1, str, lens);
			}
		}
	}
	
	
	static String ws[] = new String[521196];
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner din = new Scanner(new File("dict.txt"));
		Scanner in = new Scanner(new File("C-small-attempt0 (1).in"));
		PrintWriter out = new PrintWriter(new File("resultC1.out"));
//		Scanner in = new Scanner(System.in);
		
		root = new TrieNode();
		for (int i = 0; i < ws.length; i++) {
			ws[i] = din.next();
			insert(root, ws[i].toCharArray(), 0);
		}
		
		System.out.println("121");
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			
			c = in.next().toCharArray();
			best = 999;
			flag = new int[c.length];
			find(0, -5);
			System.out.println("Case #"+t+": "+best);
			out.println("Case #"+t+": "+best);
		}
		
		out.close();
		
	}
	
	static TrieNode root;
	static int best;
	

	private static void solve() {
		
		int count = 0;
		for (int i = 0; i < flag.length; i++) {
			count += flag[i];
		}
		if(count > best) return ;
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(-1);
		
		int done[] = new int[c.length];
		while(!q.isEmpty()){
			
			int ix = q.poll()+1;
			if(ix >= c.length) break;
			
			char str[] = new char[c.length - ix];
			int p = 0;
			for (int i = ix; i < c.length; i++) {
				str[p] = c[i];
				if(flag[i]==1){
					str[p] = '1';
				}
				p++;
			}
			
			ArrayList<Integer> lens = new ArrayList<Integer>();
			
			contains(root, 0, str, lens);
			
			
			for (int i = 0; i < lens.size();i++) {
				int nex = lens.get(i);
				if(done[ix+nex] == 0){
					done[ix+nex] = 1;
					q.add(ix+nex);
				}
			}
		}
		if(done[done.length - 1] == 1){
			best = count;
		}
		
	}
	
	
	private static void find(int i, int last) {
		if(i == c.length){
			
//			System.out.println(Arrays.toString(flag));
			
			solve();
			
			return ;
		}
		
		find(i+1,last);
		if(i - last >= 5){
			flag[i] = 1;
			find(i+1, i);
			flag[i] = 0;
		}
		
		
	}
	


	static int flag[];
	static char c[];
	

}
