#include <stdio.h> 

#include <iostream> 

#include <stdio.h> 

#include <string> 

#include <fstream> 

using namespace std; 
int countNum(int num,int A,int B)
{
	int orign= num;
	int n[10];
	int SumN[8] = {};
	int count = 0;
	int k = 0;
	int sum=0;
	int flag = 0;
	int ff = 0;
	while (num != 0)
	{
		n[k++] = num % 10;
		num /= 10;
	}
	for ( int i = k - 1; i>=0 ; i--)
	{
		flag = 0;
		sum = 0;
		for ( int s = 0; s < k; s++)
		{
			sum = sum * 10 + n[(i-s+k)%(k)];
		}
		if (sum > orign && sum <=B)
		{
			for ( int tt = 0 ; tt < 8 ; tt++)
				if (SumN[tt] == sum)
				{
					flag = 1;
					break;
				}
				else
					flag = 0;
			if (flag == 0)
			{
				SumN[ff++]=sum;
				count ++;
			}
		}
	}

	return count;
}

int main() 
{
	ifstream fin ("C:/Code/C-large.in",ios::in);
	ofstream fout("C:/Code/test.txt"); 
	int N,A,B;
	int sum;
	fin >> N;
	for ( int i = 1 ; i <= N ; i++)
	{
		fout <<"Case #"<<i<<": ";
		fin >> A;
		fin >> B;
		sum = 0;
		for ( int k = A; k <= B ; k++)
		{
			sum += countNum(k,A,B);
		}
		fout << sum  << endl;
	}

	fin.close();
	fout.close();
	return 0;
}