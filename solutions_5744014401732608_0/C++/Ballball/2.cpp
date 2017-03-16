#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 26;
int a[MAXN];
int count[10];


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("B-small-attempt1.in");
	fout.open("B-small-attempt1.out");
	int T;
	fin>>T;
	for (int i = 1;i<=T;i++)
	{
		int B,M;
		fin>>B>>M;
		fout<<"Case #"<<i<<": ";
		if (B<2)
		{
			fout<<"IMPOSSIBLE\n";
		}
		else if (B==2)
		{
			if (M==1)
			{
				fout<<"POSSIBLE\n01\n00\n";
			}
			else fout<<"IMPOSSIBLE\n";
		}
		else if (B==3)
		{
			if (M==1)
				fout<<"POSSIBLE\n001\n000\n000\n";
			else if (M==2)
				fout<<"POSSIBLE\n011\n001\n000\n";
			else fout<<"IMPOSSIBLE\n";
		}
		else if (B==4)
		{
			if (M==1)
				fout<<"POSSIBLE\n0001\n0000\n0000\n0000\n";
			else if (M==2)
				fout<<"POSSIBLE\n0101\n0001\n0000\n0000\n";
			else if (M==3)
				fout<<"POSSIBLE\n0111\n0001\n0001\n0000\n";
			else if (M==4)
				fout<<"POSSIBLE\n0111\n0011\n0001\n0000\n";
			else fout<<"IMPOSSIBLE\n";
		}
		else if (B==5)
		{
			if (M==1)
				fout<<"POSSIBLE\n00001\n00000\n00000\n00000\n00000\n";
			else if (M==2)
				fout<<"POSSIBLE\n01001\n00001\n00000\n00000\n00000\n";
			else if (M==3)
				fout<<"POSSIBLE\n01101\n00001\n00001\n00000\n00000\n";
			else if (M==4)
				fout<<"POSSIBLE\n01111\n00001\n00001\n00001\n00000\n";
			else if (M==5)
				fout<<"POSSIBLE\n01111\n00011\n00001\n00001\n00000\n";
			else if (M==6)
				fout<<"POSSIBLE\n01111\n00011\n00011\n00001\n00000\n";
			else if (M==7)
				fout<<"POSSIBLE\n01110\n00111\n00011\n00001\n00000\n";
			else if (M==8)
				fout<<"POSSIBLE\n01111\n00111\n00011\n00001\n00000\n";
			else fout<<"IMPOSSIBLE\n";
		}
		else if (B==6)
		{
			if (M==1)
				fout<<"POSSIBLE\n000001\n000000\n000000\n000000\n000000\n000000\n";
			else if (M==2)
				fout<<"POSSIBLE\n010001\n000001\n000000\n000000\n000000\n000000\n";
			else if (M==3)
				fout<<"POSSIBLE\n011001\n000001\n000001\n000000\n000000\n000000\n";
			else if (M==4)
				fout<<"POSSIBLE\n011101\n000001\n000001\n000001\n000000\n000000\n";
			else if (M==5)
				fout<<"POSSIBLE\n011111\n000001\n000001\n000001\n000001\n000000\n";
			else if (M==6)
				fout<<"POSSIBLE\n011111\n000011\n000001\n000001\n000001\n000000\n";
			else if (M==7)
				fout<<"POSSIBLE\n011111\n000011\n000011\n000001\n000001\n000000\n";
			else if (M==8)
				fout<<"POSSIBLE\n011111\n000011\n000011\n000011\n000001\n000000\n";
			else if (M==9)
				fout<<"POSSIBLE\n011110\n000111\n000011\n000011\n000001\n000000\n";
			else if (M==10)
				fout<<"POSSIBLE\n011111\n000111\n000011\n000011\n000001\n000000\n";
			else if (M==11)
				fout<<"POSSIBLE\n011110\n000111\n000111\n000011\n000001\n000000\n";
			else if (M==12)
				fout<<"POSSIBLE\n011111\n000111\n000111\n000011\n000001\n000000\n";
			else if (M==13)
				fout<<"POSSIBLE\n011010\n001111\n000111\n000011\n000001\n000000\n";
			else if (M==14)
				fout<<"POSSIBLE\n011100\n001111\n000111\n000011\n000001\n000000\n";
			else if (M==15)
				fout<<"POSSIBLE\n011110\n001111\n000111\n000011\n000001\n000000\n";
			else if (M==16)
				fout<<"POSSIBLE\n011111\n001111\n000111\n000011\n000001\n000000\n";
			else fout<<"IMPOSSIBLE\n";
		}
	}
	fin.close();
	fout.close();
	return 0;
}