#include <iostream>
#include <stdio.h>
#include <map>
#include <list>
using namespace std;

map<int,bool> dicsum;
map<int,string> check;
int c[100];
string res1;
string res2;
int n;

bool find(string s,int sum,int i)
{
	if (i>=n)
		return false;

	if (dicsum[sum] && strcmp(check[sum].c_str(),s.c_str())!=0)
	{
		res1=check[sum];
		res2=s;
		return true;
	}
	int sum1=sum+c[i];
	string str1=s;
	if (s.length()!=0)
		str1.append(" ");
	char cc[10];
	sprintf(cc,"%d",c[i]);
	str1.append(cc);
	if (dicsum[sum1] && strcmp(check[sum1].c_str(),s.c_str())!=0)
	{
		res1=check[sum1];
		res2=str1;
		return true;
	}
	dicsum[sum1]=true;
	check[sum1]=str1;
	if (find(str1,sum1,i+1))
		return true;
	if (find(s,sum,i+1))
		return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		dicsum.clear();
		check.clear();
		cin>>n;
		for (int j=0;j<n;j++)
			cin>>c[j];

		printf("Case #%d:\n",i);
		if (find("",0,0))
		{
			list<int> l1,l2;
			int pos;
			int tmp;
			sscanf(res1.c_str(),"%d",&tmp);
			l1.push_back(tmp);

			while((pos=res1.find(' '))!=-1)
			{
				res1=res1.substr(pos+1,res1.length()-pos);
				sscanf(res1.c_str(),"%d",&tmp);
				l1.push_back(tmp);
			}

			sscanf(res2.c_str(),"%d",&tmp);
			l2.push_back(tmp);

			while((pos=res2.find(' '))!=-1)
			{
				res2=res2.substr(pos+1,res2.length()-pos);

				sscanf(res2.c_str(),"%d",&tmp);
				l2.push_back(tmp);
			}

			map<int,int> dic;
			list<int>::iterator ls;
			for (ls=l1.begin();ls!=l1.end();ls++)
				dic[*ls]++;
			for (ls=l2.begin();ls!=l2.end();ls++)
				dic[*ls]++;
			bool space=false;
			for (ls=l1.begin();ls!=l1.end();ls++)
			{
				if (dic[*ls]==1)
				{
					if (space)
						printf(" ");
					else
						space=true;
					printf("%d",*ls);
				}
			}
			printf("\n");
			space=false;
			for (ls=l2.begin();ls!=l2.end();ls++)
			{
				if (dic[*ls]==1)
				{
					if (space)
						printf(" ");
					else
						space=true;
					printf("%d",*ls);
				}
			}
			printf("\n");
			
		}
		else 
			printf("Impossible\n");
		//cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}