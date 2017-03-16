import java.util.Scanner;


public class Bull {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int cases = sc.nextInt();
		
		for(int c = 0; c<cases; c++){
			long r = sc.nextLong();
			long t = sc.nextLong();
			
			long tot = 0;
			long count = 0;
			
			long i = r;
			while(true){
				if((i+1)*(i+1) - i*i +tot <= t){
					tot += (i+1)*(i+1) - i*i;
					count++;
					i+=2;
				} else {
					break;
				}
			}
			
			System.out.printf("Case #%d: %d\n",(c+1),count);
		}

	}

}
