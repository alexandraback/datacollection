import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class Recycle {
	
	public static String recycle(int a, int b) {
		int result = 0;
		int digit, temp, cnt;
		String str;
		int array[] = new int[b + 1];
		
		for (int i = 0; i < b; i++){
			array[i] = 0;
		}
		
		for (int i = a; i < b; i++){
			if (array[i] == 1)
				continue;
			array[i] = 1;
			
			str = i+"";
			digit = str.length();
			
			temp = i;
			cnt = 0;
			for (int j = 0; j < digit - 1; j++){
				temp = (temp / 10) + (temp % 10)*(int)Math.pow(10, digit - 1);
				if (temp == i)
					break;
				if (a <= temp && temp <= b){
					if(array[temp] == 0){
						cnt++;
						array[temp] = 1;
						//System.out.println(String.format("(%d, %d)", i, temp));
					}
				}
			}
			result += factorial(cnt);
		}
		return "" + result;
	}
	
	public static int factorial(int a){
		if (a <= 0)
			return 0;
		return a + factorial(a - 1); 
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
		
		File output = new File("output_recycle.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				int a;
				int b;
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				a = Integer.parseInt(tokenizer.nextToken());
				b = Integer.parseInt(tokenizer.nextToken());
				bw.write(String.format("Case #%d: %s\n", i+1, recycle(a, b)));
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
