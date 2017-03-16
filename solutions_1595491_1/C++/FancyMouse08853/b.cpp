#include<iostream>
#include<algorithm>
using namespace std;

const int Max = 100;
int main()
{
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		int N, S, p;
		int score[Max];
		cin>>N>>S>>p;
		for(int i=0;i<N;i++)
			cin>>score[i];
		sort(score,score+N);
		int result = 0;
		for(int i=N-1;i>=0 && S>=0;i--)
		{
			if(3*p-2 <= score[i])
			{
				result++;
				continue;
			}
			if(3*p-4 > score[i])
				break;
			if(S == 0)
				break;
			if(p == 1) continue; //surprise useless in this case
			S--;
			result++;
		}
		cout<<"Case #"<<_<<": "<<result<<endl;
	}
	return 0;
}
