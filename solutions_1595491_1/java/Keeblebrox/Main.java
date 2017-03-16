import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;


public class Main {
	static final String inputFilename = "B-large.in";
	
	static class DataSet {
		public int bestScore,
				   specialScoreCount;
		public int[] scores;
		
		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder("<$DataSet:")
					.append(bestScore).append(", ")
					.append(specialScoreCount).append(", ");
			if (null != scores) {
				sb.append("[");
				for (int i=0, n=scores.length; i<n; ++i) {
					sb.append(scores[i]);
					if (i<n-1) sb.append(", ");
				}
				sb.append("]");
			}
			return sb.append(">").toString();
		}
		
		public static DataSet parse(String input) {
			if (null == input) return null;
			
			DataSet result = new DataSet();
			int begin = 0;
			int end = input.indexOf(' ');
			
			int scoresCount = Integer.parseInt(input.substring(begin, end));
			begin = end + 1;
			end = input.indexOf(' ', begin);
			
			result.specialScoreCount = Integer.parseInt(input.substring(begin, end));
			begin = end + 1;
			end = input.indexOf(' ', begin);
			
			result.bestScore = Integer.parseInt(input.substring(begin, end));
			result.scores = new int[scoresCount];
			for (int i=0; i<scoresCount; ++i) {
				begin = end + 1;
				end = input.indexOf(' ', begin);
				if (end < 0) result.scores[i] = Integer.parseInt(input.substring(begin));
				else		 result.scores[i] = Integer.parseInt(input.substring(begin, end));
			}
			
			return result;
		}
	}	
	
	
	
	public static Reader getFileReader(String filename) {
		BufferedReader result = null;
		try {
			result = new BufferedReader(new FileReader(filename));
		}
		catch (FileNotFoundException e) {
			System.err.println("Couldn't find the file \""+filename+"\"");
			e.printStackTrace();
		}
		return result;
	}
	
	public static String readLine(BufferedReader reader) {
		try {
			return reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public static void closeReader(Reader r) {
		try { 
			r.close(); 
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	public static Writer getFileWriter(String filename) {
		BufferedWriter result = null;
		try {
			result = new BufferedWriter(new FileWriter(filename));
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return result;
	}
	
	public static void writeLine(BufferedWriter writer, String line) {
		try {
			writer.write(line);
			writer.newLine();
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	public static void closeWriter(Writer w) {
		try { 
			w.close(); 
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	public static String formatCase(int caseNumber, int result) {
		return new StringBuilder("Case #").append(caseNumber).append(": ").append(result).toString();
	}
	
	public static float diffScore(int best, int score) {
		int remainder = score-best;
		float avg = remainder/2f;
		return avg-best;
	}
	
	public static void main(String[] args) {
		BufferedReader in = (BufferedReader) getFileReader(inputFilename);
		int lineCount = Integer.parseInt(readLine(in));
		List<DataSet> dataSets = new ArrayList<DataSet>();
		for (int i=0; i<lineCount; ++i) {
			dataSets.add(DataSet.parse(readLine(in)));
		}
		closeReader(in);
		
		// perform the testing
		BufferedWriter out = (BufferedWriter) getFileWriter(inputFilename.replace(".in", ".out"));
		for (int i=0, n=dataSets.size(); i<n; ++i) {
			DataSet set = dataSets.get(i);
			int usedSurprises = 0;
			int setResult = 0;
			for (int j=0, m=set.scores.length; j<m; ++j) {
				float diff = diffScore(set.bestScore, set.scores[j]);
				if (set.scores[j] >= set.bestScore) {
					if (diff >= -1) 
						setResult++;
					else if (diff >= -2 && usedSurprises < set.specialScoreCount) {
						setResult++;
						usedSurprises++;
					}
				}
			}
			writeLine(out, formatCase(i+1, setResult)); 
		}
		closeWriter(out);
	}

}
