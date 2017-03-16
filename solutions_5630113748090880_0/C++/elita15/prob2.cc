#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include <list>
#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout

//freopen("in.txt", "r", stdin);
//freopen ("myfile.txt","w",stdout);
//fclose (stdout);
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t, cases=0;
	scanf("%d",&t);
	int a[3000];
	while(t--) {
		memset(a,0,sizeof(a));
		int n,x;
		scanf("%d",&n);
		int r= 2*n-1;
		for(int i=0;i<r;i++)
		{
				for(int j=0;j<n;j++){
				scanf("%d",&x);
					a[x]++;
				}
		}
		vector<int> v;
		for(int i=0;i<3000;i++)
		{	
			if(a[i]%2==1)
				v.push_back(i);
		}
		sort(v.begin(),v.end());
		cout << "Case #" << ++cases << ": ";
		for(int i=0;i<v.size();i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	//fclose(stdout);
	return 0;
}
