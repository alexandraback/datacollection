#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class Sequence{
  public:
  	vector <int> P;
  	int time;
  	Sequence(const vector<int>& pp,int t):P(pp),time(t){}
  	bool operator < (const Sequence& str) const{
        return P<str.P;
    }
};
set <Sequence> solved;

int solve(vector <int> P){
	sort(P.begin(),P.end(),[](int aa,int bb){return aa>bb;});
	if(P[0]<4) return P[0];
	set<Sequence>::iterator it=solved.find(Sequence(P,0));
	if(it!=solved.end()) return (*it).time;
	int best=P[0];
	for(int i=1;i<=P[0]/2;i++){
		vector <int> PN=P;
		PN.push_back(i);
		PN[0]-=i;
		best=min(best,1+solve(PN));
	}
	solved.insert(Sequence(P,best));
	return best;
}

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		int D;
		scanf("%d",&D);
        vector <int> P(D);
		for(int i=0; i<D; i++){
		    scanf("%d",&P[i]);
		}
		printf("Case #%d: %d\n",t,solve(P));
	}
  return 0;
}
