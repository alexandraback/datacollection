#include<iostream>
#include<algorithm>
using namespace std;

const int inf = 1000;//*1000*10;
int T[inf];
int pr[inf];

typedef long long lint;
lint rev(lint n)
{
	lint v = 0;
	while(n)
	{
		v = v*10+(n%10);
		n/=10;
	}
	return v;
}

void ans(int N, bool v=false)
{
	if(N) 
	{
			
			ans(pr[N]);
		if(pr[N]!=N-1) printf("%d ",N);
	}
	
}

lint solve(lint a,lint b)
{
	return (b-a)+1;
}
lint arr_a[10000000+10];
lint arr_b[10000000+10];
int v[1000];
void solve(int test)
{
	lint N;
		scanf("%I64d",&N);

	int cnt = 0;
	lint nn = N;
	while(nn!=0)
	{
		v[cnt]=nn%10;
		cnt++;
		nn/=10;
	}

	lint p = 10, b,a;
	int col = 0;
	arr_a[0]=1;
	arr_b[0]=1;
	col++;
	for(int i = 1; i < cnt;i++)
	{
		lint last_a=p;
		lint last_b= inf;
		lint k = 1;
		a = p;
		for(int j= 0; j < i; j++)
		{
			a += 9*k;
			b=rev(a);
			if(j!=0 && solve(last_b,b) < solve(last_a,a))
			{
				//last_a;
				break;
			}
			last_a = a;
			last_b = b;
			k*=10;
		}
		if(last_a <= N && last_b <= N) 
		{
			arr_a[col]=last_a;
			arr_b[col]=last_b;
			col++;
		}		

		p*=10;
	}
	a=0;
	for(int i = cnt-1; i >= cnt/2; i--)
	{
		a = a*10+v[i];
	}
	lint c = 0;
	for(int i = cnt/2-1; i >= 0; i--)
	{
		c = c*10+v[i];
	}
//	printf("c = %I64d\n",c);
	if(c==0) a--;
	for(int i = cnt/2-1; i >= 0; i--)
		a*=10;
	a++;
	b = rev(a);
	swap(a,b);
	if(a<b && a<=N && b <=N)
	{
		if(a > arr_b[col-1] && b > arr_b[col-1])
		{
			arr_a[col]=a;
			arr_b[col]=b;
			col++;
		}
	}
	lint answer = 0;
	for(int i = 0 ; i < col; i++)
	{
		if(i) 
		{
	//		printf("[%I64d; %I64d] %I64d\n",arr_b[i-1],arr_a[i],solve(arr_b[i-1], arr_a[i]));
			answer += solve(arr_b[i-1], arr_a[i]);
		}
		//answer += solve(arr_a[i], arr_b[i]);
		//printf("[%I64d; %I64d]\n",arr_a[i],arr_b[i],solve(arr_a[i], arr_b[i]));

	}
	answer += solve(arr_b[col-1], N);
//	cout << "answer: " << answer << endl;
	
	
//	printf("\n");
	printf("Case #%d: %I64d\n",test,answer);
	//ans(N);
	//printf("\n\n");
	
}




int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	T[1]=1;
	for(int i = 2; i <= inf&&0; i++)
	{
		if(T[i])
		{
			if(T[i] > T[i-1]+1)
			{
				pr[i]=i-1;
			}
			T[i]=min(T[i],T[i-1]+1);
		}
		else
		{
			T[i]= T[i-1]+1;
			pr[i] = i-1;
		}
		lint j = rev(i);
		if(j <= i) continue;
		if(T[j])
		{
			if(T[j]>T[i]+1)
			{
				pr[j]=i;
			}
			T[j] = min(T[j], T[i]+1);
		}
		else 
		{
			T[j]=T[i]+1;
			pr[j]=i;
		}
	}
	int tt;
	scanf("%d",&tt);
	for(int i = 1; i<=tt;i++) solve(i);
	return 0;
}