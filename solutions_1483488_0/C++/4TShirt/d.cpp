#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define CLOCK cout << "Clock " << (double)clock()/CLOCKS_PER_SEC << endl

int a,b;
string stra,strb;
map<int,int> m;
int tens[]={1,10,100,1000,10000,100000,1000000,10000000};
long long getN(string str)
{
    int len = str.length();
    long long num = 0;
    for (int i=0;i<len;i++)
        num = num*10 + (str[i]-'0');
    return num;
}
int getStr(long long num)
{
    int len = 0;
    while(num)
    {
        num /= 10;
        len ++;
    }
    return len;
}

void getAC(int n)
{
    int len = getStr(n);
    long long num = n;
    for (int i=1;i<len;i++)
    {
        num = num%tens[len-1]*10 + num/tens[len-1];
        if(num>n && num<=b)
            m[num] ++;
    }
}
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	//freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cases=1;cases<=t;cases++)
	{
		scanf("%d %d",&a,&b);
		strb = getStr(b);
		long long res = 0;
		for (int i=a;i<b;i++)
		{
		    m.clear();
		    stra = getStr(i);
            getAC(i);
            res += m.size();
		}
		printf("Case #%d: ",cases);
		cout << res << endl;
	}
	return 0;
}
