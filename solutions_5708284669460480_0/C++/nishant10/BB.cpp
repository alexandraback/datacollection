#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define f first
#define s second
#define pb push_back

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

//freopen("in.txt","r",stdin); 
//freopen("out.txt","w",stdout); 
int A[30];
double prob[30];
double Ans[100];
int mark[30];
string str2,str1;
char str[40];
vector<int> vec;
int k,l,s;

void search1(int cnt,double val)
{
	int sz,i,x,j,cnt1;	
	
	
	cnt1 = 0;
	//printf("%lf\n",val);
	sz =  str2.size();  
	for(i = 0;i < cnt;i++)
	{
		x = i;
		//printf("%c",str[i]);
		for(j = 0;j < sz && (x+j) < cnt;j++)
		{	
			if(str[x+j] != str2[j])
			{
				break;
			}

		}
		if(j == sz)
		{
			cnt1++;
		}
		
	}
	//printf("\n");
	Ans[cnt1] += val;
	
}

void func(int cnt,double val)
{
	int i,sz;
	if(cnt == s)
	{
		search1(cnt,val);
		return;		

	}
	
	sz= vec.size();
	for(i = 0;i < sz;i++)
	{		
			str[cnt] = vec[i] + 'A';
			func(cnt+1,val*prob[vec[i]]);
	}
	
}

double calculate()
{
	double ans;	

	ans = 0.0;
	int max,i;
	max = 0;
	for(i = 1;i <= 7;i++)
	{
		if(Ans[i] > 0.00000000)
		{
			max = i;
		}
	}
	for(i = 0;i < max;i++)
	{
			ans += (max-i)*Ans[i];
	}
	return ans;
	

}

int main()
{
	int t,i,sz,cnt,idx;
	double sol;
	
	scanf("%d",&t);
	idx = 1;
	while(t--)
	{
		scanf("%d %d %d",&k,&l,&s);
		cin>>str1;
		cin>>str2;
		sz = str1.size();
		  
		for(i = 0;i < sz;i++)
		{
			A[str1[i]-'A']++;
			if(mark[str1[i] - 'A'] == 0)
			{	
				vec.pb(str1[i] - 'A');
			}
			mark[str1[i] - 'A'] = 1;
		}
		for(i = 0;i < 26;i++)
		{
			prob[i] = ((double)A[i])/sz;
		}
		for(i = 0;i < 26;i++)
		{
			if(mark[i])
			{
				cnt = 1;
				str[cnt-1] = 'A' + i; 
				func(cnt,prob[i]);
			}
		}


		sol = calculate();
		printf("Case #%d: %0.7lf\n",idx,sol);
		vec.clear();
		memset(Ans,0,sizeof(Ans));
		memset(mark,0,sizeof(mark));
		memset(A,0,sizeof(A));
		idx++;

	}	

	return 0;
}
