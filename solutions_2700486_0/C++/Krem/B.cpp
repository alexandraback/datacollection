#include<cstdio>

template<typename T>
T abs(T x) {return (x<0)?(-x):x; }

template<typename T>
T min(T a, T b) {return (a<b)?a:b;}

template<typename T>
T turbo_pow(T a, int x)
{
	T res = 1;
	for(int i = 1; i <= x; i<<=1)
	{
		if(x&i)
			res *= a;
		a *= a;
	}
	return res;
}

int main()
{
	int T; scanf("%d",&T);
	for(int ii = 0; ii < T; ii++)
	{
		int N, X, Y;
		scanf("%d %d %d",&N,&X,&Y);
		X = abs(X);
		int layer = (X+Y)/2;
		int l_bot = 2*layer*layer-layer;
		int l_top = 2*(layer+1)*(layer+1)-layer-1;
		double prob;
		if(l_bot >= N)
			prob = 0;
		else if(l_top <= N)
			prob = 1;
		else
		{
			int lol = N - l_bot;
			Y++;
			if((!X) && lol < layer*4+1)
			{
				prob = 0;
			}
			else
			{
			
				double res = 0;
				double cnt = 1./2.;
				double anti = 1.;
				cnt = turbo_pow(cnt,lol);
				for(int i = lol; i >= 0; i--)
				{
					if(i >= 2*layer)
						;
					else if(lol-i >= 2*layer)
						break;
					else
					{
						anti -= cnt;
						if(Y<=i)
							res += cnt;
					}
					cnt = (cnt*i)/(lol-i+1);
				}
				if(Y <= lol - 2*layer)
					prob = 1.;
				else
					prob = res + anti/2;
			}
		}
		printf("Case #%d: %.7f\n", ii+1, prob);
	}
	return 0;
}
