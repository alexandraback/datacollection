import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;



public class Problem2 {
	public static class Pair{
		int x = 0;
		int y = 0;
		Pair(int a, int b){
			x=a;
			y=b;
		}
		
		public boolean equals(Object o){
			if (!(o instanceof Pair))
				return false;
			Pair o2 = (Pair) o;
			return o2.x == x && o2.y == y;
		}
		
		public int hashCode(){
			int[] a = {x,y};
			return Arrays.hashCode(a);
		}
		
		public int getX(){
			return x;
		}
		
		public int getY(){
			return y;
		}
	}
	
	public static void main(String[] args) {
		FileReader input;
		try {
			input = new FileReader("B-small-attempt0.in.txt");
			BufferedReader reader = new BufferedReader(input);
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			int test = Integer.parseInt(reader.readLine());
			for (int k = 1; k <= test; k++) {
				// Solution here
				Scanner scanner = new Scanner(reader.readLine());
				int x = scanner.nextInt();
				int y = scanner.nextInt();
				Pair destination = new Pair(x,y);
				int jump = 1;
				HashMap<Pair, String> frontier = new HashMap<Pair,String>();
				frontier.put(new Pair(0,0), "");
				while(!frontier.containsKey(destination)){
					HashMap<Pair, String> newFrontier = new HashMap<Pair, String>();
					for(Pair p : frontier.keySet()){
						Pair north = new Pair(p.x, p.y+jump);
						Pair south = new Pair(p.x, p.y-jump);
						Pair east = new Pair(p.x+jump, p.y);
						Pair west = new Pair(p.x-jump, p.y);
						if(!newFrontier.containsKey(north)){
							newFrontier.put(north, frontier.get(p)+"N");
						}
						if(!newFrontier.containsKey(south)){
							newFrontier.put(south, frontier.get(p)+"S");
						}
						if(!newFrontier.containsKey(east)){
							newFrontier.put(east, frontier.get(p)+"E");
						}
						if(!newFrontier.containsKey(west)){
							newFrontier.put(west, frontier.get(p)+"W");
						}
					}
					frontier = newFrontier;
					jump++;
				}
				out.println("Case #" + k + ": "+frontier.get(destination));
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
