#include <stdio.h>
#include <string.h>
void solve(int);
int main()
{
	freopen("inputB3.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}

long long int abs(long long int k)
{
	return k>0?k:-k;
}
int a;
long long int ans = (long long int)1<<62;
long long ans_X,ans_Y;
char ans_x[20],ans_y[20];
char x[20],y[20];
void func(int k)
{
	long long int first,second;
	char X[20],Y[20];
	for(int i=1;i<=a;i++)
	{
		X[i] = x[i];
		Y[i] = y[i];
	}
	
	//k번째부터 값달라짐
	for(int i=1;i<k;i++)
	{
		if(x[i]=='?'&&y[i]=='?') X[i] = Y[i] = '0';
		else if(x[i]=='?'&&y[i]!='?') X[i] = Y[i];
		else if(y[i]=='?'&&x[i]!='?') Y[i] = X[i];
		else if(x[i]==y[i]);
		else return; // impossible
	}
	if(k==a+1)
	{
		first = second = 0;
		for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
		for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
		if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		return;
	}
	//case 1
	if(x[k]=='?'&&y[k]=='?')
	{
		//X>Y
		X[k] = '1';
		Y[k] = '0';
		for(int i=k+1;i<=a;i++)
		{
			if(x[i]=='?') X[i] = '0';
			if(y[i]=='?') Y[i] = '9';
		}
		first = 0, second = 0;
		for(int i=1;i<=a;i++) first*=10,first+=(long long int)(X[i]-'0');
		for(int i=1;i<=a;i++) second*=10,second+=(long long int)(Y[i]-'0');
		if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		
		//X<Y
		X[k] = '0';
		Y[k] = '1';
		for(int i=k+1;i<=a;i++)
		{
			if(x[i]=='?') X[i] = '9';
			if(y[i]=='?') Y[i] = '0';
		}
		first = second = 0;
		for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
		for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
		if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
	}
	//case 2
	else if(x[k]=='?'&&y[k]!='?')
	{
		//X>Y
		if(y[k]!='9')
		{
			X[k]=Y[k]+1;
			for(int i=k+1;i<=a;i++)
			{
				if(x[i]=='?') X[i] = '0';
				if(y[i]=='?') Y[i] = '9';
			}
			first = second = 0;
			for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
			for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
			if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		}
		//X<Y
		if(y[k]!='0')
		{
			X[k] = Y[k]-1;
			for(int i=k+1;i<=a;i++)
			{
				if(x[i]=='?') X[i] = '9';
				if(y[i]=='?') Y[i] = '0';
			}
			first = second = 0;
			for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
			for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
			if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		}
	}
	// case 3
	else if(x[k]!='?'&&y[k]=='?')
	{
		//X>Y
		if(x[k]!='0')
		{
			Y[k]=X[k]-1;
			for(int i=k+1;i<=a;i++)
			{
				if(x[i]=='?') X[i] = '0';
				if(y[i]=='?') Y[i] = '9';
			}
			first = second = 0;
			for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
			for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
			if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		}
		//X<Y
		if(X[k]!='9')
		{
			Y[k] = X[k]+1;
			for(int i=k+1;i<=a;i++)
			{
				if(x[i]=='?') X[i] = '9';
				if(y[i]=='?') Y[i] = '0';
			}
			first = second = 0;
			for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
			for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
			if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		}
	}
	//case 4
	else
	{
		if(x[k]==y[k]) return;
		if(x[k]>y[k])
		{
			for(int i=k+1;i<=a;i++)
			{
				if(x[i]=='?') X[i] = '0';
				if(y[i]=='?') Y[i] = '9';
			}
			first = second = 0;
			for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
			for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
			if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		}
		if(x[k]<y[k])
		{
			for(int i=k+1;i<=a;i++)
			{
				if(x[i]=='?') X[i] = '9';
				if(y[i]=='?') Y[i] = '0';
			}
			first = second = 0;
			for(int i=1;i<=a;i++) first*=10,first+=X[i]-'0';
			for(int i=1;i<=a;i++) second*=10,second+=Y[i]-'0';
			if(ans>=abs(first-second))
		{
			if(ans==abs(first-second))
			{
				if(ans_X>first || (ans_X==first&&ans_Y>second))
				{
					for(int i=1;i<=a;i++)
					{
						ans_x[i] = X[i];
						ans_y[i] = Y[i];
					}
					ans_X = first;
					ans_Y = second;
				}
			}
			else
			{
				ans = abs(first-second);
				for(int i=1;i<=a;i++)
				{
					ans_x[i] = X[i];
					ans_y[i] = Y[i];
				}
				ans_X = first;
				ans_Y = second;
			}
		}
		}
	}
}
void clear()
{
	ans = (long long int)1<<62;
	for(int i=0;i<=19;i++) ans_x[i]=ans_y[i]=0;
	for(int i=0;i<=19;i++) x[i] = y[i] = 0;
	ans_X = ans_Y = 0;
}
void solve(int T)
{
	clear();
	int i;
	scanf("%s",x+1);
	scanf("%s",y+1);
	a = strlen(x+1);
	for(i=1;i<=a+1;i++) func(i);
	printf("Case #%d: %s %s\n",T,ans_x+1,ans_y+1);
}
