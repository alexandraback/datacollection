import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C-small-attempt2.in"));
//		Scanner sc = new Scanner(new File("C.in"));
//		Scanner sc = new Scanner(new File("C-large 1.in"));

		int t = sc.nextInt();
		int count = 1;

		while (t-- > 0) {
			int jackets = sc.nextInt();
			int pants = sc.nextInt();
			int shirts = sc.nextInt();
			
			int K = sc.nextInt(); // Number of times a pair may be worn

			int outfits = 0;
			Map<String, Integer> JP = new HashMap<String, Integer>(jackets*pants);
			Map<String, Integer> JS = new HashMap<String, Integer>(jackets*shirts);
			Map<String, Integer> PS = new HashMap<String, Integer>(pants*shirts);

			for(int s = 0; s < shirts; s++) {
				for(int p = 0; p < pants; p++) {
			for(int j = 0; j < jackets; j++) {

						if(!JP.containsKey(j + "" + p)) {
							JP.put((j + "" + p), 0);
						}
						if(!JS.containsKey(j + "" + s)) {
							JS.put((j + "" + s), 0);
						}
						if(!PS.containsKey(p + "" + s)) {
							PS.put((p + "" + s), 0);
						}
						
						
						
						if(JP.get(j + "" + p) < K && JS.get(j + "" + s) < K && PS.get(p + "" + s) < K) {
							JP.put((j + "" + p), JP.get(j + "" + p) + 1);
							JS.put((j + "" + s), JS.get(j + "" + s) + 1);
							PS.put((p + "" + s), PS.get(p + "" + s) + 1);
							outfits++;
						}
					}
				}
			}
			
			JP = new HashMap<String, Integer>(jackets*pants);
			JS = new HashMap<String, Integer>(jackets*shirts);
			PS = new HashMap<String, Integer>(pants*shirts);
			
			System.out.println("Case #" + count + ": " + outfits);

			for(int s = 0; s < shirts; s++) {
				for(int p = 0; p < pants; p++) {
			for(int j = 0; j < jackets; j++) {

						if(!JP.containsKey(j + "" + p)) {
							JP.put((j + "" + p), 0);
						}
						if(!JS.containsKey(j + "" + s)) {
							JS.put((j + "" + s), 0);
						}
						if(!PS.containsKey(p + "" + s)) {
							PS.put((p + "" + s), 0);
						}
						
						
						
						if(JP.get(j + "" + p) < K && JS.get(j + "" + s) < K && PS.get(p + "" + s) < K) {
							JP.put((j + "" + p), JP.get(j + "" + p) + 1);
							JS.put((j + "" + s), JS.get(j + "" + s) + 1);
							PS.put((p + "" + s), PS.get(p + "" + s) + 1);
							System.out.println((j+1) + " " + (p+1) + " " + (s+1));
						}
					}
				}
			}
			
			count++;
		}

		sc.close();
	}
}
