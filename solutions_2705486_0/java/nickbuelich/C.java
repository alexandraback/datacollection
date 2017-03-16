import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class C {
	static String cur;
	static TreeSet<String> dict;
	static int memo[][];
	public static void main(String[] args) throws Exception{
		Scanner sc =new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		Scanner D =new Scanner(new File("dict.txt"));
		dict = new TreeSet<String>();
		while(D.hasNext()){
			String xx = D.next();
			dict.add(xx);
		}
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			cur = sc.next();
			memo = new int[cur.length()][cur.length()];
			for(int[] x : memo)Arrays.fill(x,-1);
			int many = DP(0,cur.length()-1);
			System.out.printf("Case #%d: %d%n",t,many);
			out.printf("Case #%d: %d%n",t,many);
		}
		out.close();
	}
	private static int DP(int i, int j) {
		if(memo[i][j]!=-1)return memo[i][j];
		int best = Integer.MAX_VALUE;
		if(j-i<10){
			if(dict.contains(cur.substring(i, j+1)))return memo[i][j]=0;
			int length = j-i+1;
			char[] magic = cur.substring(i, j+1).toCharArray();
			for(int a=0;a<length;a++){
				for(int b=0;b<26;b++){
					magic[a]=(char)('a'+b);
					if(dict.contains(String.valueOf(magic))){
						best = Math.min(best,1);
					}
					for(int c=a+5;c<length;c++){
						for(int d=0;d<26;d++){
							magic[c]=(char)('a'+d);
							if(dict.contains(String.valueOf(magic))){
								best = Math.min(best,2);
							}
						}
						magic = cur.substring(i, j+1).toCharArray();
						magic[a]=(char)('a'+b);
					}
				}
				magic = cur.substring(i, j+1).toCharArray();
			}
		}
		for(int a=i;a<j;a++){
			best = Math.min(best, DP(i,a)+DP(a+1,j));
		}
		return memo[i][j]=best;
	}
}
