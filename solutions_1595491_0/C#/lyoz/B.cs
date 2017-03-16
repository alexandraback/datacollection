using System;

class B{
	void Solve(){
		int n=NextInt(),s=NextInt(),p=NextInt();
		int[] ts=new int[n];
		for(int i=0;i<n;i++)
			ts[i]=NextInt();
		
		int c1=0,c2=0;
		foreach(int t in ts){
			if(t==0){
				if(t/3>=p)
					c1++;
			}
			else if(t%3==0){
				if(t/3>=p)
					c1++;
				else if(t/3+1>=p)
					c2++;
			}
			else if(t%3==1){
				if(t/3+1>=p)
					c1++;
			}
			else if(t%3==2){
				if(t/3+1>=p)
					c1++;
				else if(t/3+2>=p)
					c2++;
			}
		}
		Console.WriteLine(c1+Math.Min(s,c2));
	}
	void Run(){
		int tc=NextInt();
		for(int i=1;i<=tc;i++){
			Console.Write("Case #{0}: ",i);
			Solve();
		}
	}
	
	string[] tokens;
	int tokenIndex;
	string Next(){
		while(tokens==null || tokenIndex==tokens.Length){
			tokens=Console.ReadLine().Split(null);
			tokenIndex=0;
		}
		return tokens[tokenIndex++];
	}
	int NextInt(){
		return int.Parse(Next());
	}
	static void Main(){
		new B().Run();
	}
}
