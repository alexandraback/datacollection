import java.io.*;
import java.util.*;

public class GarbledEmail{
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    String[] dic;
    int wordN= 521196;
    int INF=Integer.MAX_VALUE/2;
    public void run() throws Exception {
        //in = new BufferedReader(new FileReader("D.IN"));
    	in = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
    	
    	dic=new String[521196];
    	for (int i = 0; i < wordN; i++) {
			dic[i]=next();
		}
    
  

		//System.out.println(solve("uprfucupaeeeepuppcfuuuplupeeiuupuxcrpcoppupzpucpua")); 
    	
        in = new BufferedReader(new FileReader("C-small-attempt1.in"));
        out =new PrintWriter(new FileWriter("C.OUT"));
        
        int T=nextInt();
        for (int i = 0; i < T; i++) {
			String str=next();
			int res=solve(str);
			out.println(String.format("Case #%d: %s", i+1,res));	
		}




        out.flush();
        out.close();
        in.close();
    }
    public int solve(String str){
    	int n=str.length();
    	int[][] dp=new int[n][n];
    	for (int[] is : dp) {
			Arrays.fill(is, -1);
		}
    	for (int i = 0; i < str.length(); i++) {
			for (int j = i; j < str.length(); j++) {
				dp[i][j]=calcScore(str.substring(i,j+1));
			}
		}
    	for (int j = 0; j < n; j++) {
			for (int i = 0; i < j; i++) {
				if(dp[0][i]==-1) continue;
				if(dp[i+1][j]==-1) continue;
				if(dp[0][j]==-1) dp[0][j]=dp[0][i]+dp[i+1][j];
				else dp[0][j]=Math.min(dp[0][j],dp[0][i]+dp[i+1][j]  );
			}
		}
    	return dp[0][n-1];
    }
    public int calcScore(String str){
    	int score=INF;
    	for (int i = 0; i < wordN; i++) {
			if(dic[i].length()!=str.length()) continue;
			int lastDifPos=-1;
			boolean isOK=true;
			int chgCnt=0;
			for (int j = 0; j < str.length(); j++) {
				if(str.charAt(j)!=dic[i].charAt(j)){
					chgCnt++;
					if(lastDifPos==-1) {lastDifPos=j;continue;}
					if(j-lastDifPos<5) {isOK=false;break;}
					lastDifPos=j;
				}
			}
			if(isOK) score=Math.min(score, chgCnt);
		}
    	if(score==INF) return -1;
    	return score;
    }

    public static void main(String[] args) throws Exception {
        new GarbledEmail().run();
    }

    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(in.readLine());
            } catch (Exception e) {
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}
//2013-5-5 1:20:40

