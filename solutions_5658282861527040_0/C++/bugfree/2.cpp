#include <iostream>
using namespace std;

unsigned long long helper(unsigned int A, unsigned int B, unsigned int K)
{
	unsigned int A0 = A & 0xFF;
	unsigned int B0 = B & 0xFF;
	unsigned int K0 = K & 0xFF;

	unsigned int A1 = (A & 0xFF00) >> 8;
	unsigned int B1 = (B & 0xFF00) >> 8;
	unsigned int K1 = (K & 0xFF00) >> 8;
	
	unsigned int A2 = (A & 0xFF0000) >> 16;
	unsigned int B2 = (B & 0xFF0000) >> 16;
	unsigned int K2 = (K & 0xFF0000) >> 16;
	
	unsigned int A3 = (A & 0xFF000000) >> 24;
	unsigned int B3 = (B & 0xFF000000) >> 24;
	unsigned int K3 = (K & 0xFF000000) >> 24;
	
	unsigned long long result = 0;
	for(unsigned int i3 = 0; i3 <= A3; ++i3)
	{
		for(unsigned int j3 = 0; j3 <= B3; ++j3)
		{
			unsigned int k3 = i3 & j3;
			if(k3 < K3)
			{
				unsigned long long tmp3 = 1;
				tmp3 *= A2 + 1;
				tmp3 *= B2 + 1;
				tmp3 *= A1 + 1;
				tmp3 *= B1 + 1;
				tmp3 *= A0 + 1;
				tmp3 *= B0 + 1;
				result += tmp3;
			}
			else if(k3 == K3)
			{
				for(unsigned int i2 = 0; i2 <= A2; ++i2)
				{
					for(unsigned int j2 = 0; j2 <= B2; ++j2)
					{
						unsigned int k2 = i2 & j2;
						if(k2 < K2)
						{
							unsigned long long tmp2 = 1;
							tmp2 *= A1 + 1;
							tmp2 *= B1 + 1;
							tmp2 *= A0 + 1;
							tmp2 *= B0 + 1;
							result += tmp2;
						}
						else if(k2 == K2)
						{
							for(unsigned int i1 = 0; i1 <= A1; ++i1)
							{
								for(unsigned int j1 = 0; j1 <= B1; ++j1)
								{
									unsigned int k1 = i1 & j1;
									if(k1 < K1)
									{
										result += (A0 + 1) * (B0 + 1);
									}
									else if(k1 == K1)
									{
										for(unsigned int i0 = 0; i0 <= A0; ++i0)
										{
											for(unsigned int j0 = 0; j0 <= B0; ++j0)
											{
												unsigned int k0 = i0 & j0;
												if(k0 <= K0)
												{
													++result;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return result;
}

void fun()
{
	int T;
	cin >> T;
	unsigned int A;
	unsigned int B;
	unsigned int K;
	for(int i = 1; i <= T; ++i)	
	{
		cin >> A >> B >> K;
		unsigned long long result;
		if(A == 0 || B == 0 || K == 0)
		{
			result = 0;
		}
		else
		{
			result = helper(A - 1, B - 1, K - 1);
		}
		cout << "Case #" << i << ": " << result <<endl;
	}
}

int main()
{
	fun();
}
