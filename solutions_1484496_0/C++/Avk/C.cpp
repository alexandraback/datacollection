#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <climits>
using namespace std;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define REPS(p,s) for (char * p = s; *p ; p++)
#define FOR(var,start,end) for (int var=(start); var<=(int)(end); ++var)
#define FORD(var,start,end) for (int var=(start); var>=(int)(end); --var) 
#define PB push_back
#define PF push_front
#define BP pop_back
#define FP pop_front
#define BN begin()
#define RN rbegin()
#define RD rend()
#define ED end()
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define IT(X) __typeof((X).BN)
#define RIT(X) __typeof((X).RN) 
#define REF(X) __typeof(__typeof(X)::reference) 
#define FORIT(it, X) for(IT(X) it = (X).BN; it != (X).ED; ++it)
#define FORITR(it, X) for(RIT(X) it = (X).RN; it != (X).RD; ++it) 
#define VV(X) vector < vector< X > >
#define PIB(X)  pair<IT(X),bool >  

typedef long long LL;
typedef unsigned long long ULL;
typedef istringstream ISS;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< PII > VPII;

int main()
{
    int cases,caseNum;
    cin >> cases;
	caseNum = 1;
	cin.ignore();
    while(cases>0)
    {
		int n,i,j,nums[200],sum,k,curr,prev,curr2;
		bool done = false;
		VI poss,temp;
		vector<int>::reverse_iterator rit;
		map <int, vector<int> > sets;

		sum = 0;

		cin >> n;

		for(j=0;j<n;j++)
		{
			cin >> nums[j];
			sum+=nums[j];
		}

		int sums[sum];

		for(i=1;i<sum+1;i++){sums[i]=0;}

		sums[0] = 1;
		poss.PB(0);

		for(i=0;i<n;i++)
		{
			for(j=0,k=poss.size();j<k;j++)
			{
				if(sums[poss[j]+nums[i]] == 1)
				{
					done = true;
					curr = poss[j];
					prev = nums[i];
					break;
				}
				else
				{
					int fs = poss[j]+nums[i];
					sums[fs] = 1;
					sums[fs] = 1;
					poss.PB(fs);
					VI v;
					v.PB(nums[i]);
					v.PB(poss[j]);
					sets[fs] = v;
				}
			}
			if(done)
			{
				break;
			}
		}

		printf("Case #%d:\n",caseNum);
		if(done)
		{
			cout << sets[curr+prev][0]<<" ";
			curr2 = sets[curr+prev][1];
			while(curr2!=0)
			{
				temp = sets[curr2];
				cout<<temp[0]<<" ";
				curr2 = temp[1];
			}
			cout<<endl;

			cout<<prev<<" ";
			while(curr!=0)
			{
				temp = sets[curr];
				cout<<temp[0]<<" ";
				curr = temp[1];
			}

		}
		else
		{
			cout<<"Impossible";
		}

		//output the answer here
		cout<<endl;
        cases--;
		caseNum++;
    }
    return 0;
}
