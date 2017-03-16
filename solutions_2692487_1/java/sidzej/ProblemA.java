package round12_a;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class ProblemA {

	//static String filePath = "src/round12_a/test.in"; 
	//static String filePath = "src/round12_a/A-small-attempt4.in";
	static String filePath = "src/round12_a/A-large.in";
	static StringBuffer fullResult = new StringBuffer();
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new FileReader(filePath));
		int noTestCases = s.nextInt();
		for (int i = 0; i < noTestCases; i++) {
			String result = "";			
			Long currentNote = s.nextLong();
			long noOfNotes = s.nextLong();
			List<Long> notes = new ArrayList<Long>();
			for (int j = 0; j < noOfNotes; j++) {
				notes.add(s.nextLong());
			}
			Collections.sort(notes);
			currentNote = processNotes(currentNote, notes);
			long startOperations = notes.size();
			long noOfOperationsToAdd = (currentNote == 1) ? startOperations : 0l;
			while (!notes.isEmpty() && currentNote > 1) {
				long[] resultxx = makeMove(currentNote, notes);
				noOfOperationsToAdd += resultxx[0];
				currentNote = resultxx[1];
				currentNote = processNotes(currentNote, notes);
			}
			result += Math.min(startOperations, noOfOperationsToAdd);
			fullResult.append("Case #" + (i + 1) + ": " + result + "\n");
		}
		writeFile();
	}


	private static long[] makeMove(Long currentNote, List<Long> notes) {
		long noOfOperationsToAdd = 0;
		for (noOfOperationsToAdd = 0; noOfOperationsToAdd >= 0; ) {
			currentNote += currentNote - 1;
			noOfOperationsToAdd++;
			if (currentNote > notes.get(0)) {
				break;
			}
		}
		if (noOfOperationsToAdd >= notes.size()) {
			noOfOperationsToAdd = notes.size();
			notes.clear();
		}
		return new long[]{noOfOperationsToAdd, currentNote};
	}

	private static Long processNotes(Long currentNote, List<Long> notes) {
		Iterator<Long> it = notes.iterator();
		while (it.hasNext()) {
			long note = it.next();
			if (currentNote > note) {
				currentNote += note;
				it.remove();
			} else {
				break;
			}
		}
		return currentNote;
	}


	static void writeFile() throws IOException {
		String path = filePath.replace(".in", ".out");
		BufferedWriter out = new BufferedWriter
			    (new OutputStreamWriter(new FileOutputStream(path),"UTF-8"));
		out.write(fullResult.toString());
		out.close();
		System.out.println(fullResult);
	}
}
