package codes;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class InputOutput {
	private Object instance;
	
	private String[][] inputCases;
	private String[][][] outputCases;
	
	
	public void readFile (String inputFile) {
		File file = new File(inputFile);
		FileReader fileReader = null;
		try {
			fileReader = new FileReader(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		BufferedReader bufferedReader = new BufferedReader(fileReader);
		
		String line = null;
		try {
			line = bufferedReader.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		line = line.trim();
		
		int n = Integer.valueOf(line);
		
		inputCases = new String[n][]; 
		for (int i = 0; i < n; ++i) {
			try {
				line = bufferedReader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			inputCases[i] = line.split("\\s+");
		}
		
		try {
			bufferedReader.close();
			fileReader.close();

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public void invokeMethod(String className, String methodName) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		Class<?> cls;
		Method method = null;
		
		Class<?> arg = String[].class;
		
		try {
			cls = Class.forName(className);
			if (instance == null)				
				instance = cls.newInstance();
			
			method = cls.getDeclaredMethod(methodName, arg);
		} catch (ClassNotFoundException | NoSuchMethodException | SecurityException | InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int n = inputCases.length;
		
		outputCases = new String[inputCases.length][][];
		
		for (int i = 0; i < n; ++i) {
			Object[] param = {inputCases[i]};
			outputCases[i] = (String[][]) method.invoke(instance, param);
		}
		
	}
	
	public void writeFile (String outputFile, boolean noSpace) {
		File file = new File(outputFile);
		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		FileWriter fileWriter = null;
		try {
			fileWriter = new FileWriter(file);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
		
		int n = outputCases.length;
		
		boolean printBackSpace = false;
		if (outputCases[0][0].length > 1) {
			printBackSpace = true;
		}
		
		String head = "Case #";
		for (int i = 0; i < n; ++i) {
			try {
				bufferedWriter.write(head);
				bufferedWriter.write(Integer.toString((i+1)) + ":");
				
				if (printBackSpace) {
					bufferedWriter.write("\n");
				}
				
				for (String[] itemArray : outputCases[i]) {
					for (String item : itemArray) {
						if (item != null) {
							if (!noSpace)
								bufferedWriter.write(" "+item);
							else 
								bufferedWriter.write(item);
						}	
					}
					bufferedWriter.write("\n");
				}
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		try {
			bufferedWriter.flush();
			bufferedWriter.close();
			fileWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
	}

	public static void main(String[] args) {
		InputOutput instance = new InputOutput();
		
		String directory = "./data/CookieClickerAlpha/";
		String inputFile = directory + "B-large.in";
		String outputFile = directory + "B-large.out";
		
		boolean noSpace = false;
		String className = "codes.CookieClickerAlpha";
		
		String methodName = "optimalBuyingTime";
		
		
		instance.readFile(inputFile);
		
		try {
			instance.invokeMethod(className, methodName);
		} catch (IllegalAccessException | IllegalArgumentException
				| InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		instance.writeFile(outputFile, noSpace);
	}
}
