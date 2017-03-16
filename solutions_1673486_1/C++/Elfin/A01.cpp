#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<cstring>

using namespace std;


void inputp(vector<double> &p, int &A, int &B)
{	
	for(int i=0;i<A;i++)
	{
		scanf("%lf", &p[i]);
	}
}

void init(const vector<double> &p, const int A, vector<double> &pminb)
{
	pminb[A]=1;

	for(int minb=A-1; minb>=0; minb--)
	{
		pminb[minb]=pminb[minb+1]*p[A-minb-1];
	}

	for(int minb=A; minb>0; minb--)
	{
		pminb[minb]*=(1-p[A-minb]);
	}
}

double calc(const int A,const int B, vector<double> &pminb)
{
	vector<double> expected(A+2);
	for(int b=0; b<=A; b++)
	{
		for(int minb=0; minb<=A; minb++)
		{
			int keystrokes = (b>=minb)? (B-A+1+2*b): (B-A+1+2*b+B+1);
			expected[b]+= keystrokes * pminb[minb];
		}

	}
	expected[A+1]=B+2;
	return *min_element(expected.begin(), expected.end());
}


int main()
{
	freopen("D:\\Users\\theaa\\Downloads\\A-large.in","r",stdin);
	freopen("D:\\Users\\theaa\\Downloads\\A-large.out","w",stdout);
	int T;
	cin>>T;
	
	for(int caseno=1; caseno<=T; caseno++)
	{
		int A, B;
		cin>>A>>B;
		vector<double> p(A);
		vector<double> pminb(A+1);

		inputp(p, A, B);
		init(p, A, pminb);
		printf("Case #%d: ", caseno);
		printf("%.6lf\n", calc(A, B,  pminb) );
	}


	return 0;
}