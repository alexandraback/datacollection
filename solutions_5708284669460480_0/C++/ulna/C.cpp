#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <ctype.h>
#include <utility>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)


double res,q,p;

void dfs(int ind,string form,string key,string tar,int goal) {
	if (ind==goal) {
		double cnt=0;p++;
		rep(i,form.size()-tar.size()+1) {
			bool flag=0;
			reps(j,i,i+tar.size()-1) {
				if (form[j]!=tar[j-i]) {
					flag=1;break;
				}
			}
			if (!flag) cnt++;
		}
		q=max(q,cnt);
		res+=cnt;
	} else {
		rep(i,key.size()) {
			dfs(ind+1,form+key[i],key,tar,goal);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin;ofstream fout;
	fin.open("in.txt");fout.open("out.txt");
	int t,k,l,s;
	fin >> t;
	rep(i,t) {
		fin >> k >> l >> s;
		string key,target;
		fin >> key >> target;
		res=0.;p=0;q=0.;
		dfs(0,"",key,target,s);
		res/=p;q-=res;
		fout << "Case #" << i+1 << ": " << fixed << setprecision(6) <<  q << endl;
	}
	return 0;
}

