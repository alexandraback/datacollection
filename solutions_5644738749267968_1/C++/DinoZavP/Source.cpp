#include<iostream>
#include<algorithm>
using namespace std;

void main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, N, ans1, ans2, k, index1, index2;
	double A[2][1000], B[2][1000];
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>N;
		cout<<"Case #"<<t<<": ";
		ans1=0;
		ans2=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<N;j++)
			{
				cin>>A[i][j];
				B[i][j]=A[i][j];
			}
		sort(A[0],A[0]+N);
		sort(A[1],A[1]+N);
		sort(B[0],B[0]+N);
		sort(B[1],B[1]+N);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if ((A[0][i]>A[1][j]) && (A[0][i]!=-1) && (A[1][j]!=-1)) {ans1++; A[1][j]=-1; A[0][i]=-1;}
		k=N;
		index1=0;
		index2=N-1;
		for(int j=N-1;j>=0;j--)
			if ((B[0][j]>B[1][index2]) && (B[0][j]!=-1) && (B[1][index2]!=-1))
			{
				ans2++;
				B[0][j]=-1;
				B[1][index1]=-1;
				k--;
				index1++;
			} else 
			{
				B[0][j]=-1;
				B[1][index2]=-1;
				index2--;
				k--;
			}
		cout<<ans1<<" "<<ans2<<endl;
	}
}