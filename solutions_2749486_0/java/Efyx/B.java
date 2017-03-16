package gcj2013.round1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class B {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
				
		int T = scanner.nextInt();
		for(int t=0; t<T; t++) {
			int X = scanner.nextInt();
			int Y = scanner.nextInt();
			
			String s = solve(X,Y);
			//check(s, X, Y);
			System.out.println("Case #" + (t+1) + ": " +  s);
		}
	}

	private static void check(String s, int X, int Y) {
		if(s.length() >= 500) {
			throw new RuntimeException("Too many moves: " + s.length());
		}
		int x=0, y=0;
		int d=1;
		for(int i=0; i<s.length(); i++) {
			switch(s.charAt(i)) {
			case 'E': x+=d; break;
			case 'W': x-=d; break;
			case 'N': y+=d; break;
			case 'S': y-=d; break;
			default: throw new RuntimeException("oups");
			}
			d++;
		}
		if(x!=X || y!=Y) {
			throw new RuntimeException("X="+X+", Y="+Y+", x="+x+", y="+y);
		}
	}

	private static String solve(int X, int Y) {
		StringBuilder dirs = new StringBuilder(500);
		
		int x=0, y=0;
		int d = 1; // distance of next jump
		
		while(x != X) {
			if(x < X) { // go east
				if(Math.abs(X-(x+d)) < X-x) {
					x += d;
					dirs.append('E');
					d++;
				}
				else {
					x += 1;
					dirs.append("WE");
					d += 2;
				}
			}
			else { // go west
				if(Math.abs(X-(x-d)) < x-X) {
					x -= d;
					dirs.append('W');
					d++;
				}
				else {
					x -= 1;
					dirs.append("EW");
					d += 2;
				}
			}
		}
		
		while(y != Y) {
			if(y < Y) { // go north
				if(Math.abs(Y-(y+d)) < Y-y) {
					y += d;
					dirs.append('N');
					d++;
				}
				else {
					y += 1;
					dirs.append("SN");
					d += 2;
				}
			}
			else { // go south
				if(Math.abs(Y-(y-d)) < y-Y) {
					y -= d;
					dirs.append('S');
					d++;
				}
				else {
					y -= 1;
					dirs.append("NS");
					d += 2;
				}
			}
		}
		
		return dirs.toString();
	}
}
