import java.util.Scanner;


public class cca {
	public static void main(String[] args){
		Scanner ft = new Scanner(System.in);
		int t = Integer.parseInt(ft.nextLine());
		for(int i = 0; i < t; i++){
			String[] cur = ft.nextLine().split(" ");
			double c = i(cur[0]);
			double f = i(cur[1]);
			double x = i(cur[2]);
			double r = 2.0;
			double time = 0;
			while(x/r > (x/(r + f) + c/r)){
				time+=c/r;
				r+=f;
			}
			time+=x/r;
			System.out.println("Case #" + (i + 1) + ": " + time);
		}
	}
	public static double i(String s){ return Double.parseDouble(s); }
}
