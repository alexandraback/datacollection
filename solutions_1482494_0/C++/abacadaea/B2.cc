#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("B2.in");
FILE * fout = fopen("B2.out","w");

const int MAX=1005;
vector<pair<int,int> > one, two;
int state[MAX], sec[MAX];

bool by_first(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
	return (sec[a.second]>sec[b.second]);
    }
    return (a.first<b.first);
}

void solve(int t){
    int N; fin >> N;
    one.clear(); two.clear();
    for(int i=0; i<N; i++){
	int a,b; fin >> a>> b;
	one.push_back(pair<int,int> (a,i));
	two.push_back(pair<int,int> (b,i));
	sec[i]=b;
	state[i]=0;
    }
    sort(one.begin(),one.end(),by_first);
    sort(two.begin(),two.end(),by_first);
    /*
    for(int i=0; i<N; i++){
	cout << one[i].first << " " << one[i].second<<endl;
    }
    for(int i=0; i<N; i++){
	cout << two[i].first << " " << two[i].second<<endl;
    }*/

    int aind=0, bind=0, cur=0, res=0;
    bool works=true;
    for(;cur<2*N; ){
	assert(bind<N);
	if(bind<N){
	    if(two[bind].first<=cur){
		int cind=two[bind].second;
		res+=1;
		cur+=2-state[cind];
		state[cind]=2;
		bind++;
		continue;
	    }
	}
	if(aind<N){
	    if(one[aind].first<=cur){
		int cind=one[aind].second;
		if(state[cind]!=0){
		    aind++; continue;
		}
		
		res+=1;
		cur+=1;
		state[cind]=1;
		aind++;
		continue;
	    }
	}
	works=false;
	break;
    }
    fprintf(fout,"Case #%d: ",t);
    if(works){
	fprintf(fout,"%d\n", res);
    }else{
	fprintf(fout,"Too Bad\n");
    }
}

int main(){
    int T; fin >> T;
    for(int i=0; i<T; i++){
	solve(i+1);
    }
}
