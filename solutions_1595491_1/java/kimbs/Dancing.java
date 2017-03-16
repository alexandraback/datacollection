import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Dancing {
	
	public static String dancing(int N, int S, int p, int number[]) {
		int result = 0;
		int CntS = S;
		int score;
		
		for (int i = 0; i < N; i++){
			score = number[i];
			if ( 3*p - 2 <= score )
				result ++;
			else if ( score < 3*p - 4 )
				continue;
			else if ( p - 2 >= 0 && CntS > 0){
				result ++;
				CntS --;
			}
		}
		
		return "" + result;
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
		
		File output = new File("output_Dancing.txt");
		BufferedWriter bw;
		
		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				int N;
				int S;
				int p;
				int number[];
				
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				N = Integer.parseInt(tokenizer.nextToken());
				S = Integer.parseInt(tokenizer.nextToken());
				p = Integer.parseInt(tokenizer.nextToken());
				number = new int[N];
				for (int j = 0; j < N; j++){
					number[j] = Integer.parseInt(tokenizer.nextToken());
				}
				
				bw.write(String.format("Case #%d: %s\n", i+1, dancing(N, S, p, number)));
			}
			
			br.close();
			fileReader.close();
			
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
