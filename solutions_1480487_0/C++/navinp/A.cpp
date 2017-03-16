#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int  main()
{
	int no,tc;
	scanf(" %d",&no);
	for(tc=1;tc<=no;tc++){
		printf("Case #%d:",tc);
	int n,i;
	scanf(" %d",&n);
	vector<int> v;
	int y;
	double S=0;
	const double MYEPS=1e-9;
	for(i=0;i<n;i++) {
		scanf(" %d",&y); v.push_back(y);
		S+=y;
	}
	vector< double> D;
	double TOT=0;
	for(i=0;i<n;i++)
	{
		if(i==0) D.push_back(0);
		else D.push_back( (v[0]-v[i])*1./S);
		TOT+=D[i];
	}
	double x=(1-TOT)*1./n;
	vector<double > ans;
	double FTOT=0;
	for(i=0;i<n;i++) {
		if((x+D[i])*100 >MYEPS)  ans.push_back((x+D[i])*100);
		else ans.push_back(0);
		FTOT+=ans[i];
	}
	for(i=0;i<n;i++)
		printf(" %.5f",ans[i]*100./FTOT);
	printf("\n");

	
	
	}
	return 0;
}
