import java.util.*;
public class cj_04_small {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int t=0;
		while(t<=n){
			t++;
			int a=sc.nextInt();
			int b=sc.nextInt();
			int c=sc.nextInt();
			if(a==1){
				System.out.println("Case #"+t+": GABRIEL");
				continue;
			}
			if(a==2){
				if(b*c%2==0){
					System.out.println("Case #"+t+": GABRIEL");
					continue;
				}
				else{
					System.out.println("Case #"+t+": RICHARD");
					continue;
				}
			}
			if(a==3){
				if(b==1||c==1){
					System.out.println("Case #"+t+": RICHARD");
					continue;
				}
				else{
					if(b*c%3==0){
						System.out.println("Case #"+t+": GABRIEL");
						continue;
					}
					else{
						System.out.println("Case #"+t+": RICHARD");
						continue;
					}
				}
			}
			if(a==4){
				if(b<=2||c<=2){
					System.out.println("Case #"+t+": RICHARD");
					continue;
				}
				if(b*c%4==0){
					System.out.println("Case #"+t+": GABRIEL");
					continue;
				}
				else {
					System.out.println("Case #"+t+": RICHARD");
					continue;
				}
			}
		}
	}

}
