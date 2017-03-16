#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#define pii pair<int,int>
using namespace std;
int infinity =1000000;
string skeleton(string s)
{

    string ans;
    int n=s.size();
    char prev='A';
    for(int i=0;i<s.size();++i)
    {
       if(s[i]!=prev)
            {
                ans+=s[i];
            }
        else
        {

        }
        prev=s[i];
    }


    return ans;
}
vector<int> rep(string s)
{
    int n=s.size();
    char prev='A';
    int cur=0;
    vector<int> ans;
    for(int i=0;i<n;++i)
    {

        if(s[i]!=prev)
        {
            ans.push_back(cur);
            cur=1;
        }
        else
        {
            ++cur;
        }
        prev=s[i];
    }
    if(cur)
        ans.push_back(cur);
    return ans;
}
main(void)
{
    int t,n;
    scanf("%d",&t);

    for(int tt=1;tt<=t;++tt)
    {
        printf("Case #%d: ",tt);
    
        int A,B,K;
        cin>>A>>B>>K;
        
        // A--;
        // B--;
        // K--;
        int count=0;

        for(int a=0;a<A;++a)
        {
            for(int b=0;b<B;++b)
                if((a&b) < K)
                {
                    ++count;
                    
                }
        }
        printf("%d\n",count);
    }
}
