#include<iostream>
#include<fstream> 
#include <iomanip>
using namespace std;

int main()
{
	ifstream f1;
	ofstream f2;
	f1.open("E:\\code jam\\q4\\D-small-attempt0.in");
	f2.open("E:\\code jam\\q4\\1.out");
	int n;
	f1>>n;
	int i,t,j,p,q,a,b;
	int fore,back;
	double weightA[1100],weightB[1100],temp;
	for (i=1;i<=n;i++)
	{
		f1>>t;
		for (j=0;j<t;j++) f1>>weightA[j];
		for (j=0;j<t;j++) f1>>weightB[j];
		for (p=0;p<t;p++)//sort
		{
			for (q=p;q<t;q++)
			{
				if (weightA[p]>weightA[q])
				{
					temp=weightA[p];
					weightA[p]=weightA[q];
					weightA[q]=temp;
				}
				if (weightB[p]>weightB[q])
				{
					temp=weightB[p];
					weightB[p]=weightB[q];
					weightB[q]=temp;
				}
			}
		}
		b=t-1;a=t-1;
		back=0;fore=0;
		while ((a>=0) && (b>=0))
		{
			while (weightB[b]<weightA[a])
			{
				a--;
				if (a<0) break;
			}
			if (a>=0) back++;
			b--;
			a--;
		}
		b=0;a=0;
		while ((a<t) && (b<t))
		{
			while (weightB[b]>weightA[a])
			{
				a++;
				if (a>=t) break;
			}
			if (a<t) fore++;
			b++;
			a++;
		}
		f2<<"Case #"<<i<<": "<<fore<<" "<<t-back<<endl;
	}
}
