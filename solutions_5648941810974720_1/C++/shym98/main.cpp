#pragma comment(linker,"/STACK:100000000000,100000000000")

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define D long double
#define pi pair<int,int>
#define F first
#define S second
#define forn(i,n) for (int(i)=0;(i)<(n);i++)
#define forr(i,x,y) for (int(i)=(x);(i)<=(y);i++)
#define ford(i,x,y) for (int(i)=(x);(i)>=(y);i--)
#define rev reverse
#define in insert
#define er erase
#define all(n) (n).begin(),(n).end()
#define graf vector<vector<pi> >
#define graf1 vector<vector<ll> >
#define sqr(a) (a)*(a)
#define file freopen("a.in","r",stdin);freopen("a.out","w",stdout);
#define y1 asdadasdasd

const int INF = 1e9;
const D cp = 2 * asin(1.0);
const D eps = 1e-9;
const ll mod = 1000000007;

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //file;
    int T;
    cin>>T;
    forn(Q,T)
    {
        map<char,int> a;
        string s;
        cin>>s;
        multiset<int> res;
        forn(i,s.size()) a[s[i]]++;
        if (a['Z'])
        {
            while(a['Z'])
            {
                a['Z']--;
                a['E']--;
                a['R']--;
                a['O']--;
                res.in(0);
            }
        }
        if (a['W'])
        {
            while(a['W'])
            {
                a['T']--;
                a['W']--;
                a['O']--;
                res.in(2);
            }
        }
        if (a['X'])
        {
            while(a['X'])
            {
                a['S']--;
                a['I']--;
                a['X']--;
                res.in(6);
            }
        }
        if (a['G'])
        {
            while(a['G'])
            {
                a['E']--;
                a['I']--;
                a['G']--;
                a['H']--;
                a['T']--;
                res.in(8);
            }
        }
        if (a['S'])
        {
            while(a['S'])
            {
                a['S']--;
                a['E']--;
                a['V']--;
                a['E']--;
                a['N']--;
                res.in(7);
            }
        }
        if (a['V'])
        {
            while(a['V'])
            {
                a['F']--;
                a['I']--;
                a['V']--;
                a['E']--;
                res.in(5);
            }
        }
        if (a['F'])
        {
            while(a['F'])
            {
                a['F']--;
                a['O']--;
                a['U']--;
                a['R']--;
                res.in(4);
            }
        }
        if (a['T'])
        {
            while(a['T'])
            {
                a['T']--;
                a['H']--;
                a['R']--;
                a['E']--;
                a['E']--;
                res.in(3);
            }
        }
        if (a['O'])
        {
            while(a['O'])
            {
                a['O']--;
                a['N']--;
                a['E']--;
                res.in(1);
            }
        }
        if (a['N'])
        {
            while(a['N'])
            {
                a['N']--;
                a['I']--;
                a['N']--;
                a['E']--;
                res.in(9);
            }
        }
        cout<<"Case #"<<Q+1<<": ";
        for (multiset<int>::iterator i = res.begin();i!=res.end();i++)
            cout<<*i;
        cout<<endl;
    }
    return 0;
}
