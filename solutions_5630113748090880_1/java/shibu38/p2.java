package code_jam;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class p2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		for(int z=1;z<=q;z++){
			int n=sc.nextInt();
			ArrayList<Integer> l=new ArrayList<Integer>();
			int[] a=new int[2501];
			for(int i=0;i<(2*(n)*(n)-n);i++){
				a[sc.nextInt()]++;
			}
			for(int i=0;i<2501;i++){
				if((a[i]!=0)&&(a[i]%2!=0))
					l.add(i);
			}
			Collections.sort(l);
			String x="";
			for(int i=0;i<l.size();i++){
				x=x+l.get(i)+" ";
			}
			System.out.println("Case #"+z+": "+x);
		}
	}

}
