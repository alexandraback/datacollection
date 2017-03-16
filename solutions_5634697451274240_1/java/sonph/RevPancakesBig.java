package gcj2016;


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedList;

public class RevPancakesBig {
	private static final String INPUT_FILE_NAME = "B-small-attempt0.in";
	private static final String OUTPUT_FILE_NAME = "B-small-alg2.out";
	private static final int INF = 1000000; //TODO: for S.length()=100, INF should be diff ?

	public static void main(String[] args) {
		new RevPancakesBig().start();
	}


	private HashMap<String,Integer> ms = new HashMap<>();
	
	private void start() {
		try (
				MyReader reader = new MyReader(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
				PrintWriter printer = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
				String s = reader.nextString();
				printer.println("Case #" + (i+1) + ": " + minStep(s));
//				System.out.println("Case #" + (i+1) + ": " + minStep(s));
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private int minStep(String s) {
//		this.ms  = new HashMap<>();
//		ms.put("0", 1);
//		ms.put("1", 0);
//		String binaryString = convertTo01(s);
//		return solve(binaryString);
		
		String start = reduce(convertTo01(s));
		if ( start.equals("1") ) return 0;
		HashMap<String, Integer> dist = new HashMap<>();
		dist.put(start,0);
		LinkedList<String> q = new LinkedList<>();
		q.push(start);		
		
		while ( ! q.isEmpty()) {
			String u = q.pop();
			char[] cc = u.toCharArray();
			for(int i = 1 ; i <= cc.length ; i++) {
				String transformed = transform(cc,i); //exclusive
				String redTrans = reduce(transformed);
				if ( redTrans.equals("1") ) return dist.get(u) + 1;
				if ( redTrans.length() < transformed.length() && dist.get(redTrans) == null ) {
					dist.put(redTrans,dist.get(u) + 1);
					q.push(redTrans);
					
				}
			}
		}
		return -1;
	}


	private Integer solve(String s) {
//		Assert.assertEquals("0",reduce("00000"));
//		Assert.assertEquals("1",reduce("11111"));
//		Assert.assertEquals("10101",reduce("1101100011"));
//		Assert.assertEquals("1",reduce("1"));
//		Assert.assertEquals("0",reduce("0"));
		

//		Assert.assertEquals("0", transform("1".toCharArray(), 1));
//		Assert.assertEquals("1", transform("0".toCharArray(), 1));
//		Assert.assertEquals("1111", transform("0000".toCharArray(), 4));
//		Assert.assertEquals("0000", transform("1111".toCharArray(), 4));
//		Assert.assertEquals("0100", transform("1100".toCharArray(), 1));
//		Assert.assertEquals("1010", transform("1010".toCharArray(), 4));
//		Assert.assertEquals("1010", transform("1010".toCharArray(), 2));
//		Assert.assertEquals("0100", transform("1010".toCharArray(), 3));
		
		
		s = reduce(s);
		Integer steps = ms.get(s);
		if ( steps != null ) return steps;
		char[] cc = s.toCharArray();
		int minSteps = INF;
		for(int i = 1; i <=  cc.length ; i++ ) {
			String transformed = transform(cc,i); //exclusive
			String redTrans = reduce(transformed);
			if ( redTrans.length() < transformed.length()) {
				minSteps = Math.min(minSteps, 1 + solve(redTrans));
			}
		}
		ms.put(s, minSteps);
		return minSteps;
	}
	
	//exclusive endPos
	private String transform(char[] cc, int endPos) {
		char[] tt = new char[cc.length];
		char[] flipped = new char[endPos]; //length of flip = endPos
		for(int i = 0 ; i < endPos ; i++) {
			flipped[i] = (char) ('0' + (1-(cc[endPos-i-1]-'0')));
		}
		for(int i  = endPos ; i < cc.length ; i++) {
			tt[i] = cc[i];
		}
		for(int i = 0 ; i < endPos ; i++) {
			tt[i] = flipped[i];
		}
		return new String(tt);
	}

	private String reduce(String s) {
		char[] cc = s.toCharArray();
		char lastChar = '#';
		StringBuilder sb = new StringBuilder();
		for(int i = 0 ; i < cc.length ; i++) {
			if ( cc[i] != lastChar) {
				lastChar = cc[i];
				sb.append(cc[i]);
			}
		}
		return sb.toString();
	}

	private String convertTo01(String s) {
		char[] cc = s.toCharArray();
		for(int i = 0 ; i < cc.length ; i++) {
			if ( cc[i] == '-') cc[i]='0';
			else cc[i]='1';
		}
		return new String(cc);
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
