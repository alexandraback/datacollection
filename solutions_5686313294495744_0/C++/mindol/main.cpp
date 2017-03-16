#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
string a[17][2];
map<string,int> L,R;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int mindol=1;mindol<=tc;mindol++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1];
            L[a[i][0]]++;
            R[a[i][1]]++;
        }
        int cnt=0;
        for(int i=n;i>=1;i--)
        {
            if(L[a[i][0]] >= 2 && R[a[i][1]] >= 2)
            {
                cnt++;
                L[a[i][0]]--;
                R[a[i][1]]--;
            }
        }
        printf("Case #%d: %d\n",mindol,cnt);
        L.clear(), R.clear();
    }
    return 0;
}
