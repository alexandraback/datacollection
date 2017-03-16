/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package practicejam;

import java.io.*;

/**
 *
 * @author GreenTie
 */
public class PracticeJam {

//    public int[] compute(int[][] input){
//        int[] result=new int[input.length];
//        for(int i=0;i<input.length;i++)
//            result[i]=compute(input[0],input[1]);
//        return result;
//    }
    public static int compute(int n, int k) {
        if ((k & 0x01) == 0) {
            return 0;
        } else {
            int x = (1 << n);
            return (k + 1) % x == 0 ? 1 : 0;
        }
    }
    public static final String[] Result = {"OFF", "ON"};
    public static final char[] DicB = {'Y', 'H', 'E', 'S', 'O', 'C', 'V', 'X', 'D', 'U', 'I', 'G', 'L', 'B', 'K', 'R', 'Z', 'T', 'N', 'W', 'J', 'P', 'F', 'M', 'A', 'Q'};
    public static final char[] DicA = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
    public static final int[] Normal = {0, 1, 1, 1,
        2, 2, 2,
        3, 3, 3,
        4, 4, 4,
        5, 5, 5,
        6, 6, 6,
        7, 7, 7,
        8, 8, 8,
        9, 9, 9,
        10, 10, 10};
    public static final int[] Surprising = {0,
        0, 2, 2,
        2, 3, 3,
        3, 4, 4,
        4, 5, 5,
        5, 6, 6,
        6, 7, 7,
        7, 8, 8,
        8, 9, 9,
        9, 10, 10,
        10, 0, 0
    };

    public static String problemA(String G) {
        StringBuilder sb = new StringBuilder(G.length());
        for (int i = 0; i < G.length(); i++) {
            char x = G.charAt(i);
            if (x >= 'A' && x <= 'Z') {
                sb.append(DicB[x - 'A']);
            } else if (x >= 'a' && x <= 'z') {
                sb.append(DicA[x - 'a']);
            } else {
                sb.append(x);
            }
        }
        return sb.toString();
    }
    
    public static int problemB(String G){
        int result=0;
        String[] temp=G.split(" ");
        int N=Integer.parseInt(temp[0]);
        int S=Integer.parseInt(temp[1]);
        int p=Integer.parseInt(temp[2]);
        int[] scr=new int[N];
        int count=N;
        int suprise=S;
        for(int i=0;i<N;i++){
            scr[i]=Integer.parseInt(temp[i+3]);
            if(scr[i]>=29){result++;count--;}
            else if(scr[i]==1){count--;if(p<=1)result++;}
            else if(scr[i]==0){count--;if(p==0)result++;}
            else if(Normal[scr[i]]>=p){
                result++;count--;
            }
            else{
                if(Surprising[scr[i]]>=p&&suprise>0){
                    result++;
                    count--;
                    suprise--;
                }
            }
        }
        
        return result;
    }
    

    /**
     * @param args the command line arguments
     */
    public static void mainA(String[] args) {
        String[] x = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
        for (String G : x) {
            System.out.println(problemA(G));
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader(new File("B-large.in")));
        int x = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= x; i++) {
            //String[] temp=br.readLine().trim().split(" ");
            sb.append("Case #").append(i).append(": ").append(problemB(br.readLine()));
            sb.append('\n');
            //sb.append("Case #").append(i).append(": ").append(Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]).append('\n');
            //System.out.printf("Case #%d: %s\n",i,Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]);   
        }
        System.setOut(new PrintStream(new File("B-large.out")));
        System.out.print(sb.toString());
        br.close();

    }
}
