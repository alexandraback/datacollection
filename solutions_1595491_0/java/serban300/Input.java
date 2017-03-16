/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dancing;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Serban
 */
public class Input {
    
    PrintWriter out;

    public Input(String fileName) {
        //C-large-practice.in
        try {
            out = new PrintWriter(new File("result.txt"));
            Scanner scan = new Scanner(new File(fileName));
            int T = scan.nextInt();
            scan.nextLine();
            for (int i = 0; i < T; i++) {
                int N = scan.nextInt();
                int S = scan.nextInt();
                int p = scan.nextInt();
                int[] marks = new int[N]; 
                for(int j=0;j<N;j++) {
                    marks[j] = scan.nextInt();
                }
                solve(N, S, p, marks, i);
            }
            out.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    
    private void solve(int N, int S, int p, int[] marks, int testCase) {
        out.print("Case #" + (testCase + 1) + ": ");
        int nr = 0;
        int leftS = S;
        for(int i=0;i<N;i++) {
            //System.out.print(marks[i]+" ");
            int c = marks[i];
            switch(p) {
                case 0:
                    nr++;
                    break;
                case 1:
                    if(c>=1)
                        nr++;
                    break;
                default:
                    if(c >= 3*p-2)
                        nr++;
                    else
                        if(leftS > 0 && c >= 3*p-4) {
                            nr++;
                            leftS--;
                        }
            }
        }
        System.out.println(nr);
        out.print(nr);
        out.println();
        out.flush();
    }
}
