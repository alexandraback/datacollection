package RC;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	static String zip(String str) {//連続する文字を一つにする
		StringBuilder res = new StringBuilder();
		char bef = '!';
		for(int i = 0; i < str.length(); i++) {
			if(str.charAt(i) != bef) {
				res.append(str.charAt(i));
				bef = str.charAt(i);
			}
		}
		return res.toString();
	}

	static int fuck(String str[]) {
		return (rec(0, str, new boolean[str.length], ""));
	}
	
	static int rec(int cnt, String str[], boolean used[], String res) {
		if(cnt == str.length) {
			for(int i = 0; i < 26; i++) {
				boolean up = false;
				int ucnt = 0;
				for(int j = 0; j < res.length(); j++) {
					if(!up && res.charAt(j) == ('a'+i)) {
						up = true;
						ucnt++;
					} else if(up && res.charAt(j) != ('a'+i)) {
						up = false;
					}
				}
				if(ucnt > 1) {
					return 0;
				}
			}
			return 1;
		}
		
		int ans = 0;
		for(int i = 0; i < str.length; i++) {
			if(used[i] == false) {
				used[i] = true;
				ans += rec(cnt+1, str, used, res+str[i]);
				used[i] = false;
			}
		}
		return ans;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B-small-attempt2.in"));
		PrintWriter pw = new PrintWriter(new File("outB_Small2"));
//				Scanner sc = new Scanner(System.in);
//				PrintWriter pw = new PrintWriter(System.out);

		//階乗の計算
		long F[] = new long[111];
		F[0] = 1;
		long MOD = 1000000007;
		for(int i = 1; i < F.length; i++) {
			F[i] = (F[i-1]*(long)i)%MOD;
		}

		int T = sc.nextInt();
		L:for(int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			String[] s = new String[N];
			for(int i = 0; i < N; i++) {
				s[i] = zip(sc.next());
			}
			
			pw.println("Case #"+t+": "+fuck(s));
			if(true)continue;
			if(N == 1) {
				pw.println("Case #"+t+": "+1);
				continue L;
			}

			//同じ文字が，同じ電車に，２回以上登場したらダメ aba
			for(int i = 0; i < N; i++) {
				int cnt[] = new int[26];
				for(int j = 0; j < s[i].length(); j++) {
					cnt[s[i].charAt(j) - 'a']++;
				}
				for(int j = 0; j < cnt.length; j++) {
					if(cnt[j] > 1) {
						pw.println("Case #"+t+": "+0);
						continue L;
					}
				}
			}

			//真ん中に出てくる文字は，１回のみの登場が許される abc b
			{
				boolean center[] = new boolean[26];
				for(int i = 0; i < s.length; i++) {
					for(int j = 1; j < s[i].length()-1; j++) {
						center[s[i].charAt(j) - 'a'] = true;
					}
				}

				int cnt[] = new int[26];
				for(int i = 0; i < s.length; i++) {
					for(int j = 0; j < s[i].length(); j++) {
						cnt[s[i].charAt(j) - 'a']++;
					}
				}

				for(int i = 0; i < 26; i++) {
					if(center[i] && cnt[i] > 1) {
						pw.println("Case #"+t+": "+0);
						continue L;
					}
				}
			}

			//長さ２以上で，同じ先頭のもの，同じ末尾のものが存在したらだめ ab ac, ba bc
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(i == j)
						continue;
					if(s[i].length() == 1 || s[j].length() == 1)
						continue;

					if(s[i].charAt(0) == s[j].charAt(0) ||
							s[i].charAt(s[i].length()-1) == s[j].charAt(s[j].length()-1)) {
						pw.println("Case #"+t+": "+0);
						continue L;
					}
				}
			}


			//長さ１と２以上に分離
			int len1[] = new int[26];
			ArrayList<String> len2 = new ArrayList<String>();
			for(int i = 0; i < N; i++) {
				if(s[i].length() == 1) {
					len1[s[i].charAt(0) - 'a']++;
				} else {
					len2.add(s[i]);
				}
			}

			//長さ２以上で，ヘッド，テイルをくっつける．
			for(char c = 'a'; c <= 'z'; c++) {
				int headC = -1;
				int tailC = -1;
				for(int i = 0; i < len2.size(); i++) {
					if(len2.get(i).charAt(0) == c) {
						headC = i;
					} else if(len2.get(i).charAt(len2.get(i).length()-1) == c) {
						tailC = i;
					}
				}

				if(headC != -1 && tailC != -1) {
					ArrayList<String> nlen2 = new ArrayList<String>();
					for(int i = 0; i < len2.size(); i++) {
						if(i == headC || i == tailC)
							continue;
						nlen2.add(len2.get(i));
					}
					String add = len2.get(tailC) + len2.get(headC).substring(1);
					nlen2.add(add);
					len2 = nlen2;
				}
			}

			//列車ごとにパターン数を計算(長さ2以上+長さ1以上で合成できる奴)
			boolean appd[] = new boolean[26];
			ArrayList<Long> pat = new ArrayList<Long>();
			for(int i = 0; i < len2.size(); i++) {
				String str = len2.get(i);
				long num = 1;
				for(int j = 0; j < str.length(); j++) {
					appd[str.charAt(j) - 'a'] = true;
					num = (num * F[len1[str.charAt(j) - 'a']])%MOD;
				}
				pat.add(num);
			}

			//長さ1で独立している奴の対処 a a ab c c cでいうc
			for(int i = 0; i < 26; i++) {
				if(appd[i] == false && len1[i] > 0) {//長さ１のはいくつかあるが，今までに連結されていないやつ
					pat.add(F[len1[i]]);
				}
			}

			long ans = F[pat.size()];//各連結成分の並べ方
			for(int i = 0; i < pat.size(); i++) {
				ans = (ans * pat.get(i))%MOD;//各連結成分のパターンをかける
			}

			pw.println("Case #"+t+": "+ans);
		}

		pw.flush();
	}
}
