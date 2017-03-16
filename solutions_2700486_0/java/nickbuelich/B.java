import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class B {
	static Graph[][] hack;
	public static void main(String[] args) throws Exception{
		Scanner sc =new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		int T = sc.nextInt();
		double best = 0;
		for(int t=1;t<=T;t++){
			int N = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			int many = 0;
			for(int mask=0;mask<(1<<N);mask++){
				hack = new Graph[40][40];
				Graph root = new Graph(0,8);
				for(int a=0;a<N;a++){
					root.place((mask>>a)&1);
				}
				//System.out.println(root.find(x,y));
				int thing = root.find(x,y);
				if(thing>=1)thing=1;
		//		System.out.println(thing);
				many+=thing;
			}
			best = (many+0.0)/(1<<N);
			System.out.printf("Case #%d: %f%n",t,best);
			out.printf("Case #%d: %f%n",t,best);
		}
		out.close();
	}

	private static class Graph  {
		int x,y;
		Graph left,right;
		boolean used;
		Graph(int a, int b){
			used = false;
			x=a;
			y=b;
			hack[a+20][b+20]=this;
			if(b!=0){
				if(hack[a-1+20][b-1+20]==null)
				left = new Graph(a-1,b-1);
				else left = hack[a-1+20][b-1+20];

				if(hack[a+1+20][b-1+20]==null)
				right = new Graph(a+1,b-1);
				else right = hack[a+1+20][b-1+20];
			}
		}
		public int find(int a, int b) {
			if(this.x==a&&this.y==b){
				if(this.used)return 1;
				return 0;
			}
			int ans =0;
			if(this.left!=null)ans+= left.find(a, b);
			if(this.right!=null)ans+= right.find(a, b);
			return ans;
		}
		public void place(int i) {
		//	System.out.println(x+" "+y);
			if(this.y==0){
			//		System.out.println(x+" "+y);

				this.used=true;
				return;
			}
			if(this.left.used&&this.right.used){
				//	System.out.println(x+" "+y);

				this.used=true;
				return;
			}
			if(this.left.used&&!this.right.used){
				right.place(i);
				return;
			}
			if(!this.left.used&&this.right.used){
				left.place(i);
				return;
			}
			if(y>1){
				if(!this.left.used&&!this.right.used&&this.left.right.used){
					if(i==0)left.place(i);
					else right.place(i);
					return;
				}
				else 
					left.right.place(i);
				
				return;
			}
			if(left.used)right.place(i);
			else left.place(i);
		//	if(i==0)left.place(i);
		//	else right.place(i);
			
		}
	}
}
