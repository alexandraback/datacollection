#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<memory.h>
using namespace std;

double EPS = 1e-11;
int sc[1000];
int n;
pair<double,int> ssc[1000];
double tot;

bool can(int ind, double score, double ratio) {
	int st = upper_bound(ssc, ssc+n, make_pair(score,-1), greater<pair<double,int> >())-ssc;
	double sum = 0;
	for(int i=st;i<n;i++) {
		if(ssc[i].second == ind) continue;
		sum += (score - ssc[i].first)/tot;
	}
	return sum > (1.0-ratio);
}

int main()	{

	//freopen("a_sample.in","rt",stdin);

	//freopen("a_small.in","rt",stdin);
	//freopen("a_small.out","wt",stdout);

	freopen("a_large.in","rt",stdin);
	freopen("a_large.out","wt",stdout);

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		cin>>n;
		tot = 0;
		for(int i=0;i<n;i++) {
			cin>>sc[i];
			ssc[i] = make_pair(sc[i], i);
			tot += sc[i];
		}
		sort(ssc, ssc+n, greater<pair<double,int> >());

		cout<<"Case #"<<tt<<":";

		cout.precision(7);
		cout.setf(ios::fixed);

		for(int i=0;i<n;i++) {
			double st = 0, end = 1, md;
			int cnt = 0;
			while(end-st > EPS && cnt < 200) {
				md = (st+end)/2.0;
				if(can(i, md*tot+sc[i], md)) end = md;
				else st = md;
				cnt++;
			}
			cout<<" "<<st*100;
		}
		cout<<endl;
	}

	return 0;
}