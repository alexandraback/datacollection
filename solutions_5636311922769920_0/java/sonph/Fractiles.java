package gcj2016;


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import gcj2016.CountingSheep.MyReader;
import junit.framework.Assert;

public class Fractiles {
	private static final String INPUT_FILE_NAME = "D-small-attempt0.in";
	private static final String OUTPUT_FILE_NAME = "D-small.out";

	public static void main(String[] args) {
		new Fractiles().start();
	}
	
	private void start() {
		try (
				MyReader reader = new MyReader(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
				PrintWriter printer = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
				Integer baseLength = reader.nextInt();
				Integer C = reader.nextInt();
				Integer S = reader.nextInt();
				String output = "";
				for(int k = 0 ; k < baseLength - 1; k++) {
					output += "" + (k+1) + " ";
				}
				output += ""+baseLength;
				printer.println("Case #" + (i+1) + ": " + output );
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public class MyReader implements AutoCloseable {

		private BufferedReader br;
		private int index;
		private String[] words;

		public MyReader(BufferedReader br) {
			this.br = br;
		}
				
		public Integer nextInt() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return Integer.parseInt(s);
			} catch (Exception e) {
				e.printStackTrace();
				return null;
			}
		}				
		
		private String getNextWord() throws IOException {
			if ( words == null || index >= words.length) {
				String line = br.readLine();
				if ( line == null ) return null;
				index = 0;
				words = line.split(" ");
			}
			return words[index++];
		}

		public String nextString() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return s;
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
		}

		@Override
		public void close() throws Exception {
			try { this.br.close(); } catch (Exception e) {}
		}
	}
}
