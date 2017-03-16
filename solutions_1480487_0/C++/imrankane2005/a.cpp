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

int s[401];
int N;
int X;
#define EPS 1e-11
bool test(double th, int ind)
{
    vector<int> num;
    double tval = (double)s[ind] + X * th;
    fir(i, 0, N) if (i != ind) num.push_back(s[i]);
    srt(num);
    double left = 1. - th;
    fir(i, 0, num.size())
    {
        if (num[i] - tval > EPS)
            return false;
        double tk = (tval - num[i])/(double)X;
        if (tk - left > EPS)
            return true;
        left -= tk;
    }
    
    return false;
}

int main()
{
    int tc;
    cin>>tc;
    int kase = 0;
    while(tc--) {
        cin>>N;
        fir(i, 0, N) cin>>s[i];
        printf("Case #%d:", ++kase);
        X = 0;
        fir(i, 0, N) X += s[i];
        //cout<<test(0.26, 0)<<endl;
        fir(i, 0, N) {
            double lo = 0;
            double hi = 1.;
            fir(j, 0, 64) {
                double md = (lo + hi)/2.;
                if (test(md, i))
                    hi = md;
                else
                    lo = md;
            }
            printf(" %.6lf", (hi * 100));
        }
        printf("\n");
    }
    return 0;
}