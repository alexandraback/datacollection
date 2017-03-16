import java.io.*;
import java.util.*;


public class GCJ03 {
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s = new Scanner(new File("GCJ03.txt"));
		PrintStream out = new PrintStream(new File("GCJ03.out.txt"));
		int t=s.nextInt();
		for(int i=0;i<t;i++){
			int n=s.nextInt();
			int m=s.nextInt();
			if(n>m){
				int aaa=m;
				m=n;
				n=aaa;
			}
			int k=s.nextInt();
			int min=100000;
			if(n>=k||m>=k)min=k;
			out.print("Case #");
			out.print(i+1);
			out.print(": ");
			for(int j=0;j<=n-2;j++)
				for(int l=j;l<=m-2;l++){
						if(j*l+2*j+2*l-(j)*(j-1)/2>=k)
							if(min>2*(j+l)-(j-1))
								min=2*(j+l)-(j-1);
					if(j*l+2*j+2*l>=k)
						if(min>2*(j+l))
							min=2*(j+l);
					if(j*l+2*j+2*l+1>=k)
						if(min>2*(j+l)+1)
							min=2*(j+l)+1;
					if(j*l+2*j+2*l+2>=k)
						if(min>2*(j+l)+2)
							min=2*(j+l)+2;
					if(j*l+2*j+2*l+3>=k)
						if(min>2*(j+l)+3)
							min=2*(j+l)+3;
					if(j*l+2*j+2*l+4>=k)
						if(min>2*(j+l)+4)
							min=2*(j+l)+4;
				}
			out.println(min);
		}
	}
}
