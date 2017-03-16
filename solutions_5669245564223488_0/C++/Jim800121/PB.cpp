#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define CHARNUM 200
#define STRNUM 200

using namespace std;


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
    int T,caseNum=1;
    scanf("%d", &T);
    while(caseNum<=T)
    {
        int N;
        scanf("%d", &N);
        char str[STRNUM][CHARNUM]={0};
        for(int i=0; i<N; i++)
        {
            scanf("%s", str[i]);
        }
        int ord[STRNUM]={0};
        for(int i=0; i<N; i++) ord[i] = i;
        int cnt=0;
        while(1)
        {
            bool flag[30];
            for(int i=0; i<26; i++) flag[i]=false;
            bool res=true;
            for(int i=0; i<N; i++)
            {
                int lastNum;
                int lastlen;
                if(i>0)
                {
                    lastNum = ord[i-1];
                    lastlen = strlen(str[lastNum]);
                }
                int thislen = strlen(str[ord[i]]);
                for(int j=0; j<thislen; j++)
                {
                    //printf("%d %d %d %c\n", i, ord[i], j, str[ord[i]][j]);
                    if(flag[str[ord[i]][j]-'a']==false)
                    {
                        flag[str[ord[i]][j]-'a'] = true;
                    }
                    else
                    {
                        if(j!=0)
                        {
                            if(str[ord[i]][j-1]!=str[ord[i]][j])
                            {
                                res = false;
                                //printf("F1\n");
                                break;
                            }
                        }
                        else
                        {
                            if(str[lastNum][lastlen-1]!=str[ord[i]][j])
                            {
                                res = false;
                                //printf("F2\n");
                                break;
                            }
                        }
                    }
                }
                if(res==false)
                    break;
            }

            if(res==true) cnt++;
            //printf("cnt %d\n",cnt);
            if(!next_permutation(ord, ord+N)) break;
        }
        printf("Case #%d: %d\n", caseNum, cnt);

        caseNum++;
    }
    return 0;
}
