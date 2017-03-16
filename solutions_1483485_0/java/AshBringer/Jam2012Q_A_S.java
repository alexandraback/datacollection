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
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author violetlily
 */
public class Jam2012Q_A_S {

    private final String ipath = "A-small-attempt0.in";
    private final String opath = "A-small-attempt0.ou";
    private final String map = "yhesocvxduiglbkrztnwjpfmaq";

    public void Handle() throws FileNotFoundException {
        
        PrintStream out = new PrintStream(   
                new BufferedOutputStream(   
                        new FileOutputStream(opath)));   
        System.setOut(out);
        
        Scanner sc = new Scanner(new FileInputStream(new File(ipath)));
        int n = sc.nextInt();
        int ii = 0;
        while (n >= 0) {
            String g = sc.nextLine();
            StringBuffer sb = new StringBuffer();
            for(int i = 0 ; i < g.length() ; i ++){
                char t = g.charAt(i);
                if(Character.isLowerCase(t)){
                    sb.append(map.charAt(t-'a'));
                }
                else{
                    sb.append(" ");
                }
            }
            String s = sb.toString();
            System.out.println("Case #" + ii + ": " + s);
            ii++;
            --n;
        }
        out.close();
    }
    
    

    public static void main(String args[]) throws Exception {
        Jam2012Q_A_S t = new Jam2012Q_A_S();
        t.Handle();
    }
}
