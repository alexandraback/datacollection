import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;


public class Osmos {
	public static void main(String[] args) {
		try {
			Scanner s = new Scanner(new File("input.txt"));
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
				int ans = solve(motes,moteSize);
				System.out.println("Case #" + c + ": " + ans);
				//break;
			}
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	}
	public static int solve(int[] motes,int moteSize) {
		//System.out.println("original: ");
		//printArray(motes);
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
}
