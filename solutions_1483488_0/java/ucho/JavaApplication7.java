/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication7;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author ucho
 */
public class JavaApplication7 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        //BitSet counted = new BitSet(2000000);
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        Scanner scanner = new Scanner(new FileReader("input"));
        int tests = scanner.nextInt();
        scanner.nextLine();
        for(int t=0;t<tests;t++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int count = 0;
            for (int n = from; n <= to; n++) {
                String asString = String.valueOf(n);
                Set<String> used = new HashSet<String>();
                for(int j=1;j<asString.length();j++) {
                    String tmp = asString.substring(j)+asString.substring(0,j);
                    if (tmp.startsWith("0")) {
                        continue;
                    }
                    if (used.contains(tmp)) {
                        continue;
                    }
                    int intTmp = Integer.valueOf(tmp);
                    if (intTmp>=from && intTmp<=to && intTmp> n) {
                        count++;
                        used.add(tmp);
                    }
                }
            }
            String msg = "Case #"+(t+1)+": "+count;
            System.out.println(msg);
            writer.println(msg);
            scanner.nextLine();
        }
        writer.close();
        
    }
}
