#include <bits/stdc++.h>
using namespace std;

int main() {
	 freopen("1B.txt","r",stdin);
	    freopen("1BOUT.txt","w",stdout);
	int t;
	long int n,i,j,k,x;
	scanf("%d",&t);
	int ans[51];
for(int j=0;j<t;j++)
	{int A[2501]={0};
	    cin>>n;
	for(i = 0 ;i<2*n-1;i++)
    {
        for(k=0;k<n;k++)
        {
            cin>>x;
            A[x]++;
        }

    }
	    int y=0;
	    for(i=0;i<2501;i++)
        {
            if(A[i]%2!=0)
                ans[y++]=i;
        }

    cout<<"Case #"<<j+1<<": ";
    for(i=0;i<n;i++)
    {cout<<ans[i];
    if(i!=n-1)
        cout<<" ";
    }
    cout<<endl;
      	//printf("Case #%d: %s\n",j+1,s1);


	}

	// your code goes here
	return 0;
}
