#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

#define SI(x) scanf("%d ",&x)
#define SL(x) scanf("%lld",&x)

typedef long long LL;
using namespace std;

int from[] = {24 ,13 ,5 ,8 ,2 ,22 ,11 ,1 ,10 ,20 ,14 ,12 ,23 ,18 ,4 ,21 ,25 ,15 ,3 ,17 ,9 ,6 ,19 ,7 ,0 ,16};
int to[26];
char S[102];

void pre()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(from[j]==i)
            {
                to[i]=j;  
            }
        }
    }
}


int main()
{
//    freopen("in.in","r",stdin);
    freopen("A-small-output.txt","w",stdout);
   
    pre();
    int T, tnum = 1;
    SI(T);

    while(T-- >0)
    {
        gets(S);
        int n = strlen(S);
        for(int i=0;i<n;i++)
        {
            if(S[i]==' ')continue;
            S[i] = (char)(to[S[i]-'a']+'a');
        }

        printf("Case #%d: %s\n",tnum,S);
        tnum++;
    }


    fclose(stdout);
	return 0;
}
