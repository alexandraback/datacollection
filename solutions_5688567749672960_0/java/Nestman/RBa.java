package gcj2015;

import java.io.*;
import java.util.*;

public class RBa {
	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
	//	Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/A-small-attempt3.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/Rnd1B_a.txt");
		
		int res,rep,i,j;
		int[] ans = new int[1000001];
		ArrayDeque<Integer> q = new ArrayDeque<Integer>();
		q.add(1);
		Arrays.fill(ans,100000000);
		ans[1] = 1;
		
		while(!q.isEmpty()) {
			
			int t = q.poll();
			if ((t<1000000) && (ans[t+1]>ans[t]+1)) {
				ans[t+1] = ans[t]+1;
				q.add(t+1);
			}
			if ((rev(t)<=1000000) && (ans[rev(t)]>ans[t]+1)) {
				ans[rev(t)] = ans[t]+1;
				q.add(rev(t));
			}
			System.out.println(q.size());
		}
		
		res = sc.nextInt();
		for(rep=1;rep<=res;rep++) {
			
			int n = sc.nextInt();
			System.out.println(ans[n]);
			ou.printf("Case #%d: ",rep);
			ou.println(ans[n]);
		}
		
		ou.close();
	}
	
	public static int rev(int a){
		
		String s = Integer.toString(a);
		String s2 = "";
		int i;
		for(i=0;i<s.length();i++) {
			s2 += s.charAt(s.length()-1-i);
		}
		
		return Integer.parseInt(s2);
	}
}
