using System;
using System.Collections.Generic;

namespace GCJ12q2
{

	class Tool{
		public static int gcd(int a,int b){
			while(b!=0){
				int t=a%b;
				a=b;
				b=t;
			}
			return a;
		}
	}
	
	class Program
	{
		
		int H,W,D;
		int sr,sc;
		
		class Point:IComparable<Point>{
			public int y;
			public int x;
			public Point(int x,int y){
				this.x=x;
				this.y=y;
			}
			
			public int CompareTo(Point rhs){
				if(x>rhs.x)return 1;
				if(x<rhs.x)return -1;				
				if(y>rhs.y)return 1;
				if(y<rhs.y)return -1;
				return 0;
			}
			
			public override string ToString(){
				return String.Format("({0},{1})",x,y);
			}
			
		}
		
		
		void addToDict(SortedSet<Point> dict,Point p){
			if(dict.Contains(p))return;
			int dx=p.x-sr,dy=p.y-sc;
			if(Math.Sqrt(dx*dx+dy*dy)>D)return;
			dict.Add(p);			
		}
		
		void solveCase(int number){
			string[] ins=Console.ReadLine().Split(new char[0],StringSplitOptions.RemoveEmptyEntries);
			H=int.Parse(ins[0]);W=int.Parse(ins[1]);D=int.Parse(ins[2]);
			
			//Soving the small
			for(int i=0;i<H;++i){
				string str=Console.ReadLine();
				int pos=str.IndexOf('X');
				if(pos>-1){
					sr=i;
					sc=pos;
				}
			}
			
			H-=2;
			W-=2;
			
			sr=sr*2-1;
			sc=sc*2-1;
			H*=2;
			W*=2;
			D*=2;
			
			SortedSet<Point> dict=new SortedSet<Program.Point>();
			dict.Add(new Point(sr,sc));
			
			while(true){
				int sz=dict.Count;
				SortedSet<Point> ndict=new SortedSet<Program.Point> ();
				foreach(var p in dict){

						addToDict(ndict,new Point(-p.x,p.y));

						addToDict(ndict,new Point(p.x,-p.y));

						addToDict(ndict,new Point(H*2-p.x,p.y));

						addToDict(ndict,new Point(p.x,W*2-p.y));
				}
				dict.UnionWith(ndict);
				int nsz=dict.Count;
				if(sz==nsz) break;
			}
			
			//foreach(var p in dict)Console.Write(p+" ");
			
			SortedSet<Point> result=new SortedSet<Program.Point>();
			foreach(var p in dict){
				int g=Math.Abs(Tool.gcd(p.x-sr,p.y-sc));
				if(g!=0){
					Point np=new Point((p.x-sr)/g,(p.y-sc)/g);
					if(!result.Contains(np))result.Add(np);
				}
			}
			
			Console.WriteLine(String.Format("Case #{0}: {1}",number,result.Count));
			
		}
			
		void solve(){
			
			//Console.SetIn(new System.IO.StreamReader("sample-small.in"));
			int n=int.Parse(Console.ReadLine());
			for(int i=1;i<=n;++i)
				solveCase(i);
		}
		
		public static void Main(string[] args)
		{
			new Program().solve();
		}
	}
}