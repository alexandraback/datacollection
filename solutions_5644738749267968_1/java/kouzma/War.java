package com.nastya.code_jam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

public class War {

	public static void main(String args[]) {
		try {
			BufferedReader in = new BufferedReader(new FileReader("data/in/war.in"));
			PrintWriter out = new PrintWriter("data/out/war.out");

			int amount = Integer.parseInt(in.readLine());
			
			for (int k = 0; k < amount; k++) {
				int count = Integer.parseInt(in.readLine());

				String strGirl = in.readLine();
				String[] arrGirl = strGirl.split(" ");
				
				String strBoy = in.readLine();
				String[] arrBoy = strBoy.split(" ");

				ArrayList<Double> listGirl = new ArrayList<Double>();
				ArrayList<Double> listBoy = new ArrayList<Double>();
				for (int i = 0; i < count; i++) {
					listGirl.add(Double.parseDouble(arrGirl[i]));
					listBoy.add(Double.parseDouble(arrBoy[i]));
				}
				Collections.sort(listGirl);
				Collections.sort(listBoy);
				
				out.println("Case #" + (k + 1) + ": " + cheet(listGirl, listBoy) + " " + play(listGirl, listBoy));
			}
			
			in.close();
			out.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Конец!");
	}

	private static int play(ArrayList<Double> listGirl, ArrayList<Double> listBoy) {
		int size = listGirl.size();
		int score = 0;
		for (int i = 0; i < size; i++) {
			Double girlValue = listGirl.get(i);
			for (int j = listBoy.size() - 1; j >= 0; j--) {
				if (girlValue > listBoy.get(j)) {
					if (j == listBoy.size() - 1) {
						score++;
						listBoy.remove(0);
						break;
					}
					else {
						listBoy.remove(j + 1);
						break;
					}
				}
			}	
		}
		return score;
	}

	private static int cheet(ArrayList<Double> listGirl, ArrayList<Double> listBoy) {
		int size = listGirl.size();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j <= i; j++) {
				if (listGirl.get(size - 1 - i + j) < listBoy.get(j))
					return i;
			}	
		}
		return size;
	}
}
