import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class A_1B {
//	4
//	2 20 10
//	2 10 0
//	4 25 25 25 25
//	3 24 30 21
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String s = r.readLine();
		int T=new Integer(s);
		for(int tt=1;tt<=T;tt++){
			System.out.print("Case #"+tt+": ");
			String[] sp=r.readLine().split("[ ]+");
			int n=new Integer(sp[0]);
			int[] arr=new int[n];
			int sum=0;
			for (int i = 0; i < arr.length; i++) {
				arr[i]=new Integer(sp[i+1]);
				sum+=arr[i];
			}
			double[] res=new double[n];
			double temp=0;
			for(int i=0;i<arr.length;i++){
				double low = 0.0 , high= 100.0;
				int itr=100;
				while(itr-->0){
					double mid=(low+high)/2.0;
					if(can(mid,i,arr,sum)){
						high=mid;
					}
					else{
						low=mid;
					}
				}
				res[i]=high;
				temp+=res[i];
			}
			System.out.println(temp);
//			System.out.printf("%.7f",res[0]);
//			for (int j = 1; j < res.length; j++) {
//				System.out.printf(" %.7f",res[j]);
//			}
//			System.out.println();
			
		}
	}

private static boolean can(double mid, int i, int[] arr,int x) {
	double  p =mid/100.0;
	double rem = 1-p;
	double[] votes=new double[arr.length];
	votes[i]=arr[i]+x*p;
	for (int j = 0; j < votes.length; j++) {
		if(i==j)continue;
		double temp = (votes[i]-arr[j])/x;
		if(temp<0)continue;
		if(rem<temp)return true;
		rem-=temp;
	}
	return false;
}
}
