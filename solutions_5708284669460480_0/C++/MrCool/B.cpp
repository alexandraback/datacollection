#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int K, L ,S;
int allBananas, allInstances;
string keyboard, target, line;

int instanceNum()
{
	int result = 0;
	for(int i=0;i<S-L+1;i++)
	{
		int k;
		for(k=0;k<L;k++)
			if(line[k+i] != target[k])
				break;
		if(k == L)
			result++;
	}
	return result;
}

int Sequals1()
{
	int result = 0;
	for(int i=0;i<K;i++)
	{
		line[0] = keyboard[i];
		result += instanceNum();
		allInstances++;
	}
	return result;
}

int Sequals2()
{
	int result = 0;
	for(int a=0;a<K;++a)
	{
		line[0] = keyboard[a];
		for(int b=0;b<K;++b)
		{
			line[1] = keyboard[b];
			//cout << "line: " << line[0] << line[1] << endl;
			result += instanceNum();
			allInstances++;
		}
	}
	return result;
}

int Sequals3()
{
	int result = 0;
	for(int a=0;a<K;++a)
	{
		line[0] = keyboard[a];
		for(int b=0;b<K;++b)
		{
			line[1] = keyboard[b];
			for(int c=0;c<K;++c)
			{
				line[2] = keyboard[c];
				result += instanceNum();
				allInstances++;
			}
		}
	}
	return result;
}

int Sequals4()
{
	int result = 0;
	for(int a=0;a<K;++a)
	{
		line[0] = keyboard[a];
		for(int b=0;b<K;++b)
		{
			line[1] = keyboard[b];
			for(int c=0;c<K;++c)
			{
				line[2] = keyboard[c];
				for(int d=0;d<K;++d)
				{
					line[3] = keyboard[d];
					result += instanceNum();
					allInstances++;
				}
			}
		}
	}
	return result;
}

int Sequals5()
{
	int result = 0;
	for(int a=0;a<K;++a)
	{
		line[0] = keyboard[a];
		for(int b=0;b<K;++b)
		{
			line[1] = keyboard[b];
			for(int c=0;c<K;++c)
			{
				line[2] = keyboard[c];
				for(int d=0;d<K;++d)
				{
					line[3] = keyboard[d];
					for(int e=0;e<K;++e)
					{
						line[4] = keyboard[e];
						result += instanceNum();
						allInstances++;
					}
				}
			}
		}
	}
	return result;
}

int Sequals6()
{
	int result = 0;
	for(int a=0;a<K;++a)
	{
		line[0] = keyboard[a];
		for(int b=0;b<K;++b)
		{
			line[1] = keyboard[b];
			for(int c=0;c<K;++c)
			{
				line[2] = keyboard[c];
				for(int d=0;d<K;++d)
				{
					line[3] = keyboard[d];
					for(int e=0;e<K;++e)
					{
						line[4] = keyboard[e];
						for(int f=0;f<K;++f)
						{
							line[5] = keyboard[f];
							result += instanceNum();
							allInstances++;
						}
					}
				}
			}
		}
	}
	return result;
}

int Sequals7()
{
	int result = 0;
	for(int a=0;a<K;++a)
	{
		line[0] = keyboard[a];
		for(int b=0;b<K;++b)
		{
			line[1] = keyboard[b];
			for(int c=0;c<K;++c)
			{
				line[2] = keyboard[c];
				for(int d=0;d<K;++d)
				{
					line[3] = keyboard[d];
					for(int e=0;e<K;++e)
					{
						line[4] = keyboard[e];
						for(int f=0;f<K;++f)
						{
							line[5] = keyboard[f];
							for(int g=0;g<K;++g)
							{
								line[6] = keyboard[g];
								result += instanceNum();
								allInstances++;
							}
						}
					}
				}
			}
		}
	}
	return result;
}

int main()
{
	int T;
	ifstream istr("in");
	ofstream ostr("out");
	istr >> T;
	for(int times=1;times<=T;times++)
	{
		ostr << "Case #" << times << ": ";
		istr >> K >> L >> S;
		istr >> keyboard >> target;
		allBananas = 0;
		allInstances = 0;
		line = keyboard;
		cout << keyboard << " " << target << endl;

		if(L > S)
		{
			ostr << 0 << endl;
		}
		else
		{
			if(S == 1)
				allBananas = Sequals1();
			else if(S == 2)
				allBananas = Sequals2();
			else if(S == 3)
				allBananas = Sequals3();
			else if(S == 4)
				allBananas = Sequals4();
			else if(S == 5)
				allBananas = Sequals5();
			else if(S == 6)
				allBananas = Sequals6();
			else if(S == 7)
				allBananas = Sequals7();
			cout << allBananas << " " << allInstances << endl;
			ostr << std::setprecision(7)<<(double)allBananas / allInstances << endl;
		}
	}
	return 0;
}