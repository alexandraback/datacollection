/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.lang.Math;
import java.io.File;

/**
 *
 * @author Trung
 */
public class A {
    private int ncase;
    private BufferedReader reader = null;
    private int gen[];
    private double elf[];
    FileWriter write = null;

    public A() throws IOException {
        
        try {
            reader = new BufferedReader(new FileReader("I:\\Java\\GCJ\\src\\gcj\\A-small.in"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        ncase = Integer.parseInt(reader.readLine());
        elf = new double[ncase+1];
        gen = new int[ncase+1];
        for (int i=1;  i<(ncase+1);i++) {
            String frac = reader.readLine();
            String[] fraccon = frac.split("/");            
            elf[i] = Double.parseDouble(fraccon[0]) / Double.parseDouble(fraccon[1]);
            
            
            
            gen[i]=0;
            int genn = gen[i];
            boolean test = true;
            while (elf[i] != 0 && genn<41) {
                genn++;
                
                elf[i] = elf[i]*2;
                if (elf[i] >= 1) {
                    elf[i] = elf[i]-1;
                    if (test) {
                    gen[i] = genn;
                    test = false;
                    }
                    
                    
                }
                System.out.print(elf[i]+"  ");
            }
            System.out.println();
            if (genn == 41) {
                gen[i] = -1;
            }
        }
        reader.close();
    }
    
    public void out()  throws IOException {
        try {
          
          write  = new FileWriter("I:\\Java\\GCJ\\src\\gcj\\A-small.out");         
          
        } catch ( IOException e ) {
           e.printStackTrace();
        }
        PrintWriter output = new PrintWriter(write);
        for (int i =1;i<ncase+1;i++) {
            if (gen[i]==-1){
                System.out.println("Case #"+i+": impossible");
                output.println("Case #"+i+": impossible");
            }
            else {
                System.out.println("Case #"+i+": "+gen[i]);
                output.println("Case #"+i+": "+gen[i]);
            }
        }
        write.close();
    }
}
