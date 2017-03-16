#include <iostream>

using namespace std;

void Evaluar(int &S,int p, int t,int &ans)
{
	
	int media,resto;
	media=t/3;
	resto=t%3;
	if(media >= p)
	{
		ans++;
	}
	else
	{
		if(resto>0)
		{
			if(media+1 == p)
				ans++;
			else
			{
				if(S>0)
				{
					if( (resto ==2) && (resto + media == p) )
					{
						ans++;
						S--;
					}
				}
			}
		}
		else
		{
			if( (S>0) && (media != 0 ) && (media +1 ==p) )
			{
				ans++;
				S--;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	freopen("s.in","rt+",stdin);
	freopen("s.out","w+",stdout);
	cin.sync_with_stdio(false);
	int N,T,S,p,t,ans,caso=1;
	cin>>N;
	while(N--)
	{
		cin>> T >> S >> p;
		ans=0;
		while(T--)
		{
			cin>>t;
			Evaluar(S,p,t,ans);
		}
		cout<<"Case #"<<caso<<": "<<ans<<'\n';
		caso++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

