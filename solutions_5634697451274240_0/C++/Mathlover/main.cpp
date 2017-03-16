#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
void flip(vector<int>&vec,int n)
{
    vector<int>temp(n);
    for(int i=0;i<n;++i)
        temp[i]=vec[i];
    for(int i=0;i<n;++i)
        vec[i]=1-temp[n-i-1];
}
int main()
{
    int t;
    int ca=0;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("2.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        vector<int>vec(s.length());
        int n=s.length();
        for(int i=0;i<s.length();++i)
            vec[i]=(s[i]=='+'?1:0);
        int sum=0;
        for(int i=0;i<n;++i)
            sum+=vec[i];
        int i;
        for(i=0;;++i)
        {
            int j;
            bool flag=1;
            for(j=0;j<n;++j)
                if(vec[j]==0)
                    flag=0;
            if(flag)
                break;
            for(j=1;j<n;++j)
                if(vec[j]!=vec[0])
                    break;
            flip(vec,j);
//            for(int l=0;l<n;++l)
//                printf("%d",vec[l]);
//            puts("");
        }
        printf("Case #%d: %d\n",++ca,i);
    }
}
