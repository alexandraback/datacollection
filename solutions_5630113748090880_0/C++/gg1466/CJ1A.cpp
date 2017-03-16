#include<bits/stdc++.h>
using namespace std;
vector <int> ans,p;
int mark[2600];
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("CJB11.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        int n;
        cin>>n;
        p.clear();
        memset(mark,0,sizeof mark);
        for(int i=0;i<n;i++)
		{
			for(int k=0;k<(2*n-1);k++)
			{
            int a;
            cin>>a;
            if(!mark[a])
                p.push_back(a);
            mark[a]++;
			}
		}

        ans.clear();
        int s=p.size();
        for(int i=0;i<s;i++)
        {
            if(mark[p[i]]%2!=0)
                ans.push_back(p[i]);
        }
        sort(ans.begin(),ans.end());
        printf("Case #%d: ",j);
        s=ans.size();
		for(int i=0;i<s;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}
