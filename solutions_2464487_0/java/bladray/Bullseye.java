import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Bullseye{
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public void run() throws Exception {
        in = new BufferedReader(new FileReader("A-small-attempt0.in"));
        //in = new BufferedReader(new InputStreamReader(System.in));
        out =new PrintWriter(new FileWriter("A-small.OUT"));
        
       
        
        
        int T=nextInt();
        for (int i = 0; i < T; i++) {
			long r=nextLong();
			long t=nextLong();
		
			long res=solve(r, t);
			out.println(String.format("Case #%d: %s", i+1,res));	
		}
        


        out.flush();
        out.close();
        in.close();
    }
    public long solve(long r,long t){
		long lo=0,hi=t;
		long mid = 0;
		while (lo < hi)
		{
			mid = lo + (hi-lo)/2;
			if (!canDraw(mid,r,t))
				hi = mid;
			else
				lo = mid+1;
		}
//		if (canDraw(mid,r,t))
//			return -1; //all element is false
		return lo-1;         // lo is the least x for which p(x) is true
    }
    public boolean canDraw(long n,long r,long t){
    	
    	BigInteger nBig=new BigInteger(n+"");
    	BigInteger rBig=new BigInteger(r+"");
    	BigInteger tBig=new BigInteger(t+"");
    	BigInteger Two=new BigInteger("2");
    	BigInteger tmp= Two.multiply(nBig.multiply(nBig)).subtract(Two.multiply(nBig)).add(Two.multiply(nBig).multiply(rBig)).add(nBig);
    	return tmp.compareTo(tBig)<=0;
    }

    public static void main(String[] args) throws Exception {
        new Bullseye().run();
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
//2013-4-27 9:20:38

