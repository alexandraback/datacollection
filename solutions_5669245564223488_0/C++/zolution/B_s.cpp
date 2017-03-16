#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    freopen("inputB.in","r",stdin);
    freopen("outputB.txt","w",stdout);
    int co=0;
    scanf("%d",&co);
    for(int po=0;po<co;po++)
    {
        int n=0;
        scanf("%d",&n);
        char haha[15];
        char cars[15][100];
        int len[15];
        for(int h=0;h<n;h++)
        {
            scanf("%s",cars[h]);
            len[h]=strlen(cars[h]);
            haha[h]=h+'0';
        }
        haha[n]='\0';
        int ans=0;
        do
		{
			bool used[26];
			for(int h=0;h<26;h++) used[h]=false;
			used[cars[haha[0]-'0'][0]-'a']=true;
			char lc=cars[haha[0]-'0'][0];
            bool flag3=true;
			for(int h=0;h<n;h++)
			{
                int noww=haha[h]-'0';
                
                for(int g=0;g<len[noww];g++)
                {
                    if(cars[noww][g]==lc) continue;
                    if(used[cars[noww][g]-'a']==true)
                    {
                        flag3=false;
                        break;
                    }
                    used[cars[noww][g]-'a']=true;
                    lc=cars[noww][g];
                }
                if(flag3==false) break;
            }
            if(flag3) ans++;
                    
		}while(next_permutation(haha,haha+n));
		printf("Case #%d: %d\n",po+1,ans);
    }
}
        
