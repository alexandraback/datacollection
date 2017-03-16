#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool calNum(int a,int b)
{
	string sa="";
	string sb="";
	int t;
	char tc;
	while(a>=1)
	{
		t=a%10;
		tc='0'+t;
		sa=tc+sa;
		a=a/10;
	}
	while(b>=1)
	{
		t=b%10;
		tc='0'+t;
		sb=tc+sb;
		b=b/10;
	}

	bool flag=false;
	string left,right;
	for(int i=1;i<sa.size();i++)
	{
		 left=sa.substr(0,i);
		 right=sa.substr(i,sa.size()-i);
		 left=right+left;
		 if(left==sb)
		 {
			 flag=true;break;
		 }
	}
	return flag;
}

int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("out.txt");

	int T,A,B,i,j,k,result;
	fin>>T;
	for(i=0;i<T;i++)
	{
		fin>>A>>B;
		result=0;
		for(j=A;j<B;j++)
		{
			for(k=j+1;k<=B;k++)
			{
				if(calNum(j,k))
					result++;
			}
		}
		cout<<"Case #"<<i+1<<": "<<result<<endl;
		fout<<"Case #"<<i+1<<": "<<result<<endl;
	}

	return 0;
}