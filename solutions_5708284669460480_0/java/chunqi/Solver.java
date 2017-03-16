package typewriter;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class Solver {
	private FileReader m_fileReader;
	private FileWriter m_fileWriter;
	private BufferedReader m_bufferedReader;
	private BufferedWriter m_bufferedWriter;
	
	private int m_numCases;
	
	public Solver() {
		try {
			m_fileReader = new FileReader("input.txt");
			m_fileWriter = new FileWriter("output.txt");
			m_bufferedReader = new BufferedReader(m_fileReader);
			m_bufferedWriter = new BufferedWriter(m_fileWriter);
			
			m_numCases = Integer.parseInt(m_bufferedReader.readLine());
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		for(int x = 1; x <= m_numCases; x++) {
			_solveCase(x);
		}
		
		try {
			m_bufferedReader.close();
			m_bufferedWriter.close();
			m_fileReader.close();
			m_fileWriter.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private int countOccurence(String s, String t) {
		int count = 0;
		char[] a = s.toCharArray();
		char[] b = t.toCharArray();
		for(int x = 0; x < a.length; x++) {
			for(int y = 0; y < b.length && x + y < a.length; y++) {
				if(a[x + y] == b[y]) {
					if(y == b.length - 1) count++;
				}
				else break;
			}
		}
		return count;
	}
	
	private double countProb(String s, HashMap<Character, Double> keyProb) {
		char[] a = s.toCharArray();
		double prob = keyProb.get(a[0]);
		for(int x = 1; x < a.length; x++) {
			prob *= keyProb.get(a);
		}
		return prob;
	}
	
	private int overlap(String s) {
		String doubleString = s + s;
		doubleString.substring(1);
		return doubleString.indexOf(s);
	}
	
	private void _solveCase(int caseNum) {
		try {
			int K, L, S;
			int[] indices;
			double probSum = 0;
			double targetProb = 0;
			HashMap<Character, Integer> keyCount = new HashMap<Character, Integer>();
			HashMap<Character, Double> keyProb = new HashMap<Character, Double>();
			String[] parts = m_bufferedReader.readLine().split(" ");
			K = Integer.parseInt(parts[0]);
			L = Integer.parseInt(parts[1]);
			S = Integer.parseInt(parts[2]);
			String keys = m_bufferedReader.readLine();
			String target = m_bufferedReader.readLine();
			indices = new int[K];
			for(int x = 0; x < keys.length(); x++) {
				char key = keys.charAt(x);
				if(keyCount.containsKey(key)) {
					keyCount.put(key, keyCount.get(key) + 1);
				}
				else {
					keyCount.put(key, 1);
				}
			}
			for(char key : keyCount.keySet()) {
				keyProb.put(key, (double) keyCount.get(key) / K);
			}
			for(char x = 'A'; x <= 'Z'; x++) {
				if(keyProb.get(x) == null) keyProb.put(x, 0.0);
			}
			targetProb = keyProb.get(target.charAt(0));
			for(int x = 1; x < target.length(); x++) {
				targetProb *= keyProb.get(target.charAt(x));
			}
			if(targetProb != 0.0) {
				int stride = overlap(target) == -1 && overlap(target) < L + 1 ? overlap(target) + 1 : L;
				for(int x = 0; x < S; x += stride) {
					if(x + L > S) break;
					else {
						probSum += 1.0 - targetProb;
					}
				}
			}
			m_bufferedWriter.write("Case #" + caseNum + ": " + probSum + "\n");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
