#include "stdafx.h"

#define PROBLEM_NAME "R1C_Prob_C"
#define PROBLEM_SMALL_INPUT "C-small-attempt0"
#define PROBLEM_LARGE_INPUT "C-large"

struct info
{
	int type;
	__int64 count;
};

int N, M;
vector<info> box;
vector<info> toy;

struct state
{
	int ibox;
	__int64 box_remains;
	int itoy;
	__int64 toy_remains;

	bool consume_box()
	{
		ibox++;
		if (ibox >= N)
			return false;
		box_remains = box[ibox].count;
		return true;
	}
	bool consume_toy()
	{
		itoy++;
		if (itoy >= M)
			return false;
		toy_remains = toy[itoy].count;
		return true;
	}
};

__int64 process(state& s)
{
	__int64 packs = 0;

	if (box[s.ibox].type == toy[s.itoy].type)
	{
		if (s.box_remains < s.toy_remains)
		{
			packs += s.box_remains;
			s.toy_remains -= s.box_remains;
			if (!s.consume_box())
				return packs;
			else
				return packs + process(s);
		}
		else if (s.box_remains > s.toy_remains)
		{
			packs += s.toy_remains;
			s.box_remains -= s.toy_remains;
			if (!s.consume_toy())
				return packs;
			else
				return packs + process(s);
		}
		else
		{
			packs += s.toy_remains;
			if (!s.consume_box())
				return packs;
			if (!s.consume_toy())
				return packs;
			return packs + process(s);
		}
	}

	if (s.ibox >= N || s.itoy >= M)
		return packs;

	// drop boxes
	state s_drop_box = s;
	__int64 packs_drop_box = 0;
	if (s_drop_box.consume_box())
	{
		packs_drop_box = process(s_drop_box);
	}

	// drop toys
	state s_drop_toy = s;
	__int64 packs_drop_toy = 0;
	if (s_drop_toy.consume_toy())
	{
		packs_drop_toy = process(s_drop_toy);
	}

	if (packs_drop_box > packs_drop_toy)
		return packs + packs_drop_box;
	else
		return packs + packs_drop_toy;
};


int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_SMALL_INPUT ".in", PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_LARGE_INPUT ".in", PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;

	for (int cases=1; cases<=T; ++cases)
	{
		fin >> N >> M;

		box.resize(N);
		toy.resize(M);

		for (int i=0; i<N; ++i)
		{
			fin >> box[i].count >> box[i].type;
		}
		for (int i=0; i<M; ++i)
		{
			fin >> toy[i].count >> toy[i].type;
		}

		state s;
		s.ibox = 0;
		s.itoy = 0;
		s.box_remains = box[s.ibox].count;
		s.toy_remains = toy[s.itoy].count;
		//s.box_remains = box[s.ibox].count - 1;
		//s.toy_remains = toy[s.itoy].count - 1;

		int firstbox = 0;
		//if (box[0].type == toy[0].type)
		//	firstbox = 1;

		__int64 packs = process(s);

		fout << "Case #" << cases << ": " << (packs +firstbox) << endl;
	}

	return 0;
}
