#include<iostream>
using namespace std;
int i,j,k,temp,T,X[2];
void print(int i,int j)
{
	if (i==1)
		if (j==1) cout<<'N';
		else cout<<'S';
	else 
		if (j==1) cout<<'E';
		else cout<<'W'; 
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	cin>>T;
	for (k=0;k<T;k++)
	{
		cout<<"Case #"<<k+1<<": ";
		cin>>X[0]>>X[1];
		i=1;
		for (j=0;j<2;j++)
		{
			if (X[j]<0)
			{
				temp=-1;
				X[j]=-X[j];
			}
			else temp=1;
			while (X[j]>=i)
			{
				print(j,temp);
				X[j]-=i;
				i++;
			}
			for (;X[j]>0;X[j]--)
			{
				print(j,-temp);
				print(j,temp);
				i+=2;
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}