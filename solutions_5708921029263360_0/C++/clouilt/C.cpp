#include <iostream>
#include <cstring>
using namespace std;
int T, J, P, S, K;

int dress[1003][3];
int comb[3][13][13];
int comb2[13][13][13];

int test2(int a){
	memset(comb2, 0, sizeof(comb2));
	memset(comb, 0, sizeof(comb));
	for(int i = 0; i<=a; ++i){
		if(++comb2[ dress[i][0] ][ dress[i][1] ][dress[i][2]] > 1)
			return 1;

		if(++comb[0][dress[i][0]][dress[i][1]] > K)
			return 1;
		if(++comb[1][dress[i][0]][dress[i][2]] > K)
			return 1;
		if(++comb[2][dress[i][1]][dress[i][2]] > K)
			return 1;
	}
	return 0;
	// return dress[a][0]==dress[b][0] && dress[a][1] == dress[b][1] &&
		// dress[a][2] == dress[b][2];
}

int test(int k){
	int cnt = 1;
	dress[0][0]=dress[0][1]=dress[0][2]=0;

	while(cnt<k){
		for(int s = 0; s<S; ++s )
			for(int p = 0; p<P; ++p )
				for(int j = 0; j<J; ++j ){
					dress[cnt][0]= j;
					dress[cnt][1]= p;
					dress[cnt][2]= s;
					if(test2(cnt))
						goto _f;
					goto _k;
				_f:
					1;
				}
		return 0;
	_k:
		++cnt;
	}
	return 1;
}

int main(){
	cin>>T;
	for(int cs = 1; cs<=T; ++cs){
		cin>>J>>P>>S>>K;
		int mm = J*P*S;
		int l = 1;
		int r = mm;
		int m;

		while(l < r){
			m = (l + r + 1 ) / 2;
			if(test(m)){
				l = m;
			}else
				r= m -1;
		}

		cout<<"Case #"<<cs<<": ";
		cout<<l<<endl;
		for(int i = 0; i < l; ++i ){
			cout<<dress[i][0]+1<<' '<<dress[i][1]+1<<' '<<dress[i][2]+1<<endl;
		}
	}

	return 0;
}
