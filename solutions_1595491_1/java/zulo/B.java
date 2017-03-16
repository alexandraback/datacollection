import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class B {
	int[] mp=new int[33], sp=new int[33];

	void start() {
		for (int a=0; a<11; a++)
			for (int b=a; b<11 && b<a+3; b++)
				for (int c=b; c<11 && c<a+3; c++) {
					int s=a+b+c;
					if (c-a<2) mp[s]=Math.max(mp[s],c);
					else sp[s]=Math.max(sp[s],c);
				}
	
		Scanner sc=new Scanner(System.in);
		int nt=sc.nextInt();
		for (int t=1; t<=nt; t++) {
			int n=sc.nextInt(), surp=sc.nextInt(), top=sc.nextInt(), score, re=0;
			for (int i=0; i<n; i++) {
				score=sc.nextInt();
				if (mp[score]>=top) re++;
				else if (sp[score]>=top && surp>0) {
					surp--;
					re++;
				}
			}
			System.out.printf("Case #%d: %d\n", t, re);
		}
	}

	public static void main(String[] args) throws Exception {
		new B().start();
	}
}