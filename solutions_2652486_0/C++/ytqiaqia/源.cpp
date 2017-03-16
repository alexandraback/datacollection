#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <queue>

using namespace std;
const int MAXN = 1e5+10;
const long double eps = 1e-7;
int R,N,M,K;

bool guess(int x)
{
	bool flag = false;
	if(x==125){cout<<"555"<<endl;flag = true;}
	if(x==27){cout<<"333"<<endl;flag = true;}
	if(x==64){cout<<"444"<<endl;flag = true;}
	if(x==36){cout<<"334"<<endl;flag = true;}
	if(x==48){cout<<"344"<<endl;flag = true;}
	if(x==75){cout<<"355"<<endl;flag = true;}
	if(x==100){cout<<"455"<<endl;flag = true;}
	if(x==80){cout<<"445"<<endl;flag = true;}
	if(x==45){cout<<"335"<<endl;flag = true;}
	if(x==60){cout<<"345"<<endl;flag = true;}
	if(x==24){cout<<"234"<<endl;flag = true;}
	if(x==30){cout<<"235"<<endl;flag = true;}
	if(x==40){cout<<"245"<<endl;flag = true;}
	return flag;
}
int S[1000],V[1000];
void solve()
{
	for(int i = 0;i<K;++i)
	{
		if(guess(S[i]))
			return;
	}
	int icount =0;
	for(int i = 0; i < K&&icount<3; ++i)
	{
		if(S[i]==2||S[i]==3||S[i]==5)
		{
			cout<<S[i];
			//icount ++;
			V[icount++]=S[i];
		}
		else if(S[i]==9)
		{
			cout<<3;
			V[icount++]=3;
		}
		else if(S[i] ==25)
		{
			cout<<5;
			V[icount++]=5;
		}
		else if(S[i]==16)
		{
			cout<<4;
			V[icount++]=4;
		}
	}
	if(icount==3)cout<<endl;
	if(icount < 3)
	{
		for(int i = icount; i < N; ++i)
		{
			cout<<2;
			if(i==N-1)cout<<endl;
		}
	}
}
int main()
{
	freopen("C-small-1-attempt1.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; ++i)
	{
		cin>>R>>N>>M>>K;
		cout<<"Case #"<<i<<":"<<endl;
		while(R--)
		{
			for(int j=0; j < K; ++j)
				cin>>S[j];
		
			solve();
		}
	}
	return 0;
}
