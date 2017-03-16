#include <algorithm>
#include <cassert>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

typedef enum
{
	S_1 = 0,
	S_I = 1,
	S_J = 2,
	S_K = 3,
	S_NUM
} letter_t;

typedef enum
{
	PLUS,
	MINUS
} sign_t;

const sign_t sign_transition[S_NUM][S_NUM] =
{
	PLUS, PLUS, PLUS, PLUS,
	PLUS, MINUS, PLUS, MINUS,
	PLUS, MINUS, MINUS, PLUS,
	PLUS, PLUS, MINUS, MINUS
};

const letter_t letter_transition[S_NUM][S_NUM] =
{
	S_1, S_I, S_J, S_K,
	S_I, S_1, S_K, S_J,
	S_J, S_K, S_1, S_I,
	S_K, S_J, S_I, S_1
};

typedef struct state_t
{
	state_t() : letter(S_1), sign(PLUS) {}
	state_t(letter_t l, sign_t s) : letter(l), sign(s) {}
	
	letter_t letter;
	sign_t sign;
} state_t;

static letter_t letter(char c)
{
	switch (c)
	{
	case '1':
		return S_1;
	case 'i':
		return S_I;
	case 'j':
		return S_J;
	case 'k':
		return S_K;
	}

	assert(false);
	while (1);
}

