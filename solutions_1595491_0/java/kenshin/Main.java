import java.util.*;
public class Main {
	public static void main(String[] args){
		int t;
		Scanner s = new Scanner(System.in);
		t=s.nextInt();
		for(int k=0;k<t;k++){
			int n,p,S;
			n=s.nextInt();
			S=s.nextInt();
			p=s.nextInt();
			int[] total = new int[n];
			int count=0;
			for(int i=0;i<n;i++){
				total[i]=s.nextInt();
				if(total[i]<((p==1)?1:((p==2)?2:3*p-4))) continue;
				if(total[i]>3*p-3) count++;
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
