#include "iostream"

using namespace std;

int main()
{
	freopen("1.out", "w", stdout);
	int t,i,j,k,sum,id = 1,s,res,p,n;
	
	cin >> t;
	while(t--)
	{
		cin >> n >> s >> p;
		res = 0;
		for(i = 0;i < n; i++)
		{
			cin >> sum ;

			if((sum + 2) / 3 >= p)
				res ++;
			else if(sum >= 2 &&(sum + 4) / 3 >= p && s > 0)
			{
				res++;
				s --;
			}

		}
		
		cout <<"Case #" << id++ <<": " << res << endl;
	}
}
