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

/**
 * 类CookieClicker.java的实现描述：TODO 类实现描述
 * 
 * @author noMoon Apr 12, 2014 1:46:19 PM
 */
public class CookieClicker {

    public static void main(String[] args) throws IOException {

        File file = new File("B-small-attempt1.in.txt");
        File outputFile = new File("CookieClicker.out");
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
        // 这里inputstream 未指定字符集
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        String line = br.readLine();
        int issueNumber = Integer.valueOf(line);
        for (int i = 0; i < issueNumber; i++) {

            line = br.readLine();
            String[] inputList = line.split(" ");
            double C = Double.valueOf(inputList[0]);
            double F = Double.valueOf(inputList[1]);
            double X = Double.valueOf(inputList[2]);
            double time = X / 2.0;
            int farmNumber = 0;
            double formortime = 9999999999999999999999.0;
            while (formortime > time) {
                farmNumber++;
                double tempTime = 0.0;
                double rate = 2.0;
                for (int j = 0; j < farmNumber; j++) {
                    tempTime += C / rate;
                    rate += F;
                }
                tempTime += X / rate;
                formortime = time;
                time = tempTime;
            }
            bw.write("Case #" + String.valueOf(i + 1) + ": " + String.valueOf(formortime));
            bw.newLine();
        }
        br.close();
        bw.close();

    }

}
