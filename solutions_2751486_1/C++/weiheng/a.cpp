#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int notvowel(char ch)
{
    if(ch =='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return 0;
    return 1;
}

int main()
{
    int t,n,cas,i,pre,j;
    char str[1000006];
    int len;
    int st;
    int ans;
    cin>>t;
    cas = 1;
    while(cas<=t)
    {
        scanf("%s %d",str,&n);
        pre=0;
        ans=0;
        len = strlen(str);
        for(st=-1,i=0; str[i]!=0; i++)
        {
            if(notvowel(str[i]))
            {
                pre++;
                if(pre<n)
                    continue;
                ans += (i-n+1-st)*(len-i);
                st = i-n+1;
            }
            else
            {
                pre=0;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
        cas++;
    }
    return 0;
}
