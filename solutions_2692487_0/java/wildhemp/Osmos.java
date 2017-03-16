package com.wildhemp.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Osmos {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
	BufferedReader dis = new BufferedReader(new InputStreamReader(
		new FileInputStream(args[0])));

	int testNum = Integer.parseInt(dis.readLine());
	for (int test = 0; test < testNum; test++) {
	    String[] strs = dis.readLine().split(" ");
	    long a = Long.parseLong(strs[0]);
	    int n = Integer.parseInt(strs[1]);
	    
	    strs = dis.readLine().split(" ");
	    int[] motes = new int[n];
	    
	    for (int idx = 0; idx < n; idx ++) {
		motes[idx] = Integer.parseInt(strs[idx]);
	    }
	    
	    Arrays.sort(motes);
	    
	    System.out.println("Case #" + (test + 1) +": " + solve(a, motes, 0));
	}
    }

    public static long solve(long a, int[] motes, int idx) {
	if (a == 1) {
	    return motes.length;
	}
	if (idx >= motes.length) {
	    return 0;
	}
	long count = 0;
	if (motes[idx] >= a) {
	    long aTemp = a;
	    while (aTemp <= motes[idx]) {
		aTemp += aTemp - 1;
		count ++;
	    }
	    long ca = solve(aTemp + motes[idx], motes, idx + 1);
	    long cb = solve(a, motes, idx + 1);
	    
	    if (ca + count <= cb + 1) {
		return count + ca;
	    } else {
		return 1 + cb;
	    }
	}
	
	return solve(a + motes[idx], motes, idx + 1);
    }
    
}
