#include <iostream>
using namespace std;

typedef long long LINT;

LINT xn[100],xm[100];
int tn[100],tm[100];

int n,m;

LINT Calc(LINT cxn, int ctn, int nn, LINT cxm, int ctm, int mm)
{
	if(nn>n || mm>m)
		return 0;

	if(ctn==ctm)
	{
		if(cxn==cxm)
			return cxn+Calc(xn[nn],tn[nn],nn+1,xm[mm],tm[mm],mm+1);
		else if(cxn>cxm)
			return cxm+Calc(cxn-cxm,ctn,nn,xm[mm],tm[mm],mm+1);
		else 
			return cxn+Calc(xn[nn],tn[nn],nn+1,cxm-cxn,ctm,mm);
	}

	LINT sol1=0;
	LINT sol2=0;
	int i;
	for(i=mm; i<m; i++)
		if(tm[i]==ctn)
			break;
	sol1=Calc(cxn,ctn,nn,xm[i],tm[i],i+1);
	sol2=Calc(xn[nn],tn[nn],nn+1,cxm,ctm,mm);

	return max(sol1,sol2);
}


void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		cin>>n>>m;

		for(int i=0; i<n; i++)
			cin>>xn[i]>>tn[i];
		for(int i=0; i<m; i++)
			cin>>xm[i]>>tm[i];

		LINT sol=Calc(xn[0],tn[0],1,xm[0],tm[0],1);
		cout<<"Case #"<<ii+1<<": "<<sol<<endl;
	}
}