#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int CAS,cas = 0;
char str[255];
vector<string> dict;
int dp[100];
map<int,vector<int> >hash;
bool cmp(const string &s1,const string &s2)
{
    return s1.length() < s2.length();
}

int absx(int a)
{
    return a < 0 ? -a : a;
}

int calc(string& str,int start, int len)
{
    int hashSize = hash[len].size();
    int ret = 100000;
    for(int i = 0;i <  hashSize;i++)
    {
        int tmp = 0;
        int index = hash[len][i];
        for(int j = 0;j < len;j++)
        {
            if(dict[index][j] != str[start + j])
            {
                if(absx(dict[index][j] - str[start + j - 1]) >= 5)
                    tmp++;
                else
                {
                    tmp = -1;
                    break;
                }
            }
        }
        if(tmp != -1 && ret > tmp) ret = tmp;
    }
    return ret;
}
int minx(int a,int b)
{
    if(a == -1) return b;
    if(b == -1) return a;
    return  a < b ? a : b;
}
int main()
{
    FILE *pF  = fopen("garbled_email_dictionary.txt", "r");
    for(int i = 0;i < 521196;i++)
    {
        fscanf(pF,"%s",str);
        string sstr(str);
        dict.push_back(sstr);
        hash[sstr.length()].push_back(i);
    }
    fclose(pF);
    scanf("%d",&CAS);
    while(CAS--)
    {
        scanf("%s",str);
        string tarStr(str);
        memset(dp,0xff,sizeof dp);
        dp[0] = 0;
        for(int i = 1;i <= tarStr.length();i++)
        {
            for(int j = 0;j < i;j++)
                dp[i] = minx(dp[i],dp[j] + calc(tarStr,j,i - j));
        }
        printf("Case #%d: %d\n",++cas,dp[tarStr.length()]);
    }
}
