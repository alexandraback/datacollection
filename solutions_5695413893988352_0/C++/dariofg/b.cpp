#include <iostream>
#include <vector>
#include <string>
#include <math.h>

//#define abs(a) (a)>0?(a):(-a)

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int I=1;I<=T;I++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		cout << "Case #" << I << ": ";
		vector<pair<int,int> > poss;
		pair<int,int> p;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]=='?')
			{
				p.first = i;
				p.second = 1;
				poss.push_back(p);
			}
			if(s2[i]=='?')
			{
				p.first = i;
				p.second = 2;
				poss.push_back(p);
			}
		}
		int num=1;
		int rec1,rec2;
		for(int i=0;i<poss.size();i++,num*=10);
		for(int i=0;i<num;i++)
		{
			int a = i;
			for(int j=0;j<poss.size();j++)
			{
				p = poss[j];
				if(p.second==1)
					s1[p.first]='0'+a%10,a/=10;
				else
					s2[p.first]='0'+a%10,a/=10;
			}
			int aa=0,bb=0;
			for(int j=0;j<s1.size();j++)
			{
				aa*=10;
				bb*=10;
				aa+=int(s1[j]-'0');
				bb+=int(s2[j]-'0');
				//cout << aa << bb << endl;
			}
			if(!i)
				rec1=aa,rec2=bb;
			if(fabs(bb-aa)<fabs(rec2-rec1))
				rec1=aa,rec2=bb;
			else if((fabs(bb-aa)==fabs(rec2-rec1)))
			{
				if(aa<rec1)
					rec1=aa,rec2=bb;
				else if(aa==rec1)
					if(bb<rec2)
						rec1=aa,rec2=bb;
			}
			//if((abs(bb-aa)<abs(rec2-rec1)) ||((abs(bb-aa)==abs(rec2-rec1)) && (aa<rec1) )|| ((abs(bb-aa)==abs(rec2-rec1)) && (aa==rec1) && (bb<rec2)))
			//	rec1=aa,rec2=bb;
		}
		for(int i=0;i<s1.size();i++)
		{
			s1[s1.size()-1-i] = '0'+rec1%10;
			s2[s2.size()-1-i] = '0'+rec2%10;
			rec2/=10;
			rec1/=10;
		}
		cout << s1 << " " << s2 << endl;
	}
}
