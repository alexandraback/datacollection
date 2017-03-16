#include <stdio.h>
#include <malloc.h>
#include <algorithm>
#include <vector>

#define FEXIT() do { \
	if(fip) fclose(fip);\
	if(fop) fclose(fop);\
} while(0)

#define EXIT() do { \
	FEXIT(); \
	if(table) free(table);\
} while(0)

enum res_code
{
	kFail = -1,
	kSucc = 0,
};

#define FSUCC(p) ((p) == kSucc)
#define FFAIL(p) ((p) == kFail)

////////////////////////////////////////////////////////////////////////// assistant func
static int openfile(int argc, char **argv, FILE *&fip, FILE *&fop)
{
	FEXIT();
	if(argc != 3 || !(fip = fopen(argv[1], "r")) || !(fop = fopen(argv[2], "w")))
	{
		FEXIT();
		return kFail;
	}
	return kSucc;
}
////////////////////////////////////////////////////////////////////////// 

using namespace std;
static const int limits = 1000;
static const int lno = limits + 1;
static const int scount = lno * lno;
static const int columcount = lno;

static char *table = NULL;
static int runcase(FILE *fip)
{
	int total;
	char visited[lno];
	vector<int> l_reach[lno];

	fscanf(fip, "%d", &total);
	
	memset(table, 0, scount);
	memset(visited, 0, lno);

	for(int i = 1; i <= total; ++i)
	{
		vector<int> &l_res = l_reach[i];
		int connect, lable;
		fscanf(fip, "%d", &connect);
		char *row = table + i * columcount;
		vector<int> l_elem;
		for(int j = 0; j < connect; ++j)
		{
			fscanf(fip, "%d", &lable);
			l_res.push_back(lable);
		}
	}

	vector<int> l_head;
	vector<int> l_queue;
	l_head.reserve(limits);
	l_queue.reserve(limits);
	for(int i = 1; i <= total; ++i)
	{
		if(visited[i])
			continue;

		l_queue.push_back(i);

		int l_header= -1;
		do 
		{
			int l_cur = l_queue.back();
			if(l_header == l_cur)
			{
				visited[l_cur] = 1;
				l_queue.pop_back();
				l_head.pop_back();
				if(!l_head.empty())
				{
					l_header = l_head.back();

					vector<int> &l_headres = l_reach[l_header];
					vector<int> &l_child = l_reach[l_cur];
					char *row = table + l_header * columcount;
					int l_connect = l_child.size();
					for(int j = 0; j < l_connect; ++j)
					{
						if(++row[l_child[j]] > 1)
							return kSucc;

						l_headres.push_back(l_child[j]);
					}
				}

				continue;
			}

			vector<int> &l_res = l_reach[l_cur];
			int l_connect = l_res.size();
			//char *row = table + l_header * columcount;*/

			if(l_connect == 0)
			{
				if(l_header != -1)
				{
					char *row = table + l_header * columcount;
					if(++row[l_cur] > 1)
						return kSucc;
				}

				visited[l_cur] = 1;
				l_queue.pop_back();
				continue;
			}

			if(visited[l_cur])
			{
				if(l_header != -1)
				{
					vector<int> &l_headres = l_reach[l_header];
					char *row = table + l_header * columcount;
					for(int j = 0; j < l_connect; ++j)
					{
						if(++row[l_res[j]] > 1)
							return kSucc;

						l_headres.push_back(l_res[j]);
					}
				}

				l_queue.pop_back();
				continue;
			}

			// not connect 
			// connect
			l_header = l_cur;
			l_head.push_back(l_cur);

			for(int j = 0; j < l_connect; ++j)
			{
				int l_elem = l_res[j];
				l_queue.push_back(l_elem);
			}

		} while(!l_queue.empty());
	}

	return kFail;
}


int main(int argc, char*argv[])
{
	FILE *fip, *fop;
	fip = fop = NULL;

	if(FFAIL(openfile(argc, argv, fip, fop)))
	{
		EXIT();
		return kFail;
	}

	table = (char*)malloc(scount * sizeof(char));
	int cases, result;
	fscanf(fip, "%d", &cases);
	for(int i = 1; i <= cases; ++i)
	{
		result = runcase(fip);
		fprintf(fop, "Case #%d: %s\n", i, FSUCC(result) ? "Yes" : "No");
	}

	EXIT();
	return kSucc;
}
