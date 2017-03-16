import java.io.File;
import java.util.Scanner;
public class A {
	public static void main(String[] args) throws Exception {
		if(args.length < 1) {
			System.out.println("Usage : java A <inputfile>");
			return;
		}
		File f = new File(args[0]);
		Scanner sc = new Scanner(f);
		int count = sc.nextInt();
		for(int n=1;n<=count;n++) {
			String s = sc.next();
			String[] sa = s.split("/");
			long num = Long.parseLong(sa[0]);
			long den = Long.parseLong(sa[1]);
			long den1 = den;
			int c = 0;
			while(den > 1) {
				if(den <= num) break;
				c++;
				den = den / 2;
			}
			//check for impossible
			den = den1;
			while(num > 1) {
//				System.out.println(den+" "+num);
				if(den % 2 == 1) {c = -1;break;}
				den /= 2;
				if(num > 1 && num >= den) {
					num -= den;
				}

			}
			
//			System.out.println(num+"/"+den);
			System.out.print("Case #"+n+": ");
//			System.out.print(num+"/"+den1+" ");
			if(c == -1) System.out.println("impossible");
                	else System.out.println(c);
		}
	}
}
