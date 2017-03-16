import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {
		int t;
		Scanner scan = new Scanner(System.in);
		t = scan.nextInt();
		for(int i = 0; i < t; i++) {
			int x = scan.nextInt();
			int y = scan.nextInt();
			int stepLen = 1;
			int idx = 0;
			String ans = "";			
			int cx = 0;
			while(x != cx) {
				if(idx%2 == 0) {
					ans = ans + 'E';
					cx = cx + stepLen;
				} else {
					ans = ans + 'W';
					cx = cx - stepLen;
				}
				idx++;
				stepLen++;
			}
			int cy = 0;
			idx = 0;
			if(y > 0 && y < stepLen) {
				ans = ans + 'S';
				cy = cy - stepLen;
				stepLen++;
			}
			while(y != cy) {
				if(idx%2 == 0) {
					ans = ans + 'N';
					cy = cy + stepLen;
				} else {
					ans = ans + 'S';
					cy = cy - stepLen;
				}
				idx++;
				stepLen++;
			}
			
			System.out.println("Case #"+(i+1)+": "+ans);
		}
	}
}
