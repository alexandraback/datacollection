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
#define printv(v) for(int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<"\n";
#define printa(a) for (int i=0; i<sizeof(a)/8; i++) cout<<a[i]<<" "; cout<<"\n";
#define print2D(a,m,n) for (int i=0; i<m; i++) {for (int j=0; j<n; j++) cout<<a[i][j]<<" "; cout<<"\n";}
#define sum(a) int s=0; for (int i=0; i<sizeof(a)/8; i++) s+=a[i];

using namespace std;

long long INF = 9999999999;
double EPSILON = 0.00000001;
bool used[2000001];

int sint(string s){
    int num=0;
    istringstream myStream(s);
    (myStream>>num);
    return num;
}

string str (int num){
    ostringstream oss;
    oss<< num;
    return oss.str();
}

vector <string> split(string s)
{
    vector <string> tokens;
    stringstream os(s);
    string temp;
    while (os >> temp)
    {
        tokens.push_back(temp);
    }
    return tokens;
}

int maxv(vector<int> v){
    int m = -9999999;
    for0(i,v.size()) m = max(m,v[i]);
    return m;
}

int minv(vector<int> v){
    int m = 9999999;
    for0(i,v.size()) m = min(m,v[i]);
    return m;
}

long long recycle(int n, int a, int b)
{
    if (used[n]) return 0;
    long long count = 1;
    string m = str(n);
    int l = m.length();
    for0(_,l-1){
        m = m[l-1]+m.substr(0,l-1);
        int z = sint(m);
        if (z > n and z <= b and not used[z]){
            used[z] = true;
            count++;
        }
    }
    return count*(count-1)/2;
}

int main()
{
    ifstream in("recycled_numbers.in");
    FILE *out;
    out = fopen("recycled_numbers.out","w");
    int cases;
    in >> cases;

    for0(casen,cases){
        ms(used,false);
        int a,b;
        in >> a >> b;
        long long count = 0;

        fori(n,a,b){
            count += recycle(n,a,b);
        }
        fprintf(out,"Case #%d: %lld\n",casen+1,count);
    }
    return 0;
}
