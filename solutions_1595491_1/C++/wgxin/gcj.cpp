#include<iostream>
#include<string>
using namespace std;
const int maxn = 101;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int T;
	int N, S, P;
	int ti;
	int score1, score2, score3;
	int ans;
	cin>>T;
	
	for(int cas=1;cas<=T;cas++)
	{
		ans=0;
		cin>>N>>S>>P;
		for(int i=0;i<N;i++)
		{
			cin>>ti;
			
			score1 = ti/3;
			ti -= score1;
			score2 = ti/2;
			score3 = ti - score2;	

			if(score3 >= P)
				ans++;
			else if(S>0 && P-score3==1 && score3==score2 && score2>0)
			{
				ans++;
				S--;
			}
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;;
	}
}