import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Dijkstra {
	
	static String filename = "C-small-attempt1";
	static Scanner sc;
	
	static int[][] table = {{1, 2, 3, 4},{2, -1, 4, -3},{3, -4, -1, 2},{4, 3,-2,-1}};
	
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream(filename + ".in"));
		System.setOut(new PrintStream(filename + ".out"));
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int casee = 1 ; casee<=t ; casee++){
			System.out.print("Case #" + casee + ": ");
			int l = sc.nextInt();
			long x = sc.nextLong();
			String s = sc.next();
			System.out.println(solve(s,x));
		}
	}
	public static String solve(String s, long x){
		int[] forwards = new int[s.length()+1];
		//int[] backwards = new int[s.length()+1];
		forwards[0] = 1;
		for(int i = 0; i < s.length(); i++){
			forwards[i+1] = transform(forwards[i], s.charAt(i) - 'g');
		}
		/*backwards[s.length()] = 1;
		for(int i = s.length()-1; i >= 0; i--){
			backwards[i] = transform(s.charAt(i) - 'g', backwards[i+1]);
		}*/
		
		int foundI = -1;
		int cur = 1;
		loop1:
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < s.length(); j++){
				cur = transform(cur, s.charAt(j)-'g');
				if(cur == 2){
					foundI = j;
					x-=i;
					break loop1;
				}
			}
		}
		if(foundI < 0){
			return "NO";
		}
		int start = (foundI+1);
		cur = 1;
		int foundJ = -1;
		loop2:
		for(int i = 0; i < 4; i++){
			int j = 0;
			if(i == 0){
				j = start;
			}
			while(j < s.length()){
				cur = transform(cur, s.charAt(j)-'g');
				if(cur == 3){
					foundJ = j;
					x-=i;
					break loop2;
				}
				j++;
			}
		}
		if(foundJ < 0){
			return "NO";
		}
		start = foundJ+1;
		cur = 1;
		for(int i = start; i < s.length(); i++){
			cur = transform(cur, s.charAt(i)-'g');
		}
		for(int i = 0; i < 4; i++){
			if(cur == 4){
				x-=i;
				break;
			}
			if(i == 3){
				return "NO";
			}
			cur = transform(cur, forwards[s.length()]);
		}
		x-=1;
		if(x < 0){
			return "NO";
		}
		x%=4;
		cur = 1;
		for(int i = 0; i < x; i++){
			cur = transform(cur, forwards[s.length()]);
		}
		if(cur == 1){
			return "YES";
		}
		return "NO";
	}
	
	
	
	public static int transform(int a, int b){
		int sign = 1;
		if(a*b < 0){
			sign*=-1;
		}
		a = Math.abs(a);
		b = Math.abs(b);
		return sign*table[a-1][b-1];
	}
}
