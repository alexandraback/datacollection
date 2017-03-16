/*
 * codeforces2.cpp
 *
 *  Created on: 19-Mar-2016
 *      Author: bajaj
 */




#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <stack>

using namespace std;

typedef long long int LL;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;    // graph representation
vector< pair<int, ii> > EdgeList; // edgelist for kruskal algorithm


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(LL i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];


LL min(LL a, LL b){
	return a < b ? a : b;
}

LL max(LL a, LL b){
	return a > b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}


int n;

int main(){

	freopen("/Users/bajaj/Downloads/C-small-attempt0 (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t=1;

	int test_c;
	cin>>test_c;


	while(test_c){

		int ss,pp,jj,kk;
		cin>>jj>>pp>>ss>>kk;

		unordered_map<int, int> spm;
		unordered_map<int, int> pjm;
		unordered_map<int, int> sjm;

		unordered_map<int, int> ssjjmm;

		int count=0;

		stack<pair<pair<int,int>, int> > ans;

		for(int i=1;i<=ss;i++){

			for(int j=1;j<=pp;j++){

				for(int k=1;k<=jj;k++){

					int sp = i*10+j;
					int spr = j*10 +i;


					int pj = j*10+k;
					int pjr = k*10+j;

					int sj = i*10 + k;
					int sjr = k*10 + i;

					int spj = i*100+j*10+k;
					int sjp = i*100 + k*10+j;
					int psj = j*100+i*10+k;
					int pjs = j*100+k*10+i;

					int jps = k*100+i*10+j;
					int jsp = k*100+j*10+i;

					bool goAhed = true;

					if(ssjjmm.find(spj) == ssjjmm.end() && ssjjmm.find(sjp) == ssjjmm.end() && ssjjmm.find(psj) == ssjjmm.end() &&
							ssjjmm.find(pjs) == ssjjmm.end() && ssjjmm.find(jps) == ssjjmm.end() && ssjjmm.find(jsp) == ssjjmm.end()){

					}
					else{
						goAhed = false;
					}

					if(!goAhed)continue;


					int spv =0 ,sjv=0, pjv=0;

					if(spm.find(sp) == spm.end()){

					}
					else{
						spv = spm[sp];
						int sprv = spm[spr];


						if(spv >= kk || sprv >=kk)
							continue;
					}

					if(pjm.find(pj) == pjm.end()){

					}
					else{
						 pjv = pjm[pj];
						 int pjrv = pjm[pjr];

						if(pjv>=kk || pjrv >= kk)
							continue;

					}

					if(sjm.find(sj) == sjm.end()){

					}
					else{
						 sjv = sjm[sj];

						 int sjvr = sjm[sjr];

						if(sjv>=kk || sjvr>=kk)
							continue;

					}

					sjm[sj] = sjv+1;
					pjm[pj] = pjv+1;
					spm[sp] = spv+1;

					sjm[sjr] = sjv+1;
					pjm[pjr] = pjv+1;
					spm[spr] = spv+1;

					ssjjmm[spj]=1;
					ssjjmm[sjp]=1;
					ssjjmm[psj]=1;
					ssjjmm[pjs]=1;
					ssjjmm[jps]=1;
					ssjjmm[jsp]=1;

					count++;
					ans.push(make_pair(make_pair(i,j),k));
				}

			}


		}

		cout<<"Case #"<<t<<": "<<count<<"\n";

		while(count){

			pair<pair<int,int>, int> a = ans.top();
			ans.pop();

			cout<<a.second<<" "<<a.first.second<<" "<<a.first.first;

			count--;

			if(count){
				cout<<"\n";
			}



		}

		t++;
		cout<<"\n";


		test_c--;
	}




	return 0;

}
