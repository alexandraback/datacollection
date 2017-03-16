package R1C;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author astorres
 */
public class B {

    public static final String rutaDatos = "C:\\Users\\Augusto\\Desktop\\Code Jam\\";
    
    public static int G[][];  
    public static int V[];
    public static int B, M;
    public static boolean CY,OK;
    static PrintWriter out;
    
    public static void BruteForce(int r, int c) {
        if(OK) return;
        if(r==B-1) {
            if(check()) {
                System.out.println("POSSIBLE");
                out.println("POSSIBLE");
                for(int i=0;i<B;i++) {
                    for(int j=0;j<B;j++){
                        System.out.print(G[i][j]);
                        out.print(G[i][j]);
                    }
                    System.out.println("");
                    out.println("");
                }
                    
                OK = true;
            }
            return;
        }
        if(c==B) {
            BruteForce(r+1,1);
            return;
        }
        G[r][c] = 1;
        BruteForce(r,c+1);
        G[r][c] = 0;
        BruteForce(r,c+1);
    }   
    
    public static boolean check() {
        CY = false;
        V = new int[B];
        Arrays.fill(V,0);
        int tot = dfs(0);
        if(CY) return false;
        return tot==M;
    }
    
    public static int dfs(int e) {
        if(CY) return 0;
        if(V[e]==1) {CY=true;return 0;}
        if(e==B-1) return 1;
        V[e] = 1;
        int tot = 0;
        for(int i=0;i<B;i++)
            if(G[e][i]==1)
                tot += dfs(i);
        V[e] = 0;
        return tot;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        String problem = "B";
        String input=problem+"-sample.in";
        //String input=problem+"-small-attempt0.in";
        //String input=problem+"-large.in";
        Scanner in = new Scanner(new File(rutaDatos+"input\\"+input));
        out = new PrintWriter(new BufferedWriter(new FileWriter(rutaDatos+"output\\"+input+".out.txt")));    
        
        /*for(B=2;B<=6;B++)
            for(M=1;M<=20;M++)
            {
                G = new int[B][B];
                for(int j=0;j<B;j++) Arrays.fill(G[j],0);
                OK=false;
                BruteForce(0,0);
                if(!OK) System.out.println(B+" "+M);
            }*/
        
        int T = in.nextInt();
        for(int i=0;i<T;i++) {
            
            /*********************************/
            
            B = in.nextInt();
            M = in.nextInt();
            
            G = new int[B][B];
            for(int j=0;j<B;j++) Arrays.fill(G[j],0);
            
            OK=false;
            
            String answer = "Case #"+(i+1)+": ";
            System.out.print(answer);
            out.print(answer);
            
            BruteForce(0,0);
            if(!OK) {System.out.println("IMPOSSIBLE");out.println("IMPOSSIBLE");}
            /*********************************/
            
            
        }
        out.close();
    }
    
}
