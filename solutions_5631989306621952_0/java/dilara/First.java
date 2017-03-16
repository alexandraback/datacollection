import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class First {

	private String filename;
	private String outputName;
	private int numberOfCases;
	private String[] strings;
	private String[] results;


	public First(String filename,String outputName){
		this.filename = filename;
		this.outputName = outputName;
	}

	public void start(){
		readFromFile();

		computeResults();

		writeOutput();

	}




	private void computeResults() {

		for(int i = 0; i<numberOfCases;i++){
			String bigS = strings[i];
			StringBuilder sb = new StringBuilder();
			char max = bigS.charAt(0);
			sb.append(max);
			char[] str = bigS.toCharArray();
			
			for(int j = 1;j<str.length;j++){
				if(str[j]<max){
					sb.append(str[j]);
				}else{
					max = str[j];
					sb.insert(0,max);					
				}
			}
			
			results[i] = sb.toString();
		}
		
		


	}

	public void readFromFile(){
		numberOfCases=0;
		Scanner scanner;
		try {
			scanner = new Scanner(new File(filename));

			numberOfCases=scanner.nextInt();
			strings = new String[numberOfCases];
			results = new String[numberOfCases];

			for(int i=0;i<numberOfCases;i++){
				String s=scanner.next();
				strings[i] = s;				
			}

			scanner.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void writeOutput(){
		File file = new File(outputName);

		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		FileWriter fw;
		try {
			fw = new FileWriter(file.getAbsoluteFile());

			BufferedWriter bw = new BufferedWriter(fw);
			for(int i = 0; i<results.length; i++){

				bw.write("Case #"+(i+1)+": "+(results[i]));
				bw.newLine();   

			}

			bw.close();

		}catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
