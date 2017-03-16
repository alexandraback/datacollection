import java.util.*;
public class QualProblemC {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			long low = br.nextLong();
			long high = br.nextInt();
			long rl = (long)Math.sqrt(low)-1;
			long rh = (long)Math.sqrt(high)+1;
			long count = 0;
			for(long i = rl;i<=rh;i++){
				if(i*i >= low && i*i <= high && isPalin(i) && isPalin(i*i)){
					count++;
				}
			}
			System.out.println("Case #"+c+": "+count);
		}
	}
	public static boolean isPalin(long num){
		StringBuilder temp = new StringBuilder(""+num);
		return temp.toString().equals(temp.reverse().toString());
	}
}
