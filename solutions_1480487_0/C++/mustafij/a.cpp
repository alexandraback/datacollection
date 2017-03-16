#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;

double get(double rem,double amrScore,double sum,double val)
{
    double lo=0, hi=rem; int run=3000;
    while(run-- && fabs(lo-hi)>TOLL)
    {
        double mid=(lo+hi)/2;
        double s=val+sum*mid;
        if(amrScore+TOLL<s) hi=mid;
        else lo=mid;
    }
    double s=val+sum*hi;
    if(amrScore+TOLL<s) return hi;
    return -100;
}

bool possible(double score,double sum,vector<int>&tmp,double ami)
{
    double amrScore=score+sum*ami;
    vector<double> v; v.push_back(amrScore);
    double rem=1-ami;
    for(int i=0;i<sz(tmp);i++)
    {
        double lagbo=get(rem,amrScore,sum,tmp[i]);
        if(lagbo<0) return true;
        rem=rem-lagbo;
    }
    return false;
}

double minReq(double score,double sum,vector<int>& tmp)
{
    double lo=0, hi=1; int run=3000;
    while(run-- && fabs(lo-hi)>TOLL)
    {
        double mid=(lo+hi)/2.0;
        if(possible(score,sum,tmp,mid)) hi=mid;
        else lo=mid;
    }
    return hi;
}

int main()
{
    int t; cin>>t; int cn=0;
    while(t--)
    {
        int N; cin>>N; vector<int> v(N,0);
        for(int i=0;i<N;i++) cin>>v[i];
        vector<double> rv(N,0); int sum=0;
        for(int i=0;i<N;i++) sum+=v[i];
        vector<int> tmp;
        for(int i=0;i<N;i++)
        {
            tmp=v; tmp.erase(tmp.begin()+i);
            double score=v[i];
            rv[i]=minReq(score,sum,tmp);
        }
        printf("Case #%d:",++cn);
        for(int i=0;i<sz(rv);i++) printf(" %.12lf",rv[i]*100);
        printf("\n");


    }

}
