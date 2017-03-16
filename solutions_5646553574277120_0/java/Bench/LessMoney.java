import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class LessMoney {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Couldn't open input file.\n" + e.getMessage());
			e.printStackTrace();
		}
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e) {
			System.out.println("Couldn't open/make output file."
					+ e.getMessage());
			e.printStackTrace();
		}

		int numTrials = scanner.nextInt();
		for (int trial = 1; trial <= numTrials; trial++) {
			try {
				writer.write("Case #" + trial + ": ");
				solveTrial(scanner, writer);
				writer.write("\n");
			} catch (IOException e) {
				System.out.println("Error on trial #" + trial + "\n"
						+ e.getMessage());
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
		System.out.println("Completed Trials!");
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int C = scanner.nextInt();
		int D = scanner.nextInt();
		long V = scanner.nextInt();
		ArrayList<Long> coins = new ArrayList<Long>(D);
		for (int i = 0; i < D; i++)
			coins.add(scanner.nextLong());
		Collections.sort(coins);
		int coinsAdded = 0;
		if (coins.get(0) != 1){
			coins.add(0, (long) 1);
			//System.out.println("added 1");
			coinsAdded++;
		}
		int totalValue = C;
		for (int i = 1; i <= coins.size(); i++){
			long target;
			if (i < coins.size())
				target = coins.get(i) - 1;
			else
				target = V;
			if (totalValue < target){
				long newCoin =  totalValue + 1;
				//System.out.println("added " + newCoin);
				coins.add(i,newCoin);
				totalValue += newCoin * C;
				coinsAdded++;
			}else{
				if (i < coins.size())
					totalValue += coins.get(i) * C;
			}
		}
		writer.write(coinsAdded + "");
	}
}
