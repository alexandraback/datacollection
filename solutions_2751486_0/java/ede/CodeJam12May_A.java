/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam12may_a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import javax.swing.JFileChooser;

/**
 *
 * @author fgoss_000
 */
public class CodeJam12May_A {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFileChooser fc = new JFileChooser("C:\\Users\\fgoss_000\\Desktop");
        int res = fc.showOpenDialog(null);
        if(res == JFileChooser.APPROVE_OPTION){
            File file = fc.getSelectedFile();
            try{
                computeFile(file);
                System.out.println("done. ");
            }catch(FileNotFoundException ex){
                System.err.println("file not found: " + ex);
            } catch (IOException ex) {
                System.err.println("io exception: " + ex);
            }
        }
    }

    public static void computeFile(File file) throws FileNotFoundException, IOException{
        BufferedReader in = new BufferedReader(new FileReader(file));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File(file.getParent(), "solution_A.txt")));
        int nCases = Integer.parseInt(in.readLine());
        for(int i=0; i<nCases; i++){
            String[] words = in.readLine().split(" ");
            int n = Integer.parseInt(words[1]);
            int solution = computeCase(words[0], n);
            out.write("Case #" + (i+1) + ": " + solution + "\n");
        }
        in.close();
        out.close();
    }

    public static int computeCase(String name, int n){
        int sum = 0;
        int iCons = -1;
        int consCons = 0;
        for(int i=0; i<name.length(); i++){
            if(isVowel(name.charAt(i)))
                consCons = 0;
            else 
                consCons++;
            if(consCons >= n)
                iCons = i+1-n;
            if(iCons != -1)
                sum += iCons+1;
        }
        return sum;
    }
    
    public static boolean isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public static boolean isCons(char c){
        return !isVowel(c);
    }
}
