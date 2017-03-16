package qualificationRound2011;

import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {

	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		int n = si();
		MainRoutine : for (int i = 0; i < n; i++) {
			PriorityQueue<Lawn> que = new PriorityQueue<Lawn>();
			int wy = si(),wx = si();
			boolean[][] used = new boolean[wy][wx];
			int[][] hmap = new int[wy][wx];
			for (int j = 0; j < wy; j++) {
				for (int k = 0; k < wx; k++) {
					que.offer(new Lawn(hmap[j][k]=si(),j,k));
				}
			}
			while(!que.isEmpty()){
				Lawn pos = que.poll();
				if(used[pos.y][pos.x]) continue;
				boolean yflag = true, xflag = true;
				for (int y = 0; y < wy ; y++) {
					if(used[y][pos.x]) continue;
					if(hmap[y][pos.x]>pos.h){
						yflag = false;
						break;
					}
				}
				for (int x = 0; x < wx ; x++) {
					if(used[pos.y][x]) continue;
					if(hmap[pos.y][x]>pos.h){
						xflag = false;
						break;
					}
				}
				if(!yflag && !xflag) {
					out.println("Case #"+(i+1)+": NO");
					continue MainRoutine;
				}
				if(yflag){
					for (int y = 0; y < wy; y++) {
						used[y][pos.x] = true;
					}
				}
				if(xflag){
					for (int x = 0; x < wx; x++) {
						used[pos.y][x] = true;
					}
				}
			}
			out.println("Case #"+(i+1)+": YES");
		}
		out.flush();
	}

	static int si() {
		return Integer.parseInt(scan.next());
	}
}

class Lawn implements Comparable<Object> {
	int h,y,x;
	Lawn(int ih,int iy,int ix){
		h=ih; y=iy; x=ix;
	}
	@Override
	public int compareTo(Object o) {
		return this.h-((Lawn)o).h;
	}
}
