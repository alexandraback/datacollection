#include<iostream>
#include<cstdio>
using namespace std;

int ile[1000005];

int reverse(int a) 
{
	int ret = 0;
	while(a > 0) 
	{
		ret = 10*ret + (a%10);
		a/=10;
		}
	return ret;
	}

int main() {
	ios_base::sync_with_stdio(0);
	int testy, n;
	
	for(int i=1; i<=10; i++) ile[i] = i;
	
	for(int i=11; i<=1000000; i++) 
	{
		if(reverse(i) < i && (i % 10 != 0)) ile[i] = min(ile[i-1], ile[reverse(i)]) + 1;
		else ile[i] = ile[i-1] + 1;
		}
	
	cin >> testy;
	for(int i=1; i<=testy; i++)
	{
		cin >> n;
		cout << "Case #" << i << ": " << ile[n] << endl;
		}
	return 0;
}
