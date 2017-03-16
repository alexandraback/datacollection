import java.util.*;
import java.io.*;
import java.math.*;



public class Solver
{
	
	public int[] convert(String[] s) {
		int[] res = new int[s.length];
		for(int i = 0;i < s.length; i++) {
			res[i] = Integer.parseInt(s[i]);
		}
		return res;
	}
	
	private class Pair {
		int f;
		int s;
		private Pair(int fst, int snd) {f = fst; s = snd;}
		
	}
	
	public double[] convertD(String[] s) {
		double[] res = new double[s.length];
		for(int i = 0;i < s.length; i++) {
			res[i] = Double.parseDouble(s[i]);
		}
		return res;
	}
	
	public void printArr(int[][] s) {
		for(int[] row : s) {
			for(int el : row) {System.out.print(el);}
			System.out.println("");
		}
	}
	
	public String solve(BufferedReader reader) {
		try{
			int[] dims = convert(reader.readLine().split(" "));
			double[] probs = convertD(reader.readLine().split(" "));
			int a = dims[0];
			int b = dims[1];
			double opt = b+2;
			double prod = 1;
			for(int i = a; i >= 0; i--) {
				if(prod*(2*i + b - a + 1) + (1-prod)*(2*i + 2*b - a + 2) < opt ) {
					opt = prod*(2*i + b - a + 1) + (1-prod)*(2*i + 2*b - a + 2);
				}
				if(i != 0) {
					prod *= probs[a-i];
				}
			}
			return "" + (opt);
		}
		catch(Exception e) {
			e.printStackTrace();
			return "";
		}
			
	}
	
	public String solve2(BufferedReader reader) {
		try{
			int dim = Integer.parseInt(reader.readLine());
			ArrayList<Pair> onestar = new ArrayList<Pair>();
			ArrayList<Pair> twostar = new ArrayList<Pair>();
			HashMap<Integer,Integer> sndmap = new HashMap<Integer,Integer>();
			HashSet<Integer> fstset = new HashSet<Integer>();
			int[] nums;
			for(int i = 0; i < dim;i++) {
				nums = convert(reader.readLine().split(" "));
				int fst = nums[0];
				int snd = nums[1];
				Pair one = new Pair(i,fst);
				Pair two = new Pair(i,snd);
				boolean flag = false;
				for(int j = 0; j < onestar.size(); j++) {
					if(onestar.get(j).s > one.s) {
						onestar.add(j,one);
						flag = true;
						break;
					}
				}
				if(!flag) {onestar.add(one);}
				flag = false;
				for(int j = 0; j < twostar.size(); j++) {
					if(twostar.get(j).s > two.s) {
						twostar.add(j,two);
						flag = true;
						break;
					}
				}
				fstset.add(new Integer(i));
				sndmap.put(new Integer(i), new Integer(snd));
				if(!flag) {twostar.add(two);}
			}
			int coins = 0;
			int tries = 0;
			while(twostar.size() != 0) {
				if (twostar.get(0).s <= coins) {
					int level = twostar.get(0).f;
					twostar.remove(0);
					sndmap.remove(level);
					tries++; 
					if(fstset.contains(new Integer(level))) {
						coins += 2;
						fstset.remove(new Integer(level));
					}
					else {coins += 1;}
					continue;
				}
				int maxlvl = 0;
				int maxcoins = 0;				
				for(int j = 0; j < onestar.size(); j++) {
					int level = onestar.get(j).f;
					if(!sndmap.containsKey(new Integer(level)) || !fstset.contains(new Integer(level))) {
						onestar.remove(j);
						j--;
					}
				}
				int j = 0;
				if(onestar.size() == 0) { return "Too Bad";}
				if(onestar.get(0).s > coins) {
					return "Too Bad";
				}
				while(onestar.get(j).s <= coins) {
					int level = onestar.get(j).f;
					Integer reqcoins = sndmap.get(new Integer(level));
					if (reqcoins.intValue() > maxcoins) {
						maxlvl = level;
						maxcoins = reqcoins.intValue();
					}
					j++;
					if(j >= onestar.size()) {
						break;
					}
				}
				tries++; 
				coins++;
				fstset.remove(maxlvl);
			}
			return "" + tries;
		}
		catch(Exception e) {
			e.printStackTrace();
			return "";
		}
	
	}
	
	public static void main(String[] args)
	{	
		try
		{			
			FileReader flrdr = new FileReader(new File("test.in"));
			BufferedReader br = new BufferedReader(flrdr);
			FileWriter writer = new FileWriter("output.txt");
			int n = Integer.parseInt(br.readLine());
			Solver s = new Solver();
			for(int i = 1; i < n+1; i++)
			{
				//System.out.println("Case #" + i + ": " + s.solve4(br) + "\n");
				writer.write("Case #" + i + ": " + s.solve2(br) + "\n");
			}
			writer.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static void checkFiles(String f1, String f2) {
		try {
			FileReader flrd1 = new FileReader(new File(f1));
			FileReader flrd2 = new FileReader(new File(f2));
			BufferedReader br1 = new BufferedReader(flrd1);
			BufferedReader br2 = new BufferedReader(flrd2);
			int count = 1;
			while(br1.readLine().equals(br2.readLine())) {
				count++;
			}
			System.out.println(count);
		}
		catch(Exception e) {e.printStackTrace();}
	}
}