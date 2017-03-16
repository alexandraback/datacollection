#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXV 50

typedef struct vertex vertex;

struct vertex {
	int zip;
	int num;
	int visited;
	vertex *adj[MAXV + 1];
};


int N, M;
vertex graph[MAXV + 1];
int visited[MAXV + 1];
char path[5*MAXV + 1];

int vert_cmp(void *a, void *b)
{
	vertex **i = a;
	vertex **j = b;
	return (*i)->zip - (*j)->zip;
}

void read_input()
{
	int i;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i) {
		scanf("%d", &graph[i].zip);
	}
	for (i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].adj[graph[a].num++] = graph + b;
		graph[b].adj[graph[b].num++] = graph + a;
	}
	for (i = 1; i <= N; ++i) {
		qsort(graph[i].adj, graph[i].num, sizeof graph[i].adj[0],
				vert_cmp);
	}
}

int find_smallest(void)
{
	int i;
	int min = 1000000;
	int minpos = -1;
	for (i = 1; i <= N; ++i) {
		if (graph[i].zip < min) {
			minpos = i;
			min = graph[i].zip;
		}
	}
	assert(minpos >= 0);
	return minpos;
}

void dfs(vertex *v)
{
	int i;
	char buf[6];
	assert(v->visited == 0);
	v->visited = 1;
	sprintf(buf, "%d", v->zip);
	strcat(path, buf);
	for (i = 0; i < v->num; ++i) {
		vertex *u = v->adj[i];
		if (!u->visited) {
			dfs(u);
		}
	}
}

char *solve(void)
{
	int v;
	read_input();
	v = find_smallest();
	dfs(&graph[v]);
	return path;
}

void clear_data(void)
{
	memset(graph, 0, sizeof graph);
	path[0] = '\0';
}

int main()
{
	int T, i;
	scanf("%d", &T);
	for (i = 1; i <= T; ++i) {
		clear_data();
		printf("Case #%d: %s\n", i, solve());
	}
	return 0;
}
