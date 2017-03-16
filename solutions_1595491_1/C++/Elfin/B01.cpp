#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<iostream>
#include<stdio.h>

using namespace std;

int satisfy_cost_s(int point, const int p)
{
	int remainder=point%3;
	int quotient=point/3;

	if(remainder==0)
	{
		if(quotient>=p) return 0;
		if(quotient+1>=p&&quotient>0) return 1;
	}
	else if(remainder==1)
	{
		if(quotient+1>=p) return 0;
	}
	else if(remainder==2)
	{
		if(quotient+1>=p) return 0;
		if(quotient+2>=p) return 1;
	}
	return -1;
}

int count_max_satisfy(const vector<int> &points, const int S, const int p)
{
	int cnt=0;
	int s_remain=S;
	for(int i=0;i<points.size();i++)
	{
		int cost_s = satisfy_cost_s(points[i], p);
		if(cost_s==-1) continue;
		else if(cost_s==0) cnt++;
		else if(cost_s==1&&s_remain>0)
		{
			s_remain-=cost_s;
			cnt++;
		}

	}
	return cnt;
}


int main()
{
	freopen("C:\\Users\\theaa\\Downloads\\B-large.in","r",stdin);
	freopen("C:\\Users\\theaa\\Downloads\\B-large.out","w",stdout);
	int T;
	cin>>T;
	
	for(int caseno=1; caseno<=T; caseno++)
	{
		int N,S,p;

		//input
		cin>>N>>S>>p;
		vector<int> points(N);
		for(int i=0;i<N;i++)
		{
			cin>>points[i];
		}
		//input

		int cnt_max = count_max_satisfy(points, S, p);

		cout<<"Case #"<<caseno<<": "<<cnt_max<<endl;
	}


	return 0;
}