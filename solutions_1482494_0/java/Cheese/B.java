import java.text.*;
import java.io.*;
import java.util.*;
import java.lang.Math;

public class B
{
	public static void main(String[] args) throws Exception
	{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String str;
		String[] ss;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			//System.out.println();
			
			int N = Integer.parseInt(br.readLine());
			int[] arr1 = new int[N];
			int[] arr2 = new int[N];
			for(int i = 0; i < N; i++) {
				ss = br.readLine().split(" ");
				arr1[i] = Integer.parseInt(ss[0]);
				arr2[i] = Integer.parseInt(ss[1]);
			}
			
			int a;
			int b;
			int stars = 0;
			int count = 0;
			boolean changed = true;
			while(changed) {
				changed = false;
				
				b = mins(arr2);
				
				if(b == 2002) break;
				for(int i = 0; i < N; i++) {
					if(stars >= arr2[i]) {
						if(arr1[i] == 2002) stars++;
						else stars += 2;
						arr2[i] = 2002;
						arr1[i] = 2002;
						count++;
						changed = true;
						//System.out.println("Stars: " + stars + "  " + i + " 2");
					}
				}
				if(changed) continue;
				
				a = mins(arr1);
				if(a > stars) break;
				
				int best = listmins(stars, arr1, arr2);
				arr1[best] = 2002;
				count++;
				stars++;
				//System.out.println("Stars: " + stars + "  " + best + " 1");
				changed = true;
			
			}
			
			String output = "";
			if(mins(arr1) != 2002 || mins(arr2) != 2002) output = "Too Bad";
			else output += count;
			System.out.println(output);
		}
		
	}
	
	public static int mins(int[] arr) {
		int min = 2002;
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] < min) min = arr[i];
		}
		return min;
	}
	
	public static int listmins(int stars, int[] arr1, int[] arr2) {
		int best = 0;
		int res = 0;
		for(int i = 0; i < arr1.length; i++) {
			if(stars >= arr1[i] && arr2[i] > best) {
				best = arr2[i];
				res = i;
			}
		}
		return res;
	}
}