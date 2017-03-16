/*
ID: neil
PROG: untitled
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <string.h>
#include <list>
#include <algorithm>
#include <cmath>
#include <set>

#define for0(i,n) for (int i=0; i<n; i++)
#define forin(i,n) for (int i=0; i<=n; i++)
#define forr(i,n) for (int i=n-1; i>=0; i--)
#define fori(i,a,b) for (int i=a; i<=b; i++)
#define iter(v,x) for(vector<x>::iterator it=v.begin(); it!=v.end(); it++)
#define pb(x) push_back(x)
#define vec(x) vector<x>
#define ms(a,z) memset(a,z,sizeof(a))
#define sort(a) sort(a.begin(),a.end())
#define nl() cout<<"\n"
#define print(x) cout<<x<<" "
#define printv(v) for(int _=0; _<v.size(); _++) cout<<v[_]<<" "; cout<<"\n";
#define printa(a,s) for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";
#define print2D(a,m,n) for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";}
#define sum(a,l,s) int s=0; for (int _=0; _<l; _++) s+=a[_];

using namespace std;

int INF = 999999999;
double EPSILON = 0.00000001;
vec(long long) avals,bvals;
vec(int) atypes,btypes;


long long solve2(vec(int) z)
{
    //printv(z);
    long long ans,x,v,prev;
    ans=0;
    int i=0;
    x = avals[0];
    v = 0;

    while (i <= z[0]){
        if (atypes[0] == btypes[i]){
            v = x;
            if (bvals[i] < v) v = bvals[i];
            ans += v;
            x -= v;
        }
        else v =0;
        prev = v;
        i++;
    }
    //print(ans); print(prev); nl();
    i--;
    if (z.size() == 1) return ans;

    bool first=true;
    x = avals[1];
    while (i <= z[1]){
        if (atypes[1] == btypes[i]){
            v = x;
            if (bvals[i] < v) v = bvals[i];
            if (first) v -= prev;
            if (v < 0) v = 0;
            ans += v;
            x -= v;
        }
        else v = 0;
        if (not first) prev = v;
        first = false;
        i++;
    }
    i--;
    if (z.size()==2) return ans;
    //print(ans); print(prev); nl();

    first=true;
    x = avals[2];
    while (i <= z[2]){
        if (atypes[2] == btypes[i]){
            v = x;
            if (bvals[i] < v) v = bvals[i];
            if (first) v -= prev;
            if (v < 0) v = 0;
            ans += v;
            x -= v;
        }
        first = false;
        i++;
    }
    //print(ans); nl(); nl();
    return ans;
}

long long solve(int i, int prev, vec(int) z)
{
    if (i == atypes.size()){
        return solve2(z);
    }
    long long best=0;
    fori(j,prev,btypes.size()-1){
        z.pb(j);
        long long q = solve(i+1,j,z);
        if (q > best) best = q;
        z.erase(z.begin()+z.size()-1);
    }
    return best;
}

int main()
{
    ifstream in("P3.txt");
    ofstream out("P3.out");
    int cases;
    in >> cases;

    for0(casen,cases){
        atypes.clear(); avals.clear(); bvals.clear(); btypes.clear();
        int n,m;
        in >> n >> m;

        for0(i,n){
            long long aval;
            int atype;
            in >> aval >> atype;
            atypes.pb(atype);
            avals.pb(aval);
        }
        for0(i,m){
            int t;
            long long b;
            in >> b >> t;
            btypes.pb(t);
            bvals.pb(b);
        }

        //printv(avals); printv(atypes); printv(bvals); printv(btypes); nl();
        vec(int) z;
        long long ans = solve(0,0,z);
        print(ans); nl();
        out << "Case #"<<casen+1<<": "<<ans<<"\n";
    }
    return 0;
}
