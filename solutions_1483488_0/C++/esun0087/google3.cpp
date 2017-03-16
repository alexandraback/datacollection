#include<fstream>
#include<cmath>
#include<vector>

using namespace std;

int wei(int x);//判断一个数有几位

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	//数据额上下限
	int T;//测试组数
	int A;
	int B;
	int i,j;//迭代使用
	int weishu = 0;//一个数有多少位
	int M = 0;//多少次
	int count = 0;
	int k;//临时变量
	int x;
	vector<int> answer;
	bool tag = true;

	fin >> T;
	for(i = 0; i != T; ++i)
	{
		count = 0;
		fin >> A;
		fin >> B;

		for(j = A; j <= B; ++j)
		{
			k = j;
			weishu = wei(j);
			M = (int)pow((double)10,weishu) / 10;

			x = 1;
			for(int n = 0; n != weishu; n++)
			{
				tag = true;

				if(k / 10 + k % 10 * M <= B && 
						k / 10 + k % 10 * M > j)
				{
					for(unsigned m = 0; m != answer.size(); ++m)
					{
						if(k / 10 + k % 10 * M == answer[m])
						{
							tag = false;
							break;
						}
					}
					if(tag)
					{
						answer.push_back(k / 10 + k % 10 * M);
						count++;
					}
				}
				k = k / 10 + k % 10 * M;
			}
			answer.clear();

		}
		fout << "Case #" << i + 1 << ": " << count << endl;



	}

	return 0;
}

int wei(int x)//判断一个数有几位
{
	int count = 0;
	while(x)
	{
		count++;
		x = x / 10;
	}

	return count;
}


			

