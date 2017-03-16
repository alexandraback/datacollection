import java.util.Arrays;
import java.util.Scanner;



public class Consonants {
	int[] t= new int[1000010];
	public long res(String s, int count){
		int n=s.length();
		for(int i=0; i<=s.length()+1; i++)
			t[i]=0;
		for(int i = 1; i<=n; i++){
			char c=s.charAt(i-1);
			if(c=='a'||c=='o'||c=='u'||c=='i'||c=='e')
				continue;
			else
				t[i]=t[i-1]+1;
		}
		
		long r=0;
		long p=0;
		for(long i =1; i<=n; i++){
			if(t[(int)i]>=count){
				r+=i-count+1;
				p=i-count+1;
			} else {
				r+=p;
			}
		}
		return r;
	}
	public static void main(String[] args) {
		Consonants c = new Consonants();
//		System.out.println(c.res("quartz",3));
//		System.out.println(c.res("straight", 3));
//		System.out.println(c.res("gcj", 2));
//		System.out.println(c.res("tsetse", 2));
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		scanner.nextLine();

		for(int i = 1; i<=t; i++){
			String[] w = scanner.nextLine().split(" ");
			
			System.out.println("Case #"+i+": "+c.res(w[0],Integer.parseInt(w[1])));

		}
		//System.out.println(Arrays.deepToString(arr));
	}

}
