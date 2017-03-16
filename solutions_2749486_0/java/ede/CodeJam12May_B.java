/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam12may_b;

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
public class CodeJam12May_B {

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
        BufferedWriter out = new BufferedWriter(new FileWriter(new File(file.getParent(), "solution_B.txt")));
        int nCases = Integer.parseInt(in.readLine());
        for(int i=0; i<nCases; i++){
            String[] words = in.readLine().split(" ");
            int x = Integer.parseInt(words[0]);
            int y = Integer.parseInt(words[1]);
            String solution = computeCase(x, y);
            out.write("Case #" + (i+1) + ": " + solution + "\n");
        }
        in.close();
        out.close();
    }

    public static String computeCase(int x, int y){
        int posX = 0;
        int posY = 0;
        StringBuilder sb = new StringBuilder();
        int d = 1;
        
        //approximation 
        while(d < 2*y){
            y -= d++;
            sb.append("N");
        }
        while(d < 2*(-y)){
            y += d++;
            sb.append("S");
        }
        while(d < 2*x){
            x -= d++;
            sb.append("E");
        }
        while(d < 2*(-x)){
            x += d++;
            sb.append("W");
        }
        
        
        //correction 
        while(x < 0){
            sb.append("EW");
            x++;
        }
        while(x > 0){
            sb.append("WE");
            x--;
        }
        while(y < 0){
            sb.append("NS");
            y++;
        }
        while(y > 0){
            sb.append("SN");
            y--;
        }
        
        String solution = sb.toString();
        if(solution.length() > 500)
            System.out.println("ups! " + solution.length());
        return solution;
    }
}
