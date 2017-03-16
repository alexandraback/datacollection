#define t_DEBUG_MODE 1

#include <cstdlib>
#include <cstdio>
#include <map>
#include <ctime>

using namespace std;

//int route[200];
int g_flag;
FILE *f;

map<int, int> key;

void addKey(int k, int n)
{
	map<int,int>::iterator it=key.find(k);
	if (it!=key.end())
		it->second+=n;
	else
		key.insert(pair<int, int>(k, n));
}

void decreaseKey(int k, int n)
{
	map<int,int>::iterator it=key.find(k);
	if (it!=key.end())
		it->second-=n;
	else
		key.insert(pair<int, int>(k, -n));
}

int getKeyNum(int k)
{
	map<int,int>::iterator it=key.find(k);
	if (it!=key.end())
		return it->second;
	return 0;
}

struct _chest
{
	int password;
	int key[400];
	int cnt;
	int visited;
};

_chest chest[200];
int chest_cnt;

int index;


void showKeys(int n)
{
	for(map<int, int>::iterator i=key.begin(); i!=key.end(); i++) {
		for(int k=0; k<=n; k++)
			printf("  ");
		printf("key #%d: %d\n", i->first, i->second);
	}
}

/*void Try(int n, int c)
{
#if t_DEBUG_MODE
	for(int i=0; i<n; i++)
		printf("  ");
	printf("visit chest #%d  step %d\n", c+1, n);
	for(int i=0; i<n; i++)
		printf("  ");
	printf("requires: key #%d\n", chest[c].password);
	showKeys(n);
#endif
	if (g_flag)
		return;
	if (chest[c].visited)
		return;
	if (getKeyNum(chest[c].password)<=0)
		return;
#if t_DEBUG_MODE
	for(int i=0; i<=n; i++)
		printf("  ");
	printf("Successfully opened!\n");
#endif
	route[n]=c;
	chest[c].visited=true;
	decreaseKey(chest[c].password, 1);
	for(int i=0; i<chest[c].cnt; i++) {
		addKey(chest[c].key[i], 1);
#if t_DEBUG_MODE
		for(int i=0; i<=n; i++)
			printf("  ");
		printf("Get key #%d\n", chest[c].key[i]);
#endif
	}
	//printf("\tkey %d: %d\n", chest[c].password, getKeyNum(chest[c].password));
	if (n==chest_cnt-1) {
		fprintf(f,"Case #%d: ", index+1);
		for(int i=0; i<chest_cnt; i++)
			fprintf(f,"%d ", route[i]+1);
		fprintf(f, "\n");
		g_flag=true;
		return;
	}
#if t_DEBUG_MODE
	system("pause");
#endif
	for(int i=0; i<chest_cnt; i++) {
		Try(n+1, i);
	}

	route[n]=0;
	chest[c].visited=false;
	addKey(chest[c].password, 1);
	for(int i=0; i<chest[c].cnt; i++)
		decreaseKey(chest[c].key[i], 1);
	//printf("\tkey %d: %d\n", chest[c].password, getKeyNum(chest[c].password));
	return;
}*/

struct _route
{
	int r[200];
	int lv;

	void display()
	{
		printf("Lv: %d\n", this->lv);
		for(int i=0; i<chest_cnt; i++)
			printf("%d ", this->r[i]+1);
		printf("\n\n");
	}
};

int defKey[400];
int defKeyCount;

void eval(_route *p)
{
	key.clear();
	for(int i=0; i<defKeyCount; i++)
		addKey(defKey[i],1);
	//showKeys(0);
	for(int k=0; k<chest_cnt; k++) {
		int i=p->r[k];
		//printf("Key need #%d: %d\n", chest[i].password, getKeyNum(chest[i].password));
		if (getKeyNum(chest[i].password)>0) {
			decreaseKey(chest[i].password, 1);
			for(int j=0; j<chest[i].cnt; j++)
				addKey(chest[i].key[j], 1);
			if (i==chest_cnt-1) {
				p->lv=chest_cnt;
				break;
			}
		}
		else {
			p->lv=k;
			break;
		}
	}
	//p->display();
	//system("pause");
}

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int cmp(_route *p, _route *q)
{
	//printf("cmp: \n");
	//p->display();
	//q->display();
	int ret=0;
	if (p->lv>q->lv) {
		ret= 1;
		goto end;
	}
	else if (p->lv<q->lv) {
		ret= -1;
		goto end;
	}
	for(int i=0; i<chest_cnt; i++)
		if (p->r[i]<q->r[i]) {
			ret= 1;
			break;
		}
		else if (p->r[i]>q->r[i]) {
			ret= -1;
			break;
		}
end:
	//printf("result: %d\n", ret);
	//system("pause");
	return ret;
}


int main()
{
	freopen("D-small-attempt6.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand(time(NULL));
	f=fopen("output.txt", "w");
	int nCase; scanf("%d", &nCase);
	for(index=0; index<nCase; index++) {
		//printf("QAQ\n");
		scanf("%d%d", &defKeyCount, &chest_cnt);
		for(int i=0; i<defKeyCount; i++) {
			//int t; 
			scanf("%d", &defKey[i]);
			//addKey(t, 1);
		}
		for(int i=0; i<chest_cnt; i++) {
			scanf("%d%d", &chest[i].password, &chest[i].cnt);
			chest[i].visited=false;
			for(int j=0; j<chest[i].cnt; j++)
				scanf("%d", &chest[i].key[j]);
		}

		_route best;
		best.lv=-1;
		int suc=false;

		_route t;
		for(int k=0; k<10000; k++) {
			//best.display();
			//system("pause");
			for(int i=0; i<chest_cnt; i++)
				t.r[i]=i;
			for(int j=0; j<40; j++) {
				int p=rand()%chest_cnt, q=rand()%chest_cnt;
				swap(&t.r[p], &t.r[q]);
			}
			eval(&t);
			//t.display();
			_route m; memcpy(&m, &t, sizeof(_route));
			for(int i=0; i<chest_cnt; i++)
				for(int j=0; j<chest_cnt; j++) {
					_route b; memcpy(&b, &t, sizeof(_route));
					swap(&b.r[i], &b.r[j]);
					eval(&b);
					if (cmp(&b, &m)>0)
						memcpy(&m, &b, sizeof(_route));
				}
				//m.display();
			if (m.lv>=chest_cnt)
				if (cmp(&m, &best)>0) {
					memcpy(&best, &m, sizeof(_route));
					suc=true;
				}
		}
		if (suc) {
			fprintf(f,"Case #%d: ", index+1);
			for(int i=0; i<chest_cnt; i++)
				fprintf(f,"%d ", best.r[i]+1);
			fprintf(f,"\n");
		}
		else
			fprintf(f,"Case #%d: IMPOSSIBLE\n", index+1);
		printf("Case #%d: Finished\n", index+1);
		/* traditional dfs method
		absolutely failed.
		g_flag=false;
		for(int i=0; i<chest_cnt; i++)
			Try(0, i);
		if (!g_flag)
			fprintf(f, "Case #%d: IMPOSSIBLE\n", index+1);
		printf("Case #%d fin.\n", index+1);*/
		//system("pause");
	}
	return 0;
}


