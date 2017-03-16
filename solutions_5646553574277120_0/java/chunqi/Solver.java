package less;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

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
	
	private long remainder(long n, long C, ArrayList<Long> denoms) {
		for(int x = denoms.size() - 1; x >= 0; x--) {
			long denom = denoms.get(x);
			for(int y = 0; y < C; y++) {
				if(denom <= n) {
					n -= denom;
				}
			}
		}
		return n;
	}
	
	private void _solveCase(int caseNum) {
		try {
			int cost = 0;
			long C, D , V;
			String[] parts = m_bufferedReader.readLine().split(" ");
			ArrayList<Long> denoms = new ArrayList<Long>();
			C = Long.parseLong(parts[0]);
			D = Long.parseLong(parts[1]);
			V = Long.parseLong(parts[2]);
			String[] denomStrings = m_bufferedReader.readLine().split(" ");
			for(int x = 0; x < denomStrings.length; x++) denoms.add(Long.parseLong(denomStrings[x]));
			for(long x = 1; x <= V; x++) {
				if(remainder(x, C, denoms) > 0) {
					denoms.add(x);
					Collections.sort(denoms);
					cost++;
				}
			}
			m_bufferedWriter.write("Case #" + caseNum + ": " + cost + "\n");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
