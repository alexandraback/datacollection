import java.util.Scanner;


public class A_LastWord {
public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	int t=sc.nextInt();
	String x;
	
	for(int i=0;i<t;i++){
		x=sc.next();
		String y=x.substring(0,1);
		for(int j=1;j<x.length();j++){
			if(x.charAt(j)-y.charAt(0)>=0){
				y= x.charAt(j)+y;
			}
			else{
				y=y+ x.charAt(j);
			}
		}
		System.out.println("Case #"+(i+1)+": " +y);
	}


	sc.close();
}
}
