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

    public void haha() {
        BufferedReader in = null;
        BufferedWriter out = null;
        try{
            //in = new BufferedReader(new FileReader("test.in")); out = new BufferedWriter(new FileWriter("test.out"));
            in = new BufferedReader(new FileReader("B-small-attempt1.in")); out = new BufferedWriter(new FileWriter("B-small-attempt1.out"));
            //in = new BufferedReader(new FileReader("B-large.in")); out = new BufferedWriter(new FileWriter("B-large.out"));


            int T = Integer.parseInt(in.readLine());
            System.out.println("T="+T);
            for(int i=0;i<T;i++){
                StringBuilder ans = new StringBuilder();

                String[] line = in.readLine().split(" ");
                int X = Integer.parseInt(line[0]);
                int Y = Integer.parseInt(line[1]);

                for(int j=X;j<0;j++){
                    ans.append("EW");
                }
                for(int j=0;j<X;j++){
                    ans.append("WE");
                }
                for(int j=Y;j<0;j++){
                    ans.append("NS");
                }
                for(int j=0;j<Y;j++){
                    ans.append("SN");
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