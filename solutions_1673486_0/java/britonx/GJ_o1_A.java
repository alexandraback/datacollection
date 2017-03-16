import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Hashtable;

//for(int i=0; i<0; i++){}

public class GJ_o1_A {

    public static double solve(int n, int a, double pa){
        
        return pa*(n-a+1) + (1-pa)*(n-a+1+n+1);
    }
    

    public static void main(String[] args) throws NumberFormatException, IOException  {
        java.io.BufferedReader stdin = new java.io.BufferedReader(new java.io.InputStreamReader(new FileInputStream("A-small-attempt0.in")));
        java.io.BufferedWriter stdout = new java.io.BufferedWriter(new OutputStreamWriter(new FileOutputStream("1aout.txt")));
        int T = Integer.parseInt(stdin.readLine());
        //T = 3;
        for (int ii=0; ii<T; ii++){
            String str = stdin.readLine();
            String[] words = str.split(" ");
            int a = Integer.parseInt(words[0]);
            int b = Integer.parseInt(words[1]);
            str = stdin.readLine();
            words = str.split(" ");
            double[] p = new double[a];
            double allp = 1;
            for(int i=0; i<a; i++){
                p[i] = Double.parseDouble(words[i]);
                allp *= p[i];
            }
            int ctr = 0;
            while (ctr<a && p[ctr]==1 ) ctr++;
            double res = b*3;
            
            double pa = 1;
            double tmp;
            for(int i=0; i<a; i++){
                pa *= p[i];
                tmp = a-1-i+solve(b, i+1, pa);
                
                System.out.println(String.format("  %d: %.4f", i, tmp));
                res = Math.min(res, tmp);
            }
            // enter right away
            tmp = 1+b +1;
            System.out.println(String.format(" en: %.4f",  tmp));
            res = Math.min(res, tmp);
            // enter right away
            //tmp = b-ctr+1+(a-ctr) ;
            //System.out.println(String.format(" en: %.4f",  tmp));
            //res = Math.min(res, tmp);
            

            stdout.write(String.format("Case #%d: %.6f\n", (1+ii) ,res));
            System.out.println(String.format("Case #%d: %.6f\n", (1+ii) ,res));
        }
        stdout.close();
    }

}
