import java.util.Scanner;

public class Minesweeper {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		scanner.nextLine();
		int c, f, x;
		for (int t = 0; t < T; t++) {
			String s = scanner.nextLine();
			//System.out.println(s);
			String[] tt = s.split(" ");
			c = Integer.parseInt(tt[0]);
			f = Integer.parseInt(tt[1]);
			x = Integer.parseInt(tt[2]);
			System.out.println("Case #" + (t + 1) + ": ");
			solve(c, f, x);

		}

	}

	private static void solve(int a, int b, int mines) {

		int free = a * b - mines;
		if (free == 1) {
			print(a,b,1,1,0,0);
			return;
		}
		if (a==1||b==1){
			if(a==1)
				print(a,b,1,free,0,0);
			else 
				print(a,b,free,1,0,0);
			return;
		}
		
		int j = 2;
		for (int i = 2; i <= a; i++) {
			j=2;
			while (i * j < free)
				j++;
			if(j>b)continue;
			if(i*j == free){
				print(a,b,i,j,0,0);
				return;
			}
			int rest = free - (i-1)*(j-1);
			//System.out.println(" "+rest+" "+i+" "+j);
			if(rest > 2 && (i > 2 && j > 2)){
				if(rest <= i-1){
					print(a,b,i-1,j-1,rest,0);
					return;
				}
				if(rest <= j-1){
					print(a,b,i-1,j-1,0,rest);
					return;
				}
				
				int k = j-1;
				while(rest - k <2)k--;
				//System.out.println("Val: "+i+" "+j+" "+rest+" "+k);
				if(k>=2&&rest-k>=2&&k<b&&rest-k<a){
					print(a,b,i-1,j-1,k,rest-k);
					
					return;
				}
			}

		}
		System.out.println("Impossible");

	}
	
	private static void print(int a, int b, int c, int d, int e, int f){
		
		for(int i = 1; i <= a; i ++){
			for(int j = 1; j <= b; j++){
				System.out.print(get(i,j,c,d,e,f));
			}
			System.out.println();
		}
	}

	private static char get(int i, int j, int c, int d, int e, int f) {
		if(i==1&&j==1){
			return 'c';
		}
		if(i<=c&&j<=d){
			return '.';
		}
		
		if(i==c+1&&j<=e){
			return '.';
		}
		
		if(j==d+1&&i<=f){
			return '.';
		}
		
		return '*';
	}

}
