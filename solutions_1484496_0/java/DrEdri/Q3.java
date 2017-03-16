import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.TreeSet;

public class Q3 {
	public static Problem[] probs;

	static class Problem {
		public int[] S = new int[20];
	}
			
	static class Sum implements Comparable {
		public int sum;
		public long numsUsed = 0;
		public int highestUsedIndex = -1;
		
		public boolean checkNth(int nth) {
			if ((numsUsed & (1L << nth))==0) {
				return false;
			}
			return true;
		}
		
		public void setNth(int nth) {
			numsUsed = numsUsed | (1L << nth);
			if (nth>highestUsedIndex) {
				highestUsedIndex = nth;
			}
		}

		public String printInts(Problem p) {
			String intString = "";
			for (int i=0; i<20; i++) {
				if ((numsUsed & (1L << i))!=0) {
					intString += p.S[i] + " ";
				}
			}
			return intString;
		}
		
		@Override
		public int compareTo(Object arg0) {
			Sum s = (Sum)arg0;
			return (this.sum - s.sum);
		}
	}
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.gc();
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
			
	private static String solveProblem(Problem p) {
		ArrayList<Sum> sums = new ArrayList<Sum>();
		//initialize
		for (int i=0; i<20; i++) {
			Sum s = new Sum();
			s.sum = p.S[i];
			s.setNth(i);
			sums.add(s);
		}
		
		String s1 = "";
		String s2 = "";
		
		int startNextCycle = 0;
		
		outer: for (int k=0; k<20; k++) {
			int numSums = sums.size();
			for (int i=startNextCycle; i<numSums; i++) {
				Sum s = sums.get(i);
				int hui = s.highestUsedIndex;
				for (int j=hui+1; j<20; j++) {
					if (!s.checkNth(j)) {
						Sum newSum = new Sum();
						newSum.sum = s.sum + p.S[j];
						newSum.numsUsed = s.numsUsed;
						newSum.setNth(j);
						sums.add(newSum);
					}
				}
			}
			startNextCycle = numSums;
		
			int[] check = new int[3000000];
			System.out.println("Start of check " + k + ", " + sums.size()  + " in sums.");
			
			int i = 0;
			while (i<sums.size()) {
				int val = sums.get(i).sum;
				if (check[val]!=0) {
					//found a duplicate or a solution
					if (sums.get(check[val]-1).numsUsed==sums.get(i).numsUsed) {
						//duplicate
						System.out.println(sums.get(check[val]-1) + " and " + sums.get(i));
						System.out.println(i +  ", " + (check[val]-1));
						System.out.println(sums.get(i).printInts(p) + ", " + sums.get(i).numsUsed);
						System.out.println(sums.get(check[val]-1).printInts(p) + ", " + sums.get(check[val]-1).numsUsed);
						sums.remove(i);
					} else {
						//solution
						s1 = sums.get(check[val]-1).printInts(p);
						s2 = sums.get(i).printInts(p);
						break outer;
					}
				} else {
					//use i+1 to avoid zero issue
					check[val]=i+1;
					i++;
				}
			}
			
			System.out.println("End of check " + k + ", "+ sums.size()  + " in sums.");
			
		}
			
		if (s1.equals("")) {
			return "Impossible";
		}
		
		return "\n" + s1 + "\n" + s2;
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				String[] pieces = line.split(" ");
				for (int j=0; j<20; j++) {
					probs[i].S[j] = Integer.parseInt(pieces[j+1]);
				}
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
