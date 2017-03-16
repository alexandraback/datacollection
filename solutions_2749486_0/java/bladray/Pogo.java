import java.io.*;
import java.util.*;

public class Pogo{
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public void run() throws Exception {
        in = new BufferedReader(new FileReader("B-small-attempt0.in"));
        out =new PrintWriter(new FileWriter("B.OUT"));
//        in = new BufferedReader(new InputStreamReader(System.in));
//        out = new PrintWriter(System.out);

        int T=nextInt();
        for (int i = 0; i < T; i++) {
        	int x=nextInt();
        	int y=nextInt();
			
        	String res=calc(x,y);
        	out.println(String.format("Case #%d: %s", i+1,res));			
		}


        out.flush();
        out.close();
        in.close();
    }
    public String calc(int x,int y){
    	int nowX=0,nowY=0;
    	String res="";
    	while(nowY!=y){
    		if(nowY<y){
    			res+="SN";
    			nowY++;
    		}else if(nowY>y){
    			res+="NS";
    			nowY--;
    		}
    	}
    	while(nowX!=x){
    		if(nowX<x){
    			res+="WE";
    			nowX++;
    		}else if(nowX>x){
    			res+="EW";
    			nowX--;
    		}
    	}
    	return res;
    }

    public static void main(String[] args) throws Exception {
        new Pogo().run();
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
//2013-5-12 17:21:28

