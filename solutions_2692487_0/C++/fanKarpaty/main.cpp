#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int tt=T;
	int arr[200];
	int mas[105][200];
	while(T--)
	{
		int res=0;
		int a,n;
		cin>>a>>n;
		for(int i=0;i<n;i++)cin>>arr[i];
		sort(arr,arr+n);
		memset(mas,0,sizeof(mas));
		mas[0][0]=a;
		for(int i=0;i<n;i++)
			for(int j=0;j<200;j++)
			{
				if(!mas[i][j])continue;
				mas[i+1][j+1]=MAX(mas[i+1][j+1],mas[i][j]);
				if(mas[i][j]>arr[i])mas[i+1][j]=MAX(mas[i+1][j], mas[i][j]+arr[i]);
				int temp=mas[i][j];
				if(temp<2)continue;
				int k=0;
				for(k=j;temp<=arr[i];k++)
					temp=2*temp-1;
				mas[i+1][k]=MAX(mas[i+1][k],temp+arr[i]);
			}
		for(res=0;res<200;res++)if(mas[n][res])break;
		cout<<"Case #"<<(tt-T)<<": "<<res<<endl;
		/*cout<<endl;
		for(int i=0;i<=n;i++)
		{ cout<<endl;
		for(int j=0;j<7;j++) cout<<mas[i][j]<<" ";}*/
	}
	return 0;
}