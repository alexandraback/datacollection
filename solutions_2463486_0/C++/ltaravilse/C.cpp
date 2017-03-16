#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()

using namespace std;

vector<long long> fairSquares;

vector<int> cuad(vector<int> vec)
{
    if(count(all(vec),0)==vec.size())
        return vec;
    while(vec[vec.size()-1]==0)
        vec.pop_back();
    reverse(all(vec));
    for(int i=vec.size()-1;i>=0;i--)
        vec.push_back(vec[i]);
    int n = vec.size();
    vector<int> res(2*n,0);
    forn(i,n)
    forn(j,n)
        res[i+j]+=vec[i]*vec[j];
    forn(i,2*n-1)
    if(res[i]>=10)
    {
        res[i+1]+=res[i]/10;
        res[i]%=10;
    }
    while(!res.empty() && res[res.size()-1]==0)
        res.pop_back();
    return res;
}

vector<int> cuad2(vector<int> vec)
{
    bool b = false;
    if(count(all(vec),0)==vec.size())
        return vec;
    while(vec[vec.size()-1]==0)
        vec.pop_back();
    reverse(all(vec));
    for(int i=vec.size()-2;i>=0;i--)
        vec.push_back(vec[i]);
    int n = vec.size();
    vector<int> res(2*n,0);
    forn(i,n)
    forn(j,n)
        res[i+j]+=vec[i]*vec[j];
    forn(i,2*n-1)
    if(res[i]>=10)
    {
        res[i+1]+=res[i]/10;
        res[i]%=10;
    }
    while(!res.empty() && res[res.size()-1]==0)
        res.pop_back();
    return res;
}

bool capicua(vector<int> vec)
{
    vector<int> alReves = vec;
    reverse(all(alReves));
    if(vec==alReves)
        return true;
    return false;
}

bool pal(long long t)
{
    vector<int> vec1,vec2;
    while(t!=0)
    {
        vec1.push_back(t%10);
        t/=10;
    }
    vec2 = vec1;
    reverse(all(vec1));
    return vec1 == vec2;
}

long long pot(long long base, int exp)
{
    long long res = 1;
    forn(i,exp)
        res *= base;
    return res;
}

long long num(vector<int> vec)
{
    long long res = 0;
    forn(i,vec.size())
    {
        res *= 10;
        res += vec[i];
    }
    return res;
}

int main()
{
	#ifdef ACMTUYO
	freopen("C-small.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	long long mx = pot(3,7);
	vector<int> vec(7);
	fairSquares.push_back(9);
	int t = 1;
	for(long long i=1;i<mx;i++)
	{
	    long long j = i;
	    forn(t,7)
	    {
            vec[t] = j%3;
            j/=3;
	    }
	    if(capicua(cuad(vec))==true)
            fairSquares.push_back(num(cuad(vec)));
        if(capicua(cuad2(vec)))
            fairSquares.push_back(num(cuad2(vec)));
	}
	sort(all(fairSquares));
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
	    int a,b;
	    cin >> a >> b;
	    int res = 0;
	    forn(i,fairSquares.size())
	    if(fairSquares[i]>=a && fairSquares[i]<=b)
            res++;
        cout <<"Case #"<< casito << ": "<<res << endl;
	}
}
