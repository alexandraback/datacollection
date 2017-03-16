package gcj2016;


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class FractilesBig {
	private static final String IMPOSSIBLE = "IMPOSSIBLE";
	private static final String INPUT_FILE_NAME = "D-large.in";
	private static final String OUTPUT_FILE_NAME = "D-large.out";

	public static void main(String[] args) {
		new FractilesBig().start();
	}
	
	private void start() {
		try (
				MyReader reader = new MyReader(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
				PrintWriter printer = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
				String output = solveCase(reader);
				printer.println("Case #" + (i+1) + ": " + output );
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private String solveCase(MyReader reader) {
		String output = "";
		int L = reader.nextInt();
		int C = reader.nextInt();
		int S = reader.nextInt();

		if ( C == 1 ) {
			return simpleCase(L, S);
		} else return complexCase(L,C,S);
	}

	private String simpleCase(int L, int S) {
		String output;
		if ( S < L ) output = IMPOSSIBLE;
		else {
			ArrayList<Integer> values = new ArrayList<>();
			for(int i = 1 ; i <= L ; i++) {
				values.add(i);
			}
			output = implode(values);
		}
		return output;
	}

	private String complexCase(int L, int C, int S) {
		int requiredStudents = (L + 1) / 2;
		if ( S < requiredStudents ) return IMPOSSIBLE;
		ArrayList<Integer> values = new ArrayList<>();
		int num = L;
		int cntStudent = 0;
		while ( cntStudent < requiredStudents ) {
			num = L * (cntStudent + 1) - cntStudent;
			values.add(num);
			cntStudent++;
		}
		return implode(values);
	}

	private String implode(ArrayList<Integer> values) {
		StringBuilder sb = new StringBuilder();
		if ( values != null && values.size() > 0) {
			for(int i = 0 ; i < values.size() - 1 ; i++) {
				sb.append(""+values.get(i)+ " ");
			}
			sb.append(""+values.get(values.size()-1));
		}
		return sb.toString();
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
