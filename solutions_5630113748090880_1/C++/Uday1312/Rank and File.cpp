#include<bits/stdc++.h>
using namespace std;

int main()
{

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int ar[25000],i,num,j,t,n,ts;
    cin>>ts;

    for(t=1;t<=ts;t++)
    {
        cin>>n;

        memset(ar,0,sizeof(ar));

        for(i=0;i<2*n-1;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&num);
                ar[num]++;
            }
        }

        set<int>st;
        set<int>::iterator it;

        for(i=1;i<=2500;i++)
            if(ar[i]%2==1) st.insert(i);

        printf("Case #%d:",t);

        for(it=st.begin();it!=st.end();it++)
        {
            cout<<" "<<*it;

        }
        cout<<endl;


    }


}
