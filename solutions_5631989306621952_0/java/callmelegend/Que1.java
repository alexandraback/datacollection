
import java.util.*;
 class Que1 {
	public static void main(String [] args){
		Scanner s= new Scanner(System.in);
		int t=s.nextInt();
		for(int i=0;i<t;i++){
			String str=s.next();
			String ans="";
			for(int j=0;j<str.length();j++){
				if(j==0){
					ans=ans+str.charAt(0);
				}
				else{
					if((int)ans.charAt(0)>(int)str.charAt(j)){
						ans=ans+str.charAt(j);
					}
					else{
						ans=str.charAt(j)+ans;
					}
				}
				
			}
			System.out.print("Case #");
			System.out.print(i+1);
			System.out.print(": ");
			System.out.print(ans);
			System.out.println();
		}
	}
}
