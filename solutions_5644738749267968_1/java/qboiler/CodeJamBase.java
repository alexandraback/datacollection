/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.brycealcock.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author bryce
 */
abstract public class CodeJamBase {


    public void process(String fileName) throws IOException {
        output(fileName, readInput(fileName));
    }
    public List<Case> readInput(String fileName) throws FileNotFoundException, IOException {
        FileReader reader = new FileReader(fileName + ".in");
        BufferedReader br = new BufferedReader(reader);
        int cases = Integer.parseInt(br.readLine());
        List<Case> result = new ArrayList<>();
        for (int i = 0; i < cases; ++i) {
            result.add(readAndProcessCase(i+1, br).processCase());
        }
        return result;
    }
    
    protected void output(String fileName, List<? extends Case> cases) throws IOException {
        FileWriter reader = new FileWriter(fileName + ".out");
        try (final BufferedWriter br = new BufferedWriter(reader)) {
            for (Case case1 : cases) {
                br.write(case1.toString());
                br.newLine();
            }
            br.flush();
        }
    }

    abstract protected Case readAndProcessCase(int caseNumber, BufferedReader br) throws IOException, NumberFormatException;

}
