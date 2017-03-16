#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define rep(i,n) for( int i=0;i<(n);i++)


using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

set<string> dict;
vector<string> wlist;

template<typename T> int size(const T &a) { return a.size(); } 

bool check(string& s,int a)
{
     int temp=0;
    rep(i,s.length())
    {
        if(s[i] != 'a' && s[i] != 'e' &&s[i] != 'i' &&s[i] != 'o' &&s[i] != 'u')
        {
         temp++;
        }
        else
        {
           temp=0;
        }
        if(temp == a)
          return 1;
    }
    return 0;
}
int main()
{
 
    freopen("in.in","r",stdin);
    int T=1,N,ans;
    cin >> N;
    while(N--)
    {
        string str,str2;
        int n;
        ans=0;
        cin >> str >> n;
        for(int i=0;i<str.length();i++)
        {
            for(int l=1;l<=str.length()-i;l++)
            {
                str2 =  str.substr(i,l);
                //cout <<str2<< " ";
                if(check(str2,n))
                {
                    
                    ans++;
                }
            }
        }
    cout << "Case #" << T<<": "<<ans<< "\n";
    T++;
    }
       
   
}
