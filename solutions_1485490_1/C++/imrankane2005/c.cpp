#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
#define all(x) (x).begin(),(x).end()

#define vs vector <string>
#define vi vector <int>
#define p(X) push_back((X))

#define fir(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
#define fire(i,j,n) for(int (i)=(j);(i)<=(n);(i)++)
#define firr(i,j,n) for(int (i)=(j);(i)>(n);(i)--)
#define firre(i,j,n) for(int (i)=(j);(i)>=(n);(i)--)
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)

#define srt(v) sort((v).begin(),(v).end())
#define srtc(v) sort(v.begin(),v.end(),cmp)

#define _bc(i) __builtin_popcount(i)

string lower(string s) {for(int i=0;i<s.size();i++) s[i]=tolower(s[i]);return s;}
vector<string> sep(string s,char c) { string temp;vector<string> res;for(int i=0;i<s.size();i++) { if (s[i]==c) {if (temp!="") res.push_back(temp);temp="";continue;}temp=temp+s[i];}if (temp!="") res.push_back(temp);return res;}
template<class T> T toint(string s)
{
	stringstream ss(s);
	T ret;
	ss>>ret;
	return ret;
}
template<class T> string tostr(T inp)
{
	string ret;
	stringstream ss;ss<<inp;
	ss>>ret;
	return ret;
}
template<class T> void D(T A[],int n) {for(int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template<class T> void D(vector<T> A,int n=-1) {if (n==-1) n=A.size();for(int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}

long long a[201];
int A[201];
long long b[201];
int B[201];
int N, M;
long long dp[201][201];
long long solve(int i1, int i2)
{
    if (i1 == N || i2 == M)
        return 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    long long ret = max(solve(i1 + 1, i2), solve(i1, i2 + 1));
    if (A[i1] == B[i2])
    {
        int ai = i1;
        int bi = i2;
        long long s1 = a[i1];
        long long s2 = b[i2];
        while(ai < N && bi < M) {
            ret = max(ret, min(s1, s2) + solve(ai + 1, bi + 1));
            bool c1 = false;
            bool c2 = false;
            if (s1 < s2)
            {c1 = true; ai++;}
            else
            {c2 = true; bi++;}
            if (c1)
            {
                while(ai < N && A[ai] != A[i1]) ai++;
                if (ai < N)
                    s1 += a[ai];
            }
            if (c2)
            {
                while(bi < M && B[bi] != B[i2]) bi++;
                if (bi < M)
                    s2 += b[bi];
            }
        }
    }
    return dp[i1][i2] = ret;
}
int main()
{
    int tc;
    cin>>tc;
    int kase = 0;
    while(tc--) {
        ++kase;
        cin>>N>>M;
        fir(i, 0, N) {
            cin>>a[i]>>A[i];
        }
        fir(i, 0, M) {
            cin>>b[i]>>B[i];
        }
        printf("Case #%d: ", kase);
        memset(dp, -1, sizeof(dp));
        cout<<solve(0, 0)<<endl;
    }
    return 0;
}