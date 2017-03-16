/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerese;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Kocmi
 */
public class Googlerese {
    public static void main(String[] args) {
        try {  
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st;
            String line;

            st = new StringTokenizer(br.readLine());
            int lines = Integer.parseInt(st.nextToken());
            String[] s = new String[lines];
            //load files
            for (int i = 0; i < lines; i++) {
                s[i] = br.readLine();
            }
            for (int i = 0; i < lines; i++) {
                System.out.print("Case #"+ (i+1) +": ");
                char[] c = transmute(s[i]);
                for (int j = 0; j < c.length; j++) {
                    System.out.print(c[j]);
                }
                System.out.println("");
            }
        } catch (Exception ex) {
        }
    }
    
    public static char[] transmute(String s){
        char[] code = { 'y',
                        'h',
                        'e',
                        's',
                        'o',
                        'c',
                        'v',
                        'x',
                        'd',
                        'u',
                        'i',
                        'g',
                        'l',
                        'b',
                        'k',
                        'r',
                        'z',
                        't',
                        'n',
                        'w',
                        'j',
                        'p',
                        'f',
                        'm',
                        'a',
                        'q'
        };
        char[] c = s.toCharArray();
        for (int i = 0; i < c.length; i++) {
            if(c[i]==32){continue;}
            c[i] = code[((int)c[i])-97];
        }
        return c;
    }
}
