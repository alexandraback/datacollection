#include<iostream>
#include<deque>
using namespace std;

bool pass[1001];
int inh[1001][11];

deque<int> togo;

bool run(int n)
{
	int i, j, now;
	for(i = 1; i <= n; i++)
	{
		if(inh[i][0] == 0) continue;
		
		//cout << "running from " << i << endl;
	
		for(j = 1; j <= n; j++)
			pass[j] = 0;
		
		togo.clear();
		togo.push_back(i);
		
		while(!togo.empty())
		{			
			now = togo.front();
			togo.pop_front();
			
			//cout << " passing " << now << endl;
			
			if(pass[now]) return true; //{ cout << "!\n";  return true; }
			pass[now] = 1;
			
			for(j = 1; j <= inh[now][0]; j++)
				togo.push_back(inh[now][j]);
		}
	}
	
	return false;
}

int main()
{
	int T, t = 0, n, i, j;
	bool res;
	
	for(cin >> T; T--;)
	{
		cin >> n;
		
		for(i = 1; i <= n; i++)
		{
			cin >> inh[i][0];
			for(j = 1; j <= inh[i][0]; j++)
				cin >> inh[i][j];
		}
		
		printf("Case #%d: ", ++t);
		
		cout << (run(n) ? "Yes" : "No") << endl;
	}
}