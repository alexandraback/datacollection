/* Author : Pranav
BITS PILANI Hyderabad Campus */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fr(i,n) for(i=0; i<n; i++)
#define N 1000000007
#define f first
#define sc(x) scanf("%lld",&x);
#define pr(x) printf("%lld\n",x);
#define s second
typedef vector<int> vi;
typedef pair <int, int> paint;
typedef long long ll;
ll mod;
vector<pair<ll,ll> > v;
vector<pair<ll,ll> > fin;
vector<ll> flag;
ll fact(ll n){
    ll i;
    ll res=1;
    for(i=1;i<=n;i++){
        res=(res*i)%N;
    }
    return res;
}
int main()
{
    ll res=1,n,i;
    ll t,eqct,j,curbeg,curend,find;
    cin>>t;
    string str;
ll id=1;
    while(t--){
    	res=1;
    	v.clear();
    	flag.clear();
    	fin.clear();
	    str.clear();
	    cin>>n;	
        for(i=0;i<n;i++){
            cin>>str;
            v.pb(make_pair((int)(str[0]-'a'),(int)str[str.size()-1]-'a'));
            flag.pb(0);

        }


    for(i=0;i<v.size();i++){
        if(flag[i]==1){continue;}
        // removing all a -a a-a types
        if(v[i].f==v[i].s){
            eqct=1;
            for(j=i+1;j<v.size();j++){
                if(v[i].f==v[j].f&&v[j].f==v[j].s){
                    flag[j]=1;
                    eqct++;
                }
            }
            res=(res*fact(eqct))%N;
        }
        // end of a-a types
    }

    for(i=0;i<v.size();i++){
        if(flag[i]==1){continue;}
        curbeg=v[i].f;
        curend=v[i].s;
        find=1;
        while(find!=0){
            find=0;
            for(j=0;j<v.size();j++){
                if(v[j].f==curend&&!flag[j]){
                    curend=v[j].s;
                    find=1;
                    flag[j]=1;
                }
            }
        }
        find=1;
        while(find!=0){
            find=0;
            for(j=0;j<v.size();j++){
                if(v[j].s==curbeg&&!flag[j]){
                    curbeg=v[j].f;
                    find=1;
                    flag[j]=1;
                }
            }
        }
        fin.pb(make_pair(curbeg,curend));
    }
    /*for(i=0;i<fin.size();i++){
        cout<<fin[i].f<<" "<<fin[i].s<<endl;
    }
    */
    res=res*fact(fin.size())%N;
    cout<<"Case #"<<id<<": "<<res<<endl;
    id++;
    }

    return 0;
}

