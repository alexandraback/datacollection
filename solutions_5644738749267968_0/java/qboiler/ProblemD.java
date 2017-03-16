/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.brycealcock.codejam.y2014.qr;

import com.brycealcock.codejam.Case;
import com.brycealcock.codejam.CodeJamBase;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

/**
 *
 * @author bryce
 */
public class ProblemD extends CodeJamBase {

    @Override
    protected Case readAndProcessCase(int caseNumber, BufferedReader br) throws IOException, NumberFormatException {
        Scanner s = new Scanner(br.readLine());
        int blocks = s.nextInt();
        Scanner herl = new Scanner(br.readLine());
        TreeSet<Double> her = new TreeSet<Double>();
        TreeSet<Double> his = new TreeSet<Double>();
        for (int i = 0; i < blocks; ++i) {
            her.add(herl.nextDouble());
            //  his.add(hisl.nextDouble());
        }
        Scanner hisl = new Scanner(br.readLine());
        for (int i = 0; i < blocks; ++i) {
            //   her.add(herl.nextDouble());
            his.add(hisl.nextDouble());
        }
        return new PCase(caseNumber, her, his);
    }

    class PCase extends Case {

        TreeSet<Double> herSet;
        TreeSet<Double> hisSet;
        int c;

        PCase(int caseNumber, TreeSet<Double> her, TreeSet<Double> his) {
            super(caseNumber);
            hisSet = his;
            herSet = her;
            c = caseNumber;
        }
        String result = "";

        @Override
        protected String caseResult() {
            return result;
        }

        @Override
        protected Case processCase() {
            int herHonestScore = 0;
            ArrayList<Double> hisSetHonest = new ArrayList<Double>(hisSet);
            ArrayList<Double> herSetHonest = new ArrayList<Double>(herSet);
            Collections.sort(hisSetHonest);
            Collections.sort(herSetHonest);
            int size1 = hisSetHonest.size();
            for (int i = 0; i < size1; ++i) {
                double herValue = herSetHonest.remove(herSetHonest.size() - 1);
                boolean hasLarger = false;
                int indexToRemove = 0;
                for (int j = hisSetHonest.size() - 1; j >= 0; --j) {
                    if (herValue < hisSetHonest.get(j)) {
                        hasLarger = true;
                        indexToRemove = j;
                    } else {
                        break;
                    }
                }
                if (herValue > hisSetHonest.remove(indexToRemove)) {
                    herHonestScore++;
                } else {
//                    hisSetHonest.remove(indexToRemove);
                }
            }
            hisSetHonest = new ArrayList<Double>(hisSet);
            herSetHonest = new ArrayList<Double>(herSet);
            Collections.sort(hisSetHonest);
            Collections.sort(herSetHonest);
            int herCheatingScore = 0;
            int size = hisSetHonest.size();
            for (int i = 0; i < size; ++i) {
                System.out.println(c + "::" + i + ":" + hisSetHonest + " : " + herSetHonest);

                double herHigh = herSetHonest.get(herSetHonest.size() - 1);
                double herLow = herSetHonest.get(0);
                double hisHigh = hisSetHonest.get(herSetHonest.size() - 1);
                double hisLow = hisSetHonest.get(0);
                double Hisremove =-1;
                double herremove =-1;
                if (herLow < hisLow) {
                    // remove his high and her low.
                    Hisremove =hisSetHonest.remove(hisSetHonest.size() - 1);
                    herremove = herSetHonest.remove(0);
                    assert Hisremove>herremove;
                    
                                    
                } else if (herHigh > hisHigh) {
                    // We have to find her record to remove.
                    boolean hasLarger = false;
                    int indexToRemove = 0;
                    for (int j = hisSetHonest.size() - 1; j >= 0; --j) {
                        if (hisHigh < herSetHonest.get(j)) {
                            hasLarger = true;
                            indexToRemove = j;
                        } else {
                            break;
                        }
                    }
                    assert hasLarger;

                    // remove his low and her high;
                    herremove = herSetHonest.remove(indexToRemove);
                    Hisremove = hisSetHonest.remove(hisSetHonest.size()-1);
                    ++herCheatingScore;
                    assert Hisremove<herremove;

                } else {
                    // remove his high and her low.
                    Hisremove = hisSetHonest.remove(hisSetHonest.size() - 1);
                    herremove = herSetHonest.remove(0);
                    assert Hisremove>herremove;
                }
            System.out.println("his: " + Hisremove + " her:" + herremove);
            }

            result = " " + herCheatingScore + " " + herHonestScore;
            return this;
        }
    }
}
