import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Lawnmower {
	
static PrintStream out;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in;
		out = new PrintStream(new File("out.txt"));
		try {
			in = new Scanner(new File(args[0]));
		} catch (IndexOutOfBoundsException e){
			System.out.println("Was expecting path to input file.");
			return;
		} catch (FileNotFoundException e) {
			System.out.println("Could not find the path specified.");
			return;
		}
		//get number of cases
		int cases = in.nextInt();
		for(int i=1;i<=cases;i++){
			int height = in.nextInt();
			int width = in.nextInt();
			int[][] tiles = new int[height][width];
			for(int[] row : tiles){
				for(int j=0;j<row.length;j++){
					row[j] = in.nextInt();
				}
			}
			//check
			boolean all = true;
			yl: for(int y=0;y<tiles.length;y++){
				for(int x=0;x<tiles[y].length;x++){
					boolean works = true;
					lteyl: for(int ltey=0;ltey<tiles.length;ltey++){
						if(tiles[ltey][x] > tiles[y][x]){
							works = false;
							break lteyl;
						}
					}
					if(!works){
						for(int ltex=0;ltex<tiles[y].length;ltex++){
							if(tiles[y][ltex] > tiles[y][x]){
								all = false;
								break yl;
							}
						}
					}
				}
			}
			out.print("Case #" + i + ": ");
			if(all){
				out.println("YES");
			}else{
				out.println("NO");
			}
		}
	}
}
