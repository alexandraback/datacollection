import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class GettingTheDigits {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "A-large (2)";
  
  private static void solve() throws IOException {
        String s=in.next();
        int[] num= new int[10];
        for(int i=0;i<s.length();i++){
        	char c=s.charAt(i);
        	if(c=='Z') num[0]++;
        	else if(c=='O') num[1]++;
        	else if(c=='W') num[2]++;
        	else if(c=='H') num[3]++;
        	else if(c=='U') num[4]++;
        	else if(c=='F') num[5]++;
        	else if(c=='X') num[6]++;
        	else if(c=='S') num[7]++;
        	else if(c=='G') num[8]++;
        	else if(c=='I') num[9]++;
        }
        int[] n= new int[10];
        while(num[2]-->0){
        	n[2]++; num[1]--;
        }
        while(num[6]-->0){
        	n[6]++; num[7]--; num[9]--;
        }
        while(num[8]-->0){
        	n[8]++; num[3]--; num[9]--;
        }
        while(num[0]-->0){
        	n[0]++; num[1]--;
        }
        while(num[3]-->0){
        	n[3]++;
        }
        while(num[7]-->0){
        	n[7]++;
        }
        while(num[4]-->0){
        	n[4]++; num[1]--; num[5]--;
        }
        while(num[5]-->0){
        	n[5]++; num[9]--;
        }
        while(num[9]-->0){
        	n[9]++; 
        }
        while(num[1]-->0){
        	n[1]++;
        }
        StringBuilder res= new StringBuilder();
        for(int i=0;i<10;i++)
        	for(int j=0;j<n[i];j++)
        		res.append(i);
        out.println(res);
    
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int nCases = in.nextInt();
    for (int tests = 1; tests <= nCases; tests++) {
      out.print("Case #" + tests + ": ");
      //out.println();
      solve();
    }

    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 110897);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
