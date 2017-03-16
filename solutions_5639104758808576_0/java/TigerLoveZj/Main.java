import java.util.Scanner;


public class Main {
	static int T;
	static Scanner sc;
	public static void main(String[] args){
		sc=new Scanner(System.in);
		T=sc.nextInt();
		sc.nextLine();
		for (int t=1;t<=T;t++){
			initAndWorkAndPrint(t);
		}
	}

	private static void initAndWorkAndPrint(int t) {
		String temp=sc.nextLine();
		int n=Integer.parseInt(temp.charAt(0)+"");
		temp=temp.substring(2, temp.length());
		int ans=0;
		int hasStand=0;
		for (int i=0;i<=n;i++){
			int number=Integer.parseInt(temp.charAt(i)+"");
			if (number==0){
				continue;
			}
			if (hasStand>=i){
				hasStand+=number;
			}else{
				int thisNeed=i-hasStand;
				ans+=thisNeed;
				hasStand+=number;
				hasStand+=thisNeed;
			}
		}
		System.out.println("Case #"+t+": "+ans);
	}
}
