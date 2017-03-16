/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Happy;
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

/**
 *
 * @author ipoqi
 */
public class Happy {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        new Happy().haha();
    }

    public void haha() {
        BufferedReader in = null;
        BufferedWriter out = null;
        try{
            in = new BufferedReader(new FileReader("A-small-attempt0.in"));
            out = new BufferedWriter(new FileWriter("a.out"));
            int T = Integer.parseInt(in.readLine());
            System.out.println("T="+T);

            //LinkedList<Integer> mm = new LinkedList<Integer>();
            //mm.add(new LinkedList<Integer>());
           //int[][] mm;
           //for(int ii=0;ii<mm.length;ii++){
           //     mm[0][ii] = 1;
           //}
            int[][] nodes = new int[1000][10];


            for(int i=0;i<T;i++){
                int ans = 0;

                for(int a=0;a<1000;a++){
                    for(int b=0;b<10;b++){
                        nodes[a][b] = 0;
                    }
                }

                String[] line = in.readLine().split(" ");
                int N = Integer.parseInt(line[0]);
                int[] MM = new int[N];
                int[] OK = new int[N];
                for(int a=0;a<N;a++){
                    String[] line1 = in.readLine().split(" ");
                    int M = Integer.parseInt(line1[0]);
                    MM[a] = M;
                    for(int b=0;b<M;b++){
                        nodes[a][b] = Integer.parseInt(line1[b+1])-1;
                        //System.out.println("node="+nodes[a][b]);
                    }
                }

                for(int a=0;a<N;a++){
                    for(int j=0;j<N;j++){
                        OK[j] = 0;
                    }
                    LinkedList<Integer> flist = new LinkedList<Integer>();
                    int m = MM[a];
                    for(int b=0;b<m;b++){
                        int f = nodes[a][b];
                        //System.out.println("f="+f);
                        if(OK[f]==1){
                            ans = 1;
                            break;
                        } else {
                            OK[f]++;
                            flist.add(f);
                        }
                    }
                    if(ans==1){
                        break;
                    }
                    while(flist.size()>0){
                        //System.out.println("s="+flist.size());
                        int f = flist.removeLast();
                        for(int b=0;b<MM[f];b++){
                            int f1 = nodes[f][b];
                            if(OK[f1]==1){
                                ans = 1;
                                break;
                            } else {
                                OK[f1]++;
                                flist.add(f1);
                            }
                        }
                        if(ans==1){
                            break;
                        }
                    }
                    if(ans==1){
                        break;
                    }
                }


                String aaa;
                if(ans==0){
                    aaa = "No";
                } else {
                    aaa = "Yes";
                }
                out.write("Case #"+(i+1)+": "+aaa+"\n");
                System.out.print("Case #"+(i+1)+": "+aaa+"\n");
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