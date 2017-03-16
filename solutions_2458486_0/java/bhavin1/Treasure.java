import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Treasure {

	ArrayList<Integer> keysOut;
	int stars =0;
	int levplayed=0;
	String result;
	public void output(BufferedWriter out, int caseNum, int string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}
	public void output(BufferedWriter out, int caseNum, String string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}

	class Container implements Comparable<Container> {
		ArrayList keys;
		boolean opened;
		Integer order;
		int key;
		Integer sameKeyCount;

		public Container(int ord, int pkey) {
			order=ord;
			opened=false;
			key=pkey;
			sameKeyCount=0;
			keys=new ArrayList();
			
			
		}

		@Override
		public int compareTo(Container o) {
			
			if(key==o.key) {
				
				if(Collections.frequency(keysOut, key) > 1) {
					return o.order.compareTo(order);
				}
				
				if(sameKeyCount > 0 && o.sameKeyCount > 0) {
					return o.order.compareTo(order);
				}
				if(sameKeyCount.equals(o.sameKeyCount)) {
					return o.order.compareTo(order);
				} else {
					return sameKeyCount.compareTo(o.sameKeyCount);
				}
			} else {
				return o.order.compareTo(order);
			}
				
		}
	}
	public void solve() throws IOException{
		
		Scanner in = new Scanner(new File("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.out"));
		
		
		int numCases = in.nextInt();
		for (int i = 0; i < numCases; i++) {
			
			result = "";
			keysOut=new ArrayList<Integer>();
			ArrayList<Container> chests = new ArrayList<Container>();
			int numKeys=in.nextInt();
			int numChes=in.nextInt();
			
			for(int j=0; j<numKeys; j++)
				keysOut.add(in.nextInt());
			
			for(int j=1; j<=numChes; j++) {
				createContainer(chests,in, j);
			}
			
			while(true) {
				
				boolean complete=true;
				Container openchest=null;

				for(Container chest:chests) {
					if(chest.opened) continue;
					complete=false;
					if(keysOut.contains(chest.key)) {
						if(openchest==null) {
							openchest=chest;
						} 
						else {
							if(chest.compareTo(openchest) > 0) {
								openchest=chest;
							}
						}
					}
				}
				
				if (complete) {
					output(out, i+1, result);
					break;
				}
				if(openchest == null) {
					output(out, i+1, "IMPOSSIBLE");
					break;
				}
				openChest(openchest, keysOut);
				
			}
			
			//output(out, i+1, levplayed);
			
			//output(out, i+1, "Too Bad");
		}
		
		out.close();
	}
	
	private void openChest(Container openchest, ArrayList<Integer> keysOut) {
		openchest.opened=true;
		keysOut.remove(new Integer(openchest.key));
		keysOut.addAll(openchest.keys);
		result = result  + openchest.order + " ";
		
	}
	private void createContainer(ArrayList<Container> chests, Scanner in, int ord) {
		Container c = new Container(ord, in.nextInt());
		int kcnt = in.nextInt();
		
		for(int j=1; j<=kcnt; j++) {
			int key=in.nextInt();
			if (c.key==key) {
				c.sameKeyCount++;
			}
			c.keys.add(key);
		}
		
		chests.add(c);
	}
	

	public static void main(String[] args) throws IOException{
		Treasure s = new Treasure();
		s.solve();
		
	}

}


