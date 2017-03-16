import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C{
    public static void main(String[] args) throws Exception{
        new C().run();
    }

    private static final String dictFileName = "garbled_email_dictionary.txt";
    ArrayList<String>[] dict = new ArrayList[11]; // max word length is 10

    void parseDictionary() throws Exception{
	//int mx = 0;
	BufferedReader sc = new BufferedReader(new InputStreamReader(new FileInputStream(new File(dictFileName))));
	int count = 0;
	while(true){
	    String line = sc.readLine();
	    if(line == null)break;
	    //mx = max(mx, line.length());
	    dict[line.length()].add(line);
	    count++;
	}
	//System.out.println(mx);
	//System.out.println(count);
	for(int i = 1; i < dict.length; i++)Collections.sort(dict[i]);
    }

    private static final int INF = 1<<20;
    String s;
    int len;
    int[][] edm; // edit distance memo
    int[] dp;
    int calc(int pos){
	if(pos == len)return 0;
	if(dp[pos] != INF)return dp[pos];
	int ret = INF;
	for(int i = pos+1; i <= len && i-pos <= 10; i++){
	    ret = min(ret, editDistance(pos, i) + calc(i));
	}
	return dp[pos] = ret;
    }

    int editDistance(int si, int ei){
	if(edm[si][ei] != INF)return edm[si][ei];
	String t = s.substring(si, ei);
	int n = t.length();
	int ret = INF;
	for(int i = 0; i < dict[n].size(); i++){
	    //EditDistance e = new EditDistance(t.toCharArray(), dict[n].get(i).toCharArray());
	    int sum = 0;
	    for(int j = 0; j < n; j++)if(t.charAt(j) != dict[n].get(i).charAt(j))sum++;
	    ret = min(ret, sum);
	}
	return edm[si][ei] = ret;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

	for(int i = 0; i < dict.length; i++)dict[i] = new ArrayList<String>();
	parseDictionary();

	int T = sc.nextInt();
	for(int o = 1; o <= T; o++){
	    System.out.printf("Case #%d: ", o);
	    s = sc.next();
	    len = s.length();
	    edm = new int[len+1][len+1];
	    for(int i = 0; i < edm.length; i++)Arrays.fill(edm[i], INF);
	    dp = new int[len+1];
	    Arrays.fill(dp, INF);
	    System.out.println(calc(0));
	}
    }
}

class EditDistance{
    char[] a; // source
    int an;
    char[] b; // destination
    int bn;
    int[][] dp;
    char[][] hist; // 'R': Replace, 'D': Delete, 'I': Insert, ' ': none

    public EditDistance(char[] _a, char[] _b){
        a = _a;
        an = a.length;
        b = _b;
        bn = b.length;
        dp = new int[an+1][bn+1];
        hist = new char[an+1][bn+1];
        for(int i = 0; i <= an; i++){
            for(int j = 0; j <= bn; j++){
                if(i == 0){
                    if(j > 0){
                        dp[i][j] = dp[i][j-1] + 1;
                        hist[i][j] = 'I';
                    }
                }else{
                    if(j == 0){
                        dp[i][j] = dp[i-1][j] + 1;
                        hist[i][j] = 'D';
                    }else{
                        dp[i][j] = Math.min(dp[i-1][j] + 1,
                                            Math.min(dp[i][j-1]+1, dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1)));
                        hist[i][j] = ' ';
                        if(dp[i][j] == dp[i-1][j]+1)
                            hist[i][j] = 'D';
                        else if(dp[i][j] == dp[i][j-1]+1)
                            hist[i][j] = 'I';
                        else if(dp[i][j] == dp[i-1][j-1]+1)
                            hist[i][j] = 'R';
                    }
                }
            }
        }
    }

    public int editDistance(){
        return dp[an][bn];
    }

    public void showHistory(){
        int i = an;
        int j = bn;
        ArrayList<String> ar = new ArrayList<String>();
        while(i > 0 || j > 0){
            if(hist[i][j] == 'R'){
                ar.add(String.format("REPLACE %d %c", j, b[j-1]));
                i--;j--;
            }else if(hist[i][j] == 'D'){
                ar.add(String.format("DELETE %d", j+1));
                i--;
            }else if(hist[i][j] == 'I'){
                ar.add(String.format("INSERT %d %c", j, b[j-1]));
                j--;
            }else {
                i--; j--;
            }
        }
        for(int k = ar.size()-1; k >= 0; k--)
            System.out.println(ar.get(k));
    }
}
