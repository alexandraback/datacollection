#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define mod 1000000007
using namespace std;

int n;

char str[200][200];

int appear[30];
int head[30];
int tail[30];

vector<pair<int,int> > diff;
int same[40];

long long factorial[200];

int main()
{

    factorial[0]=1;
    for (int i=1; i<=100; i++)
        factorial[i]=(factorial[i-1]*i)%mod;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int CAS1;
    scanf("%d", &CAS1);
    for (int CAS=1; CAS<=CAS1; CAS++)
    {
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
            scanf("%s", str[i]);
        memset(appear, 0, sizeof(appear));
        memset(same, 0, sizeof (same));
        diff.clear();
        memset(head, 0, sizeof(head));
        memset(tail, 0, sizeof(tail));

        int flag=1;
        for (int i=1; i<=n&&flag; i++)
        {
            int m=strlen(str[i]);
            if (str[i][0]==str[i][m-1])
            {
                for (int j=1; j<m; j++)
                    if (str[i][j-1]!=str[i][j])
                        flag=0;
                int index=str[i][0]-'a';
                same[index]++;
            }
            else
            {
                int inner[30];
                memset(inner, 0, sizeof(inner));
                int k=m-1;
                while (str[i][k]==str[i][k-1])
                    k--;
                for (int j=1; j<k; j++)
                    if (str[i][j-1]!=str[i][j])
                    {
                        int index=str[i][j]-'a';
                        inner[index]++;
                        if (inner[index]>=2)
                            flag=0;
                    }
                /*
                for (int j=0; j<26; j++)
                    printf("%d ", inner[j]);
                printf("\n");
                */
                if (flag)
                {
                    for (int j=0;j<26; j++)
                        if (inner[j]&&appear[j])
                            flag=0;
                        else 
                            appear[j]+=inner[j];

                    int index1=str[i][0]-'a';
                    int index2=str[i][m-1]-'a';
                    diff.push_back(make_pair(index1, index2));
                    if (head[index1])
                        flag=0;
                    else
                        head[index1]=diff.size();

                    if (tail[index2])
                        flag=0;
                    else
                        tail[index2]=diff.size();
                }
            }
        }

        for (int i=1; i<=n; i++)
        {
            int index1=str[i][0]-'a';
            int m=strlen(str[i]);
            int index2=str[i][m-1]-'a';
            if (appear[index1])
                flag=0;
            if (appear[index2])
                flag=0;
        }
        //printf("%d\n", flag);
        /*
        for (int i=0; i<(int)diff.size(); i++)
            printf("%d %d\n", diff[i].first, diff[i].second);
        
        printf("-----------------------------\n");
        for (int i=0; i<26; i++)
            printf("%d %d\n", head[i], tail[i]);

            */
        int left=diff.size();
        int sure=0;

        for (int i=0; i<26; i++)
            if (head[i]&&!tail[i])
            {
                sure++;
                left--;
                int cnt=head[i];
                int cnttail=diff[cnt-1].second;
             //   printf("%c %d %d\n", i+'a', cnt, cnttail);
                while (head[cnttail])
                {
                    cnt=head[cnttail];
                    cnttail=diff[cnt-1].second;
                    left--;
                }
            }
        /*
        printf("%d\n", sure);
        printf("%d\n", flag);
        */

        if (left!=0)
            flag=0;
        for (int i=0; i<26; i++)
        {
            //printf("%d ", same[i]);
            flag=(flag*factorial[same[i]])%mod;
            if (same[i]&&!head[i]&&!tail[i])
                sure++;
        }
        /*
        printf("\n");
        printf("%d\n", sure);
        printf("%d\n", flag);
        */

        flag=(flag*factorial[sure])%mod;
        printf("Case #%d: %d\n", CAS, flag);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
