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
    
    public static int compute(int n,int k){
        if((k&0x01)==0)return 0;
        else {
            int x=(1<<n);
            return (k+1)%x==0?1:0;
        }
    }
    
    public static final String[] Result={"OFF","ON"};

    public static final char[] DicB={'Y','H','E','S','O','C','V','X','D','U','I','G','L','B','K','R','Z','T','N','W','J','P','F','M','A','Q'};
    public static final char[] DicA={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    
    public static final char[] DicB2={'Y','H','E','S','O','C','V','X','D','U','I','G','L','B','K','R','Q','T','N','W','J','P','F','M','A','Z'};
    public static final char[] DicA2={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','q','t','n','w','j','p','f','m','a','z'};
    
    
    
    
    public static String problemA(String G){
        StringBuilder sb=new StringBuilder(G.length());
        for(int i=0;i<G.length();i++){
            char x=G.charAt(i);
            if(x>='A'&&x<='Z')sb.append(DicB[x-'A']);
            else if(x>='a'&&x<='z')sb.append(DicA[x-'a']);
            else sb.append(x);        
        }
        return sb.toString();
    
    }
    
    public static String problemA2(String G){
        StringBuilder sb=new StringBuilder(G.length());
        for(int i=0;i<G.length();i++){
            char x=G.charAt(i);
            if(x>='A'&&x<='Z')sb.append(DicB2[x-'A']);
            else if(x>='a'&&x<='z')sb.append(DicA2[x-'a']);
            else sb.append(x);        
        }
        return sb.toString();
    
    }
    
    /**
     * @param args the command line arguments
     */
    
    public static void mainA(String[] args){
        String[] x={"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
        for(String G:x){
            System.out.println(problemA(G));
        }
    }
    public static void main(String[] args) throws FileNotFoundException, IOException {
       BufferedReader br=new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
       int x=Integer.parseInt(br.readLine());
       StringBuilder sb=new StringBuilder();
       for(int i=1;i<=x;i++){
          //String[] temp=br.readLine().trim().split(" ");
          sb.append("Case #").append(i).append(": ").append(problemA(br.readLine())).append('\n');
           //sb.append("Case #").append(i).append(": ").append(Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]).append('\n');
           //System.out.printf("Case #%d: %s\n",i,Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]);   
       }
       System.setOut(new PrintStream(new File("A-small-attempt0.out")));
       System.out.print(sb.toString());
       br.close();
       
    }
}
