#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


void doit(){
	int n, ta,tb,cp=0,nex=true,ret=0,tix,tval;
	vector <pair<int,pair<int,int> > > via;
	vector <pair<int,int> >  vib;
	int vis[1005];
	memset(vis,0,sizeof(vis));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ta>>tb;
		via.push_back(make_pair(ta,make_pair(tb,i)));
		vib.push_back(make_pair(tb,i));
	}
	sort(via.begin(),via.end());
	sort(vib.begin(),vib.end());
	ta=0,tb=0;
	while(nex){
		nex=false;
		while(tb<vib.size() && cp>=vib[tb].first){
			ret++;
			nex=true;
			if(vis[vib[tb].second])
				cp++;
			else 
				cp+=2;
			vis[vib[tb].second]=2;
			tb++;
		}
		tval=-1,tix=-1;
		for(int i=0;i<n;i++)
		if(cp>=via[i].first && vis[via[i].second.second]==0 && tval<via[i].second.first){
			tval = via[i].second.first;
			tix=i;
		}
		if(tix!=-1){
			ret++;
			cp++;
			nex=true;
			vis[via[tix].second.second]=1;
		}
	}
	for(int i=0;i<n;i++)
	if(vis[i]!=2){
		cout<<"Too Bad"<<endl;
		return;
	}
	cout<<ret<<endl;
	return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cout<<"Case #"<<i<<": ";
        doit();
    }
    return 0;
}
