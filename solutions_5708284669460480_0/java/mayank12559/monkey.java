import java.io.*;
import java.text.DecimalFormat;
class monkey{
	public static void main(String arg[]) throws IOException{
		BufferedReader obj=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(obj.readLine());
		int t1=t;
		while(t>0){
			String s5[]=obj.readLine().split(" ");
			int k=Integer.parseInt(s5[0]);
			int l=Integer.parseInt(s5[1]);
			int s=Integer.parseInt(s5[2]);
			String s1=obj.readLine();
			String s2=obj.readLine();
			int a[]=new int[26];
			for(int i=0;i<s1.length();i++){
				a[(int)(s1.charAt(i))-65]++;
			}
			double ans=0;
			int c=0;
			for(int i=0;i<s2.length();i++){
				if(a[(int)(s2.charAt(i))-65]==0){
					c=1;
					break;
				}
			}
			if(c==1){
				System.out.println("Case #"+ (t1-t+1) +": "+ (double)ans);
			}
			else{
				int l1=s2.length();
				for(int i=0;i<s2.length()-1;i++){
					String s3=s2.substring(0,s2.length()-1-i);
					String s4=s2.substring(i+1,s2.length());
					if(s3.compareTo(s4)==0){
						l1=i+1;
						break;
					}
				}
				s-=l;
				s=s/l1;
				s+=1;
				double p=1;
			//	for(int i=0;i<l1;i++){
			//		p*=(double)((double)a[(int)s2.charAt(i)-65]/(double)s1.length());
			//	}
			//	p*=(double)(s-1);
				double q=1;
				for(int i=0;i<s2.length();i++){
					q*=(double)((double)a[(int)s2.charAt(i)-65]/(double)s1.length());
				}
				ans=(double)((double)q*(double)s);
				ans=(double)s-ans;
				ans=roundTwoDecimals(ans);
				System.out.println("Case #"+(t1-t+1)+ ": "+ans);
			}
			t--;
		}
	}

	public static double roundTwoDecimals(double d) {
   		DecimalFormat twoDForm = new DecimalFormat("#.#######");
    	return Double.valueOf(twoDForm.format(d));
	}
}