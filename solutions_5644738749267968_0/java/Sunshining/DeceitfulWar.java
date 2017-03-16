package codes;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class DeceitfulWar {
	double[] cardsA;
	double[] cardsB;
	
	String[][] results;
	
	int totalCases;
	
	public void readFile(String fileName)  {
		File file = new File(fileName);
		FileReader fileReader;
		try {
			fileReader = new FileReader(file);
			BufferedReader bufferedReader= new BufferedReader(fileReader);
			

			
			String line = bufferedReader.readLine();
			totalCases = Integer.valueOf(line.trim());
			results = new String[totalCases][2];
			
			for (int j = 0; j < totalCases; ++j) {
				line = bufferedReader.readLine();
				int cardsNumber = Integer.valueOf(line.trim());
				cardsA = new double[cardsNumber];
				cardsB = new double[cardsNumber];
				
				line = bufferedReader.readLine();
				String[] itemsA = line.split("\\s+");
				line = bufferedReader.readLine();
				String[] itemsB = line.split("\\s+");
				
				for (int i = 0; i <cardsNumber; ++i) {
					cardsA[i] = Double.valueOf(itemsA[i]);
					cardsB[i] = Double.valueOf(itemsB[i]);
				}
				
				Arrays.sort(cardsA);
				Arrays.sort(cardsB);
				
				results[j][0] = Integer.toString(optimalDeceitfulWar());
				results[j][1] = Integer.toString(optimalWar());
			}
			
			
			bufferedReader.close();
			fileReader.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private int optimalDeceitfulWar () {
		int score = 0;
		
		int posMinA = 0;
		int posMaxA = cardsA.length-1;
		
		
		int posMinB = 0;
		int posMaxB = cardsB.length-1;
		
		for (int i = 0; i < cardsA.length; ++i) {
			if (cardsA[posMaxA] < cardsB[posMaxB]) {
				++posMinA;
				--posMaxB;
			} else {
				if (cardsA[posMinA] < cardsB[posMinB]) {
					++posMinA;
					--posMaxB;
				} else {
					++posMinA;
					++posMinB;
					++score;
				}
			}			
		}
		
		if (posMinA != cardsA.length) {
			System.out.println("error posMinA not reaching end");
		}
		
		return score;			
	}
	
	private int optimalWar() {
		
		ArrayList<Double> bCards = new ArrayList<Double>();
		
		for (int i = 0; i < cardsB.length; ++i) {
			bCards.add(cardsB[i]);
		}
		
		int score = 0;
		
		for (int i = 0; i < cardsA.length; ++i) {
			double cardA = cardsA[i];
			int posB = binarySearchPos(bCards, cardA, 0, bCards.size()-1) + 1;
			if (posB == bCards.size()) {
				score += cardsA.length - i;
				break;
			} else {
				bCards.remove(posB);
			}
		}
		
		return score;
	}
	
	private int binarySearchPos(ArrayList<Double> data, double key, int start, int end) {
		if (data.size() == 0) {
			return -1;
		}
		
		while (start <= end) {
			int mid = (start + end) /2;
			if (data.get(mid) == key) {
				start = mid+1;
				end = mid;
				break;
			} else if (data.get(mid) > key) {
				end = mid - 1;
			} else {
				start =  mid + 1;
			}
		}
		
		return end;
	}
	

	public void writeData (String fileName) { 
		File file = new File(fileName);
		try {
			if (!file.exists()) {
				file.createNewFile();
			}
			
			FileWriter fileWriter = new FileWriter(file);
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
			
			String str = "Case #";
			for (int i = 0; i < totalCases; ++i) {
				bufferedWriter.write(str+ Integer.toString(i+1) + ": " + results[i][0]
						+ " " + results[i][1] + "\n");
			}
			
			bufferedWriter.flush();
			
			bufferedWriter.close();
			fileWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	public static void main(String[] args) {
		DeceitfulWar instance = new DeceitfulWar();
		
		String fileName1 = "./data/DeceitfulWar/D-small-attempt0.in";
		String fileName2 = "./data/DeceitfulWar/D-small-attempt0.out";
		
		instance.readFile(fileName1);
		instance.writeData(fileName2);
	}
}
