import java.io.*;
import java.util.*;

public class Osmos{
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public void run() throws Exception {
        in = new BufferedReader(new FileReader("A-large.in"));
        out =new PrintWriter(new FileWriter("A-large.OUT"));
//        in = new BufferedReader(new InputStreamReader(System.in));
//        out = new PrintWriter(System.out);
        int INF=Integer.MAX_VALUE/2;
        
        int T=nextInt();
        for (int i = 0; i < T; i++) {
			int A=nextInt();
			int N=nextInt();
			int[] motes=new int[N];
			for (int j = 0; j < N; j++) {
				motes[j]=nextInt();
			}
			Arrays.sort(motes);
			int minOp=INF;
			int nowAddCnt=0;
			if(A==1){
				out.println(String.format("Case #%d: %s", i+1,N));			
				continue;
			}
			for (int j = 0; j < N; j++) {
				minOp=Math.min(nowAddCnt+N-j, minOp); 
				if(A>motes[j]) A+=motes[j];
				else{
					while(motes[j]>=A){
						nowAddCnt++;
						A+=A-1;
					}
					A+=motes[j];
				}
			}
			minOp=Math.min(nowAddCnt, minOp);
			
			out.println(String.format("Case #%d: %s", i+1,minOp));			 
		}

        out.flush();
        out.close();
        in.close();
    }

    public static void main(String[] args) throws Exception {
        new Osmos().run();
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
//2013-5-5 0:16:45

