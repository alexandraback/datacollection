import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Password {
	
	public static String solve(int typeLen, int passwdLen, double prob[]) {
		String result = "";
		double okProb[] = new double[typeLen + 1];
		double expectNum[] = new double[typeLen + 1];
		
		okProb[0] = 1;
		for (int i = 1; i < typeLen + 1; i++){
			okProb[i] = okProb[i - 1]*prob[i - 1];
		}
		
		for (int i = 0; i < typeLen; i++){
			double okP = okProb[typeLen - i];
			int okNum = (2*i + passwdLen - typeLen + 1);
			expectNum[i] = okP*okNum + (1 - okP)*(okNum + passwdLen + 1);
		}
		
		expectNum[typeLen] = passwdLen + 2;
		
		double min = passwdLen * 10;
		for (int i = 0; i < typeLen + 1; i++){
			if (expectNum[i] < min){
				min = expectNum[i];
			}
		}
		
		result = String.format("%.6f", min);
		
		return result;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T = 0;
		String str = "";
		
		File input = new File(args[0]);
		FileReader fileReader;
		BufferedReader br;
		
		File output = new File("output_password.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				int typeLen, passwdLen;
				double prob[];
				
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				typeLen = Integer.parseInt(tokenizer.nextToken());
				passwdLen = Integer.parseInt(tokenizer.nextToken());
				
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				prob = new double[typeLen];
				for (int j = 0; j < typeLen; j++){
					prob[j] = Double.parseDouble(tokenizer.nextToken());
				}
				
				bw.write(String.format("Case #%d: %s\n", i+1, solve(typeLen, passwdLen, prob)));
			}
			
			fileReader.close();
			br.close();
			
			bw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
