#include<iostream>
#include<string>
#include<set>
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;

int recycle(int num, int base)
{
	int digits=1;
	while(num>=pow(float(10),digits)) digits++;
	int pb=int(pow(float(10),base));
	if(num%pb<pb/10) return -1;
	int out=(num%pb)*pow(float(10),digits-base)+int(num/pb);
	return out;
}

int main()
{
	int T,A,B;
	cin>>T;
	set<pair<int,int>> out;
	long int cur_digits,counter,temp;
	REP(i,T)
	{
		out.clear();
		cin>>A>>B;
		cur_digits=1;
		while(A>=pow(float(10),cur_digits)) cur_digits++;
		counter=0;
		for(int j=A;j<=B;j++)
		{
			for(int k=1;k<cur_digits;k++) 
			{
				temp=recycle(j,k);
				if(temp!=j&&temp>=A&&temp<=B&&temp>j)
					out.insert(pair<int,int>(j,temp));
			}
		}
		counter=out.size();
		printf("Case #%d: %d\n",i+1,counter);
	}
	cin.ignore();
	cin.get();
	return 0;
}