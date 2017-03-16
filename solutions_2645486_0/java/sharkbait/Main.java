/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    private int T;
    
    public static void main(String[] args) throws IOException {
        Main m = new Main();
//        String input = "D:\\examples\\CJ2013.1A.B\\demo.in";
        String input = "D:\\examples\\CJ2013.1A.B\\B-small-attempt0.in";
//        String input = "D:\\examples\\CJ2013.1A.B\\B-large.in";
        Reader r = new BufferedReader(new FileReader(new File(input)));
        m.read(r);
        m.solve();
    }
    
    private List<Case> CASES = new ArrayList<>();

    private void read(Reader r) throws IOException {
        LineNumberReader lnr = new LineNumberReader(r);
        
        String line = lnr.readLine();
        T = Integer.parseInt(line);
        
        for(int i = 0; i < T; i++) {
            CASES.add(Case.readCase(lnr));
        }
    }
    
    private void solve() {
        for(int i = 0; i < CASES.size(); i++) {
            Case c = CASES.get(i);
            String result = c.solve();
            System.out.println("Case #" + (i+1) + ": " + result);
//            System.out.println(c.toString());
        }
    }
    
}
