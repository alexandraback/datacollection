#include<iostream>
#include<vector>
using namespace std;

vector<int> a[1000];
int used[1000];

int dfs(int po)
{
	used[po]++;
	if(used[po]==2)
		return 1;
	int d;
	int size = a[po].size();
	for(int i=0;i<size;i++)
	{
		d = a[po][i];
		if(dfs(d)==1)
			return 1;
	}

	
		return 0;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	int i,j,k;
	int n;
//	int data[50][50];
	int m;
	int to;


	cin>>t;
	for(i = 0;i<t;i++){
		cin>>n;
		for(j=0;j<n;j++){
			a[j].clear();
		}
		for(j=0;j<n;j++){
			cin>>m;
			used[j] = 0;
			for(k=0;k<m;k++){
				cin>>to;
				a[j].push_back(to-1);
			}			
		}
		cout<<"Case #"<<(i+1)<<":";
		for(j=0;j<n;j++){
			for(k=0;k<1000;k++)
				used[k] = 0;

			if(dfs(j)==1)
				break;

			for(k=0;k<n;k++){
				if(used[k] >= 2)
					break;
			}
			if(k!=n)
				break;
		}
		if(j!=n)
			cout<<" Yes"<<endl;
		else
			cout<<" No"<<endl;		

	}
	cin>>i;
	return 0;
}