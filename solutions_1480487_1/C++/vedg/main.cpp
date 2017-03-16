#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <climits>

using namespace std;

inline void read(int & n) {
    scanf("%d", & n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);
	freopen("cout", "w", stdout);
#endif

   int cases;
   cin>>cases;
   for (int cas = 1; cas <= cases; ++cas) {
	   cout<<"Case #"<<cas<<':';
	   int n;
	   cin>>n;
	   vector<int> wwwScore(n);
	   int sum = 0;
	   for (int i = 0; i < n; ++i) {
		   cin>>wwwScore[i];
		   sum += wwwScore[i];
	   }
	   
	   double tt=sum;
	   vector<double> score(n);
	   for (int i = 0; i < n; ++i)
		   score[i] = wwwScore[i] / tt;
	   
	   
	   typedef multimap<double, int> M;
	   M mp;
	   for (int i=0;i<n;++i)
		   mp.insert(make_pair(score[i], i));
	   
	   double left = 1;
	   int count = 1;
	   double last;
	   for (M::iterator it = mp.begin(); it != mp.end(); ++it) {		   
		   M::iterator next = it;		   
		   if (++next == mp.end())
			   break;
		   double diff=(next->first-it->first);
		   if (diff*count > left)
			   break;
		   left -= diff*count;
		   last=next->first;
		   ++count;
	   }
	   
	   deque<double> ans(n);
	   left/=count;
	   M::iterator t=mp.begin();
	   for (int i = 0; i < count;++i,++t) {
		   ans[t->second]=last-t->first+left;
	   }
	   cout.precision(10);
	   for (int i=0;i<n;++i)
		   cout<<' '<<ans[i]*100;
	   cout<<endl;
   }

#ifndef ONLINE_JUDGE
    fclose(stdin);
	fclose(stdout);
    putchar('\n');
#endif
}

