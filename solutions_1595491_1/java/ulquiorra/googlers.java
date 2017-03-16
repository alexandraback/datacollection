import java.util.*;
public class googlers {
	public static void main(String[] args){
		int t;
		Scanner s = new Scanner(System.in);
		t=s.nextInt();
		for(int k=0;k<t;k++){
			int n,p,S;
			n=s.nextInt();
			S=s.nextInt();
			p=s.nextInt();
			int[] totals = new int[n];
			int count=0;
			for(int i=0;i<n;i++){
				totals[i]=s.nextInt();
				if(totals[i]<((p==1)?1:((p==2)?2:3*p-4))) continue;
				if(totals[i]>3*p-3) count++;
				else{
					if(S>0) {
						count++;
						S--;
					}
				}
			}
			System.out.println("Case #"+(k+1)+": "+count);
		}
	}
}
