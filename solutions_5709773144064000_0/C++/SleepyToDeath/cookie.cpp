#include<iostream>
#include<iomanip>
using namespace std;

void work( int n )
{
	double C,F,X;
	cin>>C>>F>>X;
	int i;
	for (i=0;;i++)
		if ( X/(2+(double)(i+1)*F) + C/(2+((double)i*F)) >= X/(2+(double)i*F) )
			break;
//	cout<<i;
	double t=0;
	for (int j=0;j<i;j++)
		t+=1/(2+(double)j*F);
	t=t*C+X/(2+(double)i*F);
	cout<<"Case #"<<n<<": "<<setprecision(9)<<t<<endl;

}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		work( i );
}

