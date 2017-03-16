import java.util.*;
public class cf_01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int t=1;
		while(t<=n){
			int n1=sc.nextInt();
			String a=sc.nextLine();
			String b=a.substring(1);
			int temp=0;
			int sum=0;
			for(int i=0;i<b.length();i++){
				if(temp<i){
					sum+=i-temp;
					temp=i;
				}
				temp+=b.charAt(i)-'0';
			}
			System.out.println("Case #"+t+": "+sum);
			t++;
		}
	}

}
