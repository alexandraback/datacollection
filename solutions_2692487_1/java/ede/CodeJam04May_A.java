/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam04may_a;

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
public class CodeJam04May_A {

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
            int a = Integer.parseInt(words[0]);
            words = in.readLine().split(" ");
            ArrayList<Integer> list = new ArrayList<Integer>();
            for(int j=0; j<words.length; j++)
                list.add(new Integer(words[j]));
            int solution = computeCase(a, list);
            out.write("Case #" + (i+1) + ": " + solution + "\n");
        }
        in.close();
        out.close();
    }

    public static int computeCase(int a, ArrayList<Integer> list){
        Collections.sort(list);
        System.out.println("a: " + a + ", list: " + list);
        int op = 0;
        int listSize = list.size();
        int opDelTail = listSize;
        if(a <= 1)
            return listSize;
        Iterator<Integer> it = list.iterator();
        for(int i=0; it.hasNext(); i++){
            int m = it.next();
            if(m < a)
                a += m;
            else{
                int ins = 0;
                while(a + (a-1)*(Math.pow(2, ins)-1) <= m){
                    ins++;
                }
                int del = listSize - i;
                opDelTail = Math.min(op + del, opDelTail);
                op += ins;
                a += (a-1)*(Math.pow(2, ins)-1) + m;
                if(del < ins)
                    return opDelTail;
            }
        }
        return Math.min(opDelTail, op);
    }
}
