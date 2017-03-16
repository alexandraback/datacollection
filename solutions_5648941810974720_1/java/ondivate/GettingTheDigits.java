import java.util.Arrays;
import java.util.Scanner;

public class GettingTheDigits {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		String[] ds={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		int[][] df=new int[10][26];
		for(int i=0;i<10;i++)
			df[i]=getf(ds[i]);
		int[] order={0,2,4,6,8,1,3,5,7,9};
		int T=sc.nextInt();
		for(int cn=1; cn<=T;cn++){
			String S=sc.next();
			int[] sf=getf(S);
			int[] ans=new int[10];
			for(int i=0;i<order.length;i++){
				while(pos(df[order[i]],sf)){
					ans[order[i]]++;
					get(df[order[i]],sf);
				}
			}
			
			System.out.print("Case #"+cn+": "); 
			for(int i=0;i<10;i++)
				while(ans[i]>0){
					ans[i]--;
					System.out.print(i);
				}
			System.out.println();
		}
	}
	static int[] getf(String S){
		int[] f=new int[26];
		for(int i=0;i<S.length();i++){
			f[S.charAt(i)-'A']++;
		}
		return f;
	}
	static boolean pos(int[] a, int[] b){
//		System.out.println(Arrays.toString(a));
//		System.out.println(Arrays.toString(b));
		for(int i=0;i<a.length;i++){
			if(a[i]>0&&b[i]<a[i]){
				return false;
			}
		}
		return true;
	}
	static void get(int[] a, int[] b){
		for(int i=0;i<a.length;i++){
			b[i]-=a[i];
		}
	}
}
