/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2013;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 *
 * @author Alejandro E. Garces
 */
public class GCJ2013 {

    static ArrayList<Long> palin;
    static ArrayList<Long> square;
    static boolean isPalin(long x)
    {
        
        StringBuilder a = new StringBuilder(String.valueOf(x));
        long y = Long.parseLong(a.reverse().toString());
       // System.out.println(x+" - "+y);
        if(x == y)return true;
       /* StringBuilder b = new StringBuilder(String.valueOf(x)).reverse();
        System.out.println("|"+a + "| - |"+b+"| - "+b.equals(a.toString()));
        if(a.equals(b))return true;*/
        return false;
    }
     /*
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        long n = 1000;
        //long n = 100000000000000l;
        long m = (int)Math.sqrt(n);
        palin = new ArrayList<Long>();
        square = new ArrayList<Long>();
        for(long i=1;i<=m;i++ )
        {
            if(isPalin(i) && isPalin(i*i))
                square.add(i*i);
        }
        //System.out.println(square);
        String file = "C-small-attempt0";
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
        int N = square.size();
        for(int cc=1;cc<=cases;cc++)
        {
            r = new StringTokenizer(in.readLine());
            long a = Long.parseLong(r.nextToken());
            long b = Long.parseLong(r.nextToken());
            int i=0;
            answer = 0;
            for(i=0;i<N;i++)
                if(square.get(i) >= a)break;
            for(;i<N;i++)
                if(square.get(i) >= a && square.get(i)<=b )answer++;
                else if(square.get(i) > b)break;
            System.out.println("Case #"+cc+": "+answer);
        }
        
        
        in.close();
        System.exit(0);
    }
}
