package kingdomrush;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.TreeSet;


public class Main {

	public static void main(String[] args) throws IOException {
		File file = new File("B-small-attempt0.in");
		FileReader fr = new FileReader(file);
		BufferedReader in = new BufferedReader(fr);

		String line = in.readLine();
		String[] tokens;
		int num = Integer.parseInt(line);
		int i=1,N,s1,s2;
		TreeSet<Level> tree;
		while (i <= num) {
			N = Integer.parseInt(in.readLine());
			tree = new TreeSet<Level>();
			for(int j=0;j<N;j++){
				line = in.readLine();
				tokens = line.split(" ");
				s1 = Integer.parseInt(tokens[0]);
				s2 = Integer.parseInt(tokens[1]);
				tree.add(new Level(s1,s2));
			}
			System.out.println("Case #" + i + ": " + handleCase(tree));
			i++;
		}
	}

	private static String handleCase(TreeSet<Level> tree) {
		int count = 0;
		int stars = 0;
		boolean flag;
		Iterator<Level> it;
		Level l;
		
		while(!tree.isEmpty()){
			//printTree(tree);
			count++;
			if(tree.first().star2<=stars){
				stars++;
				if(!tree.first().gotStar1){
					stars++;
				}
				tree.remove(tree.first());
			} else {
				flag = true;
				it = tree.descendingIterator();
				while(it.hasNext()){
					l = it.next();
					if(l.star1<=stars && !l.gotStar1){
						//System.out.println("got star1");
						l.gotStar1 = true;
						stars++;
						flag = false;
						break;
					}
				}
				if(flag){
					//System.out.println("Ending, bad...");
					return "Too Bad";
				}
			}
		}
		
		//System.out.println();
		//System.out.println("Ending, good...");
		
		return count+"";
	}
	
	@SuppressWarnings("unused")
	private static void printTree(TreeSet<Level> tree){
		for(Level l:tree){
			System.out.print("{"+l.star1+" "+l.star2+" "+l.gotStar1+"} ");
		}
		System.out.println();
	}
	
	private static class Level implements Comparable<Level>{
		int star1, star2;
		boolean gotStar1;
		
		Level(int star1a, int star2a){
			star1 = star1a;
			star2 = star2a;
			gotStar1 = false;
		}

		@Override
		public int compareTo(Level other) {
			if(this==other){
				return 0;
			}
			if(star2 > other.star2){
				return 1;
			}
			return -1;
		}
	}
}
