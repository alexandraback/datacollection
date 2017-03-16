import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class FairAndSquare {
	
	public static List<Long> list;
	
	public static String solve(long a, long b) {
		int start = 0;
		int end = 0;
		
		for (int i = 0; i < list.size(); i++){
			if (a <= list.get(i)){
				start = i;
				break;
			}
		}
		
		for (int i = start; i < list.size(); i++){
			if (b < list.get(i)){
				end = i;
				break;
			}
		}
		
		return "" + (end - start);
	}
	
	public static boolean isFair(long a){
		String str = "" + a;
		
		for (int i = 0; i < str.length() / 2; i++){
			if (str.charAt(i) != str.charAt(str.length() - i - 1)){
				return false;
			}
		}
		
		return true;
	}
	
	public static void Find(){
		long last = (long)Math.pow(10, 8);
		
		list = new ArrayList<Long>();
		
		for (long i = 0; i <= last; i++){
			if (isFair(i)){
				if (isFair(i*i)){
					list.add(i*i);
					System.out.println(i + " " +i*i);
				}
			}
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T = 0;
		String str = "";
		String result = "";
		
		File input = new File(args[0]);
		FileReader fileReader;
		BufferedReader br;
		
		File output = new File("output_FairAndSquare.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			Find();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				
				long a = Long.parseLong(tokenizer.nextToken());
				long b = Long.parseLong(tokenizer.nextToken());
				
				result = solve(a, b);
				System.out.println(result);
				bw.write(String.format("Case #%d: %s\n", i+1, result));
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
