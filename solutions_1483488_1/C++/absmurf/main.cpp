#include<iostream>
#include<string>
#include<set>
#define REP(i,n) for(long i=0;i<n;i++)

using namespace std;

long int recycle(long num, long base)
{
	long digits=1;
	while(num>=pow(float(10),digits)) digits++;
	long pb=long (pow(float(10),base));
	if(num%pb<pb/10) return -1;
	long out=(num%pb)*pow(float(10),digits-base)+long(num/pb);
	return out;
}

int main()
{
	long T,A,B;
	cin>>T;
	set<pair<long,long>> out;
	long cur_digits,counter,temp;
	REP(i,T)
	{
		out.clear();
		cin>>A>>B;
		cur_digits=1;
		while(A>=pow(float(10),float(cur_digits))) cur_digits++;
		counter=0;
		for(long j=A;j<=B;j++)
		{
			for(long k=1;k<cur_digits;k++) 
			{
				temp=recycle(j,k);
				if(temp!=j&&temp>=A&&temp<=B&&temp>j)
					out.insert(pair<long,long>(j,temp));
			}
		}
		counter=out.size();
		printf("Case #%Ld: %Ld\n",i+1,counter);
	}
	cin.ignore();
	cin.get();
	return 0;
}