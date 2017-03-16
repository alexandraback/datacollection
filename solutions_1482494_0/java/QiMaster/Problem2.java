import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Problem2{

	public static void main(String[] argvs){


		try{
			FileInputStream fstream = new FileInputStream("C:/Temp/cj/in.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			br.readLine();
			int caseNum=1;
			while ((strLine = br.readLine()) != null)   {
				int numLevels=Integer.parseInt(strLine);
				ArrayList<Level> levels = new ArrayList<Level>();
				for (int i=0;i<numLevels;i++){
					String tt = br.readLine();

					levels.add(new Level(Integer.parseInt(tt.substring(0,tt.indexOf(" "))),
							Integer.parseInt(tt.substring(tt.indexOf(" ")+1))));

				}
				if (caseNum==16){
					System.out.print("");
				}
				int moves = solve(levels,0,0);
				if (moves==0){
					System.out.println("Case #"+caseNum+": "+"Too Bad");
					caseNum++;
				} else {
					System.out.println("Case #"+caseNum+": "+moves);
					caseNum++;
				}
			}
			in.close();
		}catch (Exception e){
			System.err.println("Error: " + e.getMessage());
		}
	}



	static ArrayList<Integer> moveCount=new ArrayList<Integer>();

	public static int solve(ArrayList<Level> levels,int stars,int moves){
		if (complete(levels)){
			return moves;
		}
		Level lowOption = null;
		Level highOption = null;
		for (int i=0;i<levels.size();i++){
			Level tl = levels.get(i);
			if (!tl.lev2){
				if ((highOption==null || (highOption.lev1 && highOption.star2<tl.star2)) && tl.star2<=stars && !tl.lev2){
					highOption=tl;
				}
				if ((lowOption==null || (tl.star2>lowOption.star2)) && tl.star1<=stars && !tl.lev1){
					lowOption=tl;
				}
			}
		}
		if (highOption!=null){
			highOption.lev2=true;
			if (highOption.lev1){
				return solve(levels,stars+1,moves+1);
			} else {
				return solve(levels,stars+2,moves+1);
			}
		} else if (lowOption!=null){
			lowOption.lev1=true;
			return solve(levels,stars+1,moves+1);
		} else {
			return 0;
		}
	}

	public static boolean complete(ArrayList<Level> levels){
		for (Level tl : levels){
			if (!tl.lev2){
				return false;
			}
		}
		return true;
	}

	public static ArrayList<Level> copyLevels(ArrayList<Level> levels){
		ArrayList<Level> newLevels = new ArrayList<Level>();
		for (Level tl : levels){
			newLevels.add(tl.copy());
		}
		return newLevels;
	}

}

class Level{

	int star1;
	int star2;
	boolean lev1=false;
	boolean lev2=false;

	public Level(int star1,int star2){
		this.star1=star1;
		this.star2=star2;
	}

	public Level copy(){
		Level l = new Level(star1,star2);
		l.lev1=this.lev1;
		l.lev2=this.lev2;
		return l;
	}

}