package bsevero.codejam.round1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;


public class IOUtils {
	
	public static List<String> readFile(String fileName) {
		try {
			File file = new File(fileName);
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
			List<String> fileLines = new ArrayList<String>();
			for(String line = bufferedReader.readLine(); line != null; line = bufferedReader.readLine()) {
				fileLines.add(line);
			}

			return fileLines;
		} catch(Exception e) {
			e.printStackTrace();
			return Collections.emptyList();
		}
	}
	
	public static void writeFile(String fileName, Map<Integer, String> casesResult) {
		try {
			File file = new File(fileName);
			if(file.exists()) {
				file.delete();
			}
			file.createNewFile();
			FileWriter fileWriter = new FileWriter(file);
			PrintWriter printWriter = new PrintWriter(fileWriter);

			
			StringBuffer result = new StringBuffer();
			
			for(int i = 1; i <= casesResult.size(); i++) {
				result.append("Case #" + i + ": " + casesResult.get(i) + "\n");
			}
			printWriter.print(result.toString().substring(0, result.length() - 1));
			
			printWriter.close();
			fileWriter.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}

	
}
