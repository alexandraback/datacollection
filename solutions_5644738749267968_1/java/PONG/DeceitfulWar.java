package com.pong;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

import javax.xml.bind.annotation.adapters.XmlJavaTypeAdapter.DEFAULT;

public class DeceitfulWar {

//	static String inputFileName = "Inputs/sample.in.txt";
//	static String inputFileName = "Inputs/D-small-attempt1.in.txt";
	static String inputFileName = "Inputs/D-large.in.txt";
	static String outputFileName = "output.txt";
	
	static float EPSILON = 0.00000001f;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = null;		
		int T = 0;
		
		// read the input from a file
		try {
			br = new BufferedReader(new FileReader(inputFileName));
			
			String line = br.readLine();
			T = Integer.parseInt(line);	
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
		File file = new File(outputFileName);
		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		FileWriter fw = null;
		try {
			fw = new FileWriter(file.getAbsoluteFile());
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		BufferedWriter bw = new BufferedWriter(fw);
		
		// Solve the problem
		int N = 0;
		ArrayList<Float> naomis = new ArrayList<Float>();
		ArrayList<Float> kens = new ArrayList<Float>();
		ArrayList<Float> kens2 = new ArrayList<Float>();
		
		for (int t = 1; t <= T; t++) {
			
			String line = null;
			naomis.clear();
			kens.clear();
			kens2.clear();
			
			try {
				line = br.readLine();
				N = Integer.parseInt(line);
				
				line = br.readLine();
				String[] weighs = line.split(" ");
				for (String weigh : weighs) {
					naomis.add(Float.parseFloat(weigh));
				}
				
				line = br.readLine();
				weighs = line.split(" ");
				for (String weigh : weighs) {
					kens.add(Float.parseFloat(weigh));
				}
				
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}			
			
			Collections.sort(naomis);
			Collections.sort(kens);			
			kens2.addAll(kens);		
			
//			System.out.print("N: ");
//			for (Float naomi : naomis) {
//				System.out.print(naomi + " ");
//			}
//			System.out.println();
//			
//			System.out.print("K: ");
//			for (Float ken : kens) {
//				System.out.print(ken + " ");
//			}
//			System.out.println();
			
			int war = 0;
			int deceifulWar = 0;					
			
			// play war
			for (float naomi : naomis) {
				// find the next higher weigh in Ken's blocks
				int index = Collections.binarySearch(kens, naomi);
				
				index++;
				if (index < 0) {
					index = index * -1;
				}
				if (index > kens.size() - 1) {
					// ken will have to choose his highest block
					index--;
				}
				if (kens.get(index) < naomi) {
					war++;
				}
				kens.remove(index);
			}
			

			// Let's play deceitful war
			while (naomis.size() > 0) {
				
				if (naomis.get(0) > kens2.get(0)) {
					// naomi get win with the smallest block
					deceifulWar++;
					naomis.remove(0);
					kens2.remove(0);
				}
				else {
					// naomi uses the smallest block to get ken's largest block
					naomis.remove(0);
					kens2.remove(kens2.size() - 1);
				}
			}					
			
			try {
				System.out.println(String.format("Case #%d: %d %d", t, deceifulWar, war));
				bw.write(String.format("Case #%d: %d %d\n", t, deceifulWar, war));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		try {
			br.close();
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("done");
	}

}