int
main(int argc, char **argv)
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		out << "Case #" << t << ": ";
		
		unsigned int L;
		unsigned long long X;
		std::string s;
		in >> L >> X >> s;

		/*
		out << L << " " << X << " " << s << " " << std::endl;
		std::string r;
		for (int i = 0; i < X; i++){ r += s; }
		{
			state_t p(S_1, PLUS);
			bool letters_found = false;

			letter_t search_for = S_I;

			for (unsigned int j = 0; j < L * X; j++)
			{
				int q = letter(r[j]);

				p.sign = (sign_transition[p.letter][q] == p.sign) ? PLUS : MINUS;
				p.letter = letter_transition[p.letter][q];

				if (p.sign == PLUS && p.letter == search_for && search_for != S_1)
				{
					if (search_for == S_I) search_for = S_J;
					else if (search_for == S_J) search_for = S_K;
					else if (search_for == S_K) {
						letters_found = true;  search_for = S_1;
					}

					p = state_t (S_1, PLUS);
				}
			}

			if (letters_found && p.letter == S_1 && p.sign == PLUS)
			{
				out << "check YES" << std::endl;
			}
			else
			{
				out << "check NO" << std::endl;
			}
		}
		*/

		assert(L == s.length());

		std::vector< state_t > transition[S_NUM][2];
	
		for (letter_t i = S_1; i < S_NUM; i = (letter_t)(i + 1))
		{
			for (sign_t sign = PLUS; sign <= MINUS; sign = (sign_t)(sign + 1))
			{
				transition[i][sign].resize(L);

				state_t p(i, sign);

				for (unsigned int j = 0; j < L; j++)
				{
					int q = letter(s[j]);

					p.sign = (sign_transition[p.letter][q] == p.sign) ? PLUS : MINUS;
					p.letter = letter_transition[p.letter][q];

					transition[i][sign][j] = p;
				}
			}
		}

		unsigned long long loop = 0;
		{
			state_t loop_search(S_1, PLUS);
			bool was[S_NUM][2];
			memset(was, 0, sizeof(was));

			unsigned long long count = 0;

			while (loop == 0)
			{
				if (was[loop_search.letter][loop_search.sign])
				{
					break;
				}
				was[loop_search.letter][loop_search.sign] = true;

				loop_search = transition[loop_search.letter][loop_search.sign][L - 1];
				count++;

				if (loop_search.letter == S_1 && loop_search.sign == PLUS)
				{
					loop = count;
				}
			}
		}

		unsigned long long I_r = 0;
		int I_pos = -1;

		{
			state_t p(S_1, PLUS);
			bool was[S_NUM][2];
			memset(was, 0, sizeof(was));

			for (unsigned long long i = 0; I_pos == -1 && i < X; i++)
			{
				if (was[p.letter][p.sign])
				{
					break;
				}

				for (unsigned int j = 0; j < L; j++)
				{
					if (transition[p.letter][p.sign][j].letter == S_I
						&& transition[p.letter][p.sign][j].sign == PLUS)
					{
						I_r = i;
						I_pos = j;

						break;
					}
				}

				was[p.letter][p.sign] = true;
				p = transition[p.letter][p.sign][L - 1];
			}

			if (I_pos == -1)
			{
				out << "NO" << std::endl;

				continue;
			}

			unsigned long long J_r = 0;
			int J_pos = -1;

			{
				state_t p(S_1, PLUS);
				bool was[S_NUM][2];
				memset(was, 0, sizeof(was));

				for (unsigned int j = I_pos + 1; j < L; j++)
				{
					letter_t q = letter(s[j]);

					p.sign = (sign_transition[p.letter][q] == p.sign) ? PLUS : MINUS;
					p.letter = letter_transition[p.letter][q];

					if (p.letter == S_J && p.sign == PLUS)
					{
						J_r = I_r;
						J_pos = j;

						break;
					}
				}

				for (unsigned long long i = I_r + 1; J_pos == -1 && i < X; i++)
				{
					if (was[p.letter][p.sign])
					{
						break;
					}

					for (unsigned int j = 0; j < L; j++)
					{
						if (transition[p.letter][p.sign][j].letter == S_J
							&& transition[p.letter][p.sign][j].sign == PLUS)
						{
							J_r = i;
							J_pos = j;

							break;
						}
					}

					was[p.letter][p.sign] = true;
					p = transition[p.letter][p.sign][L - 1];
				}

				if (J_pos == -1)
				{
					out << "NO" << std::endl;

					continue;
				}
			}

			unsigned long long K_r = 0;
			int K_pos = -1;

			{
				state_t p(S_1, PLUS);
				bool was[S_NUM][2];
				memset(was, 0, sizeof(was));

				for (unsigned int j = J_pos + 1; j < L; j++)
				{
					letter_t q = letter(s[j]);

					p.sign = (sign_transition[p.letter][q] == p.sign) ? PLUS : MINUS;
					p.letter = letter_transition[p.letter][q];

					if (p.letter == S_K && p.sign == PLUS)
					{
						K_r = J_r;
						K_pos = j;

						break;
					}
				}

				for (unsigned long long i = J_r + 1; K_pos == -1 && i < X; i++)
				{
					if (was[p.letter][p.sign])
					{
						break;
					}

					for (unsigned int j = 0; j < L; j++)
					{
						if (transition[p.letter][p.sign][j].letter == S_K
							&& transition[p.letter][p.sign][j].sign == PLUS)
						{
							K_r = i;
							K_pos = j;

							break;
						}
					}

					was[p.letter][p.sign] = true;
					p = transition[p.letter][p.sign][L - 1];
				}

				if (K_pos == -1)
				{
					out << "NO" << std::endl;

					continue;
				}
			}

			{
				state_t p(S_1, PLUS);
				bool was[S_NUM][2];
				memset(was, 0, sizeof(was));

				for (unsigned int j = K_pos + 1; j < L; j++)
				{
					letter_t q = letter(s[j]);

					p.sign = (sign_transition[p.letter][q] == p.sign) ? PLUS : MINUS;
					p.letter = letter_transition[p.letter][q];
				}

				long long found = -1;

				if (p.letter == S_1 && p.sign == PLUS)
				{
					found = K_r;
				}
				else
				{
					for (unsigned long long i = K_r + 1; i < X; i++)
					{
						if (was[p.letter][p.sign])
						{
							break;
						}

						was[p.letter][p.sign] = true;
						p = transition[p.letter][p.sign][L - 1];

						if (p.letter == S_1 && p.sign == PLUS)
						{
							found = i;
							break;
						}
					}
				}

				unsigned long long left = X - found - 1ull;
				assert(found == -1 || left < X);

				if (found == -1
					|| left != 0 && (loop == 0 || left % loop != 0))
				{
					out << "NO" << std::endl;

					continue;
				}
			}

			out << "YES" << std::endl;
		}
	}

	in.close();
	out.close();

	return 0;
}