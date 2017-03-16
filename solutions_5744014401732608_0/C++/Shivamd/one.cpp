#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll i,ii,j,n,m,tt=1,t;
ll a[230][230];

void rec(ll n)
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j];
		}
		if(i!=n)
		cout<<"\n";
	}

}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);


	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<"Case #"<<tt<<": ";


			if(m>0)
            {
                ll sum = 0,flag=0;
                for(i=2;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        ll mm = m;
                        m-=1;
                        m-=sum;
                        if(a[1][i]==1&&a[i][n]==1&&flag<i){m--;}
                        if(m<0){m=mm;break;}
                        else{
                        m = mm;
                        a[1][i]=1;
                        a[i][j]=1;
                        a[j][n]=1;
                        m-=1;
                        m-=sum;
                        if(a[1][i]==1&&a[i][n]==1&&flag<i){m--;}
                        if(m<0){m=mm;break;}

                        }
                    }
                    sum += (i-1);
                    if(m<=0)break;
                }
            }
            if(m>0)
            {
                for(i=2;i<n;i++){
                    if(a[1][i]==1&&a[i][n]==1)continue;
                    m--;
                    a[1][i]=1;
                    a[i][n]=1;
                    if(m==0)break;
                }


            }
            if(m>0&&a[1][n]==0){
                a[1][n]=1;
                m--;
            }

            if(m==0){
                cout<<"POSSIBLE\n";
                rec(n);
            }
            else{
                cout<<"IMPOSSIBLE";
            }


		cout<<"\n";
		tt++;
		memset(a,0,sizeof(a));
	}

	return 0;
}

