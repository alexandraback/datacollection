#include "stdafx.h"

#define PROBLEM_NAME "R1C_Prob_A"
#define PROBLEM_SMALL_INPUT "A-small-attempt1"
#define PROBLEM_LARGE_INPUT "A-large"

struct cinfo
{
	int name;
	vector<int> parent;
};

struct cnode
{
	bool root;
	set<int> child;
};

void build_tree(vector<cnode>& tree, const vector<cinfo>& infos)
{
	tree.resize(infos.size());
	int N = (int)infos.size() - 1;

	for (int i=1; i<=N; ++i)
	{
		const cinfo& info = infos[i];

		if (info.parent.empty())
		{
			tree[i].root = true;
		}
		else
		{
			tree[i].root = false;
			for (size_t j=0; j<info.parent.size(); ++j)
			{
				tree[info.parent[j]].child.insert(i);
			}
		}
	}
}

bool mark_child(vector<cnode>& tree, int childindex, vector<char>& visited)
{
	cnode& node = tree[childindex];

	if (visited[childindex])
		return false;

	visited[childindex] = 1;
	for (set<int>::iterator it = node.child.begin(); it != node.child.end(); ++it)
	{
		int childindex = *it;
		if (!mark_child(tree, childindex, visited))
			return false;
	}
	return true;
}

bool mark_tree(vector<cnode>& tree)
{
	int N = (int)tree.size() - 1;

	for (int i=1; i<=N; ++i)
	{
		cnode& node = tree[i];

		if (!node.root)
			continue;

		vector<char> visited(N+1, 0);
		for (set<int>::iterator it = node.child.begin(); it != node.child.end(); ++it)
		{
			int childindex = *it;
			if (!mark_child(tree, childindex, visited))
				return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_SMALL_INPUT ".in");
//	set_fio(PROBLEM_SMALL_INPUT ".in", PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_LARGE_INPUT ".in");
	set_fio(PROBLEM_LARGE_INPUT ".in", PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;

	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		vector<cinfo> infos(N+1);
		for (int i=1; i<=N; ++i)
		{
			infos[i].name = i;

			int M;
			fin >> M;
			for (int j=0; j<M; ++j)
			{
				int p;
				fin >> p;
				infos[i].parent.push_back(p);
			}
		}

		vector<cnode> tree;
		build_tree(tree, infos);

		bool ok = mark_tree(tree);

		fout << "Case #" << cases << ": ";
		if (ok)
			fout << "No" << endl;
		else
			fout << "Yes" << endl;
	}

	return 0;
}
