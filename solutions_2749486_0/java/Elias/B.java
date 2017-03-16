import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class B {

	public static void main(String[] args) throws IOException {
		new B();
	}
	
	public B() throws IOException {
		Scanner in = new Scanner(new File("B-small-attempt3.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("B-small.txt"));
		int amountOfTasks = in.nextInt();
		for (int task = 0; task < amountOfTasks; task++) {
			System.out.println("Case: #" + (task+1));
			
			int x = in.nextInt() + 100;
			int y = in.nextInt() + 100;
			
			ArrayList<Pair> list = new ArrayList<Pair>();
			
			String[][] field = new String[201][201];
			field[100][100] = "";
			
			int inc = 1;
			
			list.add(new Pair(100,100));

			boolean finished = false;
			
			while(!finished) {
				ArrayList<Pair> newList = new ArrayList<Pair>();
				for (int i = 0; i<list.size(); i++) {
					Pair pair = list.get(i);
					
					Pair newPair = new Pair(pair.x, pair.y+inc);
					//System.out.println(newPair.x + " " + newPair.y);
					if (!containsPair(newList, newPair) && newPair.x >= 0 && newPair.x <=200 && newPair.y >= 0 && newPair.y <=200 /*&& field[newPair.x][newPair.y] == null*/) {
						newList.add(newPair);
						field[newPair.x][newPair.y] = field[pair.x][pair.y] + "N";
						//System.out.println(newPair.x + " " + newPair.y);
					}
					
					newPair = new Pair(pair.x, pair.y-inc);
					//System.out.println(newPair.x + " " + newPair.y);
					if (!containsPair(newList, newPair) && newPair.x >= 0 && newPair.x <=200 && newPair.y >= 0 && newPair.y <=200 /*&& field[newPair.x][newPair.y] == null*/) {
						newList.add(newPair);
						field[newPair.x][newPair.y] = field[pair.x][pair.y] + "S";
						//System.out.println(newPair.x + " " + newPair.y);
					}
					
					newPair = new Pair(pair.x+inc, pair.y);
					//System.out.println(newPair.x + " " + newPair.y);
					if (!containsPair(newList, newPair) && newPair.x >= 0 && newPair.x <=200 && newPair.y >= 0 && newPair.y <=200 /*&& field[newPair.x][newPair.y] == null*/) {
						newList.add(newPair);
						field[newPair.x][newPair.y] = field[pair.x][pair.y] + "E";
						//System.out.println(newPair.x + " " + newPair.y);
					}
					
					newPair = new Pair(pair.x-inc, pair.y);
					//System.out.println(newPair.x + " " + newPair.y);
					if (!containsPair(newList, newPair) && newPair.x >= 0 && newPair.x <=200 && newPair.y >= 0 && newPair.y <=200 /*&& field[newPair.x][newPair.y] == null*/) {
						newList.add(newPair);
						field[newPair.x][newPair.y] = field[pair.x][pair.y] + "W";
						//System.out.println(newPair.x + " " + newPair.y);
					}
				}
				System.out.println(field[x][y]);
				
				if (field[x][y] != null)
					finished = true;
				
				list = newList;
				
				inc++;
			}

			System.out.println(field[x][y]);
			out.write("Case #" + (task+1) + ": " + field[x][y]);
			out.newLine();
		}
		in.close();
		out.close();
	}
	
	private boolean containsPair(ArrayList<Pair> pairs, Pair pair) {
		for (int i = 0; i < pairs.size(); i++) {
			if (pairs.get(i).x == pair.x && pairs.get(i).y == pair.y)
				return true;
		}
		return false;
	}
	
	public class Pair {
		public int x;
		public int y;
		public Pair(int xthis , int ythis) {
			x = xthis;
			y = ythis;
		}
	}
}