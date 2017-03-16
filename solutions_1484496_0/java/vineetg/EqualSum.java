import java.io.File;
import java.io.PrintWriter;
import java.util.*;


public class EqualSum {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("C-small-attempt0.in"));
		int num = scanner.nextInt();
		scanner.nextLine();
		PrintWriter writer = new PrintWriter(new File("EqualSum.txt"));
		for(int a = 1;a<=num;a++) {
			int N = scanner.nextInt();
			int[] nums = new int[N];
			for(int i = 0;i<N;i++) {
				nums[i]=scanner.nextInt();
			}
			int[] sums = new int[100000*N];
			boolean done = false;
			int second = 0;
			int finsum = 0;
			for(int i = 1;i<Math.pow(2,N);i++) {
				int val = i;
				int index = 0;
				int sum = 0;
				while(val>0) {
					if(val%2==1) {
						sum+=nums[index];
					}
					val/=2;
					index++;
				}
				if(sums[sum]!=0) {
					finsum=sum;
					second=i;
					done=true;
					break;
				} else {
					sums[sum]=i;
				}
			}
			if(done) {
				writer.println("Case #" + a + ": " );
				System.out.println("Case #" + a + ": " );
				int one = sums[finsum];
				String s1 = "";
				String s2="";
				int index = 0;
				while(one>0) {
					if(one%2==1) {
						s1+=nums[index]+ " " ;
					}
					one/=2;
					index++;
				}
				index=0;
				while(second>0) {
					if(second%2==1) {
						s2+=nums[index] + " ";
					}
					second/=2;
					index++;
				}
				writer.println(s1);
				System.out.println(s1.trim());
				writer.println(s2);
				System.out.println(s2.trim());
			} else {
				writer.println("Case #" + a + ": \nImpossible" );
				System.out.println("Case #" + a + ": \nImpossible" );
			}
			writer.flush();
			
		}
		writer.close();
	}
}
