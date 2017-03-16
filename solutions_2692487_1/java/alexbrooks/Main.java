package app;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

	static int numCases;
	static ArrayList<String> info;
	static int maxSize;
	
	public static void main(String[] args) {
		info = new ArrayList<String>();
		readFile("Data.in");
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("Results.txt"));
			
			for (String s : info) 
				bw.write(s + "\n");
			
			bw.close();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void readFile(String filename) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			
			numCases = Integer.parseInt(br.readLine());
			//numCases = 10;
			String[] line;
			
			int currentSize, numMotes, numOps;
			ArrayList<Integer> motes;
			
			for (int i = 0; i < numCases; i++) {
				motes = new ArrayList<Integer>();
				numOps = 0;
				line = br.readLine().split(" ");
				currentSize = Integer.parseInt(line[0]);
				numMotes = Integer.parseInt(line[1]);

				line = br.readLine().split(" ");
				for (int j = 0; j < numMotes; j++)
					motes.add(Integer.parseInt(line[j]));
				
				Collections.sort(motes);
				
				System.out.println(i);
				
				for (int j = 0; j < numMotes; j++) {
					//System.out.println(currentSize + "   " + motes.get(j));
					if (currentSize > motes.get(j))
						currentSize += motes.get(j);
					else if (j == numMotes - 1)
							numOps++;
					else {
						if (motes.get(j) < 2*currentSize - 1) {
							currentSize += currentSize - 1 + motes.get(j);
							numOps++;
						}
						else {
							int temp = currentSize;
							int tempOps = 0;
							//System.out.println("Current Size: " + currentSize + "  Current Mote: " + motes.get(j));
							while (temp <= motes.get(j) && tempOps < (numMotes - j)) {
								temp += temp - 1;
								tempOps++;
								//System.out.println(temp + " - " + tempOps + " - " + (numMotes - j));

							}
							
							if (temp > motes.get(j)) {
								currentSize = temp + motes.get(j);
								numOps += tempOps;
							}
							else
								numOps++;
						}
					}
				}
				
				if (numOps > numMotes)
					numOps = numMotes;
				
				info.add("Case #" + (i+1) + ": " + numOps);
			}
			
			br.close();
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		} 
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
}
