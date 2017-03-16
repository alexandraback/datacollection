#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("B-large.in");
	fout.open("Bans.txt");
	int T;
	int N;
	int S;
	int P;
	int t;
	fin>>T;
	int nocount;
	int surcount;
	int midcount;
	for (int i=1;i<=T;i++)
	{
		fin>>N;
		fin>>S;
		fin>>P;
		nocount=0;
		surcount=0;
		midcount=0;
		for (int j=0;j<N;j++)
		{
			fin>>t;
			if (t==3*P)
			{
				if (P>=1 && P<=9)
				{
					midcount++;
				}
				else
				{
					nocount++;
				}
			}
			else
			{
				if (t==3*P-1)
				{
					if (P<=9)
					{
						midcount++;
					}
					else
					{
						nocount++;
					}
				}
				else
				{
					if (t==3*P-2)
					{
						if (P>=2)
						{
							midcount++;
						}
						else
						{
							nocount++;
						}
					}
					else
					{
						if (t==3*P-3)
						{
							if (P>=2)
							{
								surcount++;
							}
						}
						else
						{
							if (t==3*P-4)
							{
								if (P>=2)
								{
									surcount++;
								}
							}
							else
							{
								if (t<=3*P-5)
								{
								}
								else
								{
									if (t==3*P+1)
									{
										if (P>=1)
										{
											midcount++;
										}
										else
										{
											nocount++;
										}
									}
									else
									{
										if (t<=28)
										{
											midcount++;
										}
										else
										{
											nocount++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (S>surcount)
		{
			fout<<"Case #"<<i<<": "<<nocount+midcount+surcount<<endl;
		}
		else
		{
			fout<<"Case #"<<i<<": "<<nocount+midcount+S<<endl;
		}
	}

	fin.close();
	fout.close();
	return 0;
}