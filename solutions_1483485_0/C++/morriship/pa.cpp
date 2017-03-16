#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-7)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

char in[11111];

char a[]="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char b[]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

int  ch[300];

int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt0out.txt","w",stdout);
	int tt,i,j,k,n,t;
	
	rep(i,300) ch[i]=i;
	for(i=0 ; a[i] ; i++){
		ch[a[i]]=b[i];
	}
	ch['q']='z';
	ch['z']='q';
	
	sca(t);
	cin.getline(in,11111);
	rep(tt,t){
		cout << "Case #" << tt+1 << ": ";
		cin.getline(in,11111);
		for(i=0 ; in[i] ; i++){
			cout << char(ch[in[i]]);
		}
		cout << endl;
	}
}
































