import java.util.Scanner;


public class Main {
	static int X,R,C;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for (int i=1;i<=T;i++){
			X=sc.nextInt();
			R=sc.nextInt();
			C=sc.nextInt();
			if (R>C){
				int temp=R;
				R=C;
				C=temp;
			}
			if (X<=4&&R<=4&&C<=4){
				System.out.print("Case #"+i+": ");
				if (workSmall()){
					System.out.println("GABRIEL");
				}else{
					System.out.println("RICHARD");
				}
			}else{
				System.out.print("Case #"+i+": ");
				if (workLarge()){
					System.out.println("GABRIEL");
				}else{
					System.out.println("RICHARD");
				}
			}
		}
	}

	private static boolean workLarge() {
		if (X>=7){
			return false;
		}
		if (X==1){
			return true;
		}
		if (X==2){
			if (R*C%2==0){
				return true;
			}else{
				return false;
			}
		}
		if (X==3){
			if (R*C%3!=0){
				return false;
			}
			if (R==1){
				return false;
			}
			return true;//R>=2
		}
		if (X==4){
			if (R*C%4!=0){
				return false;
			}
			if (R==1||R==2){
				return false;
			}
			return true;//R>=3
		}
		if (X==5){
			if (R*C%5!=0){
				return false;
			}
			if (R<=2){
				return false;
			}
			if (R==3){
				if (C==5){
					return false;
				}else{
					return true;
				}
			}
			return true;//R>=3
		}else{//X=6
			if (R*C%6!=0){
				return false;
			}
			if (R<=2){
				return false;
			}
			if (R==3){
				return false;
			}else{
				return true;//R>=4
			}			
		}		
	}

	private static boolean workSmall() {
		if (X==1){
			return true;
		}
		if (X==2){
			if (R*C%2==0){
				return true;
			}else{
				return false;
			}
		}
		if (X==3){
			if (R*C%3!=0){
				return false;
			}
			if (R==1&&C==3){
				return false;
			}
			if (R==2&&C==3){
				return true;
			}
			if (R==3&&C==3){
				return true;
			}else{//R=3,C=4
				return true;
			}
		}else{//X=4
			if (R*C%4!=0){
				return false;
			}
			if (R==1&&C==4){
				return false;
			}
			if (R==2&&C==2){
				return false;
			}
			if (R==2&&C==4){
				return false;
			}
			if (R==3&&C==4){
				return true;
			}else{//R=4,C=4
				return true;
			}
		}
	}
}
