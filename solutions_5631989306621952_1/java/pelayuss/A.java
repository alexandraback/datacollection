import java.util.*;
class A{
	public static void main(String []args){
		Scanner s=new Scanner(System.in);
		int T=s.nextInt();
		for(int i=1; i<=T; i++){
			String cad=s.next();
			char arr[]=cad.toCharArray();
			String sol=arr[0]+"";
			for(int j=1; j<arr.length; j++){
				if(arr[j]<( sol.toCharArray()[0] ) ){
					sol=sol+arr[j];
				}
				else{
					sol=arr[j]+sol;
				}
			}
			System.out.println("Case #"+i+": "+sol);
		}
	}
}
