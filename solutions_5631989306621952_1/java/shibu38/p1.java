package code_jam;

import java.util.Scanner;

public class p1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		for(int z=1;z<=q;z++){
			String s=sc.next();
			String x=s.charAt(0)+"";
			char c=s.charAt(0);
			for(int i=1;i<s.length();i++){
				if(s.charAt(i)>=c){
					x=s.charAt(i)+x;
					c=s.charAt(i);
							}
				else
					x=x+s.charAt(i);
			}
			
			System.out.println("Case #"+z+": "+x);
		}
	}

}
