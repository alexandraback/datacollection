#include < iostream > 
#include <stdio.h >
using namespace std;

int main ()
{
int t;
int a[102][102];
int row_max[100];
int col_max[100];
bool f[102];
cin>>t;
for (int iii=1;iii<=t;iii++)
{
int m,n;
cin>>m>>n;

for (int j=0;j<n;j++)
{
  col_max[j]=-1;
}

for ( int i = 0; i < m; i++)
{
	row_max[i]=-1;
	for (int j = 0; j < n;j++)
{
	scanf (" %d ",&a[i][j]);
    if(a[i][j] >  row_max[i] )
		row_max[i]=a[i][j];
	if(a[i][j] > col_max[j] ) 
		col_max[j]=a[i][j];
}
}

int flag=1;
for ( int i = 0; i < m; i++ )
{
for (int j = 0;j<n;j++)
{
if( a[i][j] != row_max[i] && a[i][j] != col_max[j] )
{
flag=0;
break;
}
}
}

if(flag==0)
{
	cout<<"Case #"<<iii<<": NO"<<endl;
}
else
		cout<<"Case #"<<iii<<": YES"<<endl;

}
}