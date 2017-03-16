#include<iostream>
int T[100][100];
int N,M;

void ans(int v=0)
{
	if(v==-1) 
	{
		printf("Impossible\n");
		return;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			if(i+j==0) printf("c");
			else 
			{
				if(T[i][j]) printf("*");
				else printf(".");
			}
		printf("\n");
	}
}
void solve(int test)
{
	int i,j,l,r,R,cnt=0;
	
	printf("Case #%d:\n",test);
	scanf("%d%d%d",&N,&M,&R);
	for(i=0;i<N;i++)
		for(j=0;j<M;j++) T[i][j]=0;
	int K=N*M-R;
	//printf("N=%d M=%d R=%d\n",N,M,R);
	for(i=N-1;i>=2;i--)
		for(j=M-1;j>=2&&cnt<R;j--)
		{
			T[i][j]=1;
			cnt++;
		}
	if(cnt==R) return ans(); 
	if(N<=2||M<=2)
	{
		for(j=M-1;j>=0&&N<=M;j--)
			for(i=N-1;i>=0&&cnt<R;i--)
			{
				T[i][j]=1;
				cnt++;
			}
		for(i=N-1;i>=0&&N>M;i--)
			for(j=M-1;j>=0&&cnt<R;j--)
			{
				T[i][j]=1;
				cnt++;
			}
		if(K==1||(R%2==0&&K>=4)||N==1||M==1) return ans();
		return ans(-1);
	}
	l=0;
	r=0;
	
	while(cnt<R&&R-cnt>=2&&(M-r>2||N-l>2))
	{
		if(N-l>M-r)
		{
			l++;
			T[N-l][0]=T[N-l][1]=1;
		}
		else
		{
			r++;
			T[0][M-r]=T[1][M-r]=1;
		}
		cnt+=2;
	}
	if(cnt==R) return ans();
	if(cnt!=R)
	{
		if(K<=4)
		{
			if(K==1) 
			{
				T[0][1]=T[1][0]=T[1][1]=1;
				return ans();
			}		
			return ans(-1);
		}
		else
		{
			if(R-cnt==1&&(l+3<N||r+3<M))
			{
				T[2][2]=0;
				l++;	r++;
				if(N-l>M-r) T[N-l][0]=T[N-l][1]=1;
				else T[0][M-r]=T[1][M-r]=1;
				return ans();
			}
			return ans(-1);
		}
	}
	ans(-1);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,Tests;
	scanf("%d",&Tests);
	for(i=1;i<=Tests;i++) solve(i);
	return 0;
}