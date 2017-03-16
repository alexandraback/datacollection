#include <iostream>
#include <fstream>
using namespace std;

void test(int t)
{
	int K,C,S;
	cin >> K >> C >> S;
	cout << "Case #" << t << ":";
	for(int i=0;i<K;i++) cout << ' ' << i+1;
	cout << '\n';
}

int main()
{
	freopen("testin.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	int T;
	cin >>  T;
	for(int i=0;i<T;i++) test(i+1);
}