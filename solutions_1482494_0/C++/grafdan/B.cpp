#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T,t;
int a,b,i,j,anz;
int N,n;
vector < int > L,H,P; // low high progress
int cnt, run, res, cand, maxh;

void testc() {
	scanf("%d",&N);
	P.clear();
	L.clear();
	H.clear();
	for(n=0;n<N;n++) {
		scanf("%d %d",&a,&b);
		L.push_back(a);
		H.push_back(b);
		P.push_back(0);
	}
	res = 0;
	cnt = 0;
	run = 0;
	bool flag_did_sth = true;
	while(flag_did_sth) {
		flag_did_sth=false;
		//both or only high
		for(n=0;n<N;n++) {
			if(P.at(n)<2 && H.at(n)<=cnt) {
				flag_did_sth=true;
				if(P.at(n)==0) {
					P.at(n)=2;
					cnt+=2;
					run++;
				} else {
					P.at(n)=2;
					cnt++;
					run++;
				}
			}
		}
		//last case
		cand = -1; maxh = -1;
		if(!flag_did_sth) {
			for(n=0;n<N;n++) {
				if(P.at(n)==0 && L.at(n)<=cnt) { //doable
					if(H.at(n)> maxh) {
						maxh = H.at(n);
						cand = n;
					}
				}
			}
			if(cand != -1) {
				flag_did_sth=true;
				P.at(cand)=1;
				cnt++;
				run++;
			}
		}
	}
	if(cnt == 2*N) {
		printf("Case #%d: %d\n",t,run);
	} else {
		printf("Case #%d: Too Bad\n",t);		
	}

}
int main() {
	scanf("%d",&T);
	for(t=1;t<=T;t++) testc();
	return 0;

}