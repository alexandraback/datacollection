#include <iostream>

using namespace std;

struct block
{
	double v;
	int owner;
};

block blocks[2000];

int comp(const void *a, const void *b)
{
	block va = *((block*)a);
	block vb = *((block*)b);
	if (va.v == vb.v)
		return 0;
	if (va.v < vb.v)
		return -1;
	return 1;
}

void removeHighKen(int &kp)
{
	for (int i = kp; i >= 0; i--)
	{
		if (blocks[i].owner == 1)
		{
			blocks[i].owner = 2;
			kp = i - 1;
			break;
		}
	}
}

void removeLowNaomi(int &np, const int b)
{
	for (int i = np; i < b * 2; i++)
	{
		if (!blocks[i].owner)
		{
			blocks[i].owner = 2;
			np = i + 1;
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	int t, b, y, z, kp, np;
	cin >> t;
	for (int n = 1; n <= t; n++)
	{
		cin >> b;
		z = 0;
		y = 0;
		for (int i = 0; i < b; i++)
		{
			cin >> blocks[i].v;
			blocks[i].owner = 0;
		}
		for (int i = b; i < b * 2; i++)
		{
			cin >> blocks[i].v;
			blocks[i].owner = 1;
		}
		qsort(blocks, b * 2, sizeof(block), comp);
		int kc = 0;
		for (int i = b * 2 - 1; i >= 0; i--)
		{
			if (!blocks[i].owner && !kc)
				z++;
			else if (!blocks[i].owner && kc)
				kc--;
			if (blocks[i].owner)
				kc++;
		}
		np = 0;
		kp = b * 2 - 1;
		for (int i = 0; i < b * 2 && kp >= 0 && np < b * 2; i++)
		{
			if (!blocks[i].owner)
			{
				removeHighKen(kp);
				np = i + 1;
			}
			else if (blocks[i].owner == 1)
			{
				removeLowNaomi(np, b);
				y++;
			}
		}
		cout << "Case #" << n << ": " << y << " " << z << "\n";
	}
	return 0;
}

