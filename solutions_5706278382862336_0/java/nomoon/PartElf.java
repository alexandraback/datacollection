/*
 * Copyright 1999-2004 Alibaba.com All right reserved. This software is the
 * confidential and proprietary information of Alibaba.com ("Confidential
 * Information"). You shall not disclose such Confidential Information and shall
 * use it only in accordance with the terms of the license agreement you entered
 * into with Alibaba.com.
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
 * 类PartElf.java的实现描述：TODO 类实现描述
 * 
 * @author noMoon May 11, 2014 5:06:53 PM
 */
public class PartElf {
    public static void main(String[] args) throws IOException,
	    InterruptedException {
	File file = new File("A-small-attempt2.in.txt");
	File outputFile = new File("PartElf.out");
	BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
	BufferedReader br = new BufferedReader(new InputStreamReader(
		new FileInputStream(file)));
	String line = br.readLine();
	int issueNumber = Integer.valueOf(line);
	for (int i = 0; i < issueNumber; i++) {
	    line = br.readLine();
	    String[] params = line.split("/");
	    int P = Integer.valueOf(params[0]);
	    int Q = Integer.valueOf(params[1]);
	    int m = divisor1(P, Q);
	    P = P / m;
	    Q = Q / m;
	    long pow = Math.round(Math.log(Q) / Math.log(2));
	    if (Math.pow(2.0, pow) != Q) {
		bw.write("Case #" + String.valueOf(i + 1) + ": impossible");
		bw.newLine();
	    } else {
		if (P == 1) {
		    bw.write("Case #" + String.valueOf(i + 1) + ": "
			    + String.valueOf(pow));
		    bw.newLine();
		} else {
		    long tmp = pow;
		    while (P != 1) {
			int hoho = (int) Math.pow(2, --tmp);
			if (P - hoho > 0) {
			    break;
			}
		    }
		    bw.write("Case #" + String.valueOf(i + 1) + ": "
			    + String.valueOf(pow - tmp));
		    bw.newLine();
		}
	    }

	}
	br.close();
	bw.close();
    }

    private static int divisor1(int m, int n) { // 方法一：循环法
	int temp;
	if (m < n) { // if m<n,swap m,n
	    temp = m;
	    m = n;
	    n = temp;
	}
	while (m % n != 0) {
	    temp = n;
	    n = m % n;
	    m = temp;
	}
	return n;
    }

}
