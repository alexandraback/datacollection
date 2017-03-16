import java.io.*;
import java.util.*;

public class Battleship{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());
        for(int ca=1; ca<=test; ca++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r,c, w;
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            int total = (c/w)*(r-1);
            total += calcLast(c,w);
            System.out.println("Case #"+ca+": "+total);
        }
    }
    
    public static int calcLast(int c, int w){
        if(c == w){
            return w;
        }
        if(c-w >= w){
            return 1 + calcLast(c-w, w);
        }
        if (c-w < w){
            return 1 + w;
        }
        return -1;
    }
}