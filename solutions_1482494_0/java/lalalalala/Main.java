
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class AB{
	int a,b;
	AB(int a,int b){
		this.a=a;
		this.b=b;
	}
}
class Bijiao implements Comparator<AB>{

	@Override
	public int compare(AB o1, AB o2) {
		if (o1.b>o2.b){
			return 1;
		}
		return -1;
	}
	
}
class Main{
	public static void main(String arg0[])throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
		DecimalFormat df=new DecimalFormat("0.000000");
		df.setRoundingMode(RoundingMode.HALF_UP);
		Scanner in=new Scanner(f);
		int cin=in.nextInt();
		for (int ci=0;ci<cin;ci++){
			int n=in.nextInt();
			AB[] a=new AB[n];
			boolean[] tell=new boolean[n];
			for (int i=0;i<n;i++){
				a[i]=new AB(in.nextInt(),in.nextInt());
			}
			Arrays.sort(a, new Bijiao());
			int sum=0,ans=0,bu=0;
			boolean tellans=false;
			while (bu<n){
				if (a[bu].b<=sum){
					sum+=2;
					if (tell[bu]) sum--;
					ans++;
					bu++;
				}else{
					boolean tellab=false;
					for (int i=n-1;i>=bu;i--){
						if (!tell[i]&&sum>=a[i].a){
							sum++;
							ans++;
							tell[i]=true;
							tellab=true;
							break;
						}
					}
					if (!tellab) tellans=true;
				}
				if (tellans) break;
			}
			if (tellans){
				out.println("Case #"+(ci+1)+": Too Bad");
			}else
			out.println("Case #"+(ci+1)+": "+ans);
		}
		   out.close();          
		   System.exit(0);  
	}
}