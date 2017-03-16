#include <bits/stdc++.h>
using namespace std;
const string nums[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int get(char c)
{
    return (int)(c-'A');
}
int main()
{
    freopen("A.txt","r",stdin);
    freopen("Aout.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        printf("Case #%d: ",tt);
        string s;
        cin >> s;
        int acnt[26];
        for(int i=0;i<26;i++) acnt[i]=0;
        for(int i=0;i<s.length();i++) acnt[get(s[i])]++;
        int sol[10];
        for(int i=0;i<10;i++) sol[i]=0;
        sol[0]=acnt[get('Z')];
        for(int i=0;i<nums[0].length();i++) acnt[get(nums[0][i])]-=sol[0];
        sol[6]=acnt[get('X')];
        for(int i=0;i<nums[6].length();i++) acnt[get(nums[6][i])]-=sol[6];
        sol[8]=acnt[get('G')];
        for(int i=0;i<nums[8].length();i++) acnt[get(nums[8][i])]-=sol[8];
        sol[2]=acnt[get('W')];
        for(int i=0;i<nums[2].length();i++) acnt[get(nums[2][i])]-=sol[2];
        sol[3]=acnt[get('H')];
        for(int i=0;i<nums[3].length();i++) acnt[get(nums[3][i])]-=sol[3];
        sol[7]=acnt[get('S')];
        for(int i=0;i<nums[7].length();i++) acnt[get(nums[7][i])]-=sol[7];
        sol[4]=acnt[get('R')];
        for(int i=0;i<nums[4].length();i++) acnt[get(nums[4][i])]-=sol[4];
        sol[5]=acnt[get('F')];
        for(int i=0;i<nums[5].length();i++) acnt[get(nums[5][i])]-=sol[5];
        sol[1]=acnt[get('O')];
        for(int i=0;i<nums[1].length();i++) acnt[get(nums[1][i])]-=sol[1];
        sol[9]=acnt[get('I')];
        for(int i=0;i<nums[9].length();i++) acnt[get(nums[9][i])]-=sol[9];
        int sum=0;
        for(int i=0;i<26;i++) sum+=acnt[i];
        if(sum!=0)
        {
            assert(false);
        }
        for(int i=0;i<10;i++)
        {
            char cur=(char)(i+'0');
            for(int j=0;j<sol[i];j++) printf("%c",cur);
        }
        printf("\n");
    }
}
