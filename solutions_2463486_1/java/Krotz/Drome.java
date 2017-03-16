import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Drome {

	private static long[] num = new long[346];
	
	public static void main(String[] args) {
		
		int i, j, T;
		long  n, m;
		String line;
		String[] tokens;
		int counter;
		
		try {
			
			File fileOut = new File("C:/Users/Robi/Desktop/CodeJam/dromeo.txt");
			File fileIn = new File("C:/Users/Robi/Desktop/CodeJam/dromei.txt");
			File fileH = new File("C:/Users/Robi/Desktop/CodeJam/dromeH.txt");
			
			BufferedReader brH = new BufferedReader(new FileReader(fileH.getAbsoluteFile()));
			BufferedReader br = new BufferedReader(new FileReader(fileIn.getAbsoluteFile()));
			BufferedWriter bw = new BufferedWriter(new FileWriter(fileOut.getAbsoluteFile()));
 
			// if file doesn't exists, then create it
			if (!fileOut.exists()) {
				fileOut.createNewFile();
		}
			
			
			
		T = Integer.parseInt(br.readLine());
		
		
		//precalculated palindromes
		for(i = 0; i < 42; i++) {
			num[i] = Long.parseLong(brH.readLine());
			System.out.println(num[i]);
		}
		
		for(i = 0; i < T; i++){
			
			line = br.readLine();
			tokens = line.split(" ");
			n = Long.parseLong(tokens[0]);
			m = Long.parseLong(tokens[1]);
			
			counter = 0;
			
			for(j = 0; j < 42; j++){
				if((n <= num[j]) && (num[j] <= m))
					counter++;
			}
			bw.write("Case #"+Integer.toString(i+1)+": "+Integer.toString(counter));
			bw.newLine();
		}
		
		
		
			
			
		bw.close();
		br.close();
		brH.close();
 
		System.out.println("Done");
 
		} catch (IOException e){ 
			e.printStackTrace();
		}
		
	}
	
}
