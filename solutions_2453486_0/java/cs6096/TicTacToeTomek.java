import java.util.*;
public class TicTacToeTomek {
	public static Scanner scan = new Scanner(System.in);
	public static boolean bug = false;
	public static void main(String[] args){
		int n1 = Integer.parseInt(scan.next());
		for (int i = 0; i < n1; i++) {
			char[][] l1 = new char[4][4];
			for (int j = 0; j < 4; j++) {
				l1[j]=scan.next().toCharArray();
				if (bug) System.out.println(Arrays.toString(l1[j]));
			}
			int win = -1;
			for (int j = 0; j < 4; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j][j2]=='O'||l1[j][j2]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=1;
				}
			}
			if (bug) System.out.println(win);
			for (int j = 0; j < 4; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j2][j]=='O'||l1[j2][j]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=1;
				}
			}
			if (bug) System.out.println(win);
			for (int j = 0; j < 4; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j2][j]=='X'||l1[j2][j]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=2;
				}
			}
			if (bug) System.out.println(win);
			for (int j = 0; j < 4; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j][j2]=='X'||l1[j][j2]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=2;
				}
			}
			if (bug) System.out.println(win);
			//diag
			for (int j = 0; j < 1; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j2][j2]=='X'||l1[j2][j2]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=2;
				}
			}
			if (bug) System.out.println(win);
			for (int j = 0; j < 1; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j2][3-j2]=='X'||l1[j2][3-j2]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=2;
				}
			}
			if (bug) System.out.println(win);
			for (int j = 0; j < 1; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j2][3-j2]=='O'||l1[j2][3-j2]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=1;
				}
			}
			if (bug) System.out.println(win);
			for (int j = 0; j < 1; j++) {
				boolean k1 = true;
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j2][j2]=='O'||l1[j2][j2]=='.'){
						k1=false;
					}
				}
				if (k1){
					win=1;
				}
			}
			if (bug) System.out.println(win);
			int count  = 0;
			for (int j = 0; j < 4; j++) {
				for (int j2 = 0; j2 < 4; j2++) {
					if (l1[j][j2]!='.'){
						count++;
					}
				}
			}
			if (count==16&&win==-1){
				win=0;
			}
			if (bug) System.out.println(win);
			if (bug) System.out.println("final "+win);
			System.out.print("Case #"+(i+1)+": ");
			if (win==1){
				System.out.print("X won");
			}
			if (win==2){
				System.out.print("O won");
			}
			if (win==0){
				System.out.print("Draw");
			}
			if (win==-1){
				System.out.print("Game has not completed");
			}
			System.out.print("\n");
		}
	}
}
