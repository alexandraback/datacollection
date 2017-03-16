/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

char str[1000010];

int solve(int cc)
{
    int n;
    scanf("%s %d",str,&n);
    long long sol=0;
    int last=-1;
    int cnt=0;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {

        if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
        {
            cnt++;
            if(cnt>=n)
            {
                long long tmp=(i-n+1)-last;
                long long tmp2=len-i;
                sol+=(tmp*tmp2);
                last=i-n+1;
            }
        }else
        {
            cnt=0;
        }
//        printf("i=%d,cnt=%d,last=%d,sol=%lld\n",i,cnt,last,sol);
    }
    printf("Case #%d: %lld\n",cc,sol);
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        solve(i+1);

	return 0;
}
