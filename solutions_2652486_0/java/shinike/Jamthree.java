import java.util.Scanner;


public class Jamthree {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		int r=sc.nextInt();
		int n=sc.nextInt();
		int m=sc.nextInt();
		int k=sc.nextInt();
		
		System.out.println("Case #1:");
		
		for(int i=0;i<r;i++) {
			int hint[]=new int[k];
			boolean ok[]=new boolean[k+1];
			for(int j=0;j<k;j++) {
				hint[j]=sc.nextInt();
			}
			
			xx: for(int a=2;a<=m;a++) {
				for(int b=2;b<=m;b++) {
					for(int c=2;c<=m;c++) {
						ok[k]=true;
						for(int j=0;j<k;j++) {
							if(hint[j]==1 || hint[j]==a || hint[j]==b || hint[j]==c) ok[j]=true;
							if(hint[j]==a*b || hint [j]==b*c || hint[j]==c*a || hint[j]==a*b*c) ok[j]=true;
							
							if(!ok[j]) {
								ok=new boolean[k+1];
								break;
							}
						}
						if(ok[k]) {
							System.out.println(a+""+b+""+c);
							break xx;
						}
					}
				}
			}
		}
		
		
		
	} 

}
