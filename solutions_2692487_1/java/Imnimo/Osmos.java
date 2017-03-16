import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Osmos {
	public static void main(String[] args) {

		try {
			Scanner s = new Scanner(new File("A-large.in"));
			int numCases = Integer.parseInt(s.nextLine());
			for(int c = 1;c<=numCases;c++) {
				String first = s.nextLine();
				String[] fa = first.split(" ");
				int moteSize = Integer.parseInt(fa[0]);
				int numMotes = Integer.parseInt(fa[1]);
				int[] motes = new int[numMotes];
				String second = s.nextLine();
				String[] sa = second.split(" ");
				for(int i = 0;i<numMotes;i++) {
					motes[i] = Integer.parseInt(sa[i]);
				}
				Arrays.sort(motes);
				OsmosGame.motes = motes;
				int ans = solve2(moteSize);
				System.out.println("Case #" + c + ": " + ans);
				//break;
			}
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	}
	public static void generate() {
		int numMotes = 50;
		int[] motes = new int[numMotes];
		for(int i = 0;i<numMotes;i++) {
			motes[i] = (int)(Math.random()*1000000);
		}
		int moteSize = (int)(Math.random()*100);
		OsmosGame.motes = motes;
		int x = solve2(moteSize);
		System.out.println(x);
	}
	public static int solve(int[] motes,int moteSize) {
		System.out.println("original: ");
		printArray(motes);
		System.out.println("Mote size: " + moteSize);
		System.out.println("============");
		int total = 0;
		int index = -1;
		for(int i = 0;i<motes.length;i++) {
			if(motes[i]<moteSize) {
				moteSize+=motes[i];
				//System.out.println("Eating " + i);
				//System.out.println("New Size: " + moteSize);
			} else {
				index = i;
				break;
			}
		}
		if(index==-1) {
			return 0;
		}
		if(moteSize<=1) {
			int[] deleted = new int[motes.length - index- 1];
			System.arraycopy(motes,index+1,deleted,0,deleted.length);
			int deleteCount = solve(deleted,moteSize);
			return deleteCount+1;
		}
		if(motes[index] - moteSize < moteSize) {
			int[] added = new int[motes.length - index + 1];
			added[0] = moteSize-1;
			System.arraycopy(motes, index, added, 1, added.length-1);
			return 1+solve(added,moteSize);
		}
		int[] added = new int[motes.length - index + 1];
		added[0] = moteSize-1;
		System.arraycopy(motes, index, added, 1, added.length-1);
		//System.out.println("ADDED: ");
		//printArray(added);
		int addCount = solve(added,moteSize);
		int[] deleted = new int[motes.length - index- 1];
		System.arraycopy(motes,index+1,deleted,0,deleted.length);
		int deleteCount = solve(deleted,moteSize);
		total = Math.min(addCount, deleteCount)+1;
		return total;
	}
	public static void printArray(int[] arr) {
		for(int i = 0;i<arr.length;i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	public static int solve2(int size) {
		ArrayList<OsmosGame> queue = new ArrayList<OsmosGame>();
		OsmosGame start = new OsmosGame(0,size);
		queue.add(start);
		while(!queue.isEmpty()) {
			Collections.sort(queue,new OC());
			OsmosGame current = queue.remove(0);
			//System.out.println(current.depth);
			//System.out.println("Looking at " + current.index + " with size " + current.moteSize + " with depth " + current.depth);
			if(current.index == OsmosGame.motes.length) {
				return current.depth;
			}
			if(current.moteSize<=1) {
				OsmosGame child = new OsmosGame(current.index+1,current.moteSize);
				child.depth = current.depth+1;
				queue.add(child);
				continue;
			}

			OsmosGame child = new OsmosGame(current.index+1,current.moteSize);
			child.depth = current.depth+1;
			queue.add(child);
			
			int ms = current.moteSize;
			int goal = OsmosGame.motes[current.index];
			int count = 0;
			while(ms<=goal) {
				ms = ms + ms - 1;
				count++;
			}
			
			OsmosGame child2 = new OsmosGame(current.index,ms);
			child2.depth = current.depth+count;
			queue.add(child2);
		}
		return 0;
	}
}
class OC implements Comparator<OsmosGame> {

	@Override
	public int compare(OsmosGame arg0, OsmosGame arg1) {
		return arg0.depth - arg1.depth;
	}
	
}
class OsmosGame {
	static int[] motes;
	int index;
	int moteSize;
	int depth;
	public OsmosGame(int start,int ms) {
		int i = start;
		while(i<motes.length && ms>motes[i]) {
			ms+=motes[i];
			i++;
		}
		moteSize = ms;
		index = i;
	}
}
