#include<iostream>
#include<string>
using namespace std;

int t, i, k, l, s;
string kbd;
string tgt;
string ss=string(100,' ');
long long totalcnt, maxcnt, wordcnt;

void go(int x, long long cnt) {
	int j;
	if( x == s ) {
		wordcnt++;
		if(cnt>maxcnt) maxcnt=cnt;
		totalcnt+=cnt;
		return;
	}
	for(j=0; j<k; j++) {
		ss[x]=kbd[j];
		x++;
		if(x>=l && tgt==ss.substr(x-l,l)) {
			go(x,cnt+1);
		} else {
			go(x,cnt);
		}
		x--;
	}
}

int main(){
	
	double ddm, dda, ddb;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	cin>>t;
	for( i=1; i<=t; i++ ) {
		cin>>k>>l>>s>>kbd>>tgt;
		maxcnt=wordcnt=totalcnt=0;
		go(0,0);
		dda = totalcnt;
		ddb = wordcnt;
		ddm = maxcnt;
		printf("Case #%d: %.7lf\n",i,ddm-(dda/ddb));
		//cout<<"Case #"<<i<<": "<<ddm-(dda/ddb)<<endl;
	}

	return 0;
}
/*
2
1
8
2
9 7
*/