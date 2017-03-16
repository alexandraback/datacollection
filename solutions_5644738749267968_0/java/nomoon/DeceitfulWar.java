/*
 * Copyright 1999-2004 Alibaba.com All right reserved. This software is the confidential and proprietary information of
 * Alibaba.com ("Confidential Information"). You shall not disclose such Confidential Information and shall use it only
 * in accordance with the terms of the license agreement you entered into with Alibaba.com.
 */
package hoho;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 类DeceitfulWar.java的实现描述：TODO 类实现描述
 * 
 * @author noMoon Apr 12, 2014 2:52:47 PM
 */
public class DeceitfulWar {

    public static void main(String[] args) throws IOException {

        File file = new File("D-small-attempt0.in.txt");
        File outputFile = new File("DeceitfulWar.out");
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
        // 这里inputstream 未指定字符集
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        String line = br.readLine();
        int issueNumber = Integer.valueOf(line);
        for (int i = 0; i < issueNumber; i++) {
            line = br.readLine();
            int blockNumber = Integer.valueOf(line);
            String[] NaomiBlocks = br.readLine().split(" ");
            String[] KenBlocks = br.readLine().split(" ");
            List<Double> NaomiWeight = new ArrayList<Double>();
            List<Double> KenWeight = new ArrayList<Double>();
            for (int j = 0; j < blockNumber; j++) {
                NaomiWeight.add(Double.valueOf(NaomiBlocks[j]));
                KenWeight.add(Double.valueOf(KenBlocks[j]));
            }
            Collections.sort(NaomiWeight);
            Collections.sort(KenWeight);
            int maxScore = 0;
            int minScore = 0;
            for (int j = 0; j < blockNumber; j++) {
                if (NaomiWeight.get(j).compareTo(KenWeight.get(j)) > 0) {
                    minScore++;
                }
            }
            maxScore = minScore;
            for (int k = 1; k < blockNumber + 1; k++) {
                List<Double> NaomiNewWeight = new ArrayList<Double>();
                for (int j = k; j < blockNumber; j++)
                    NaomiNewWeight.add(NaomiWeight.get(j));
                for (int j = 0; j < k; j++)
                    NaomiNewWeight.add(NaomiWeight.get(j));
                int tempScore = 0;
                for (int j = 0; j < blockNumber; j++) {
                    if (NaomiNewWeight.get(j).compareTo(KenWeight.get(j)) > 0) {
                        tempScore++;
                    }
                }
                if (tempScore > maxScore) maxScore = tempScore;
                if (tempScore < minScore) minScore = tempScore;
            }

            bw.write("Case #" + String.valueOf(i + 1) + ": " + String.valueOf(maxScore) + " "
                     + String.valueOf(minScore));
            bw.newLine();
        }
        br.close();
        bw.close();

    }
}
