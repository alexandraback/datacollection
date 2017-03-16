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

void solve(int t){
    int A,B;
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
		res+=1;
		cout << i << " " << cur << endl;
		assert(cur);
		assert(i!=cur);
		assert(cur>=p10[d-1]);
	    }
	}
    }

    cout << res << endl;
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
    }
}
