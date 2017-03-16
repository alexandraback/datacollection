package round1c;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ProblemC {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		// Get the number of test cases
		int j, p, s, k;
		int totalCases = input.nextInt();
		for (int caseId = 1; caseId <= totalCases; caseId++) {
			// Read numbers
			j = input.nextInt();
			p = input.nextInt();
			s = input.nextInt();
			k = input.nextInt();
			
			List<int[]> outfits = getOutfits(j, p, s, k);
			
			// Print the result
			StringBuilder out = new StringBuilder();
			out.append("Case #" + caseId + ": " + outfits.size() + "\n");
			for (int[] outfit : outfits)
				out.append((outfit[0] + 1) + " " + (outfit[1] + 1) + " " + (outfit[2] + 1) + "\n");
			System.out.print(out);
		}
		
		input.close();
	}
	
	private static List<int[]> getOutfits(int maxJ, int maxP, int maxS, int maxComs) {
		List<int[]> outfits = null, maxOutfits = null;
		
		for (int j = 0; j < maxJ; j++)
			for (int p = 0; p < maxP; p++)
				for (int s = 0; s < maxS; s++) {
					outfits = chooseOutfits(new LinkedList<int[]>(), new int[]{j, p, s},
							new int[]{maxJ - 1, maxP - 1, maxS - 1}, new HashMap<Combination, Integer>(), maxComs);
					if (maxOutfits == null || outfits.size() > maxOutfits.size())
						maxOutfits = outfits;
				}
		
		return maxOutfits;
	}
	
	private static List<int[]> chooseOutfits(List<int[]> outfits, int[] chosen, int[] max, HashMap<Combination, Integer> coms, int maxTimes) {
		// Get combinations and check the max size
		Combination com;
		// j, p
		com = new Combination(0, chosen[0], 1, chosen[1]);
		if (!addAndCheckCombination(coms, com, maxTimes))
			return outfits;
		// j, s
		com = new Combination(0, chosen[0], 2, chosen[1]);
		if (!addAndCheckCombination(coms, com, maxTimes))
			return outfits;
		// p, s
		com = new Combination(1, chosen[0], 2, chosen[1]);
		if (!addAndCheckCombination(coms, com, maxTimes))
			return outfits;
		
		// Pass, add this outfit
		outfits.add(chosen);
		
		// Next iteration
		int[] choose;
		if (chosen[2] < max[2])
			choose = new int[]{chosen[0], chosen[1], chosen[2] + 1};
		else if (chosen[1] < max[1])
			choose = new int[]{chosen[0], chosen[1] + 1, 0};
		else if (chosen[0] < max[0])
			choose = new int[]{chosen[0] + 1, 0, 0};
		else
			return outfits;
		
		return chooseOutfits(new LinkedList<int[]>(outfits), choose, max, new HashMap<Combination, Integer>(coms), maxTimes);
	}
	
	// true: OK, false: Boom!!
	private static boolean addAndCheckCombination(Map<Combination, Integer> timesMap, Combination com, int maxTimes) {
		Integer times = timesMap.get(com);
		if (times == null)
			times = 1;
		else
			times++;
		timesMap.put(com, times);
		
//		if (com.left.pos == 0 && com.left.number == 0 && com.right.pos == 1 && com.right.number == 0) {
//			System.out.println(com);
//			System.out.println(timesMap);
//			System.out.println(maxTimes);
//		}
		
		if (times > maxTimes)
			return false;
		return true;
	}
	
	private static class Type {
		int pos = -1;
		int number = -1;
		
		@Override
		public String toString() {
			return "[" + pos + ", " + number + "]";
		}
		
		@Override
		public boolean equals(Object obj) {
			if (obj == this)
				return true;
			
			if (!(obj instanceof Type))
				return false;
			
			Type t = (Type) obj;
			
			return pos == t.pos && number == t.number;
		}
		
		@Override
		public int hashCode() {
			int hashCode = 17;
			hashCode = 31 * hashCode + pos;
			hashCode = 31 * hashCode + number;
			return hashCode;
		}
	}
	
	private static class Combination {
		Type left, right;
		
		public Combination(int leftPos, int leftNum, int rightPos, int rightNum) {
			left = new Type();
			left.pos = leftPos;
			left.number = leftNum;
			right = new Type();
			right.pos = rightPos;
			right.number = rightNum;
		}
		
		@Override
		public String toString() {
			return "[" + left + ", " + right + "]";
		}
		
		@Override
		public boolean equals(Object obj) {
			if (obj == this)
				return true;
			
			if (!(obj instanceof Combination))
				return false;
			
			Combination com = (Combination) obj;
			return (left.equals(com.left) && right.equals(com.right)) ||
					(right.equals(com.right) && left.equals(com.left));
		}
		
		@Override
		public int hashCode() {
			int hashCode = 17;
			hashCode = 31 * hashCode + left.hashCode() + right.hashCode();
			return hashCode;
		}
	}
}
