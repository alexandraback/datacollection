using System;
using System.Collections;
using System.Collections.Generic;
 
class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		List<int> H=new List<int>();
		for(int i=0;i<A;i++){
			for(int j=0;j<B;j++){
				H.Add(i&j);
			}
		}
		int ans=0;
		for(int i=0;i<H.Count;i++){
			if(H[i]<K)ans++;
		}
		Console.WriteLine("{0}",ans);
	
	
	}

	int A;
	int B;
	int K;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		var s=Console.ReadLine().Split(' ');
		A=int.Parse(s[0]);
		B=int.Parse(s[1]);
		K=int.Parse(s[2]);
	}
}