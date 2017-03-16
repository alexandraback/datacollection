#include <iostream>
#include <string>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

typedef struct qch_s
{
	bool minus;
	char ch;
}qch_t;

qch_t multiple_qch(qch_t *a, qch_t *b)
{
	qch_t resp;

	resp.minus = (a->minus != b->minus);

	if (a->ch == b->ch)
	{
		resp.ch = 1;
		resp.minus = !resp.minus;
	}
	else if (a->ch == 1)
	{
		resp.ch = b->ch;
	}
	else if (b->ch == 1)
	{
		resp.ch = a->ch;
	}
	else if (a->ch == 'i')
	{
		if (b->ch == 'j')
		{
			resp.ch = 'k';
		}
		else
		{
			resp.ch = 'j';
			resp.minus = !resp.minus;
		}
	}
	else if (a->ch == 'j')
	{
		if (b->ch == 'i')
		{
			resp.ch = 'k';
			resp.minus = !resp.minus;
		}
		else
		{
			resp.ch = 'i';
		}
	}
	else
	{
		if (b->ch == 'i')
		{
			resp.ch = 'j';
		}
		else
		{
			resp.ch = 'i';
			resp.minus = !resp.minus;
		}
	}

	return resp;
}

int main()
{
	int T, test, L, X, i, SXsz;
	string S, SX;
	qch_t a, b;
	bool was_i, was_k;

	cin>>T;

	for (test = 1; test <= T; test++)
	{
		cin>>L>>X>>S;

		//X = MIN(X, (X%5)+10);

		SX.clear();
		for (i = 0; i < X; i++)
		{
			SX += S;
		}
		SXsz = SX.size();

		was_i = was_k = false;

		a.ch = SX[0]; a.minus = false;
		if (!was_i && a.ch == 'i' && !a.minus)
		{
			was_i = true;
		}

		for (i = 1; i < SXsz; i++)
		{
			b.ch = SX[i]; b.minus = false;

			a = multiple_qch(&a, &b);

			if (!was_i && a.ch == 'i' && !a.minus)
			{
				was_i = true;
			}
			else if (was_i && !was_k && a.ch == 'k' && !a.minus)
			{
				was_k = true;
			}
		}

		cout<<"Case #"<<test<<": "<<((was_i && was_k && a.ch == 1 && a.minus) ? "YES" : "NO")<<endl;
	}

	return 0;
}
