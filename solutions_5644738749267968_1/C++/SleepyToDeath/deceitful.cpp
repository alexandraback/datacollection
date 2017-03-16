#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int war( vector<double> & b1 , vector<double> & b2 )
{
	sort( b1.begin() , b1.end() );
	sort( b2.begin() , b2.end() );
	int point = 0;
	size_t j = 0;
	size_t i = 0;
	while ( true )
	{
		while ( i < b1.size() && b1[i] < b2[j] )
			i++;
		if ( i<b1.size() )
			point++;
		else
			break;
		i++;
		j++;
	}
	return point ;
}
	

void work( int n )
{
	vector<double> b1;
	vector<double> b2;
	b1.clear();
	b2.clear();
	int num=0;
	cin>>num;
	for (int i=0; i<num; i++)
	{
		double tmp;
		cin>>tmp;
		b1.push_back( tmp );
	}
	for (int i=0; i<num; i++)
	{
		double tmp;
		cin>>tmp;
		b2.push_back( tmp );
	}
	cout<<"Case #"<<n<<": "<<war( b1 , b2 )<<' '<<num-war( b2 , b1 )<<endl;
}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		work( i );
}

