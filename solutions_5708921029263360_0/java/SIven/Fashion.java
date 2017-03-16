import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Fashion {
	private static List<String> outfits = new ArrayList<String>();
	private static int nbJackets, nbPants, nbShirts, k;

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = Integer.parseInt(in.nextLine()); // Scanner has functions to
													// read ints, longs,
													// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			nbJackets = in.nextInt();
			nbPants = in.nextInt();
			nbShirts = in.nextInt();
			k = in.nextInt();
			generateOutfits();
			System.out.println("Case #" + i + ": " + outfits.size());
			for (String outfit : outfits) {
				System.out.println(outfit);
			}
		}
	}

	private static void generateOutfits() {
		// int maxIndex1 = Math.min(nbJackets, k);
		int maxIndex1 = nbJackets;
		List<String> jackets = new ArrayList<String>();
		for (int i = 1; i <= maxIndex1; i++) {
			jackets.add("" + i);
		}
		// int maxIndex2 = Math.min(nbPants, k);
		int maxIndex2 = nbPants;
		List<String> pants = new ArrayList<String>();
		for (int j = 0; j <= k; j++) {
			for (String jacket : jackets) {
				int numberToAdd = ((Integer.parseInt(jacket)-1 + j) % nbPants) + 1;
				pants.add(jacket + " " + numberToAdd);
			}
		}
		// int maxIndex3 = Math.min(nbShirts, k);
		int maxIndex3 = nbShirts;
		outfits = new ArrayList<String>();
		for (int l = 0; l <= k; l++) {
			for (String pant : pants) {
				int numberToAdd = Math.max(Integer.parseInt(pant.split(" ")[0]), Integer.parseInt(pant.split(" ")[1]));
				numberToAdd = ((numberToAdd-1 + l) % nbShirts) + 1;
				String newOutfit = pant + " " + numberToAdd;
				outfits.add(newOutfit);
			}
		}

		Set<String> doubled = new LinkedHashSet<>(outfits);
		outfits.clear();

		List<String> survivors = new ArrayList<String>();
		survivors = new ArrayList<String>();
		survivors.addAll(doubled);
		
		for(String outfit : survivors){
			if(!tooManyMatches(outfit)){
				outfits.add(outfit);
			}
		}
	}

	private static boolean tooManyMatches(String newOutfit) {
		int counter1 = 0;
		int counter2 = 0;
		int counter3 = 0;
		String[] newSplit = newOutfit.split(" ");
		for(String outfit : outfits){
			String[] splitOutfit = outfit.split(" ");
			//System.out.println(newOutfit + " " + outfit + (newSplit[0].equals(splitOutfit[0])) +( newSplit[1].equals(splitOutfit[1])) + (newSplit[2].equals(splitOutfit[2])));
			if(newSplit[0].equals(splitOutfit[0])){
				if(newSplit[1].equals(splitOutfit[1])){
					counter1++;
					if(counter1 >= k){
						return true;
					}
				}if(newSplit[2].equals(splitOutfit[2])){
					counter2++;
					if(counter2 >= k){
						return true;
					}
				}
			}if(newSplit[1].equals(splitOutfit[1])){
				if(newSplit[2].equals(splitOutfit[2])){
					counter3++;
					if(counter3 >= k){
						return true;
					}
				}
			}
		}
		return false;
	}
}
