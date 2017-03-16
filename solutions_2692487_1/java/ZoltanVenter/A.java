import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class A {
	private static LinkedList<Integer> motes;
	private static int armin;

	public A(LinkedList<Integer> motes, int armin) {
		this.motes = motes;
		this.armin = armin;
	}

	public static boolean absorb() {
		int temp = 0;
		for (int i : motes) {
			if (i < armin) {
				temp = i;
				break;
			}
		}

		if (temp != 0) {
			motes.removeFirstOccurrence(temp);
			armin += temp;
			return true;
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("input"));
		PrintWriter outfil = new PrintWriter(new FileWriter("output"));

		int numTests = sc.nextInt();
		for (int test = 1; test <= numTests; test++) {
			
			int a = sc.nextInt();
			LinkedList<Integer> n = new LinkedList<Integer>();
			int size = sc.nextInt();
			int[] temp = new int[size];

			for (int i = 0; i < size; i++)
				temp[i] = sc.nextInt();
			Arrays.sort(temp);
			for (int i = 0; i < size; i++)
				n.add(temp[i]);

			new A(n, a);
			int added = 0;
			int changes = Integer.MAX_VALUE;
			while (true) {
				
				if(armin == 1){
					changes = motes.size();
					break;
				}
				while (absorb()) {

				}
				int flag = added + motes.size();
				int nextMote = armin + armin - 1;
				
				if(flag < changes) changes = flag;				
				
				if (motes.size() == 0) {
					break;
				} 			
					armin = nextMote;
					added++;							
			}
			
			outfil.println("Case #" + test + ": " + changes);
			outfil.flush();
		}
		outfil.close();
		sc.close();
	}
}
