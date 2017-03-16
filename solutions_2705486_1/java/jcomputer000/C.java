import java.util.*;
import java.io.*;
public class C {
	static int count = 0;
	class Trie {
		int ind;
		Trie[] next = new Trie[26];
		boolean end = false;
		Trie() {
			ind = count++;
		}
		void add(String s) {
			add(0,s);
		}
		void add(int pos, String s) {
			if (pos == s.length()) {
				end = true;
				return;
			}
			int c = s.charAt(pos)-'a';
			if (next[c] == null)
				next[c] = new Trie();
			next[c].add(pos+1,s);
		}
	}
	Trie start;
	final int oo = (int)1e9;
	String text;
	HashMap<Integer,Integer>[][] map;
	int foo(int pos, int togo, Trie trie) {
		if (trie == null)
			return oo;
		if (pos == text.length())
			return (trie.end || trie.ind == 0) ? 0 : oo;
		Integer mr = map[pos][togo].get(trie.ind);
		if (mr != null)
			return mr;
		int ret = oo;
		if (trie.end)
			ret = foo(pos,togo,start);
		int c = text.charAt(pos)-'a';
		ret = Math.min(ret,foo(pos+1,Math.max(togo-1,0),trie.next[c]));
		if (togo == 0)
			for (int i=0; i<26; i++)
				if (i!=c)
					ret = Math.min(ret,foo(pos+1,4,trie.next[i])+1);
		map[pos][togo].put(trie.ind,ret);
		return ret;
	}
	C(Scanner in) throws Exception {
		start = new Trie();
		Scanner in2 = new Scanner(new File("garbled_email_dictionary.txt"));
		while(in2.hasNext())
			start.add(in2.next());
		int T = in.nextInt();
		for (int t=0; t<T; t++) {
			text = in.next();
			map = new HashMap[text.length()][5];
			for (HashMap[] x: map)
				for (int i=0; i<x.length; i++)
					x[i] = new HashMap<Integer,Integer>();
			System.out.printf("Case #%d: %d\n",t+1,foo(0,0,start));
		}
	}
	public static void main(String[] args) throws Exception {
		new C(new Scanner(System.in));
	}
}
