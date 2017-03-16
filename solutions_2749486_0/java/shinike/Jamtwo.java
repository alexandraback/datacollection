import java.util.*;



public class Jamtwo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			String ans="";
			String a="WE";
			if(x<0) {
				a="EW";
				x=0-x;
			}
			String b="SN";
			if(y<0) {
				b="NS";
				y=0-y;
			}
			
			for(int j=0;j<x;j++) {
				ans=ans+a;
			}
			for(int j=0;j<y;j++) {
				ans=ans+b;
			}
			System.out.println("Case #"+(i+1)+": "+ans);
		}
	}

}
