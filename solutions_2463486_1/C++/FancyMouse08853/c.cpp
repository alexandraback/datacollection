#include<iostream>
#include<cstring>
using namespace std;

const int Max = 105;
int limit[Max], len;
int Compute(int* data, int i, int curlen)
{
	{
		int temp[Max];
		memset(temp,0,sizeof(temp));
		for(int x=0;x<curlen;x++)
			for(int y=0;y<curlen;y++)
				temp[x+y] += data[x] * data[y];
		// bad if we have carry
		for(int x=0;x<2*curlen-1;x++)
			if(temp[x] >= 10)
				return 0;
		// bad if we exceed threshold
		for(int x=len-1;x>=0;x--)
			if(temp[x] < limit[x])
				break;
			else if(temp[x] > limit[x])
				return 0;
	}
	if(i > curlen-1-i)
	{
		/*
		for(int j=curlen-1;j>=0;j--)
			cout<<data[j];
		cout<<endl;
		*/
		return 1;
	}
	int start = i==0 ? 1 : 0;
	int top = curlen==1 ? 3 : 2;
	int result = 0;
	for(int j=start;j<=top;j++)
	{
		data[i] = data[curlen-1-i] = j;
		result += Compute(data, i+1, curlen);
		data[i] = data[curlen-1-i] = 0;
	}
	return result;
}
int Compute(char* buf)
{
	len = strlen(buf);
	memset(limit,0,sizeof(limit));
	for(int i=0;i<len;i++)
		limit[len-1-i] = buf[i] - '0';
	int result = 0;
	int data[Max];
	for(int i=1;2*i-1<=len;i++)
	{
		memset(data,0,sizeof(data));
		result += Compute(data, 0, i);
	}
	return result;
}
int main()
{
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		char buf[Max];
		cin>>buf;
		if(buf[strlen(buf)-1] != '0')
			buf[strlen(buf)-1]--;
		int result = -Compute(buf);
		cin>>buf;
		result += Compute(buf);
		cout<<"Case #"<<_<<": "<<result<<endl;
	}
	return 0;
}
