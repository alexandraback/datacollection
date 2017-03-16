import static java.lang.System.in;
import static java.lang.System.out;

import java.io.*;
import java.util.*;

public class ReorderingCars {
	static final double EPS = 1e-10;
	static final double INF = 1 << 31;
	static final double PI = Math.PI;

	public static BufferedReader in;
	public static PrintWriter out;

	StringBuilder sb = new StringBuilder();


	public void run() throws IOException {
		in =new BufferedReader(new FileReader("in.txt"));
		out=new PrintWriter(new FileWriter("out.txt"));
		long m = 1000000007;
		Scanner sc = new Scanner(in);
		StringBuilder sb = new StringBuilder();
		int T = sc.nextInt();
		//String input;
		String [] inputArray;
		long [] fac = new long[27];
		fac[0] = 1;
		for (int i=1; i<27; i++)
			fac[i] = (fac[i-1] * i ) %m;
		for (int t=1; t<=T; t++){
			int n = sc.nextInt();
			inputArray = new String[n];
			for (int i=0; i<n; i++)
				inputArray[i]= sc.next();
			boolean can = true;
			sb.append("Case #" + t + ": ");
			int [] mid = new int[26];
			int [] head = new int[26];
			int [] tail = new int[26];
			int [] all = new int[26];
			int [] dir = new int[26];
			for (int i=0; i<26; i++)
				dir[i] = -1;
			for (int i=0; i<n; i++){
				String s = inputArray[i];
				char c = s.charAt(0);
				int j; 				
				for ( j=1; j<s.length() && s.charAt(j)==c; j++);
				if (j==s.length()) all[c-'a']++;	
				else {
					if (head[c-'a']==1) can = false;
					head[c-'a']++;
					char c1 = c;
					char c2 = s.charAt(s.length()-1);
					for (j=1; j<s.length(); j++){
						if (s.charAt(j)!=c1 && s.charAt(j)!=c2) {
							if (mid[s.charAt(j)-'a']==1) can = false;
							if (head[s.charAt(j)-'a']>0) can = false;
							if (tail[s.charAt(j)-'a']>0) can = false;
							if (all[s.charAt(j)-'a']>0) can = false;
							mid[s.charAt(j)-'a']=1;
							while(j+1<s.length() && s.charAt(j)==s.charAt(j+1)) j++;
						}
					}
					if (tail[c2-'a']==1) can = false;
					tail[c2-'a']++;		
					dir[c1-'a'] = c2-'a';
					if (c1==c2) can = false;
				}
			}
			if (can == false){
				sb.append("0\n");
				continue;
			}
			long [] ans = new long [100];
			int num = 0;
			boolean[] vis = new boolean[26];
			long last = 1;
			for (int i=0; i<26; i++)
				if (head[i]==1 && !vis[i])
				{	
					vis[i] = true;
					ans[num] =1;
					ans[num] = (ans[num] * fac[all[i]]) % m; // aaa
					
					int j = dir [i];
					while (j>0 && !vis[j]){
						vis[j] = true;
						ans[num] = (ans[num] * fac[all[j]]) % m; // aaa
						j = dir[j];
					}
					if (j>0) {
						last = 0;
						break;
					}
					num++;
				}
			for (int i=0; i<26; i++)
				if (!vis[i] && (head[i]==0 && tail[i]==0) && all[i]>0){
					ans[num] = fac[all[i]];
					num++;
				}
			for (int i=0; i<num; i++){
				last = (last * ans[i]) %m;
			}
			last = (last *fac[num])%m;
			sb.append(last + "\n");
		}
		ln(sb);
		sc.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new ReorderingCars().run();
	}
	public static void ln(Object obj) {
		out.print(obj);
	}
}
