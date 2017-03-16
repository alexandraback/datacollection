import java.util.Scanner;

class Scores {
	double[] sc;
	double sum;
	int N;
	Scores(Scanner scan){
		N = scan.nextInt();
		sc = new double[N];
		sum = 0;
		for(int n=0; n<N; n++){
			sc[n] = scan.nextInt();
			sum += sc[n];
		}
		for(int n=0; n<N; n++){
			sc[n] /= sum;
		}
	}
	
	boolean isOk(int i, double y){
		double score = sc[i]+y;
		double s = 0;
		int p = 0;
		for(int n=0; n<N; n++){
			if(n != i && sc[n] <= score) {
				s += sc[n];
				p++;
			}
		}
		return (s+1-y)/p <= score;
	}
	
	double min(int i){
		double step = 1;
		double y = 0;
		while(step >= 1e-10){
			if(!isOk(i,y))
				y+=step;
			else{
				y-=step;
				step/=10;
			}
		}
		if(y<0) y=0;
		return y;
	}
}

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++){
			Scores s = new Scores(sc);
			System.out.print("Case #"+t+":");
			for(int n=0; n<s.N; n++)
				System.out.print(" "+format(100d*s.min(n)));
			System.out.println();
		}
	}
	static double format(double y){
		return Math.round(y*1e7)/1e7;
	}
}
