import java.util.*;

public class a {
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int r = reader.nextInt();
			int p = reader.nextInt();
			
			int pr = r;
			int cnt = 0;
			while(true){
				int req = 2*pr + 1;
				if(req > p)
					break;
				cnt++;
				p -= req;
				pr+=2;
			}
			
			System.out.println("Case #"+t+": "+cnt);
		}
	}
}
