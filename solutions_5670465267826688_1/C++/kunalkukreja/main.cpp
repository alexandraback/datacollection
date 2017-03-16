#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007

int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    map<char,int> conversion;
    conversion.insert(mp('i',2));
    conversion.insert(mp('j',3));
    conversion.insert(mp('k',4));
    vector<vi> mat(5,vi(5,0));
    fore(i,1,5)
    {
        fore(j,1,5)
        {
            if(i==1 || j==1)
                mat[i][j] = i*j;
            else if(i==j)
                mat[i][j] = -1;
            else
            {
                int num1 = i,num2 = j;
                num1--;
                num2--;
                if(((num1+1)%3) == (num2%3))
                    mat[i][j] = (num2+2);
                else
                    mat[i][j] = -(num1+2);
                if(mat[i][j]==5)
                    mat[i][j] = 2;
                if(mat[i][j]==-5)
                    mat[i][j] = -2;
            }
        }
    }
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		ll n,x;
		cin>>n>>x;
		if(x>8)
            x = 4 + (x%4);
		string temp;
		cin>>temp;
		string s = "";
		n*=x;
		fore(i,0,x)
            s+=temp;
		vi prefix(n),suffix(n);
		prefix[0] = conversion[s[0]];
		suffix[n-1] = conversion[s[n-1]];
		int cur = prefix[0];
		bool mins = false;
		fore(i,1,n)
		{
		    cur = mat[cur][conversion[s[i]]];
		    if(!mins)
                prefix[i] = cur;
            else
                prefix[i] = -cur;
		    if(cur<0)
                mins = !mins;
            cur = abs(cur);
		}

		cur = suffix[n-1];
		mins = false;
		ford(i,n-2,0)
		{
		    cur = mat[conversion[s[i]]][cur];
		    if(!mins)
                suffix[i] = cur;
            else
                suffix[i] = -cur;
            if(cur<0)
                mins = !mins;
            cur = abs(cur);
		}
		vi vis(n,-1);
		bool found = false;
		fore(i,0,n)
		{
		    if(found)
                vis[i] = 1;
		    if(prefix[i]==2)
                found = true;
		}
		found = false;
		fore(i,0,n-1)
		{
		    if(vis[i]==-1)
                continue;
            if(prefix[i]==4 && suffix[i+1]==4)
            {
                found = true;
                break;
            }
		}
		if(found)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
	}
	return 0;
}
