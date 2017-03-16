#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define fill(arr,val) memset(arr,val,sizeof(arr))

typedef long long ll;

using namespace std;

int n, q, used[26];
ll ans = 0;
string str;
vector < pair <int, int > > vp;

void redirect()
{
    freopen("test.txt","r",stdin);
    freopen("solution.txt","w",stdout);
}

void init()
{
    cin >> str ;
    cin.ignore();
    cin >> q;
    
    fill(used,0);
    
    used['a'-'a']=1;
    used['e'-'a']=1;
    used['i'-'a']=1;
    used['o'-'a']=1;
    used['u'-'a']=1;
}

void solve(int testnum)
{
    ans = 0;
    str.push_back('u');
    int cnt = 0;
    
    vp.clear();
    
    int start = -1, contigious = 0;
    
    f(i,0,str.size()-1)
        if (used[str[i]-'a']==1)
        {
            if (contigious) 
            {
                if (i-start>=q) vp.push_back(make_pair(start,i-1));
                contigious = 0;
            }
        }
        else 
        {
            if (contigious) continue;
            else
            {
                start = i;
                contigious = 1;
            }
        }
    
    if (vp.empty()) ans = 0;
    else 
    {
        ll pred = 0;
        
        for(int i=0; i<vp.size(); i++)
        {
//            cout << pred << " " << vp[i].second << endl;
            
            for(int pos=pred; pos+q-1<=vp[i].second; pos++)
            {
                ans += (ll)(str.size() - max(vp[i].first,pos) - q);
//                cout << "POS " << pos << " CNT " << (str.size() - max(vp[i].first,pos) - q) << endl;
            }
                
            pred = vp[i].second - q + 2;
        }
    }    
    
    cout << "Case #" << testnum << ": " << ans << endl;
}

int main()
{
    redirect();
    
    int tests = 1;   cin >> tests;
    
    f(i,1,tests)
    {
        init();
        solve(i);
    }
    
    return 0;
}