package gcj2013;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.util.*;
/**
 *
 * @author Alejandro E. Garces
 */
public class ManageYourEnergy {

    static int[] values;
    static int regain;
    static int max;
    static int n;
    static int answer = 0;
    static void solve(int i, int energy, int gain )
    {
        //System.out.println(i+" - "+energy+" - "+gain+" - "+n+" - "+max);
        if(energy<0)return;
        if(energy>max)energy=max;
        if(i == n){
            answer = Math.max(answer, gain);
            return;
        }
        for(int j=0;j<=energy;j++)
        {
            solve(i+1, energy-j+regain, gain+values[i]*j);
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        String file = "B-small-attempt1";
        String line = "";
        StringTokenizer r;
        
        System.setIn(new FileInputStream(file+".in"));
        System.setOut(new PrintStream(new FileOutputStream(file+"O.out")));
        
        /////////////////////
        //Input from Console
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //Scanner in = new Scanner(System.in);
        
        /////////////////////
        //Input from file
        //BufferedReader in = new BufferedReader(new FileReader(file+".txt"));
        //Scanner in = new Scanner(new File(file+".txt"));
        //FileWriter archivo = new FileWriter(file+"O.txt");
        //PrintWriter out = new PrintWriter(archivo);
        //out.flush();
        ////////////////////
        
        int cases = Integer.parseInt(in.readLine());
        for(int cc=1;cc<=cases;cc++)
        {   answer = 0;
            r = new StringTokenizer(in.readLine());
            max = Integer.parseInt(r.nextToken());
            regain = Integer.parseInt(r.nextToken());
            n = Integer.parseInt(r.nextToken());
            values = new int[n];
            r = new StringTokenizer(in.readLine());
            for(int i=0;i<n;i++)values[i] =  Integer.parseInt(r.nextToken());
            solve(0, max, 0);
            System.out.println("Case #"+cc+": "+answer);
        }
        
        
        in.close();
        System.exit(0);
    }
}
