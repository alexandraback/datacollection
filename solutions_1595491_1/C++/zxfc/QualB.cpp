#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <cassert>
#include <cctype>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int points[101];
int solve(int id, int p, int s)
{
    bool notsup, sup;
    notsup=false;
    sup=false;
    for(int i=0; i<=10; i++)
    {
        for(int j=i; (j<(i+3)) && (j<11); j++)
        {
            for(int k=j; (k<(i+3))&& k<11; k++)
            {
                int sum = i+j+k;
                if(sum!=points[id])continue;
                if(k<p)continue;
                if((k-i)<2)notsup=true;
                else if((k-i)==2)sup=true;
            }
        }
    }
    if(notsup)
        return 1;
    else if(sup && s>0)return 2;
    else return 0;

}
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	int testcases;
	cin>>testcases;
	for(int cases=1; cases<=testcases; cases++)
	{
	    int n, s, p, res=0;
	    cin>>n>>s>>p;
	    for(int i=0; i<n; i++)cin>>points[i];
	    for(int i=0; i<n; i++)
	    {
	        int t = solve(i, p, s);
	        if(t)res++;
	        if(t==2)s--;
	    }
	    cout<<"Case #"<<cases<<": "<<res<<endl;
	}
	return 0;
}

