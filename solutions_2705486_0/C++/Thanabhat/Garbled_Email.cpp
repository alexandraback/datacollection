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

#define INF 100000000

using namespace std;

char word[600000][16];
int nword=521196;
int lword[600000];
vector<int> lst[26][27];

char str[64];
int len;
int sol;
int dp[55][5];

inline int test(int p,int ind,int *first,int *last,int *cnt)
{
    if(lword[ind]>len-p)
        return -1;
    int _last=-10;
    *cnt=0;
    for(int i=0;i<lword[ind];i++)
    {
        if(word[ind][i]!=str[p+i])
        {
            if(i-_last<5)
                return -1;
            _last=i;
            cnt++;
        }
    }
    *first=4;
    for(int i=0;i<min(lword[ind],4);i++)
        if(word[ind][i]!=str[p+i])
            *first=i;
    if(lword[ind]-_last==1)
        *last=4;
    else if(lword[ind]-_last==2)
        *last=3;
    else if(lword[ind]-_last==3)
        *last=2;
    else if(lword[ind]-_last==4)
        *last=1;
    else
        *last=0;
    return 1;
}

int solve(int cc){

    scanf("%s",str);
    len=strlen(str);

    for(int i=0;i<5;i++)
        dp[0][i]=0;

    int first,last,cnt;
    for(int i=1;i<=len;i++)
    {
        for(int j=0;j<5;j++)
            dp[i][j]=INF;

        for(int j=0;j<27;j++)
        {
            for(int k=0;k<lst[str[i-1]-'a'][j].size();k++)
            {
                if(test(i-1,lst[str[i-1]-'a'][j][k],&first,&last,&cnt))
                {
                    for(int l=0;l<=last;l++)
                    {
                        dp[i][l]=min(dp[i][l],dp[i-1][first]+cnt);
                    }
                }
            }
        }

        if(i==len)
            continue;

        for(int j=0;j<26;j++)
        {
            for(int k=0;k<lst[j][str[i]-'a'].size();k++)
            {
                if(test(i-1,lst[j][str[i]-'a'][k],&first,&last,&cnt))
                {
                    for(int l=0;l<=last;l++)
                    {
                        dp[i][l]=min(dp[i][l],dp[i-1][first]+cnt);
                    }
                }
            }
        }

    }

    sol=INF;
    for(int i=0;i<5;i++)
        sol=min(dp[len][i],sol);

    printf("Case #%d: %d\n",cc,sol);

    return 1;
}

int main(){


//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    FILE *fr=fopen("garbled_email_dictionary.txt","r");
    for(int i=0;i<nword;i++)
        fscanf(fr,"%s",word[i]);
    fclose(fr);

    for(int i=0;i<nword;i++)
        lword[i]=strlen(word[i]);

    for(int i=0;i<nword;i++)
    {
        if(lword[i]==1)
            lst[word[i][0]-'a'][26].push_back(i);
        else
            lst[word[i][0]-'a'][word[i][1]-'a'].push_back(i);
    }

//    for(int i=0;i<26;i++)
//    {
//        for(int j=0;j<27;j++)
//        {
//            printf("\t\t%d",lst[i][j].size());
//        }
//        printf("\n");
//    }

//    int cnt[11];
//    for(int i=0;i<11;i++)
//        cnt[i]=0;
//    for(int i=0;i<nword;i++)
//        cnt[(int)strlen(word[i])]++;
//    for(int i=0;i<11;i++)
//        printf("%d-%d\n",i,cnt[i]);

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        solve(i+1);



	return 0;
}
