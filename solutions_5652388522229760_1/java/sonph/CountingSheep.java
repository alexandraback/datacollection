package gcj2016;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class CountingSheep {
	private static final String FILE_NAME = "S-sample.in";

	public static void main(String[] args) {
		new CountingSheep().start();
	}
	
	private void start() {
		try (MyReader reader = new MyReader(new BufferedReader(new FileReader(FILE_NAME)))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
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
