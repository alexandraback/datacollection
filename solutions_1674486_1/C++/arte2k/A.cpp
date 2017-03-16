#include <vector>
#include <iostream>
#include <functional>
#include <numeric>
using namespace std;


bool find_loop(vector< vector<int> >& inh_graph, int base_class, std::vector<int>& trav_classes)
{
	for(int child_class : inh_graph[base_class])
	{
		//cout<<"base class:"<<base_class<<"child_class"<<child_class<< std::endl;
		if(find(trav_classes.begin(), trav_classes.end(), child_class) != trav_classes.end())
			return true;
		trav_classes.push_back(child_class);
		if(find_loop(inh_graph, child_class, trav_classes))
			return true;
	}
	return false;
}

bool solve(vector< vector<int> >& inh_graph, vector<int>& base_classes)
{
	for(int base_class  : base_classes)
	{
		std::vector<int> v;
		if(find_loop(inh_graph ,base_class, v))
			return true;
	}
	return false;
}

int main()
{
	freopen("A-large.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tcCount;
    scanf("%d", &tcCount);
    //cout<<"tc is"<<tcCount;
    for (int tc = 1; tc <= tcCount; ++tc)
    {
    	vector< vector<int> > inh_graph;
    	std::vector<int> base_classes;
    	int N;
    	scanf("%d", &N);
    	//cout<<"N is"<<N;
    	inh_graph.resize(N+1);
    	for(int n = 1; n <= N; ++n)
    	{
    		int M;
    		scanf("%d", &M);

    		//cout<<"M is"<<M;
    		if(M == 0)
    			base_classes.push_back(n);
    		else
    		{
    		for(int m = 0; m < M; ++m)
    		{
    			int parent;
    			scanf("%d", &parent);
    			inh_graph[parent].push_back(n);
    		}
    	}
    	}
    	printf("Case #%d: %s \n",tc, solve(inh_graph, base_classes)? "Yes": "No");
    }
	
}