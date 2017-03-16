import java.util.*;
import java.io.*;
import java.text.*;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		NumberFormat format = NumberFormat.getInstance();
		format.setMaximumFractionDigits(6);
		format.setMinimumFractionDigits(1);

		int n = sc.nextInt();
		for(int i=0;i<n;i++){
			int m = sc.nextInt();
			int[] s = new int[m];
			int sum = 0;
			for(int j=0;j<m;j++){
				s[j] = sc.nextInt();
				sum += s[j];
			}
			double ave = sum * 2 / m;
			int sum2 = 0;
			int tcnt = 0;
			boolean[] kakutei = new boolean[m];
			for(int j=0;j<m;j++){
				if(ave<s[j]){
					kakutei[j] = true;
					tcnt++;
				}else{
					sum2 += s[j];
				}
			}
			double ave2 = (double)(sum + sum2) / (m-tcnt);
			System.out.print("Case #" + (i+1) + ": ");
			for(int j=0;j<m-1;j++){
				if(kakutei[j]){
					System.out.print("0.000000 ");
				}else{
					double r = (ave2 - s[j])/sum*100;
					System.out.print(format.format(r) + " ");
				}
			}
			if(kakutei[m-1]){
				System.out.println("0.000000");
			}else{
				double r = (ave2 - s[m-1])/sum*100;
				System.out.println(format.format(r));
			}
		}
	}
}