package code_jam;

import java.util.ArrayList;
import java.util.Scanner;

public class p3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		for(int z=1;z<=q;z++){
			int n=sc.nextInt();
			int[] a=new int[n+1];
			for(int i=1;i<=n;i++)
			a[i]=sc.nextInt();
			int max=0;
			for(int i=1;i<=n;i++){
				int x=a[i];
				int start=a[i];
				int prev=0;
				int count=0;
				ArrayList<Integer> l=new ArrayList<Integer>();
				while(!l.contains(x)){
					count++;
					l.add(x);
					prev=x;
					x=a[x];
				}
				if((count!=n)&&(start!=a[x])){
					if((a[x]==prev)){
						if((x==start))
							count++;
						if(n-count>1){
							if(n-count>1)
							count=count+2;
							else
								count++;
							}
						
					}		
						}			
				
			max=Math.max(max,count);
			}
			System.out.println("Case #"+z+": "+max);
			}
			
				}
			
		}
		
	
	
