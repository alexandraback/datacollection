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

/**
 *
 * @author krit
 */
public class Main {

    static class CaseThread extends Thread {

        final static int inputLineCntPerCase = 1;
        int caseNo;
        private String result;
        final String[] inputStringArray;

        private CaseThread(int _caseNo, String[] _input) {
            inputStringArray = _input;
            caseNo = _caseNo;
        }

        @Override
        public void run() {
            result = "Case #" + caseNo + ":";
            final String[] input = inputStringArray[0].split(" ");
            final int row = Integer.parseInt(input[0]);
            final int column = Integer.parseInt(input[1]);
            final int mineCnt = Integer.parseInt(input[2]);
            final int blockCnt = row * column;
            final int nonMineCnt = blockCnt - mineCnt;

            int nonMineLeft = nonMineCnt;
            int x = 0, y = 0;
            try {
                if ((mineCnt == 0) || (row == 1) || (column == 1) || (nonMineCnt == 1)) {
                    throw new Exception("Fill");
                } else if (((row == 2) || (column == 2)) && (nonMineCnt % 2 == 1)) {
                    throw new Exception("Impossible");
                } else if (nonMineCnt >= 4 && (nonMineCnt != 5) && (nonMineCnt != 7)) {
                    //First row
                    nonMineLeft -= 4;
                    result += System.lineSeparator() + "..";
                    String row2 = "..";
                    x += 2;
                    for (; (x < column) && (nonMineLeft != 3) && (nonMineLeft > 0); x++) {
                        result += ".";
                        row2 += ".";
                        nonMineLeft -= 2;
                    }
                    for (; x < column; x++) {
                        result += "*";
                        row2 += "*";
                    }
                    result += System.lineSeparator() + row2;
                    x = 0;
                    y += 2;
                    //Next row
                    while (nonMineLeft > 0) {
                        result += System.lineSeparator() + "..";
                        x += 2;
                        nonMineLeft -= 2;
                        for (; (x < column) && !((nonMineLeft == 3) && (column - x < 3) && (x > 2)) && !((nonMineLeft == 2) && (y < row - 1)) && (nonMineLeft > 0); x++) {
                            result += ".";
                            nonMineLeft--;
                        }
                        for (; x < column; x++) {
                            result += "*";
                        }
                        y++;
                        x = 0;
                    }
                    throw new Exception("Fill");
                } else {
                    throw new Exception("Impossible");
                }
            } catch (Exception e) {
                if ("Impossible".equals(e.getMessage())) {
                    result += System.lineSeparator() + "Impossible";
                    nonMineLeft = 0;
                } else { //Fill
                    for (; y < row; y++) {
                        if (x == 0) {
                            result += System.lineSeparator();
                        }
                        for (; x < column; x++) {
                            if (nonMineLeft > 0) {
                                result += ".";
                                nonMineLeft--;
                            } else {
                                result += "*";
                            }
                        }
                        x = 0;
                    }
                    result = result.replaceFirst("\\.", "c");
                }
            }
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
                output.write(t.result);
                output.newLine();
            }
        }
    }
}