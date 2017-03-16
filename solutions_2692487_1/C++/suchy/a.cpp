#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long K;
	cin >> K;
	for (int k = 0; k < K; ++k)
	{
		unsigned long long a, a2, n, ops1, ops2;
		ops1 = 0; ops2 = 0;

		cin >> a >> n;
		a2 = a;
		vector<unsigned long long> v = vector<unsigned long long>(n);
		stack<unsigned long long> q = stack<unsigned long long>();

		for (long long i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		//sort
		sort(v.begin(), v.end());
		for (long long i = n-1; i >= 0; --i)
		{
			q.push(v[i]);
			//cout << v[i] << endl;
		}

		stack<unsigned long long> q2(q);
		//absorb / take / add
		while (!q.empty())
		{
			//cout << "a is " << a << " top is " << q.top();
			if(q.top() < a){
				a += q.top();
				q.pop();
				//cout << " - used it" << endl;
			} else {
				if(a + (a-1) > q.top()){
					q.push(a-1); //i'll use this
					//cout << " - pushed " << a-1 << endl;
				} else {
					//cout << " - removed it" << endl;
					q.pop(); //remove it
				}
				ops1++;
			}
		}
		//cout << "trying approach 2" << endl;
		while (ops1 != 0 && !q2.empty())
		{
			//cout << "a is " << a2 << " top is " << q2.top();
			if(q2.top() < a2){
				a2 += q2.top();
				q2.pop();
				//cout << " - used it" << endl;
			} else {
				if(a2-1 > 0) q2.push(a2-1); //i'll use this
				//cout << " - pushed " << a2-1 << endl;

				ops2++;
				if(ops2 > ops1)
					break;
			}
		}
		cout << "Case #" << k+1 << ": " << min(ops1,ops2) << endl;
	}
}