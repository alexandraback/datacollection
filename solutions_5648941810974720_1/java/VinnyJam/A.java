import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File("A_large.txt"));
		int T = in.nextInt();
		in.nextLine();
		for (int t =0; t<T; t++){
			String str = in.nextLine();
			int[] digits = new int[10];
			int l = str.length();
			int z=0, o=0, w=0,h=0,r=0,f=0,x=0,s=0,g=0,nn=0;
			for (int i=0; i<l; i++){
				if (str.charAt(i)=='Z') {
					z++;
				}
				if (str.charAt(i)=='O') {
					o++;
				}
				if (str.charAt(i)=='W') {
					w++;
				}
				if (str.charAt(i)=='H') {
					h++;
				}
				if (str.charAt(i)=='R') {
					r++;
				}
				if (str.charAt(i)=='F') {
					f++;
				}
				if (str.charAt(i)=='X') {
					x++;
				}
				if (str.charAt(i)=='S') {
					s++;
				}
				if (str.charAt(i)=='G') {
					g++;
				}
				if (str.charAt(i)=='N') {
					nn++;
				}
			}	
				digits[0] = z;
				
				digits[2] = w;
				digits[3] = h-g;
				digits[4] = r-z-digits[3];
				digits[5] = f-digits[4];
				digits[6] = x;
				digits[7] = s-x;
				digits[8] = g;
				digits[1] = o-z-digits[2]-digits[4];
				digits[9] = (nn-digits[7]-digits[1])/2;
				out.print("Case #"+(t+1)+": ");
				for (int d = 0; d<10; d++){
					for (int type = 0; type<digits[d]; type++){
						out.print(d);
					}
				}
				out.println();
			
			
		}
		out.close();

	}

}
