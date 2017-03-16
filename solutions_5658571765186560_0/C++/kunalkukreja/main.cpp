#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007

int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int x,r,c;
		cin>>x>>r>>c;
		if(x==1)
        {
            cout<<"GABRIEL"<<endl;
            continue;
        }
        if(x==2)
        {
            if((r*c)%2==0)
                cout<<"GABRIEL"<<endl;
            else
                cout<<"RICHARD"<<endl;
            continue;
        }
        if(x==3)
        {
            int other;
            if(r==3)
                other = c;
            else if(c==3)
                other = r;
            else
            {
                cout<<"RICHARD"<<endl;
                continue;
            }
            if(other>=2 && other<=4)
                cout<<"GABRIEL"<<endl;
            else
                cout<<"RICHARD"<<endl;
            continue;
        }
        if(x==4)
        {
            int other;
            if(r==4)
                other = c;
            else if(c==4)
                other = r;
            else
            {
                cout<<"RICHARD"<<endl;
                continue;
            }
            if(other>=3 && other<=4)
                cout<<"GABRIEL"<<endl;
            else
                cout<<"RICHARD"<<endl;
            continue;
        }
	}
	return 0;
}
