#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100005];
int b[100005];
int main()
{
    ll t,n,p,i,j,r,c=1;

    freopen("A-small-attempt1 (1).in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",&a);
        memset(b,0,sizeof(b));
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            b[a[i]]++;
        }
        vector<int> ans;
        while(b['S']>0 && b['I']>0 && b['X']>0)
        {
            ans.push_back(6);
            b['S']--;
            b['I']--;
            b['X']--;
        }
        while(b['Z']>0 && b['E']>0 && b['R']>0 && b['O']>0)
        {
            ans.push_back(0);
            b['Z']--;
            b['E']--;
            b['R']--;
            b['O']--;
        }
        while(b['E']>0 && b['I']>0 && b['G']>0 && b['H']>0 && b['T']>0)
        {
            ans.push_back(8);
            b['E']--;
            b['I']--;
            b['G']--;
            b['H']--;
            b['T']--;
        }

        while(b['T']>0 && b['W']>0 && b['O'])
        {
            ans.push_back(2);
            b['T']--;
            b['W']--;
            b['O']--;
        }

        while(b['S']>0 && b['E']>1 && b['V']>0 && b['N']>0)
        {
            ans.push_back(7);
            b['S']--;
            b['E']--;
            b['V']--;
            b['E']--;
            b['N']--;
        }
        while(b['F']>0 && b['O']>0 && b['U']>0 && b['R']>0)
        {
            ans.push_back(4);
            b['F']--;
            b['O']--;
            b['U']--;
            b['R']--;
        }
        while(b['F']>0 && b['I']>0 && b['V']>0 && b['E']>0)
        {
            ans.push_back(5);
            b['F']--;
            b['I']--;
            b['V']--;
            b['E']--;
        }
        while(b['O']>0 && b['N']>0 && b['E']>0)
        {
            ans.push_back(1);
            b['O']--;
            b['N']--;
            b['E']--;
        }
        while(b['N']>1 && b['I']>0 && b['E']>0 )
        {
            ans.push_back(9);
            b['N']--;
            b['I']--;
            b['N']--;
            b['E']--;

        }

        while(b['T']>0 && b['H']>0 && b['R']>0 && b['E']>1)
        {
            ans.push_back(3);
            b['T']--;
            b['H']--;
            b['R']--;
            b['E']--;
            b['E']--;
        }




        /*while(b['S']>0 && b['E']>1 && b['V']>0 && b['N']>0)
        {
            ans.push_back(7);
            b['S']--;
            b['E']--;
            b['V']--;
            b['E']--;
            b['N']--;
        }*/


        sort(ans.begin(),ans.end());

        printf("Case #%d: ",c++);
        for(i=0;i<ans.size();i++)
        printf("%d",ans[i]);


        printf("\n");
        for(i=0;i<100;i++)
        {
            if(b[i]>0)
            {
                printf("%c",i);
                //break;
            }
        }

    }
    return 0;
}
