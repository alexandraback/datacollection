package gcj2016.r1c;


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import org.junit.Assert;

public class FashionPolice {
	private static final String INPUT_FILE_NAME = "C-small-attempt1.in";
	private static final String OUTPUT_FILE_NAME = "C-small.out";

	public static void main(String[] args) {
		new FashionPolice().start();
	}

	private Integer K;
	private Integer J;
	private Integer P;
	private Integer S;
	
	private void start() {
		try (
				MyReader reader = new MyReader(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
				PrintWriter printer = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
				ArrayList<String> rs = solve(reader);
				printer.println("Case #" + (i+1) + ": "  + rs.size());
				for(int k  = 0 ; k < rs.size() ; k++) {
					printer.println(rs.get(k));
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private ArrayList<String> solve(MyReader reader) {
		this.J = reader.nextInt();
		this.P = reader.nextInt();
		this.S = reader.nextInt();
		this.K = reader.nextInt();
		return maxDays();
	}

	private ArrayList<String> maxDays() {
		// TODO Auto-generated method stub
		ArrayList<String> combi = generateAllCombination();
		ArrayList<String> rs = new ArrayList<>();
		HashMap<String,Integer> count = new HashMap<>();
		initCount(count,combi);
		
		String lastOutfit = "";
		while ( true ) {
			String outfit = chooseNext(combi,count,lastOutfit);
			if ( outfit == null) return rs;
			lastOutfit = outfit;
			rs.add(outfit);
			incCount(lastOutfit,count);
		}
	}

	private void incCount(String lastOutfit, HashMap<String,Integer> count) {
		ArrayList<String> comb2OfOutfit = getComb2OfOutfit(lastOutfit);
		for(String comb2 : comb2OfOutfit) {
			Integer tmp = count.get(comb2);
			Assert.assertNotNull(tmp);
			count.put(comb2, tmp+1);
		}
	}

	private ArrayList<String> generateAllCombination() {
		ArrayList<String> rs = new ArrayList<>();
		for(int j = 1 ; j <= J ; j++)
			for(int p = 1 ; p <= P ; p++)
				for(int s = 1 ; s <= S ; s++) {
					ArrayList<Integer> a = new ArrayList<>();
					a.add(j);
					a.add(p);
					a.add(s);
					rs.add(list2String(a));
				}
					
		return rs;
	}

	private void initCount(HashMap<String, Integer> count, ArrayList<String> combi) {
		for(String outfit : combi) {
			ArrayList<String> com2List = getComb2OfOutfit(outfit);
			for(String com2 : com2List)
				count.put(com2, 0);
		}
	}

	private ArrayList<String> getComb2OfOutfit(String outfit) {
		ArrayList<Integer> a = toArrayList(outfit);
		ArrayList<String> com2List = new ArrayList<>();
		for(int i = 0 ; i < 3 ; i++)
			for(int j = i+ 1 ; j < 3 ; j++) {
				
				String com2 = getCombi2for(a, i, j);
				com2List.add(com2);
			}
		return com2List;
	}

	private String chooseNext(ArrayList<String> combi, HashMap<String, Integer> count, String lastOutfit) {
		String outfit = null;
		for(int i = combi.size()-1 ; i >=0  ; i--)
			if ( goodToday(combi.get(i),count,lastOutfit)) return combi.get(i);
		return outfit;
	}

	private boolean goodToday(String outfit, HashMap<String, Integer> count, String lastOutfit) {	
		if ( outfit.equals(lastOutfit)) return false;
		if ( reachLimit(count,outfit)) return false;
		return true;
	}

	private boolean reachLimit(HashMap<String, Integer> count, String outfit) {
		ArrayList<Integer> a = toArrayList(outfit);
		Assert.assertEquals(3,a.size());
		ArrayList<String> comb2OfOutfit = getComb2OfOutfit(outfit);
		for(String com2 : comb2OfOutfit) 
			if ( count.get(com2) >= K) return true;
		return false;
	}

	public static ArrayList<Integer> toArrayList(String outfit) {
		ArrayList<Integer> rs = new ArrayList<>();
		String[] words = outfit.split(" ");
		for(int i = 0 ; i < words.length ; i++)
			rs.add(Integer.parseInt(words[i]));
		return rs;
	}

	private String getCombi2for(ArrayList<Integer> outfit, int i, int j) {
		ArrayList<Integer> a = new ArrayList<>();
		for(int k = 0 ; k < 3 ; k++) 
			a.add(0);
		a.set(i, outfit.get(i));
		a.set(j, outfit.get(j));
		for(int k = 0 ; k < a.size() ; k++)
			if ( k != i && k != j ) a.set(k, 0);
		return list2String(a);
	}

	public int[] toArray(ArrayList<Integer> list) {
		int[] a = new int[list.size()];
		for(int i = 0 ; i < a.length ; i++) {
			a[i] = list.get(i);
		}
		return a;	
	}
	
	public static List<Integer> toList(int[] a) {
		List<Integer> list = new ArrayList<Integer>();
		for(int i = 0 ; i < a.length ; i++)
			list.add(a[i]);
		return list;
	}

	public static String list2String(ArrayList<Integer> list) {
		StringBuilder sb = new StringBuilder();
		for(int i = 0 ; i < list.size() - 1; i++) {
			sb.append(list.get(i)+" ");
		}
		sb.append(list.get(list.size()-1));
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
		
		public Long nextLong() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return Long.parseLong(s);
			} catch (Exception e) {
				e.printStackTrace();
				return null;
			}
			
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
