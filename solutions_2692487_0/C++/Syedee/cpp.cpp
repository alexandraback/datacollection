#include<algorithm>
#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<map>
#include<set>

#define pi 4*atan(1)
#define sinx(x) sin(x*pi/180)
#define cosx(x) cos(x*pi/180)
#define tanx(x) tan(x*pi/180)
//typedef long long ll

using namespace std;


//stringstream ss (stringstream::in | stringstream::out);


vector<__int64>v;

int main()

{
	freopen("sam.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int i,j,k,n,t;
	int mote=0;
	cin>>t;
	for(int p=1;p<=t;p++){
		v.clear();
		cin>>mote>>n;
		for(i=0;i<n;i++){
			cin>>k;
			v.push_back(k);
		}
		if((int)mote==1){
			printf("Case #%d: %d\n",p,n);
			continue;
		}
		sort(v.begin(),v.end());
		int move=1000000;
		for(i=0;i<=n;i++){
			__int64 fake_mote=mote;
			int temp_move=0;
			for(j=0;j<n-i;j++){
				__int64 lol=v[j];
				while(fake_mote<=lol){
					++temp_move;
					fake_mote+=(fake_mote-1);
				}
				fake_mote+=lol;
			}
			move=move<(temp_move+i)?move:(temp_move+i);
		}
		printf("Case #%d: %d\n",p,move);
	}
	return 0;
}
