
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author violetlily
 */
public class Jam2012Q_B_S {

    private final String ipath = "B-small-attempt1.in";
    private final String opath = "B-small-attempt1.ou";

    public void Handle() throws FileNotFoundException {
        
        PrintStream out = new PrintStream(   
                new BufferedOutputStream(   
                        new FileOutputStream(opath)));   
        System.setOut(out);
        
        Scanner sc = new Scanner(new FileInputStream(new File(ipath)));
        int m = sc.nextInt();
        int ii = 1;
        while (m > 0) {

            int n = sc.nextInt();
            int s = sc.nextInt();
            int p = sc.nextInt();
            int c = 0;
            while(n > 0){
                int t = sc.nextInt();
                if(t%3 == 0){
                    if(t/3 >= p && t/3!= 0){
                        c ++;
                    }else if(t/3 +1 >= p && s > 0 && t/3!= 0){
                        c ++;
                        s--;
                    }else if(t == 0 && t/3 >= p){
                        c ++;
                    }
                }
                else if(t%3 == 1){
                    if(t/3 + 1 >=p ){
                        c++;
                    }
                }else{
                    if(t/3 +1 >= p){
                        c++;
                    }else if(t/3 + 2 >=p && s > 0){
                        c++;
                        s--;
                    }
                }
               n--;
            }
  
            System.out.println("Case #" + ii + ": " + c );
            ii++;
            m--;
        }
        out.close();
    }
    

    public static void main(String args[]) throws Exception {
        Jam2012Q_B_S t = new Jam2012Q_B_S();
        t.Handle();
    }
}
