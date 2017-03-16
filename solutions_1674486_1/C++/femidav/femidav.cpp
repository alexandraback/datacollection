#include <cstdio>
#include <map>
#include <set>

#define FOR(I, N) for(int I = 0, end_ = (N); I < end_; ++I)
int ri() { int r; scanf("%d", &r); return r; }
typedef std::set<int> SI;
typedef std::pair<SI, SI> NODE;
typedef std::map<int, NODE> NODES;

bool check(NODES& nodes, NODE& node, int cls)
{
//	printf("\tstart check for class %d\n", cls);
	for(SI::iterator i = node.second.begin(); i != node.second.end(); ++i)
	{
		int C = *i;
//		printf("\t\tprocess parent %d\n", C);
		if (node.first.find(C) != node.first.end()) {
//			printf("\t\tparent %d already processed move on\n", C);
			continue;
		}
		if (check(nodes, nodes[C], C)) {
//			printf("\t\tparent %d returned true - victory!\n", C);
			return true;
		}

		for(SI::iterator j = nodes[C].second.begin(); j != nodes[C].second.end(); ++j)
		{
			if (node.second.find(*j) != node.second.end()) {
//				printf("\t\tgrand parent %d already there - viktory!\n", *j);
				return true;
			}
			else {
//				printf("\t\tinsert grand parent %d for class %d parent %d\n", *j, cls, C);
				node.second.insert(*j);
				node.first.insert(*j);
			}
//			printf("\t\tparent %d processed\n", C);
			node.first.insert(C);
		}
	}
	return false;
}

int main()
{
	FOR(i, ri())
	{
		NODES nodes;

		int N = ri();
		bool done = false;
		for(int j = 1; j < N + 1; ++j) {
//			printf("\tmake node %d\n", j);
			nodes[j] = std::make_pair(SI(), SI());
			FOR(k, ri()) {
				int C = ri();
//				printf("\t\tinsert parent %d for class %d\n", C, j);
				nodes[j].second.insert(C);
			}
		}
		for(int j = 1; j < N + 1; ++j) {
			if (check(nodes, nodes[j], j)) {
				printf("Case #%d: %s\n", i + 1, "Yes");
				done = true;
				break;
			}
		}

		if (!done) printf("Case #%d: %s\n", i + 1, "No");
	}
}