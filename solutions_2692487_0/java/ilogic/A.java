import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

public class A {

	int moteSize;
	LinkedList<Integer> motes;
	public int changes = Integer.MAX_VALUE;
	public int removedMote = 0;
	
	public int least = Integer.MAX_VALUE;

	public A(int moteSize, LinkedList<Integer> motes) {
		this.moteSize = moteSize;
		this.motes = motes;
		
		if (moteSize == 1){
			changes = motes.size();
			return;
		}

		while (go2(0)) {

		}
	}
	
	private boolean go2(int added)
	{
		
		while (absorb()) {
			
		}
		int changes = added + motes.size();
		if (changes < this.changes)
			this.changes = changes;
		
		if (motes.size() != 0)
		{
				motes.add(moteSize - 1);
				return go2(added + 1);
		}
		
		return false;
	}

	private boolean go(boolean add) {
		while (absorb()) {

		}

		if (motes.size() != 0) {
			// Add mote
			if (add) {
				if (removedMote != 0 && removedMote < moteSize) {
					changes--;
					motes.add(removedMote);
					removedMote = 0;
					while (absorb()) {

					}
				} else {
					// int mote = 0;
					/*
					 * for (int i : motes) if (i > mote && i < moteSize) mote =
					 * i;
					 */
					if (moteSize != 1) {
						motes.add(moteSize - 1);
						changes += 1;
					}
				}
				return go(false);
			}
			// remove mote
			else {
				int mote = 0;
				for (int i : motes)
					if (i > mote)
						mote = i;
				motes.removeFirstOccurrence(mote);
				changes++;
				removedMote = mote;
				return go(true);
			}
		} else {
			// done
			return false;
		}
	}

	private boolean absorb() {
		int temp = 0;
		for (int i : motes) {
			if (i < moteSize) {
				temp = i;
				break;
			}
		}

		if (temp != 0) {
			motes.removeFirstOccurrence(temp);
			moteSize += temp;
			return true;
		}

		return false;

	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("input"));
		PrintWriter pw = new PrintWriter(new FileWriter("output"));

		int testCases = sc.nextInt();

		for (int t = 0; t < testCases; t++) {
			int aMote = sc.nextInt();
			int N = sc.nextInt();
			LinkedList<Integer> motes = new LinkedList<Integer>();
			for (int i = 0; i < N; i++) {
				motes.add(sc.nextInt());
			}
			A a = new A(aMote, motes);
			pw.println("Case #" + (t + 1) + ": " + a.changes);
		}

		pw.flush();
		pw.close();
		sc.close();
	}
}
