import java.util.*;
public class c{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		long[] powers = new long[10];
		for(int j = 0; j<10; j++){
			powers[j]=(long)Math.pow(10,j);
		}
		for(int tt = 1; tt<=T; tt++){
			int a =sc.nextInt();
			int b =sc.nextInt();
			int val=0;
			for(int i = a; i<b; i++){
				String s=""+i;
				Set<Long> set = new HashSet<Long>();
				for(int j = 1; j<s.length(); j++){
					long s1 = i/powers[j];
					long s2= i-s1*powers[j];
					long s3=s2*powers[s.length()-j]+s1;
					if(s3>i && s3<=b&& !set.contains(s3)){
						val+=1;
					}
					set.add(s3);
				}
			}
			System.out.println("Case #"+tt+": "+val);
		}
	}
}


