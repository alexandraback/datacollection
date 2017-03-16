#include <iostream>

using namespace std;

const int MAXN = 200;


int digits[10];

void mark_digits(int k)
{
	if(k==0){
		digits[0]=1;
		return;
	}
		
	while(k>0)
	{
		digits[k%10]=1;
		k/=10;
	}
}

bool check()
{
	for(int i=0;i<10;i++)
		if(digits[i]==0)
			return false;
	return true;
}


int solve(int n)
{
	for(int i=0;i<10;i++)
		digits[i]=0;
	for(int i=1;i<100000;i++) {
		mark_digits(i*n);
		if(check())
			return i*n;
	}
	return -1;
}

int main() 
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		int r = solve(n);
		cout << "Case #" << i+1 << ": ";
		if(r>=0)
			cout << r;
		else
			cout << "INSOMNIA";
		cout << endl;
	}
	return 0;
}
