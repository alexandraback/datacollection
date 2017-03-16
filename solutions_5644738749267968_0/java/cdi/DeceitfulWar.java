package com.gmail.danielcomsa.codejam.y2014.qualification;

import com.gmail.danielcomsa.codejam.Utility;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.Arrays;

/**
 * Created by daniel on 4/13/14.
 */
public class DeceitfulWar {

    public static void main(String[] args) throws IOException {
//        String file = "C-large.in";
//        String file = "sample";
        String file = "D-small-attempt0.in";

        BufferedReader reader = Utility.getReader(DeceitfulWar.class, file);
        PrintStream out = Utility.getPrintStream(DeceitfulWar.class, file);
        int testCases = Utility.readInt(reader);
        DeceitfulWar deceitfulWar = new DeceitfulWar();
        for (int i = 1; i <= testCases; i++) {
            int numberOfBlocks = Utility.readInt(reader);
            BigDecimal[] naomis = sort(Utility.readBigDecimals(reader));
            BigDecimal[] kens = sort(Utility.readBigDecimals(reader));

            int playDeceitfulWar = deceitfulWar.playDeceitfulWar(naomis, kens);
            int playWar = deceitfulWar.playWar(naomis, kens);
            String result = "Case #" + i + ": " + playDeceitfulWar + " " + playWar;
//            System.out.println(Arrays.toString(naomis));
//            System.out.println(Arrays.toString(kens));
//            System.out.println(playDeceitfulWar + " " + playWar);
            out.println(result);
            System.out.println(result);
        }
        out.flush();
        out.close();

    }

    private static BigDecimal[] sort(BigDecimal[] bigDecimals) {
        for (int i = 0; i < bigDecimals.length - 1; i++) {
            for (int j = i + 1; j < bigDecimals.length; j++) {
                if (bigDecimals[i].compareTo(bigDecimals[j]) > 0) {
                    BigDecimal aux = bigDecimals[i];
                    bigDecimals[i] = bigDecimals[j];
                    bigDecimals[j] = aux;
                }
            }
        }
        return bigDecimals;
    }

    public int playWar(BigDecimal[] naomis, BigDecimal[] kens) {
        int naomisPoints = 0;
        for (int i = 0; i < naomis.length; i++) {
            int index = -1;
            for (int j = 0; j < kens.length; j++) {
                if (kens[j] != null) {
                    if (kens[j].compareTo(naomis[i]) > 0) {
                        index = j;
                        break;
                    } else if (index == -1) {
                        index = j;
                    }
                }
            }
            if (naomis[i].compareTo(kens[index]) > 0) {
                naomisPoints++;
            }
            kens[index] = null;
        }
        return naomisPoints;
    }

    public int playDeceitfulWar(BigDecimal[] naomisOrig, BigDecimal kens[]) {
        BigDecimal[] naomis = new BigDecimal[naomisOrig.length];
        System.arraycopy(naomisOrig, 0, naomis, 0, naomis.length);
        int naomisPoints = 0;
        for (int i = 0; i < kens.length; i++) {
            int index = -1;
            for (int j = 0; j < naomis.length; j++) {
                if (naomis[j] != null) {
                    if (naomis[j].compareTo(kens[i]) > 0) {
                        index = j;
                        break;
                    } else if (index == -1) {
                        index = j;
                    }
                }
            }
            if (kens[i].compareTo(naomis[index]) < 0) {
                naomisPoints++;
            }
            naomis[index] = null;
        }
        return naomisPoints;
    }
}
