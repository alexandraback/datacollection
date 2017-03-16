package com.yapark.codejam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Prob1AB {

	int[] taskvals;
	long e;
	long r;
	long n;
	long windowLength;
	int currentLocation;
	long currentEnergy;
	
	public Prob1AB(int[] taskvals, int e, int r, int n) {
		this.taskvals = taskvals;
		this.e = e;
		this.r = r;
		this.n = n;
		currentLocation = 0;
		currentEnergy = e;
		setWindowLength();
	}
	
	public void setWindowLength() {
		if(e%r==0) {
			windowLength = e/r;
		}
		windowLength = e/r+1;
	}
		
	public int findNextTask() {
		for(int i=1; i<windowLength && currentLocation+i<n; i++) {
			if(taskvals[currentLocation]<=taskvals[currentLocation+i]) {
				return i;
			}
		}
		return 0;
	}
	
	public long getUseEnergy(int steps) {
		long needEnergy = e-r*steps;
		if(needEnergy < 0) {
			needEnergy = 0;
		}
		return needEnergy;
	}
	
	public long findBest() {
		long reward = 0;
		while(currentLocation < n) {
			int steps = findNextTask();
			if(steps==0) {
				reward = reward + currentEnergy*taskvals[currentLocation];
				currentEnergy = r;
				currentLocation = currentLocation+1;
				continue;
			}
			long neededEnergy = getUseEnergy(steps);
			if(currentEnergy>neededEnergy) {
				reward = reward + taskvals[currentLocation] * (currentEnergy - neededEnergy);
				currentEnergy = neededEnergy;
			}
			currentLocation = currentLocation+steps;
			currentEnergy = Math.min(e, currentEnergy + r*steps);
		}
		return reward;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader("B-small-attempt3.in"));
			FileWriter fw = new FileWriter("outputBsmall.txt");
			//BufferedReader br = new BufferedReader(new FileReader("input1.txt"));
			//FileWriter fw = new FileWriter("output.txt");
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			for(int i = 1; i<=numOfGames; i++) {
				line = br.readLine();
				String[] inVals = line.split(" ");
				int e = Integer.parseInt(inVals[0]);
				int r = Integer.parseInt(inVals[1]);
				int n = Integer.parseInt(inVals[2]);
				
				line = br.readLine();
				inVals = line.split(" ");
				int[] taskvals = new int[n];
				for(int j=0; j<n; j++) {
					taskvals[j] = Integer.parseInt(inVals[j]);
				}
				
				Prob1AB prob = new Prob1AB(taskvals, e, r, n);
				
				
				bw.write("Case #"+i+": "+prob.findBest()+"\n");
			}
			br.close();
			bw.flush();
			bw.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("ERROR: Cannot find file.");
			return;
		}
		catch (IOException e) {
			
		}
	}

}
