import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class C {
	static int N;
	public static void main(String[] args) throws Exception{
		Scanner sc =new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			System.out.printf("Case #%d:%n",t);
			out.printf("Case #%d:%n",t);
			int R = sc.nextInt();
			N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();
			thing2: for(int a=0;a<R;a++){
				int[] array = new int[K];
				for(int b=0;b<K;b++){
					array[b]=sc.nextInt();
				}
				for(int x1=2;x1<=M;x1++){
					for(int x2=2;x2<=M;x2++){
						loop: for(int x3=2;x3<=M;x3++){
							for(int b=0;b<K;b++){
								if(!check(x1,x2,x3,array[b]))continue loop;
							}
							System.out.println((x1+""+x2+""+x3).replaceAll("1", ""));
							out.println((x1+""+x2+""+x3).replaceAll("1", ""));

							continue thing2;
						}
					}
				}
				String outX = "";
				for(int x=0;x<N;x++){
					outX+="2";
				}
				System.out.println(outX);
				out.println(outX);


			}
			
		}
		out.close();
	}

	private static boolean check(int x1, int x2, int x3, int i) {
		if(N<=2)x3=1;
		if(N<=1)x2=1;
		for(int a=0;a<1<<3;a++){
			int cur = 1;
			if(((a>>0)&1)==1)cur*=x1;
			if(((a>>1)&1)==1)cur*=x2;
			if(((a>>2)&1)==1)cur*=x3;
			if(cur==i)return true;
		}
		return false;
	}
	
}
