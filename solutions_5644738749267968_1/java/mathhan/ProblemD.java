package codejam.y2014.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Random;

public class ProblemD {
		
	
	public ProblemD() {
	}
	
	
	             

	ArrayList<Double> stringToArray(String line, int size) {
		String[] sp = line.split(" ");
		ArrayList<Double> array = new ArrayList<Double>(sp.length);
		for (int i=0; i<sp.length; i++) {
			array.add(Double.valueOf(sp[i]));
		}
		Collections.sort(array);
		return array;
	}
	
	public ArrayList<Double> copyDoubleArray(ArrayList<Double> input) {
		ArrayList<Double> output = new ArrayList<Double>();
		for (int i=0; i<input.size(); i++) {
			output.add(input.get(i));
		}
		return output;
	}
	
	public int getDeceitfulOptimalScore(ArrayList<Double> NaomiMasses, ArrayList<Double> KenMasses) {
		while(NaomiMasses.size() > 0) {
			int pos = this.getPos(NaomiMasses, KenMasses);
			if (pos >= 0) {
				NaomiMasses.remove(0);
				KenMasses.remove(KenMasses.size() - 1);
			} else if (pos < 0) {
				return NaomiMasses.size();
			}
		}
		return NaomiMasses.size();
	}
	
	
	public int getOptimalWarScore(ArrayList<Double> NaomiMasses, ArrayList<Double> KenMasses) {
		while(NaomiMasses.size() > 0) {
			
			Double val = NaomiMasses.get(0);
			
			int pos = this.getPos2(val, KenMasses);
			if (pos >= 0) {
				NaomiMasses.remove(0);
				KenMasses.remove(pos);
			} else if (pos < 0) {
				return NaomiMasses.size();
			}
		}
		return NaomiMasses.size();
	}
	
	int getPos2(Double value, ArrayList<Double> KenMasses) {
		for (int i=0; i<KenMasses.size(); i++) {
			if (value <= KenMasses.get(i)) {
				return i;
			} 
		}
		return -1;
	}
	
	int getPos(ArrayList<Double> NaomiMasses, ArrayList<Double> KenMasses) {
		for (int i=0; i<NaomiMasses.size(); i++) {
			if (NaomiMasses.get(i) >= KenMasses.get(i)) {
				continue;
			}
			return i;
		}
		return -1;
	}
	
	
	
	String readBlock(BufferedReader br) throws IOException {
		
		int size = Integer.parseInt(br.readLine());
	
		String line_1 = br.readLine();
		String line_2 = br.readLine();
		
		ArrayList<Double> list_1 = this.stringToArray(line_1, size);
		ArrayList<Double> list_2 = this.stringToArray(line_2, size);
		
		int deceitfulOptimalScore = this.getDeceitfulOptimalScore(copyDoubleArray(list_1), copyDoubleArray(list_2));
		int warOptimalScore = this.getOptimalWarScore(copyDoubleArray(list_1), copyDoubleArray(list_2));
		System.out.println(deceitfulOptimalScore);
		System.out.println(warOptimalScore);
		return deceitfulOptimalScore + " " + warOptimalScore;
		
	}
	
	
	public ArrayList<String> read(BufferedReader br) throws NumberFormatException, IOException {
		ProblemD problemA = new ProblemD();
		 ArrayList<String> results = new  ArrayList<String>();
		int cases = Integer.parseInt(br.readLine());
		for (int i=1; i<=cases; i++) {
			String result = problemA.readBlock(br);
			results.add("Case #" + i + ": " + result);
		}
		return results;
	}
	
	
	public ArrayList<String> read(String file) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(file));
		ArrayList<String> results = this.read(br);
		br.close();
		return results;
	}
	
	
	
	public void writeResult(ArrayList<String> results, String output) throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		for (int i=0; i<results.size(); i++) {
			
			bw.write(results.get(i));
			bw.newLine();
		}
		bw.close();
	}
	
	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		//String file_name = "d-test";
		//String file_name = "D-small-attempt0.in";
		String file_name = "D-large.in";
		///String file_name = "A-test";
		String test = "src/input/" + file_name;
			
		String output = "src/output/" + file_name;
		System.out.println(output);
		ProblemD problemA = new ProblemD();
		ArrayList<String> results = problemA.read(test);
		for (String result : results) {
			System.out.println(result);
		}
		problemA.writeResult(results, output);
	}
	

}
