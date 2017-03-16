/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejamround1atask1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import javax.swing.JFileChooser;

/**
 *
 * @author fgoss_000
 */
public class GoogleCodeJamRound1ATask1 {

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
        BufferedWriter out = new BufferedWriter(new FileWriter(new File(file.getParent(), "task1Solution.txt")));
        int nCases = Integer.parseInt(in.readLine());
        for(int i=0; i<nCases; i++){
            String[] words = in.readLine().split(" ");
            long r = Long.parseLong(words[0]);
            long t = Long.parseLong(words[1]);
            String solution = computeCase(r, t);
            out.write("Case #" + (i+1) + ": " + solution + "\n");
        }
        in.close();
        out.close();
    }
    
    public static String computeCase(long r, long t){
        long c = 0;
        while(t >= 2*r + 1){
            t -= (2*r + 1);
            c++;
            r +=2;
        }
        return "" + c;
    }
}
