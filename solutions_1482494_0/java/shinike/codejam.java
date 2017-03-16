import java.util.*;
public class codejam {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		int i;
		y:for(i=1;i<=t;i++) {
			int n=sc.nextInt();
			int[][] a=new int[n][2];
			int j;
			for(j=0;j<n;j++) {
				a[j][0]=sc.nextInt();
				a[j][1]=sc.nextInt();
			}
			int have=0;
			int count=0;
			int clear[]=new int[n];
			
			x: while (have<n*2) {
				for(j=0;j<n;j++) {
					if(a[j][1]<=have && clear[j]==0) {
						have+=2;
						clear[j]=2;
						count++;
						continue x;
					}
				}
				for(j=0;j<n;j++) {
					if(a[j][1]<=have && clear[j]==1) {
						have+=1;
						clear[j]=2;
						count++;
						continue x;
					}
					
				}
				int maxstar=-1;
				int maxj=-1;
				for(j=0;j<n;j++) {
					
					if(a[j][0]<=have && clear[j]==0) {
						if(maxstar<=a[j][1]) {
							maxstar=a[j][1];
							maxj=j;
						}
					}
				}
				
				if(maxj!=-1) {
					have+=1;
					clear[maxj]=1;
					count++;
					continue x;
				}
				
				System.out.println("Case #"+i+": Too Bad");
				continue y;
			}
			
			System.out.println("Case #"+i+": "+count);
		}
		
		
	}

}
