#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cassert>
#include <climits>
#include <algorithm>


using namespace std;

vector <long long> D;
int solve();

vector <int> decompose(long long a)
{
	vector <int> ans;
	while(a)
	{
		ans.push_back(a%10);
		a/=10;
	}
	return ans;
}

double search(int head, int tail, long long key)
{
	if(head == tail)
		if(D[head] > key)
			return head + 0.5;
		else
			return head - 0.5;
	
	if(head + 1 == tail)
		if(D[head] == key)
			return head;
		else if(D[tail] == key)
			return tail;
		else
			return head + 0.5;

	int mid = (head+tail)/2;
	if(D[mid] > key)
		return search(head, mid, key);
	else if(D[mid] < key)
		return search(mid, tail, key);
	else
		return mid;
}

bool isPalindrome(vector <int> a)
{
	for(int i=0; i<a.size(); i++)
		if(a[i] - a[a.size()-1-i])
			return false;
	return true;
}

int main()
{
	for(long long i=1; i<=10000000; i++)
	{
		if(!isPalindrome(decompose(i))) continue;
		if(!isPalindrome(decompose(i*i))) continue;
		D.push_back(i*i);
//		cout << i*i << "\t" << i << endl;
	}

	int T;
	cin >> T;
	for(int i=1; i<=T; i++)
		cout << "Case #" << i << ": " << solve() << endl;
}

int solve()
{
	long long A, B;
	cin >> A >> B;
	return floor(search(0,D.size(),B)) - ceil(search(0,D.size(),A)) + 1;	
}




