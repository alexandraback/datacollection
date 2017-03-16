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
public class Bullseye {

    static int solve(long r, double t)
    {
        int count = 0;
        double prev = r*r;

        while(true)
        {
          // System.out.println(r+" - "+count);
            r+=1;
            double aux = r*r;
            //System.out.println(prev+" - "+aux+" - "+(aux-prev)+" - "+ t);
            double minus = aux-prev;
            if(minus <= t){
                count++;
                t-=minus;
                r+=1;
                prev = r*r;
            }else break;
        }
        return count;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        String file = "A-small-attempt0";
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
        int answer = -1;
        for(int cc=1;cc<=cases;cc++)
        {
            r = new StringTokenizer(in.readLine());
            long radius = Long.parseLong(r.nextToken());
            long t = Long.parseLong(r.nextToken());
            
            System.out.println("Case #"+cc+": "+solve(radius, t));
        }
        
        
        in.close();
        System.exit(0);
    }
}
