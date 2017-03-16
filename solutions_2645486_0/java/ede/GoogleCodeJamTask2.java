/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejamtask2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JFileChooser;

/**
 *
 * @author fgoss_000
 */
public class GoogleCodeJamTask2 {

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
        BufferedWriter out = new BufferedWriter(new FileWriter(new File(file.getParent(), "task2Solution.txt")));
        int nCases = Integer.parseInt(in.readLine());
        for(int i=0; i<nCases; i++){
            String[] words = in.readLine().split(" ");
            int e = Integer.parseInt(words[0]);
            int r = Integer.parseInt(words[1]);
            words = in.readLine().split(" ");
            int[] v = new int[words.length];
            for(int j=0; j<v.length; j++)
                v[j] = Integer.parseInt(words[j]);
            int solution = computeCase(e, r, v, 0, 0, e);
            out.write("Case #" + (i+1) + ": " + solution + "\n");
        }
        in.close();
        out.close();
    }
    
    public static int computeCase(int e, int r, int[] v, int k, int cGain, int maxE){
        if(k >= v.length)
            return cGain;
        int gain = 0;
        for(int i=0; i<=e; i++)
            gain = Math.max(gain, computeCase(Math.min(e-i+r, maxE), r, v, k+1, cGain + v[k]*i, maxE));
        return gain;
    }
}
