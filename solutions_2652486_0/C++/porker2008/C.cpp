#include <iostream>
using namespace std;

int product3[6][6][6][8];
int product2[6][6][4];
int product1[6][2];
int likely3[6][6][6];
int likely2[6][6];
int likely1[6];

namespace C
{
	int main()
	{
		for(int i=2;i<=5;i++)
		{
			product1[i][0] = 1;
			product1[i][1] = i;
		}
		for(int i=2;i<=5;i++)
		{
			for(int j=i;j<=5;j++)
			{
				product2[i][j][0] = 1;
				product2[i][j][1] = i;
				product2[i][j][2] = j;
				product2[i][j][3] = i*j;
			}
		}
		for(int i=2;i<=5;i++)
		{
			for(int j=i;j<=5;j++)
			{
				for(int k=j;k<=5;k++)
				{
					product3[i][j][k][0] = 1;
					product3[i][j][k][1] = i;
					product3[i][j][k][2] = j;
					product3[i][j][k][3] = k;
					product3[i][j][k][4] = i*j;
					product3[i][j][k][5] = i*k;
					product3[i][j][k][6] = j*k;
					product3[i][j][k][7] = i*j*k;
				}
			}
		}
		int T;
		cin >> T;
		for(int c=1;c<=T;c++)
		{
			int R,N,M,K;
			cin >> R >> N >> M >> K;
			cout << "Case #" << c << ":" << endl;
			for(int t=0;t<R;t++)
			{
				int test[7];
				for(int i=0;i<K;i++)
					cin >> test[i];
				if(N==1)
				{
					memset(likely1,0,sizeof(likely1));
					for(int i=0;i<K;i++)
					{
						for(int j=2;j<=M;j++)
						{
							if(likely1[j] == -1) continue;
							bool exist = false;
							for(int k=0;k<2;k++)
							{
								if(product1[j][k] == test[i])
									exist = true;
							}
							if(exist)
								likely1[j]++;
							else
								likely1[j] = -1;
						}
					}
					int max = -1;
					for(int j=2;j<=M;j++)
					{
						if(likely1[j] > max)
						{
							max = likely1[j];
						}
					}
					for(int j=2;j<=M;j++)
					{
						if(likely1[j] == max)
						{
							cout << j << endl;
							goto finish1;
						}
					}
					finish1:;
				}
				else if(N==2)
				{
					memset(likely2,0,sizeof(likely2));
					for(int i=0;i<K;i++)
					{
						for(int j=2;j<=M;j++)
						{
							for(int p=j;p<=M;p++)
							{
								if(likely2[j][p] == -1) continue;
								bool exist = false;
								for(int k=0;k<4;k++)
								{
									if(product2[j][p][k] == test[i])
										exist = true;
								}
								if(exist)
									likely2[j][p]++;
								else
									likely2[j][p] = -1;
							}
						}
					}
					int max = -1;
					for(int j=2;j<=M;j++)
					{
						for(int p=j;p<=M;p++)
						{
							if(likely2[j][p] > max)
							{
								max = likely2[j][p];
							}
						}
					}
					for(int j=2;j<=M;j++)
					{
						for(int p=j;p<=M;p++)
						{
							if(likely2[j][p] > max)
							{
								cout << j << p << endl;
								goto finish2;
							}
						}
					}
					finish2:;
				}
				else if(N==3)
				{
					memset(likely3,0,sizeof(likely3));
					for(int i=0;i<K;i++)
					{
						for(int j=2;j<=M;j++)
						{
							for(int p=j;p<=M;p++)
							{
								for(int q=p;q<=M;q++)
								{
									if(likely3[j][p][q] == -1) continue;
									bool exist = false;
									for(int k=0;k<8;k++)
									{
										if(product3[j][p][q][k] == test[i])
											exist = true;
									}
									if(exist)
										likely3[j][p][q]++;
									else
										likely3[j][p][q] = -1;
								}
							}
						}
					}
					int max = -1;
					for(int j=2;j<=M;j++)
					{
						for(int p=j;p<=M;p++)
						{
							for(int q=p;q<=M;q++)
							{
								if(likely3[j][p][q] > max)
								{
									max = likely3[j][p][q];
								}
							}
						}
					}
					for(int j=2;j<=M;j++)
					{
						for(int p=j;p<=M;p++)
						{
							for(int q=p;q<=M;q++)
							{
								if(likely3[j][p][q] == max)
								{
									cout << j << p << q << endl;
									goto finish3;
								}
							}
						}
					}
					finish3:;
				}
			}
		}
		return 0;
	}
}

int main()
{
	C::main();
}