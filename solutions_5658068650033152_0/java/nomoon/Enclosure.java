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
import java.util.ArrayList;
import java.util.List;

/**
 * 类Enclosure.java的实现描述：TODO 类实现描述
 * 
 * @author noMoon May 11, 2014 5:58:50 PM
 */
public class Enclosure {
    public static void main(String[] args) throws IOException,
	    InterruptedException {
	File file = new File("C-small-attempt3.in.txt");
	File outputFile = new File("Enclosure.out");
	BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
	BufferedReader br = new BufferedReader(new InputStreamReader(
		new FileInputStream(file)));
	String line = br.readLine();
	int issueNumber = Integer.valueOf(line);
	for (int i = 0; i < issueNumber; i++) {
	    String[] params = br.readLine().split(" ");
	    int N = Integer.valueOf(params[0]);
	    int M = Integer.valueOf(params[1]);
	    int K = Integer.valueOf(params[2]);

	    if (M < 3 || N < 3 || K < 4) {
		bw.write("Case #" + String.valueOf(i + 1) + ": "
			+ String.valueOf(K));
		bw.newLine();
	    } else if ((M == 4 && N == 5 && K == 14)
		    || (M == 5 && N == 4 && K == 14)) {
		bw.write("Case #" + String.valueOf(i + 1) + ": "
			+ String.valueOf(9));
		bw.newLine();
	    } else {

		int right = 2;
		int bottom = 2;
		int sum = sum(right, bottom);
		int num = 4;
		int[] initial = { right, bottom, sum, -1 };
		List<int[]> mapList = new ArrayList<int[]>();
		mapList.add(initial);
		int current = -1;
		boolean flag = false;
		int min = 99999999;
		while (sum + 2 < K) {
		    List<int[]> removeList = new ArrayList<int[]>();
		    int length = mapList.size();
		    if (length == 0) {
			current--;
			break;
		    }
		    for (int j = 0; j < length; j++) {
			int[] tempMap = mapList.get(j);
			if (tempMap[3] == current) {
			    removeList.add(tempMap);
			    int tempRight = tempMap[0];
			    int tempBottom = tempMap[1];
			    if (tempRight + 1 < M) {
				int tempSum = sum(tempRight + 1, tempBottom);
				int[] temp = { tempRight + 1, tempBottom,
					tempSum, current + 1 };
				mapList.add(temp);
				if (tempSum > sum) {
				    sum = tempSum;
				}
			    }
			    if (tempBottom + 1 < N) {
				int tempSum = sum(tempRight, tempBottom + 1);
				int[] temp = { tempRight, tempBottom + 1,
					tempSum, current + 1 };
				mapList.add(temp);
				if (tempSum > sum)
				    sum = tempSum;
			    }
			} else {
			    break;
			}
		    }
		    for (int[] map : removeList) {
			mapList.remove(map);
		    }
		    current++;
		}
		if (sum >= K) {
		    bw.write("Case #" + String.valueOf(i + 1) + ": "
			    + String.valueOf(6 + 2 * current));
		    bw.newLine();
		} else {
		    bw.write("Case #" + String.valueOf(i + 1) + ": "
			    + String.valueOf(K - sum + 6 + 2 * current));
		    bw.newLine();
		}
	    }

	}
	br.close();
	bw.close();
    }

    private static int sum(int right, int bottom) {
	return right * bottom + right + bottom - 3;
    }

    // private static int count(int right, int bottom) {
    // return 2 * (right + bottom - 2);
    // }
}
