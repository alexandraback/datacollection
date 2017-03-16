import java.io.*;
import java.util.*;
 
public class Main {
    /**
     * author geshpaniec
     * 23.10.2014
     */
 
    StringTokenizer in;
    BufferedReader inb;
    PrintWriter out;
    static boolean local;
    final String problemname = "success";
    final static String _localArg="geshpaniec1";
    final static byte IO=3;
        /* IO:
         * 1 - standard I/O
         * 2 - input.txt/output.txt
         * 3 - problemname.in/problemname.out
         */
 
    int[] to = {10,29,138,337,1436,3435,14434,34433,144432,344431,1444430,3444429,14444428,34444427};
   
    
    int funct(long n){
		int pow = Long.toString(n).length()-1;
		int ans = 0;
		if (pow == 0){
			ans = (int)n;
		}
		else{
			ans = to[pow-1];
			String s = Long.toString(n);
			int mid = s.length()/2;
			String l1 = s.substring(0, mid), l2 = s.substring(mid, s.length());
			
			int len = l1.length();
			
			for (int i = 0; i < len;i++){
				l1+=l1.charAt(len-i-1);
			}
			l1 = l1.substring(len);
			
			int L1 = Integer.parseInt(l1), L2 = Integer.parseInt(l2);
			if (L2 == 0 ){
				return funct(n-1)+1;
			}
			else{
				ans+=L1+L2;
				if (L1 == 1){
					ans--;
				}
			}
		}
		return ans;
    }
    
    public void solve() throws Exception {
    	int T = nextInt();
    	for (int q = 1;q<=T;q++){
    		out.println("Case #"+q+": "+funct(nextLong()));
    	}
    }
 
    public static void main(String[] args) throws Exception {
        local = false;
        if (args.length == 1 && args[0].equals(_localArg))
            local = true;
        new Main().run();
 
    }
 
    public void run() throws Exception {
        if (local) {
            inb = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            switch (IO){
                case 1:
                    inb = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(new OutputStreamWriter(System.out));
                    break;
                case 2:
                    inb = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    inb = new BufferedReader(new FileReader(problemname+".in"));
                    out = new PrintWriter(new FileWriter(problemname+".out"));
                    break;
            }
        }
        in = new StringTokenizer("");
        double Time=System.nanoTime();
        solve();
        if (local){
            Time=System.nanoTime()-Time;
            out.println();
            out.println(" Time work: "+Time/(1e9)+" seconds");
        }
        out.flush();
    }
 
    int nextInt() throws Exception {
        return Integer.parseInt(next());
    }
 
    long nextLong() throws Exception{
        return Long.parseLong(next());
    }
 
    double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }
 
    String next() throws Exception {
        if (!in.hasMoreTokens())
            in=new StringTokenizer(inb.readLine());
        return in.nextToken();
    }
 
    int[] nextArray(int n) throws Exception{
        int[] a=new int[n];
        for (int i=0;i<n;i++)
            a[i]=nextInt();
        return a;
    }
 
    long[] nextLArray(int n) throws Exception{
        long[] a=new long[n];
        for (int i=0;i<n;i++)
            a[i]=nextLong();
        return a;
    }
 
    double[] nextDArray(int n) throws Exception{
        double[] a=new double[n];
        for (int i=0;i<n;i++)
            a[i]=nextDouble();
        return a;
    }
 
    String[] nextSArray(int n) throws Exception{
        String[] a=new String[n];
        for (int i=0;i<n;i++)
            a[i]=next();
        return a;
    }

}