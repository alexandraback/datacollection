#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long a[100000],ta[10000];
int t[10000];
int  infinity = 1000000000;

int calc(long long A,long long B,long long &AA)
{
	int k=0;
	while(A<=B) 
	{
		if(A==1) 
		{
			AA=-1;
			return infinity;
		}
		A+=(A-1);
		k++;
	}
	AA=A;
	return k;
}


void solve(int T)
{
	int N,k,answer,i,j,temp;
	long long A,AA;
	scanf("%I64d%d",&A,&N);
	for(i=0;i<N;i++) scanf("%I64d",&a[i]);
	sort(a,a+N);

	for(i=0;i<N;i++)
		t[i]=infinity;
	for(i=0;i<N;i++)
	{
		t[i]=calc(A,a[i],AA)+i;
		ta[i]=AA+a[i];
		for(j=0;j<i;j++)
		{
			if(t[j]==infinity) continue;
			temp=calc(ta[j],a[i],AA)+t[j]+(i-j-1);
			if(t[i]>temp||(t[i]==temp&&ta[i]<AA))
			{
				t[i]=temp;
				ta[i]=AA+a[i];
			}
		}
	}
	answer=N;
	for(i=0;i<N;i++)
		answer=min(answer,t[i]+(N-i-1));
	printf("Case #%d: %d\n",T,answer);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,T;
	scanf("%d",&T);
	for(i=1;i<=T;i++) solve(i);
	return 0;
}
