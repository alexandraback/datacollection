/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

/**
 *
 * @author Manzha
 */
public class CodeJam {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner leer = new Scanner(new File("src/A-small-attempt0.in"));
        //FileWriter write = new FileWriter(new File("src/problemaA.out"));
        BufferedWriter salida = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/problemaA.out")));
        int t = leer.nextInt();
        String s;
        int n;
        String sub;
        int continuas=0;
        int res=0;
        for (int i = 0; i < t; i++) {
            res=0;
            s = leer.next();
            n = leer.nextInt();
            for (int j = 0; j < s.length(); j++) {
                for (int k = j + n; k < s.length()+1; k++) {
                    sub = s.substring(j, k);
                    continuas=0;
                    for (int l = 0; l < sub.length(); l++) {
                        char subs = sub.charAt(l);
                        if (subs != 'a' && subs != 'e' && subs != 'i' && subs != 'o' && subs != 'u') {
                            continuas++;
                        }else{
                            continuas=0;
                            //System.out.println("reinicioo  " +sub);
                        }
                        if(continuas==n){
                            res++;
                            continuas=0;
                           // System.out.println(sub);
                            break;
                        }
                    }
                }
            }
            System.out.println("Case #"+(i+1)+": "+res);
            salida.write("Case #"+(i+1)+": "+res+"\n");
        }
        salida.close();
    }
}
