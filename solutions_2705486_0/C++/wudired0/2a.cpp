#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<set>
using namespace std;
int a[14223];
vector<string> s[12340];
int dp[1234][10];
set<string> st;
int match(int last, const string &s1, char* s2)
{
     for (int i = 0; i < s1.length(); i++)
     {
         if (s1[i] != s2[i])
         {
             if (i-last < 5)
             {
                return -2;
             }
             last = i;
         }
     }
     if (last < 0) return 0;
     return s1.length() - last;
}
int main()
{
    int cs,i,j,k,n,m;
    char str[123];
    FILE* fp = fopen("garbled_email_dictionary.txt","r");
        for (int i = 0; i < 100 ; i++)
    s[i].clear();
    int fuck=0;
    st.clear();
    while (fscanf(fp, "%s", str) != EOF)
    {
          s[strlen(str)].push_back(string(str));
    }
    fclose(fp);
   freopen("C-small-attempt4.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&cs);
    for (int q = 0 ; q< cs; q++)
    {
        scanf("%s",str);
        //cout<<(st.find(string(str)) != st.end());
        memset(dp,0x1f,sizeof(dp));
        dp[0][5]=0;
        for (int i = 1; i <= strlen(str); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int deta = i -j;
                
                for (int k =0; k <s[deta].size(); k++)
                {
                    for (int dis = 5; dis >= 1; dis--)
                    {
                        int ret = match(-dis, s[deta][k], str+j);
                  //      cout<<dis<<' '<<ret<<endl;
                        if (ret == 0)
                        {
                            int pp = dis + deta;
                            if (pp > 5) pp = 5;
                            if (dp[i][pp] > dp[j][dis])
                               dp[i][pp] = dp[j][dis];
                    
                        }
                        else if (ret == -2) {break;}
                        else
                        {
                            if (ret > 5) ret = 5;
                            if (dp[i][ret] > dp[j][dis]+1)
                            dp[i][ret] = dp[j][dis] + 1;
                        }
                    }
                        
                }
            }
        }
        int ans = 1234;
        for (int i = 1; i <= 5; i++) if (ans > dp[strlen(str)][i]) ans = dp[strlen(str)][i];
        printf("Case #%d: %d\n", q+1, ans);
    }
//    system("pause");
}
            
