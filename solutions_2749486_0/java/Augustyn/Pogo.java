import java.util.HashSet;
import java.util.Scanner;


public class Pogo {
		int[][] t= new int[250][250];
		int N=1;
		int S=2;
		int E=3;
		int W=4;
		public int ind(int i){
			
			return i-210;
		}
		class Point{
			@Override
			public boolean equals(Object obj) {
				Point p = (Point)obj;
				return p.x==x&&p.y==y;
			}
			@Override
			public int hashCode() {
				return x*1000+y;
			}

			int x;
			int y;
			public Point(int x, int y, int step,String s) {
				super();
				this.x = x;
				this.y = y;
				this.s=s;
				this.step = step;
			}
			
			String s;
			int step=0;
		}
		public String res(int a, int b){
			Point p = new Point(0,0,0,"");
			HashSet<Point> l = new HashSet<Point>();
			HashSet<Point> l2= new HashSet<Point>();
			HashSet<Point> help;
			l.add(p);
			while(true){
				for(Point q : l){
					p=q;
					if(p.x==a&&p.y==b)
						return p.s;
					int jmp=p.step+1;
					//System.out.println(p.x+" "+p.y);
					l2.add(new Point(p.x+jmp, p.y, jmp, p.s+"E"));
					l2.add(new Point(p.x-jmp, p.y, jmp, p.s+"W"));
					l2.add(new Point(p.x, p.y+jmp, jmp, p.s+"N"));
					l2.add(new Point(p.x, p.y-jmp, jmp, p.s+"S"));
				}
				l.clear();
				help=l;
				l=l2;
				l2=help;
			}
			
		}
		
		public static void main(String[] args) {
			
			Pogo p = new Pogo();
			//System.out.println(p.res(100,100));
			//System.out.println(p.res(-3, 4));
			Scanner scanner = new Scanner(System.in);
			int t = scanner.nextInt();
			scanner.nextLine();

			for(int i = 1; i<=t; i++){
				String[] w = scanner.nextLine().split(" ");
				int a=Integer.parseInt(w[0]);
				int b= Integer.parseInt(w[1]);
				System.out.println("Case #"+i+": "+p.res(a,b));

			}
		}

	

}
