import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class C {
	static class Node {
		Node[] next;
		boolean tag;
		public Node(){
			next = new Node[26];
			tag = false;
		}
	}
	static Node insert(Node curr, String str) {
		if (curr == null) {
			curr = new Node();
		}
		if (str.length() == 0) {
			curr.tag = true;
			return curr;
		}
		else {
			int c = str.charAt(0) - 'a';
			curr.next[c] = insert(curr.next[c], str.substring(1));
			return curr;
		}
	}
	static boolean contains(Node curr, String str) {
		if (curr == null) {
			return false;
		}
		else if (str.length() == 0) {
			return curr.tag;
		}
		else {
			String kapos = str.substring(1);
			int c = str.charAt(0);
			if (c == '.') {
				for (int i = 0; i < 26; i++) {
					if (contains(curr.next[i], kapos)) {
						return true;
					}
				}
				return false;
			}
			else {
				c -= 'a';
				return contains(curr.next[c], str.substring(1));
			}
		}
	}
	static int sagot(int l, int pos) {
		if (l >= str.length()) {
			return 0;
		}
		if (pos < 0) {
			if (extra[l] < 0) {
				int min = 1000;
				for (int len = 1; len <= Math.min(10, str.length()-l); len++) {
					String curr = str.substring(l, l+len);
					if (contains(root, curr)) {
						min = Math.min(min, sagot(l+len, -1));
					}
					else {
						// contains 1
						for (int i = 0; i < len; i++) {
							String nu = curr.substring(0,i)+"."+curr.substring(i+1);
							if (contains(root, nu)) {
								min = Math.min(min, 1+sagot(l+len, len-i >=  5 ? -1 : len-i));
							}
						}
						// contains 2
						for (int j = 0; j < len; j++) {
							for (int i = j-5; i >= 0; i--) {
								String nu = curr.substring(0,i)+"."+curr.substring(i+1,j)+"."+curr.substring(j+1);
								if (contains(root, nu)) {
									min = Math.min(min, 2+sagot(l+len, len-j >= 5 ? -1 : len-j));
									j = 100;
									break;
								}
							}
						}

					}
				}
				extra[l] = min;
			}
			return extra[l];
		}
		else {
			if (dp[l][pos] < 0) {
				int min = 1000;
				for (int len = 1; len <= Math.min(10,str.length()-l); len++) {
					String curr = str.substring(l, l+len);
					if (contains(root, curr)) {
						min = Math.min(min, sagot(l+len, len+pos >= 5 ? -1 : pos));
					}
					else {
						// contains 1
						for (int i = 5-pos; i < len; i++) {
							String nu = curr.substring(0,i)+"."+curr.substring(i+1);
							if (contains(root, nu)) {
								min = Math.min(min, 1+sagot(l+len, len-i >= 5 ? -1 : len-i));
							}
						}
						// contains 2
						for (int j = 0; j < len; j++) {
							for (int i = j-5; i >= 5-pos; i--) {
								String nu = curr.substring(0,i)+"."+curr.substring(i+1,j)+"."+curr.substring(j+1);
								if (contains(root, nu)) {
									min = Math.min(min, 2+sagot(l+len, len-j >= 5 ? -1 : len-j));
									j = 100;
									break;
								}
							}
						}

					}
				}
				dp[l][pos] = min;
			}
			return dp[l][pos];
		}
	}
	static int[][] dp = null;
	static int[] extra = null;
	static String str = null;
	static Node root = null;
	public static void main(String[] args) throws Exception{
		Scanner s1 = new Scanner(new File("garbled_email_dictionary.txt"));
		root = new Node();
		while (s1.hasNext()) {
			root = insert(root, s1.next());
		}
		Scanner sc = new Scanner(in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			str = sc.next();
			dp = new int[str.length()+1][20];
			extra = new int[str.length()+1];
			for (int j = 0; j < str.length()+1; j++) {
				Arrays.fill(dp[j], -1);
			}
			Arrays.fill(extra, -1);
			out.printf("Case #%d: %d\n", i+1, sagot(0, -1));
		}


		// out.println(contains(root,"aaaamau"));
		// out.println(contains(root,"aaaan"));
		// out.println(contains(root,"zuebef"));
		// out.println(contains(root,"yozff"));
		// out.println(contains(root,"abdomenxi"));

		// out.println(contains(root,"aaacd"));
		// out.println(contains(root,"aaoen"));
		// out.println(contains(root,"abdomenxin"));
		// out.println(contains(root,"aab"));
	}
}