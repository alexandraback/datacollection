#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;

class SegTreeNode
{
public:
	int beginIdx,endIdx;
	int minVal;
};

class Query
{
public:
	int dayNo;
	int begin, end;
	int val;
	Query(int a, int b, int c, int d) : dayNo(a), begin(b), end(c), val(d) {}
};

bool comp(Query &a, Query &b)
{
	return a.dayNo < b.dayNo;
}

int allnum[400000];

//SegTreeNode segTree[4000000];
vector<Query> queries;

void Open()
{
	freopen("P3.in", "r", stdin);
	freopen("P3.out", "w", stdout);
}

void Close()
{
	fclose(stdin);
	fclose(stdout);
}

void Init()
{
	int N;
	scanf ("%d", &N);
	int d, n, s, w, e, deltad, deltap, deltas;
	queries.clear();
	nums.clear();
	for (int i = 0; i < N; i++)
	{
		scanf ("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &deltad, &deltap, &deltas);
		for (int j = 0; j < n; j++)
		{
			queries.push_back(Query(d, w, e, s));
			nums.push_back(w);
			nums.push_back(e);
			w += deltap; e += deltap;
			d += deltad;
			s += deltas;
		}
	}
	sort(nums.begin(), nums.end());
	vector<int> tmp;
	tmp.reserve(nums.size());
	tmp.push_back(nums[0]);
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] != tmp.back())
			tmp.push_back(nums[i]);
	nums = tmp;

	sort(queries.begin(), queries.end(), comp);
}

void BuildTree(int id, int beginIdx, int endIdx)
{
	//segTree[id].beginIdx = beginIdx;
	//segTree[id].endIdx = endIdx;
	//segTree[id].minVal = 0;

	//if (beginIdx < endIdx - 1)
	//{
	//	int mid = (beginIdx + endIdx)/2;
	//	BuildTree(2*id+1, beginIdx, mid);
	//	BuildTree(2*id+2, mid, endIdx);
	//}
	int b = nums[beginIdx]+1000;
	int e = nums[endIdx] + 1000;
	for (int i = b; i <= e; i++)
		allnum[i] = 0;
}

int QueryTree(int id,int begin, int end, int val)
{
	/*if (segTree[id].minVal < val) segTree[id].minVal = val;
	int segB = nums[segTree[id].beginIdx];
	int segE = nums[segTree[id].endIdx];
	if (end < segB || begin >= segE) return 2147483647;
	if (begin <= segB && segE <= end) return segTree[id].minVal;
	return min(QueryTree(2*id+1, begin, end, segTree[id].minVal), QueryTree(2*id+2, begin, end, segTree[id].minVal));*/
	begin+= 1000;
	end+= 1000;
	int minval = allnum[begin];
	for (int i = begin; i <= end; i++)
		if (minval > allnum[i])
			minval = allnum[i];
		return minval;
}

int SetTree(int id, int begin, int end, int setval, int parval)
{
	//if (segTree[id].minVal < parval) segTree[id].minVal = parval;
	//int segB = nums[segTree[id].beginIdx];
	//int segE = nums[segTree[id].endIdx];
	//if (end < segB || begin >= segE) return segTree[id].minVal;
	//if (begin <= segB && segE <= end)
	//{
	//	if (setval > segTree[id].minVal) segTree[id].minVal = setval;
	//	return segTree[id].minVal;
	//}
	//segTree[id].minVal = min(SetTree(2*id+1, begin, end, setval, segTree[id].minVal), SetTree(2*id+2, begin, end, setval, segTree[id].minVal));
	//return segTree[id].minVal;
	begin+=1000;
	end+=1000;
	for (int i = begin; i <=end; i++)
		allnum[i] = setval;
	return 0;
}

int result;

void Run(int caseNo)
{
	result = 0;
	BuildTree(0, 0, nums.size()-1);
	int dayNo = 0, lastid = 0;
	for (int i = 0; i < queries.size(); i++)
	{
		if (queries[i].dayNo != dayNo)
		{
			for (int j = lastid; j < i; j++)
				SetTree(0, queries[j].begin, queries[j].end, queries[j].val, 0);
			lastid = i;
			dayNo = queries[i].dayNo;
		}
		if (queries[i].val > QueryTree(0, queries[i].begin, queries[i].end, 0))
			result++;
	}
	printf ("Case #%d: %d\n", caseNo, result);
}

void Work()
{
	int T;
	scanf ("%d", &T);
	for (int i = 0; i < T; i++)
	{
		Init();
		Run(i+1);
	}
}

int main()
{
	Open();
	Work();
	Close();
	return 0;
}