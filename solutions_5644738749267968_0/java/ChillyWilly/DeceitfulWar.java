
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;
import java.util.TreeSet;

/**
 * @author Adrian Buturuga
 */
public class DeceitfulWar
{

	private static void solveTestCase(int testCase, Scanner input, FileOutputStream output) throws IOException
	{
		TreeSet<Float> naomi = new TreeSet<Float>();
		TreeSet<Float> ken = new TreeSet<Float>();
		TreeSet<Block> combined = new TreeSet<Block>();
		
		int N = input.nextInt();
		for (int i=0; i<N; i++) {
			Float temp = input.nextFloat();
			naomi.add(temp);
			combined.add(new Block(temp, true));
		}
		for (int i=0; i<N; i++) {
			Float temp = input.nextFloat();
			ken.add(temp);
			combined.add(new Block(temp, false));
		}
		output.write(("Case #"+testCase+": "+deceitful(combined)+" "+war(naomi, ken)+"\n").getBytes());
		
	}
	
	private static int war(TreeSet<Float> naomi, TreeSet<Float> ken) {
		int taken = 0;
		Iterator<Float> naomiIterator = naomi.descendingIterator();
		Iterator<Float> kenDescIterator = ken.descendingIterator();
		Float descKen = kenDescIterator.next();
		while (naomiIterator.hasNext()) {
			Float n = naomiIterator.next();
			if (n > descKen) {
				taken++;
			} else {
				if (kenDescIterator.hasNext()) {
					descKen = kenDescIterator.next();
				}
			}
		}
		return taken;
	}
	
	private static int deceitful(TreeSet<Block> combined) {
		int taken = 0;
		int available = 0;
		for (Block b : combined) {
			if (b.naomis) {
				if (available > 0) {
					available--;
					taken++;
				}
			} else {
				available++;
			}
		}
		return taken;
	}
	
	private static class Block implements Comparable<Block> {

		public Float value;
		public boolean naomis;

		public Block(Float value, boolean naomis)
		{
			this.value = value;
			this.naomis = naomis;
		}
		
		@Override
		public int compareTo(Block o)
		{
			return value.compareTo(o.value);
		}
		
	}
	
	public static void main(String args[]) throws Exception
	{
		File inputFile = new File("D-small-attempt1.in");
		Scanner input = new Scanner(inputFile);
		input.useLocale(Locale.US);

		File outputFile = new File("D-small-attempt1.out");
		FileOutputStream fos = new FileOutputStream(outputFile);

		int testCases = input.nextInt();

		for (int i = 1; i <= testCases; i++)
		{
			solveTestCase(i, input, fos);
		}

		input.close();
		fos.close();
	}
}
