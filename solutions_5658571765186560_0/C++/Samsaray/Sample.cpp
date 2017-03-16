#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int X,R,C;

int main()
{
	freopen("D-small-attempt1.in","rb",stdin);
	freopen("test.out","wb",stdout);
	int T;scanf("%d",&T);
	for(int cas = 1; cas <= T; ++cas){
		scanf("%d%d%d",&X,&R,&C);
		bool ok = false;
		if(R < C) swap(R,C);
		if((R * C) % X != 0) ok = true;
		else if(X >= 7) ok = true;
		else if(X == 1 || X == 2) ok = false;
		else if((X + 1) / 2 > C) ok = true;
		else if(X >= 2 * C + 1) ok = true;
		else if(R < X) ok = true;
		else if(C >= X) ok = false;
		else{
			//cout<<"last"<<endl;
			int res = X - C, ret = R - res;
			bool ok1,ok2 = false;
			for(int i=0;i<=res;++i){
				ok1 = false;
				for(int j=i;j <= R - res - 1 + i;++j){
					int a = C * j - i, b = R * C - X - a;
					//cout<<i<<' '<<j<<' '<<a<<' '<<b<<endl;
					if(a % X == 0 && b % X == 0) ok1 = true;
					if(ok1) break;
				}
				if(!ok1) ok2 = true;
			}
			//cout<<ok2<<endl;
			if(ok2) ok = true;
		}
		//cout<<"Case #"<<cas<<": "<<(ok ? "1":"2")<<endl;
		cout<<"Case #"<<cas<<": "<<(ok ? "RICHARD":"GABRIEL")<<endl;
	}
	return 0;
}
