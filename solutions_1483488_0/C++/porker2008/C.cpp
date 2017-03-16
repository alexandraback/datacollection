#include <iostream>
using namespace std;

int A,B,len,m;

bool set[2000001];

int check(int t)
{
	set[t] = true;
	int num = 1;
	for(int i=1;i<len;i++)
	{
		int temp = t%10;
		t/=10;
		t+=m*temp;
		if(set[t]==false)
		{
			set[t] = true;
			if(A<=t&&t<=B)
				num++;
		}
		else
			break;
	}
	return (num)*(num-1)/2;
}

int main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		memset(set,0,sizeof(set));
		cin >> A >> B;
		int temp = A;
		len = 0;
		m = 1;
		while(temp)
		{
			len++;
			temp/=10;
			m *= 10;
		}
		m/=10;
		int result = 0;
		for(int j=A;j<=B;j++)
		{
			if(set[j])
				continue;
			result += check(j);
		}
		cout << "Case #" << i << ": " << result << endl;
	}
}
