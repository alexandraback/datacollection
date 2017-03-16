import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter("C:\\Users\\JiaKY\\Desktop\\out.txt");
		//Scanner in = new Scanner(System.in);
		
		int t = Integer.valueOf(in.nextLine());
		for(int ii=0;ii<t;ii++){
			String line = in.nextLine();
			String[] data = line.split(" ");
			
			int n = Integer.valueOf(data[0]);
			int s = Integer.valueOf(data[1]);
			int p = Integer.valueOf(data[2]);
			
			int[] score = new int[n];
			
			for(int i=0;i<n;i++){
				score[i] = Integer.valueOf(data[3+i]);
			}
			Arrays.sort(score);
			
			int ans = 0;
			for(int i=score.length-1;i>=0;i--){
				int valid = 3*p-2;
				if(p<2)
					valid = p;
				int min = 3*p-4;
				if(p <= 2)
					min = p;
				if(score[i] >= valid)
					ans++;
				else if(s > 0){
					if(score[i] >= min){
						ans++;
						s--;
						if(s == 0)
							break;
					}
				}
			}
			out.printf("Case #%d: %d",ii+1,ans);
			out.println();
			out.flush();
		}
		
	}

}