import java.io.*;
import java.util.*;
import java.lang.*;

public class Brattleship{
	int testNum, r, c, w, ans, hit, turns, now;
	int[] board, ship;
	boolean bingo, forward, firsthitnotlast, firstmovecapture;
	public void solve(){
		int i, j;
		if (1 == w || w == c){
			ans = c;
			return;
		}
		board = new int[c + 1];
		ship = new int[c + 1];
		for (i = 0; i <= c; i++){
			board[i] = ship[i] = 0;
		}
		hit = 0;
		turns = 0;
		now = 0;
		bingo = false;
		forward = true;
		firsthitnotlast = false;
		for (i = c; i > c-w; i--)
			ship[i] = 1;
		while (hit < w){
			if (bingo){
				if (now < c && forward){
					now += 1;
					board[now] = 1;
					turns += 1;
					hit += 1;
					
				}
				else
				{
					if (now == c){
						forward = false;
						j = c;
						while (1 == board[j])
							j--;
						now = j;
						board[j] = 1;
						turns += 1;
						hit += 1;
								
					}
					else
					{
						now -= 1;
						board[now] = 1;
						turns += 1;
						hit += 1;
					}
				}
			}
			else
			{
				if (now + w <= c){
					now += w;
					board[now] = 1;
					turns += 1;
					if (1 == ship[now]){
						bingo = true;
						hit += 1;
						if (now != c){
							firsthitnotlast = true;
						}
					}
				}
			}
			
		}
		if (firsthitnotlast)
			turns += 1;
		ans = turns;
	}
	public void calculate(String filename){
		int testcase, i, j;
		Integer myInt;
		try{
			Scanner fin = new Scanner(new File(filename));
			BufferedWriter fout = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("out.txt")));
			testNum = fin.nextInt();
			for (testcase = 1; testcase <= testNum; testcase++){
				r = fin.nextInt();
				c = fin.nextInt();
				w = fin.nextInt();
				solve();
				myInt = testcase;
				fout.write("Case #"+myInt.toString()+": ");
				myInt = ans;
				fout.write(myInt.toString());
				fout.newLine();
			}
			fout.close();
			fin.close();
		} catch(Exception e){
			
		}
	}
	public static void main(String[] args){
		Brattleship myClass = new Brattleship();
		myClass.calculate("A-small-attempt0.in");
	}
}