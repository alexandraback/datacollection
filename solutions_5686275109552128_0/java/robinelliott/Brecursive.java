import java.io.*;
import java.util.*;
import java.math.*;

public class Brecursive
{
	public static int solve(int[] array, int max){
		if(max <= 3){
			return max;
		}
		else{
			/*for(int i = 0; i < 30; i++){
				System.out.printf("%d ", array[i]);
			}
			System.out.printf("\n %d\n", max);
			
			for(int j = 0, k = 3; j < 100000000; j++) k = k + j;*/
			
			int mins = max;
			int[] arr1 = new int[array.length];
			int[] arr2 = new int[array.length];
			
			for(int i = 0; i < array.length; i++){
				arr1[i] = array[i];
				arr2[i] = array[i];
			}
			
			arr1[max/2] += 1;
			arr1[(max+1)/2] += 1;
			arr1[max] -= 1;
			int max1 = max;
			for(; arr1[max1] == 0; max1--);
			int mins1 = 1 + solve(arr1, max1);
			
			arr2[max/3] += 1;
			arr2[(max+1)/3] += 1;
			arr2[(max+2)/3] += 1;
			arr2[max] -= 1;
			int max2 = max;
			for(; arr2[max2] == 0; max2--);
			int mins2 = 2 + solve(arr2, max2);
			
			if(mins1 < mins) mins = mins1;
			if(mins2 < mins) mins = mins2;
					
			return mins;
		}
	}
	
	public static void main(String[] args) throws Throwable
	{
		Scanner sc = new Scanner(new File("B-small-attempt12.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small12.out")));
		int t = sc.nextInt();
		for(int caseno = 1; caseno <= t; caseno++)
		{
			int n = sc.nextInt();
			// let m be the max no of pancakes on any plate
			// and let p be ceil(m/2)
			// then it is worth splitting if and only if
			// the number of plates with > p pancakes
			// is less than than m - p
			int[] numP = new int[1000]; // numP[i] is number of plates with i pancakes on
			int sum = 0;
			int max = 0;
			int moves = 0;
			
			for(int i = 0; i < n; i++){
				int Pi = sc.nextInt();
				numP[Pi]++;
				if(Pi > max){
					max = Pi;
				}
			}
			
			moves = solve(numP, max);
			
			out.println("Case #" + caseno + ": " + moves);
			//System.out.println(moves);
		}
		out.close();
		System.exit(0);
	}
}