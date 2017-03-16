package googlecodejam;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;

public class Solution2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		
		for(int i=0;i<t;i++)
		{
			int n = in.nextInt();
			int [][] arr = new int [2*n-1][n];
			for(int x=0;x<2*n-1;x++)
				for(int y=0;y<n;y++)
					arr[x][y]=in.nextInt();
			finalList(i+1,n,arr);
		}
	}
	
	public static void finalList(int t,int n,int[][] arr){
		HashMap<Integer,Integer> h = new HashMap<Integer,Integer>();
		ArrayList<Integer> a = new ArrayList<Integer>();
		for(int i=0;i<2*n-1;i++)
			for(int j=0;j<n;j++)
			{
				if(h.containsKey(arr[i][j]))
					h.put(arr[i][j],h.get(arr[i][j])+1);
				else
					h.put(arr[i][j],1);
			}
		Set<Integer> keyset = h.keySet();
		ArrayList<Integer> array = new ArrayList<Integer>(keyset);
		for(int i=0;i<array.size();i++){
			if(h.get(array.get(i))%2==1){
				a.add(array.get(i));
			}
			
		}
		int[] newarr= new int[a.size()];
		for(int i=0;i<n;i++)
			newarr[i] = a.get(i);
		Arrays.sort(newarr);
		System.out.print("Case #"+t+":");
		for(int i=0;i<newarr.length;i++)
			System.out.print(" "+newarr[i]);
		System.out.println();
	}

}
