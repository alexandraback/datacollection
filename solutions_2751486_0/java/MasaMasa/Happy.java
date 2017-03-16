package happy;
import java.io.*;
import java.math.*;
import java.lang.*;
import java.util.*;
import java.util.Arrays.*;
import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.io.PrintWriter;
//import java.util.StringTokenizer;

public class Happy {
    public static void main(String[] args) {
        new Happy().haha();
    }


    String V = "aeiou";
    boolean checkV(char tmp){
        boolean ok = false;
        for(int i=0;i<V.length();i++){
            if(tmp == V.charAt(i)){
                ok = true;
                break;
            }
        }
        return ok;
    }

    public void haha() {
        BufferedReader in = null;
        BufferedWriter out = null;
        try{
            //in = new BufferedReader(new FileReader("test.in")); out = new BufferedWriter(new FileWriter("test.out"));
            in = new BufferedReader(new FileReader("A-small-attempt0.in")); out = new BufferedWriter(new FileWriter("A-small-attempt0.out"));
            //in = new BufferedReader(new FileReader("A-large.in")); out = new BufferedWriter(new FileWriter("A-large.out"));

            

            int T = Integer.parseInt(in.readLine());
            System.out.println("T="+T);
            for(int i=0;i<T;i++){
                int ans = 0;

                String[] line = in.readLine().split(" ");
                //BigInteger r = new BigInteger(line[0]);
                //BigInteger t = new BigInteger(line[1]);
                //long A = Long.parseLong(line[0]);
                //int N = Integer.parseInt(line[1]);
                String name = line[0];
                int n = Integer.parseInt(line[1]);
                int L= name.length();
                int fail = 0;
                for(int j=0;j<L;j++){
                    int cnt = 0;
                    for(int k=0;k<L-j;k++){
                        char tmp = name.charAt(j+k);
                        if(checkV(tmp)==false){
                            cnt++;
                            if(cnt==n){
                                ans = ans + (L-k-j);
                                break;
                            }
                        } else {
                            cnt = 0;
                        }
                    }
                    if(cnt<n)
                        break;
                }

                out.write("Case #"+(i+1)+": "+ans+"\n");
                System.out.print("Case #"+(i+1)+": "+ans+"\n");
            }

            in.close();
            out.close();
        }catch(Exception e){
            e.printStackTrace();
            try{
                in.close();
                out.close();
            }catch(Exception e1){
                e1.printStackTrace();
            }
        }
        System.out.print("YES!\n");
    }

}