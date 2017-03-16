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

using namespace std;




vector<__int64>v;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int i,j,k,nn,t;
	int mm=0;
	cin>>t;
	for(int p=1;p<=t;p++){
		v.clear();
		cin>>mm>>nn;
		for(i=0;i<nn;i++){
			cin>>k;
			v.push_back(k);
		}
		if((int)mm==1){
			printf("Case #%d: %d\n",p,nn);
			continue;
		}
		sort(v.begin(),v.end());
		int move=1000000;
		for(i=0;i<=nn;i++){
			__int64 fake_mote=mm;
			int temp_move=0;
			for(j=0;j<nn-i;j++){
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
