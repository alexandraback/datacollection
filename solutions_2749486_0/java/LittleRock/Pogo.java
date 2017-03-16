/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package com.demister.gcj;


import java.util.*;
import java.io.*;


/**
 *
 * @author rock
 */
public class Pogo {

    public Pogo() {
    }
    
    public String getPath(int x, int y) {
        StringBuilder reval = new StringBuilder();
        if (x > 0) {
            for (int i = 0; i < x; i++) {
                reval.append("WE");
            }
        } else if (x < 0) {
            for (int i = 0; i < -x; i++) {
                reval.append("EW");
            }
        }
        
        if (y > 0) {
            for (int i = 0; i < y; i++) {
                reval.append("SN");
            }
        } else if (y < 0) {
            for (int i = 0; i < -y; i++) {
                reval.append("NS");
            }
        }
        
        return reval.toString();
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
        Pogo dealer = new Pogo();

        int numOfTests = in.nextInt();

        for (int i = 0; i < numOfTests; i++) {
            out.printf("Case #%d: ", i + 1);

            // Todo
            int x = in.nextInt();
            int y = in.nextInt();
            out.print(dealer.getPath(x, y));

            out.println();
            out.flush();
        }

        in.close();
        out.close();
    }
}
