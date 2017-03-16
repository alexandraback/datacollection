import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class CloseMatch {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "B-small-attempt2";
  
  private static void solve() throws IOException {
        String sc=in.next(), sj=in.next(); int l=sc.length();
        char[] c=sc.toCharArray(), j=sj.toCharArray();
        //int x=1; while(l-->1) x*=10;
        int x=1;
        for(int i=0;i<l;i++)
        	x*=10;
        boolean[] cc=new boolean[x], jj=new boolean[x];
        Arrays.fill(cc,true); Arrays.fill(jj, true);
        StringBuilder s= new StringBuilder();
        for(int i=0;i<l;i++){
        	//int nj=0,nc=0;
        	char a=c[i], b=j[i];
        	if(a!='?'){
        		for(int k=0;k<x;k++){
        			s= new StringBuilder(""+k);
        			while(s.length()<l) s.insert(0, 0);
        			//out.println(s+" "+s.charAt(i)+" "+a);
        			if(s.charAt(i)!=a)
        				cc[k]=false;
        		}	
        	}
        	if(b!='?'){
        		for(int k=0;k<x;k++){
        			s= new StringBuilder(""+k);
        			while(s.length()<l) s.insert(0, 0);
        			if(s.charAt(i)!=b)
        				jj[k]=false;
        		}
        	}
        }
        int d=x+11;
        int[] res= new int[2]; res[0]=x+1; res[1]=x+1;
        for(int i=0;i<x;i++){
        	for(int k=0;k<x;k++){
        		if(!cc[i] || !jj[k]) continue;
        		int t=Math.abs(i-k);
        		if(t<d){
        			d=t; res[0]=i;res[1]=k;
        		} else if(t==d){
        			if(i<res[0]){
        				res[0]=i; res[1]=k;
        			}else if(i==res[0]){
        				if(k<res[1])
        				res[1]=k;
        			}
        			
        		}
        	}
        }
        StringBuilder s1= new StringBuilder(""+res[0]);
        while(s1.length()<l) s1.insert(0, 0);
        StringBuilder s2= new StringBuilder(""+res[1]);
        while(s2.length()<l) s2.insert(0, 0);
        out.println(s1+" "+s2);
    
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
