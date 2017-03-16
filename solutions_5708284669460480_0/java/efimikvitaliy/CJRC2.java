import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class CJRC2 {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter("OUTPUT.TXT");
		int T = sc.nextInt();
		int k,l,s;
		String str;
		char[] A;
		char[] B;
		double[] P = new double[256];
		int p1,p2,p3;
		boolean bl;
		double pVal;
		double banOst;
		for(int t = 0 ; t<T; ++t){
			for(int i=0 ; i<256; ++i){
				P[i] =0;
			}
			k = sc.nextInt();
			l = sc.nextInt();
			s = sc.nextInt();
			str = sc.next();
			//System.out.println(str);
			A = str.toCharArray();
			str = sc.next();
			//System.out.println(str);
			B = str.toCharArray();
			p1 = 0;
			bl = false;
			for(int i=1; i<l; ++i){
				//System.out.println(B[i] + " " + B[0]);
				if( B[i] == B[0] )
				{
					bl = true;
					for(int m=i; m<l; ++m){
						//System.out.println(B[m] + " " + B[m-i]);
						if(B[m] != B[m-i])
							bl = false;
					}
					if(bl)
						p1 = i;
				}
				if(bl)
					break;
			}
			//System.out.println(p1);
			if(p1 == 0)
			{
				p1  = l;
			}
			p2 = l-p1;
			p3 = (s-p2)/p1;
//			if((s-p2)%p1 > 0){
//				p3++;
//			}
			//--p3; //столько бананов
			//System.out.println("Слов " + p3);
			for(int i=0 ; i<k; ++i){
				++P[((int)A[i])];
			}
			for(int i=0 ; i<256; ++i){
				P[i] /= k;
			}
//			for(int i=0 ; i<k; ++i){
//				System.out.println(A[i] + " " + P[((int)A[i])]);
//			}
			pVal = 1;
			for(int i=0; i<l;++i){
				pVal *= P[((int)B[i])];
			}
			//System.out.println("pVal = " + pVal);
			banOst = p3 - pVal*p3;
			if(pVal == 0)
				banOst = 0;
			pw.println("Case #" + (t+1) + ": " + banOst );
		}
		pw.close();
	}

}
