package codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Lottery {

	public static void main(String[] args) throws Exception {


		ConsoleReader reader;
		if (args.length > 0) {

			reader = new ConsoleReader(args[0]);
		} else {

			reader = new ConsoleReader();
		}

		int num = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= num; i++) {

			System.out.print("Case #" + i + ": ");
			
			String[] tokens=reader.readLine().split(" ");
			int a=Integer.parseInt(tokens[0]);
			int b=Integer.parseInt(tokens[1]);
			int k=Integer.parseInt(tokens[2]);
			
			int win=win(a,b,k);
			System.out.println(win);

		}
	}
	
	private static int win(int a, int b ,int k) {
		
		int win=0;
		
		for(int i=0;i<a;i++) {
			
			for(int j=0;j<b;j++) {
				
				int x=i&j;
				if(x<k)
					win++;
			}
		}
		
		return win;
		
	}
	
	public static class ConsoleReader {

		private BufferedReader br;

		public ConsoleReader(String file) throws FileNotFoundException {

			br = new BufferedReader(new FileReader(new File(file)));

		}

		public ConsoleReader() {

			br = new BufferedReader(new InputStreamReader(System.in));

		}

		public String readLine() {

			try {

				return br.readLine();
			} catch (IOException e) {
				System.err.println("Exception while reading " + e);
			}

			return null;
		}

	}


}
