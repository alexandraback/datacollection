#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("C1.in");
FILE * fout = fopen("C1.out","w");

int dig(int a){
    int res=0;
    while(a>0){
	res+=1;
	a=a/10;
    }
    return res;
}

int p10[9],d;

int rot(int a){
    int last=a%10;
    return (a/10)+p10[d-1]*(last);
}

bool works(int a, int b){
    int o=a;
    for(int i=0; i<d; i++){
	a=rot(a);
	if(a==b and a!=o) return true;
    }
    return false;
}

vector<pair<int,int> > ans;
int A,B;

void solve(int t){
    ans.clear();
    fin >> A >>B;
    d=dig(A); 
    int res=0;
    for(int i=A; i<=B; i++){
	int cur=i;
	//cout << i << " " << rot(i
	for(int j=1; j<=d; j++){
	    cur=rot(cur);
	    if(cur<=i) continue;
	    if(A<= cur and cur<=B){
		/*res+=1;
		cout << i << " " << cur << endl;
		assert(cur);
		assert(i!=cur);
		assert(cur>=p10[d-1]);
		assert(works(i,cur));*/
		ans.push_back(pair<int,int> (i,cur));
	    }
	}
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
	if(i>0){
	    if(ans[i]==ans[i-1]) res--;
	}
	res++;
    }
    fprintf(fout,"Case #%d: ",t);
    fprintf(fout,"%d\n", res);
}

void slo(int t){
    int res=0;
    for(int i=A; i<=B; i++){
	for(int j=i+1; j<=B; j++){
	    if(works(i,j)){
		res+=1;
		assert(ans[res-1]==(pair<int,int> (i,j)));
	    }
	}
    }
    fprintf(fout,"Case #%d: ",t);
    fprintf(fout,"%d\n", res);
    
}

int main(){
    p10[0]=1;
    for(int i=1; i<9; i++){
	p10[i]=10*p10[i-1];
    }
    int T; fin >> T;
    for(int i=0; i<T; i++){
	solve(i+1);
	//slo(i+1);
    }
}
