/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 *
 * @author krit
 */
public class Main {

    static class CaseThread extends Thread {

        final static int inputLineCntPerCase = 3;
        final int caseNo;
        final String[] inputStringArray;
        String result;

        private CaseThread(int _caseNo, String[] _input) {
            inputStringArray = _input;
            caseNo = _caseNo;
            result = "Case #" + caseNo + ": ";
        }

        @Override
        public void run() {
            int pieceCnt = Integer.parseInt(inputStringArray[0]);
            String[] tmp = inputStringArray[1].split(" ");
            List<Double> naomiPieces = new ArrayList<>(pieceCnt);
            List<Double> kenPieces = new ArrayList<>(pieceCnt);
            for (String a : tmp) {
                naomiPieces.add(Double.parseDouble(a));
            }
            tmp = inputStringArray[2].split(" ");

            for (String a : tmp) {
                kenPieces.add(Double.parseDouble(a));
            }
            Collections.sort(naomiPieces);
            Collections.sort(kenPieces);
            int minScore = pieceCnt, maxScore = 0;
            int i = 0, j = 0;
            for (; i < pieceCnt && j < pieceCnt; i++) {
                for (; j < pieceCnt; j++) {
                    if(naomiPieces.get(i) < kenPieces.get(j)){
                        minScore--;
                        j++;
                        break;
                    }
                }
            }
            i=0;j=0;
            for (; i < pieceCnt && j < pieceCnt; i++) {
                for (; j < pieceCnt; j++) {
                    if(kenPieces.get(i) < naomiPieces.get(j)){
                        maxScore++;
                        j++;
                        break;
                    }
                }
            }
            result += maxScore + " " + minScore;
        }
    }

    public static void main(String[] args) throws Exception {

        FileReader fr = new FileReader("D:\\CodeJam\\input.txt");
        final int caseCnt;
        ArrayList<CaseThread> threadList;
        try (BufferedReader input = new BufferedReader(fr)) {
            caseCnt = Integer.parseInt(input.readLine());
            threadList = new ArrayList<>(caseCnt);
            for (int i = 0; i < caseCnt; i++) {
                String[] inputStringArray = new String[CaseThread.inputLineCntPerCase];
                for (int j = 0; j < CaseThread.inputLineCntPerCase; j++) {
                    inputStringArray[j] = input.readLine();
                }
                CaseThread t = new CaseThread((i + 1), inputStringArray);
                threadList.add(t);
                t.start();
            }
        }

        FileWriter fw = new FileWriter("D:\\CodeJam\\output.txt");
        try (BufferedWriter output = new BufferedWriter(fw)) {
            for (int i = 0; i < caseCnt; i++) {
                CaseThread t = threadList.get(i);
                t.join();
                System.out.println(t.result);
                output.write(t.result);
                output.newLine();
            }
        }
    }
}