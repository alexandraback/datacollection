package com.nus.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class Dijkstra {
    // public static Complex I = new Complex(1, 'i');
    // public static Complex J = new Complex(1, 'j');
    // public static Complex K = new Complex(1, 'k');
    // public static Complex ONE = new Complex(1, '1');

    public static Complex XpowIs[] = null;

    public static Complex XpowI(int pow) {
        return XpowIs[pow % 4];
    }

    public static void init(char chars[], int repetitions) {
        Complex currentChar = new Complex(1, '1');
        for (int i = 0; i < chars.length; ++i) {
            currentChar = currentChar.multiply(new Complex(1, chars[i]));
        }
        Complex X = new Complex(currentChar);
        XpowIs = new Complex[Math.min(4 + repetitions % 4, repetitions) + 1];
        XpowIs[0] = new Complex(1, '1');
        for (int i = 1; i < XpowIs.length; ++i) {
            XpowIs[i] = currentChar;
            currentChar = currentChar.multiply(X);
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new FileReader(new File(args[0])));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File(args[1]))));
        int iterationsNum = Integer.parseInt(br.readLine());

        for (int i = 0; i < iterationsNum; ++i) {
            String[] line = br.readLine().split("\\s+");
            int stringLength = Integer.parseInt(line[0]);
            int repNum = Integer.parseInt(line[1]);

            char chars[] = br.readLine().toCharArray();
            init(chars, repNum);

            if (!XpowIs[XpowIs.length - 1].equals(new Complex(-1, '1'))) {
                bw.write("Case #" + (i + 1) + ": NO" + "\n");
                continue;
            }
            // Find first index of i.
            int iIndex = -1;
            int iPower = 0;
            Complex currentChar = new Complex(1, '1');
            for (iPower = 0; iPower < Math.min(repNum, 6); ++iPower) {
                for (int c = 0; c < stringLength; ++c) {
                    currentChar = currentChar.multiply(new Complex(1, chars[c]));
                    if (currentChar.equals(new Complex(1, 'i'))) {
                        iIndex = c;
                        break;
                    }
                }
                if (iIndex != -1) {
                    break;
                }
            }
            if (iIndex == -1) {
                bw.write("Case #" + (i + 1) + ": NO" + "\n");
                continue;
            }

            // Find last index of j.
            int kIndex = -1;
            int kPower = 0;
            currentChar = new Complex(1, '1');
            for (kPower = 0; kPower < Math.min(repNum, 6); ++kPower) {
                for (int c = stringLength - 1; c >= 0; --c) {
                    currentChar = new Complex(1, chars[c]).multiply(currentChar);
                    if (currentChar.equals(new Complex(1, 'k'))) {
                        kIndex = c;
                        break;

                    }
                }
                if (kIndex != -1) {
                    break;
                }
            }
            if (kIndex == -1) {
                bw.write("Case #" + (i + 1) + ": NO" + "\n");
                continue;
            }

            if ((iPower + kPower == (repNum - 1) && iIndex < kIndex) || iPower + kPower < (repNum - 1)) {
                bw.write("Case #" + (i + 1) + ": YES" + "\n");
                continue;
            }

            bw.write("Case #" + (i + 1) + ": NO" + "\n");

        }

        br.close();
        bw.close();

    }
}
