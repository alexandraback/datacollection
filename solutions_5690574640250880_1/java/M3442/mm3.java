import java.util.Scanner;


public class mm3 {

	static int m;
	static int r;
	static int c; static int tot = 0;
	public static void main(String[] args){
		Scanner f = new Scanner(System.in);
		int t = i(f.nextLine());
		int lp = 0;
		int[] dont = {0,2,3,5,7};
		for(int i = 0; i < t; i++){
			String[] cur = f.nextLine().split(" ");
			r = i(cur[0]);
			c = i(cur[1]);
			m = i(cur[2]);
			int s = r*c - m;
			if(s == 1){
				System.out.println("Case #" + (i + 1) + ":");
				for(int k = 0; k < r; k++){
					for(int l = 0; l < c; l++){
						//System.out.print(((k - 1)+(x - 2)*(l - 2)));
						if(k == 0 && l == 0){
							System.out.print("c");
						}else{
							System.out.print("*");
						}
					}
					System.out.println();
				}
			}else{
			boolean done = false;
			for(int j = 0; j < dont.length; j++){
				done = done || s == dont[j];
			}
			if(done && !(r == 1 || c == 1)){
				System.out.println("Case #" + (i + 1) + ":");
				System.out.println("Impossible");
				lp++;
			}
			
			if(r == 1 || c == 1){
				if(s > 1){
					System.out.println("Case #" + (i + 1) + ":");
					lp++;
					if(r == 1){
						for(int x = 0; x < c; x++){
							if(x == 0){
								System.out.print("c");
							}else if(x < s){
								System.out.print(".");
							}else{
								System.out.print("*");
							}
						}
						System.out.println();
					}else{
						for(int x = 0; x < r; x++){
							if(x == 0){
								System.out.println("c");
							}else if(x < s){
								System.out.println(".");
							}else{
								System.out.println("*");
							}
						}
					}
				}else{
					System.out.println("Case #" + (i + 1) + ":");
					lp++;
					System.out.println("Impossible");
				}
				done = true;
			}
			if(!done){
				for(int x = 2; x <= r; x++){
					for(int y = 2; y <= c; y++){
						if(!done){
						int start = 2*x + 2*y -4;
						int end = x*y;
						if(s <= end && s >= start){
							System.out.println("Case #" + (i + 1) + ":");
							lp++;
							//System.out.println("W" + x + " " + y + " " + start + " " + end + " " + s);
							for(int k = 0; k < r; k++){
								for(int l = 0; l < c; l++){
									//System.out.print(((k - 1)+(x - 2)*(l - 2)));
									if(k == 0 && l == 0){
										System.out.print("c");
									}else if((k < 2 && l < y) || (l < 2 && k < x)){
										System.out.print(".");
									}else if((l < y && k < x) && ((k - 1)+(x - 2)*(l - 2))<=(s - start)){
										System.out.print(".");
									}else{
										System.out.print("*");
									}
								}
								System.out.println();
							}
							done = true;
						}
						}
					}
				}
			}
			if(!done){
				System.out.println("Case #" + (i + 1) + ":");
				lp++;
				System.out.println("Impossible");
			}
		}
		}
		//System.out.println(lp);
	}
	public static int i(String s){ return Integer.parseInt(s);}
}
