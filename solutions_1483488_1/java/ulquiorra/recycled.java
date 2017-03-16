import java.util.HashSet;
import java.util.Scanner;

public class recycled {
	public static void main(String[] args){
		int t;
		Scanner s = new Scanner(System.in);
		t=s.nextInt();
		for(int k=1;k<=t;k++){
			int a,b;
			a=s.nextInt();
			b=s.nextInt();
			int al=a/10,d=1;
			while(al>0){
				d++;
				al/=10;
			}
			int count=0;
			for(int i=a;i<=b;i++){
				HashSet<Integer> hs = new HashSet<Integer>();
				for(int j=1;j<d;j++){
					int p=(int) (Math.pow(10,j));
					int l=i/p;
					int r=i%p;
					int n=r*((int) (Math.pow(10,d-j))) + l ;
					if(n>=a && n<=b && n!=i) {
						if(!hs.contains(n)){
							count++;
							hs.add(n);
						}
					}
				}
			}
			System.out.println("Case #"+k+": "+(count/2));
		}
	}
}
