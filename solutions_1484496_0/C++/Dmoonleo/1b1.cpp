#include<iostream>
#include<list>
using namespace std;

class subset
{
	public:
	int sum;
	int num;
	subset()
	{
		sum = 0;
		num = 0;
	}
	
};

bool compare(subset A, subset B)
{
	if(A.sum > B.sum) return false;
	return true;
}

int main()
{
	int T = 0;
	cin >> T;
	//int c = 0;
	for(int i = 0; i < T; i++)
	{
		int A[20];
		int dummy = 20;
		cin >> dummy;
		list<subset> B;
		for(int j = 0; j < 20; j++)
		{
			cin >> A[j];
		}
		for(int j = 0; j < 1024*1024; j++)
		{
			int j1 = j;
			subset c;
			for(int k = 0; j1 != 0; k++)
			{
				if(j1%2) c.sum += A[k];
				j1 /= 2;
				//cout << j1 << endl;
			}
			c.num = j;
			B.push_front(c);
			//if(j % 1000 == 0) cout << j << endl;
		}
		B.sort(compare);
		for(int j = 0; j < 1024*1024; j++)
		{
			int temp1 = B.front().sum;
			int temp2 = B.front().num;
			if(!B.empty())
			{
				B.pop_front();
				if(temp1 == B.front().sum)
				{
					cout << "Case #" << i+1 << ":" << endl;
					for(int k = 0; k < 20; k++)
					{
						if(temp2%2) cout << A[k] << " ";
						temp2 /= 2;
					}
					cout << endl;
					for(int k = 0; k < 20; k++)
					{
						if(B.front().num%2) cout << A[k] << " ";
						B.front().num /= 2;
					}
					cout << endl;
					//cout << temp2 << endl;
					//cout << B.front().num << endl;
					break;
				}
			}
			else 
			{
				cout << "impossible" << endl;
				break;
			}
		}
		
		//cout << "front: " << B.front().sum << endl;
		//cout << c << endl;
	}
	//cout << c << endl;
	//system("pause");
	return 0;
}
