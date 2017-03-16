#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
int T,A,B;
float gl[100000];
float eb[100000];
float ebg(int num)
{
	if(num==A)return (A+B+1);
	int i,j;
	float qg=1.0;
	float mingl;
	float dgv;
	for(i=0;i<A-num;i++)
		qg*=gl[i];
	mingl=qg*(1+num+num+B-A)+(1-qg)*(B+B-A+2+num+num);
	dgv=ebg(num+1);
	if (dgv<mingl)mingl=dgv;
	return mingl;
}
int main()
{
	ifstream cin("A-small-attempt0.in",ios::in);
	ofstream cout("1.txt",ios::out);

	cin>>T;
	int i,j;
	float fnu;
	int enu;
	float gll;
	float minnum;
float dgv;
	for(i=0;i<T;i++)
	{
		gll=1.0;
		cin>>A>>B;
		for(j=0;j<A;j++)
		{
			cin>>gl[j];
			gll*=gl[j];
		}
		enu=2+B;
		fnu=gll*(1+B-A)+(1-gll)*(B+B-A+2);
		minnum=enu;
		if(fnu<minnum)minnum=fnu;
		dgv=ebg(1);
		if(dgv<minnum)minnum=dgv;


		cout<<"Case #"<<i+1<<": ";
		cout<<right<<fixed<<setw(6)<<minnum<<endl;




	}















	return 0;
}