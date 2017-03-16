#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<cmath>

using namespace std;

struct node{
	bool found;
	long long int res;
	long long int number;
};

int pow(int num, int exp)
{
	int out = 1;
	while (exp-- > 0)
		out *= num;
	return out;
}

int Reverse(int num)
{
	int nb_digits = 0;
	while (num / pow(10, nb_digits) > 0)
		++nb_digits;

	int out = 0, iterator = nb_digits;
	while (iterator > 0)
	{
		out += num / pow(10, iterator - 1) * pow(10, nb_digits - iterator);
		num %= pow(10, --iterator);
	}
	return out;
}

int main(){
	int T;
	cin >> T;
	long long int n;
	vector<node> nodes;
	nodes.resize(10000000);
	for (int ti = 1; ti <= T; ti++){
		
		cin >> n;
		for (int i = 0; i < 1000000; i++)
		{
			nodes[i].number = i+1;
			nodes[i].found = false;
			nodes[i].res = 0;
		}
		nodes[0].res = 1;
		nodes[0].found = true;
		
		queue<node> S;
		S.push(nodes[0]);
		
		while (nodes[n - 1].found == false)
		{
			node cn = S.front();
			S.pop();
			if (!nodes[cn.number].found){
				nodes[cn.number].found = true;
				nodes[cn.number].res = cn.res + 1;
				S.push(nodes[cn.number]);
			}
			long long int nn = cn.number;
			while (nn % 10 == 0)
			{
				nn = nn / 10;
			}
			nn = Reverse(nn);
			if (!nodes[nn-1].found){
				nodes[nn-1].found = true;
				nodes[nn-1].res = cn.res + 1;
				S.push(nodes[nn-1]);
			}
		}
		printf("Case #%d: %d\n", ti, nodes[n-1].res);
	}
}