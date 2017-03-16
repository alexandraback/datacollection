import java.util.*;
public class Round1AProblemA {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			long curr = br.nextLong();
			long have = br.nextLong();
			long count = 0;
			while(have-(2*(curr+1)-1) >= 0){
				count++;
				have-=(2*(curr+1)-1);
				curr+=2;
			}
			System.out.println("Case #"+c+": "+count);
		}
	}
}
