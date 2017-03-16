#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int e,r,n,v[100];
int f[11][6];
void cm(int&x,int y){
	if(x<y)x=y;
}
int main(){
	int ti=1,tc;
	for(cin >> tc;ti<=tc;++ti){
		cin >> e>>r>>n;
		for(int i=0;i<n;++i)cin >> v[i];
		memset(f,0x80,sizeof(f));
		f[0][e]=0;
		for(int i=0;i<n;++i)
			for(int x=0;x<=e;++x)
			for(int y=0;y<=x;++y)
				cm(f[i+1][min(x-y+r,e)],f[i][x]+y*v[i]);
		int ans=*max_element(f[n],f[n]+e+1);
		cout<<"Case #"<<ti<<": "<< ans << endl;
	}
}
