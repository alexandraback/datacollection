import java.util.*;
import java.io.*;

public class Diamonds {
	static long[][] chooseAtMost;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("file")));
		//genChooseAtMost();
		StringTokenizer st = new StringTokenizer(in.readLine());
		int cases = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<= cases; i++){
			st = new StringTokenizer(in.readLine());
			double prob;
			int num = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int layer = (Math.abs(x) + y) /2;
			int level = y +1;
			int numsNeeded = buildLayer(layer);
			int numsAbove = buildLayer(layer + 1);
			if(num <= numsNeeded)
				prob = 0;
			else if(num >= numsAbove)
				prob = 1;
			else if(x == 0)
				prob = 0;
			else{
				int numRem = num - numsNeeded;
				int bricks = 4*layer + 1;
				int atMost = numRem - level;
				if(atMost >= 2*layer)
					prob = 1;
				else if(atMost < 0)
					prob = 0;
				else
					prob = chooseAtMost(numRem, atMost);
			}
			out.println("Case #" + i + ": " + prob);
		}
		out.close();
	}
	
	public static double chooseAtMost(int numRem, int atMost){
		if(numRem <= atMost) return 1;
		if(atMost < 0) return 0;
		return (chooseAtMost(numRem - 1, atMost) +
				chooseAtMost(numRem - 1, atMost - 1))/2;
		/*
		double curr = chooseAtMost[numRem][atMost];
		
		
		double curr = numRem;
		for(int i = 2; i <= level; i++){
			curr /= i;
			curr *= numRem - i;
		}
		for(int i=0; i < numRem; i++)
			curr /= 2;
		return curr; */
		
	}
	
	public static int buildLayer(int n){
		return (2*n - 1) * n;
	}
	
	public static void genChooseAtMost(){
		chooseAtMost = new long[40][40];
		for(int r=0; r < 40; r++){
			for(int c=0; c<=r; c++){
				if(c == 0)
					chooseAtMost[r][c] = 1;
				else if(r == c)
					chooseAtMost[r][c] = 2*chooseAtMost[r-1][c-1];
				else
					chooseAtMost[r][c] = chooseAtMost[r-1][c-1] + chooseAtMost[r-1][c];
			}
		}
	}
}
