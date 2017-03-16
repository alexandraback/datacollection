import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Collections;
import java.util.List;
import java.util.Vector;

public class Problem1 {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			int pbcount = Integer.parseInt(in.readLine());
			int pbidx = 1;
			while (pbcount > 0) {
				// Size of the playfield
				String sizel = in.readLine();
				String[] sizea = sizel.split(" ");
				if(sizea.length != 2) {
					System.err.println("Unexpected header");
					return;
				}
				int moteCount = Integer.parseInt(sizea[1]);
				int moteSize = Integer.parseInt(sizea[0]);
				Vector<Integer> enemyMotes = new Vector<Integer>(moteCount);
				
				sizel = in.readLine();
				sizea = sizel.split(" ");
				if(sizea.length != moteCount) {
					System.err.println("Bad mote count");
					return;
				}
				
				for(int i=0; i<moteCount; ++i) {
					enemyMotes.add(new Integer(sizea[i]));
				}
				
				int changes = 0;
				
				Collections.sort(enemyMotes);
				changes = travel(moteSize, 0, enemyMotes);

				System.out.println("Case #" + String.valueOf(pbidx) + ": " + String.valueOf(changes));

				--pbcount;
				++pbidx;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	static int travel(int moteSize, int changes, List<Integer> enemies) {
		boolean twitch = false;
		Vector<Integer> foes = new Vector<Integer>(enemies);
		int currentEnemy = 0;
		while(!foes.isEmpty()) {
			currentEnemy = foes.remove(0);
			if(moteSize>currentEnemy) {
				// Eat
				moteSize += currentEnemy;
			} else if(moteSize==1) {
				// Unwinnable
				++changes;
			} else {
				twitch = true;
				break;
			}
		}
		if(!twitch) {
			return changes;
		}
		
		int kill = travel(moteSize, changes + 1, foes);
		
		int tempMoteSize = moteSize;
		int addChanges = 0;
		while(tempMoteSize<=currentEnemy) {
			++addChanges;
			// Add another mote
			tempMoteSize += tempMoteSize - 1;
			//System.out.println(String.valueOf(tempMoteSize) + " " + String.valueOf(currentEnemy));
		}
		
		//System.out.println(String.valueOf(addChanges));
		
		int grow = travel(tempMoteSize + currentEnemy, changes + addChanges, foes);
		
		//System.out.println(String.valueOf(kill) + " " + String.valueOf(grow));
		
		if(kill<grow) {
			return kill;
		} else {
			return grow;
		}
	}

}
