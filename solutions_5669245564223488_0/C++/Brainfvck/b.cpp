#include<iostream>
#include<cstring>
using namespace std;

long long dp[100][100][100];

bool valid(string s)
{
      int map[26] = {0},cur;
      map[s[0] - 'a'] = 1;
      for (int i = 1; i < s.length(); i++)
      {
	    if (map[s[i] - 'a'] > 0 && s[i] != s[i - 1]) return false;
	    map[s[i] - 'a'] = 1;
      }
      return true;
}
int N;
int count;
int used[100];
string s[100];
string curr;
void dfs(int n)
{
      if (n == 0)
      {
	    count ++;
	    return ;
      }
      else
      {
	    for (int i = 0; i < N; i++)
		  if (!used[i] && valid(curr + s[i]))
		  {
			used[i] = 1;
			string tmp = curr;
			curr += s[i];
			dfs(n - 1);
			used[i] = 0;
			curr = tmp;
		  }
      }
}

int main()
{
      int tt;
      cin >> tt;
      for (int ii = 0; ii < tt; ii++)
      {
	    cin >> N;
	    for (int i = 0; i < N; i++)
	    {
		  cin >> s[i];
		  if (!valid(s[i]))
		  {
			cout << "Case #" << ii + 1 << ": " << 0 << endl;
			continue;
		  }
		  else
		  {
			string tmp = "";
			tmp += s[i][0];
			for (int j = 1; j < s[i].length(); j++)
			      if (s[i][j] != s[i][j - 1]) tmp += s[i][j];
			s[i] = tmp;
		  }
	    }
	    memset(used,0,sizeof(used));
	    curr = "";
	    count = 0;
	    dfs(N);
	    cout << "Case #" << ii + 1 << ": " << count << endl;
      }
      return 0;
}
