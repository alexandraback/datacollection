#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define PI (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=((n)-1);i>=0;i--)
#define rrep(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("Aout.txt","w",stdout);
    string num[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
    	set<int> s[26];
    	string str;
    	for(int i=0;i<10;i++)
    	{
    		for(int j=0;j<num[i].size();j++)
    			s[num[i][j]-'A'].insert(i);
    	}
    	cin>>str;
    	int cnt[26]={0};
    	for(int i=0;i<str.size();i++)
    	{
    		cnt[str[i]-'A']++;
    	}
    	int ans[10]={0};
    	for(int i=0;i<10;i++)
    	{
    		int cur,curtot;
    		for(int j=0;j<26;j++)
    		{
    			if(s[j].size()==1)
    			{
    				cur=*s[j].begin();
    				curtot=cnt[j];
    				break;
    			}
    		}
    		//cout<<cur<<endl;
    		ans[cur]=curtot;
    		for(int j=0;j<num[cur].size();j++)
    		{
    			cnt[num[cur][j]-'A']-=curtot;
    			s[num[cur][j]-'A'].erase(cur);
    		}
    	}
    	printf("Case #%d: ",t);
    	for(int i=0;i<10;i++)
    		for(int j=0;j<ans[i];j++)
    			printf("%d",i);
    	printf("\n");
    }
    return 0;
}