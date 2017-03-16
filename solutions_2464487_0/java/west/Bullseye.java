import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Bullseye {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		if(args.length != 2) {
			System.out.println("Usage: Dancing [input file] [output file].");
		}


		// input
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(args[0]));
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			return;
		}

		// output
		File outputFile = null;
		FileWriter fw = null;
		BufferedWriter bw = null;
		String content = new String();		
		String line = null;
		long r = 0;
		long t = 0;
		long n = 0;
		double temp;
		try {


			outputFile = new File(args[1]);

			// if file doesnt exists, then create it
			if (!outputFile.exists()) {
				outputFile.createNewFile();
			}

			fw = new FileWriter(outputFile.getAbsoluteFile());
			bw = new BufferedWriter(fw);



		} catch (IOException e) {
			e.printStackTrace();
		}





		int cases = Integer.parseInt(br.readLine());
		//		int M = 0;
		//		int N = 0;
		//			byte[][] initialState = null;
		//byte[][] initialState = currentState;

		StringTokenizer token = null;
		for (int i=1; i <= cases; i++) {
			System.out.println(i);
			token = new StringTokenizer(br.readLine());
			r = Long.parseLong(token.nextToken());
			t = Long.parseLong(token.nextToken());
			temp = 1-2*r;
			n = (long) Math.floor(((temp + Math.sqrt(temp*temp + 8.0 * t))/4.0));
			while(2*r+2*n-1 > t/n) {
				n--;
			}
			content += "Case #" + i + ": " + n;			
			content += "\n";

		}

		bw.write(content);
		bw.close();
		br.close();
	}

}


