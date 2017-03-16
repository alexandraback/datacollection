import java.util.*;
public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int i,j,len,p,temp,total;
		HashSet<Integer>[] map = new HashSet[2000000];
		for (i=1;i<2000000;i++) {
			map[i] = new HashSet<Integer>();
			len = (int)Math.log10(i)+1;
			p = (int)Math.pow(10, len-1);
			temp = i;
			for (j=0;j<len-1;j++) {
				temp = (temp%10)*p+temp/10;
				if (temp>i && temp<=2000000)
					map[i].add(temp);
			}
		}
		for (i=1;i<=T;i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			total = 0;
			for (j=a;j<b;j++) {
				for (Integer t : map[j]) {
					if (t>j && t<=b)
						total++;
				}
			}
			System.out.println("Case #"+i+": "+total);
		}
	}

}
