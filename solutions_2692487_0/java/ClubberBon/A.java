package com.boney;

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import com.google.common.collect.Lists;
import com.google.common.primitives.Ints;

public class A {
	
	public static final String INPUT_FILE = "C:/Play/A-input.txt";
	public static final String OUTPUT_FILE = "C:/Play/A-ouput.txt";
	
	public static void main(String[] args) {
		A t = new A();
		try {
			t.doTheJob();
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}
	
	private void doTheJob() throws Exception {
		Scanner in = new Scanner(new File(INPUT_FILE));
		FileWriter fw = new FileWriter(new File(OUTPUT_FILE));
		int totalTestCases = in.nextInt();
		System.out.println("Total test cases " + totalTestCases);
		for (int i = 0; i < totalTestCases; i++) {
			int mainMote = in.nextInt();
			int origMote = mainMote;
			int otherMotesSize = in.nextInt();
			int otherMotes[] = new int[otherMotesSize];
			for (int j = 0; j < otherMotes.length; j++) {
				otherMotes[j] = in.nextInt();
			}
			Arrays.sort(otherMotes);
			List<Integer> sortedList = new ArrayList<Integer>();
			for(int x : otherMotes) {
				sortedList.add(x);
			}
			int opCount = 0;
			int mainLength = sortedList.size();
			for (int j = 0; j < mainLength; j++) {
				if(mainMote > sortedList.get(j)) {
					mainMote = mainMote + sortedList.get(j);
				} else {
					if(j == otherMotes.length - 1) {
						sortedList.set(j, 0);
						opCount++;
					} else {
						int nodesLeft = mainLength - j;
						// max operations is nodesleft
						int tmpMainMote = mainMote;
						int tmpOpCount = opCount;
						while(nodesLeft > 0) {
							if(tmpMainMote - 1 == 0) {
								break;
							}
							System.out.println("Adding mote " + (tmpMainMote - 1) + " curr mote " + tmpMainMote);
							tmpMainMote = tmpMainMote + tmpMainMote - 1;
							tmpOpCount++;
							if(tmpMainMote > sortedList.get(j)) {
								break;
							}
							nodesLeft--;
						}
						if(tmpMainMote <= sortedList.get(j)) {
							opCount += (mainLength - j); // To remove them all
							break;
						} else {
							opCount = tmpOpCount;
							mainMote = tmpMainMote;
							mainMote = mainMote + sortedList.get(j);
						}
						if(opCount == mainLength) {
							break;
						}
					}
				}
			}
			System.out.println(sortedList);
			System.out.println("Case #" + (i + 1) + ": " + opCount + " original mote " + origMote);
			fw.write("Case #" + (i + 1) + ": " + opCount + "\n");
		}
		fw.flush();
		fw.close();
	}
	
}
