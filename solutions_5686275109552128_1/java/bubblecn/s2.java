import java.util.*;
public class cj_02 {
	static int findMax(int[] a){
		int max=-100;
		for(int i=0;i<a.length;i++)
			if (a[i]>max)
				max=a[i];
		return max;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int t=0;
		while(t<=n){
			t++;
			int n1=sc.nextInt();
			int[] a=new int[n1];
			for(int i=0;i<n1;i++)
				a[i]=sc.nextInt();
			int max=findMax(a);
			int min=max;
			for(int i=1;i<=max;i++){
				int temp=i;
				for(int j=0;j<n1;j++)
					if(a[j]>i)
						if(a[j]%i==0)
							temp+=a[j]/i-1;
						else temp+=a[j]/i;
				min=Math.min(min,temp);
			}
			System.out.println("Case #"+t+": "+min);
			

		}
	}

}
