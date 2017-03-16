package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class Round1A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        int  test = sc.nextInt();
        for (int i = 1 ;i <= test;i++){
            int r = sc.nextInt();
            int c = sc.nextInt();
            int w = sc.nextInt();
            out.print("Case #"+i+": "+found(r,c,w));
            out.println();
        }
    out.flush();
        
    }
   public static int found (int r , int c ,int w){
       int res = 0;
       res = c/w;
       res = res*r;
       if (c%w == 0 ){
       res = res+w-1;    
       }else{
           res =res +w;
       }
       
       return res;
   }
}
