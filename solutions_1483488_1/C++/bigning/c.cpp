#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;

	ofstream fout("out.txt");

int calNum(int A,int B)
{
	string sa,strTemp,left,right;
	int result=0;
	int temp,t;
	char tc;
	for(int mmm=A;mmm<B;mmm++)
	{
		set<int> sss;
		int i=mmm;
		sa="";
		//strTemp="";
		while(i>=1)
		{
			t=i%10;
			tc='0'+t;
			sa=tc+sa;
			i=i/10;
		}
		for(int k=1;k<sa.size();k++)
		{
			if(sa[k]<sa[0])
				continue;
			left="";
			right="";
			left=sa.substr(0,k);
			right=sa.substr(k,sa.size()-k);
			strTemp=right+left;
			
			temp=0;
			int tt=1;
			for(int m=strTemp.size()-1;m>=0;m--)
			{
				temp+=(tt*(strTemp[m]-'0'));
				tt=tt*10;
			}
			if(temp>mmm && temp<=B)
			{
				sss.insert(temp);
			}
		}
		result+=sss.size();
	}
	return result;

}

int main()
{
	ifstream fin("C-large.in");

	int T,A,B;
	fin>>T;
	for(int i=0;i<T;i++)
	{
		fin>>A>>B;
		int tttt=calNum(A,B);
		cout<<"Case #"<<i+1<<": "<<tttt<<endl;
		fout<<"Case #"<<i+1<<": "<<tttt<<endl;
	}

	return 0;
}