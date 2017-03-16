#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<int, int> used, ID;
vector<int> Rec;
#define lhs l, m, rt << 1
#define rhs m + 1, r, rt << 1 | 1

const int mix = -1;
const int maxn = 1000010;
int color[maxn*4];
int lab[maxn];

//vector<int> map[maxn];

struct seg {
    int l, r, x;
    friend bool operator < (const seg& s1, const seg& s2) { return s1.x < s2.x; }
} seg[maxn] ;

void PushDown(int rt)
{
    if (color[rt] != mix)
    {
        color[rt << 1] = color[rt << 1 | 1] = color[rt];
        color[rt] = mix;
    }
}

void Update(int beg, int end, int value, int l, int r, int rt)
{
    if (beg <= l && r <= end)
    {
        color[rt] = max(color[rt], value);
        return ;
    }
    PushDown(rt);

    int m = (l + r) >> 1;
    if (beg <= m)
        Update(beg, end, value, lhs);
    if (end > m)
        Update(beg, end, value, rhs);
}

void Query(int beg, int end, int value, int l, int r, int rt)
{
    if (color[rt] != mix)
    {
        if (lab[color[rt]] != value)
        {
            //map[value].push_back(color[rt]);
            lab[color[rt]] = value;
        }
        return ;
    }
    if (l == r)
        return ;

    PushDown(rt);

    int m = (l + r) >> 1;
    if (beg <= m)
        Query(beg, end, value, lhs);  
    if (end > m)
        Query(beg, end, value, rhs);
}

struct attack
{
	int d;
	int w;
	int e;
	int s;
}att[1000010];

bool cmp(attack a, attack b)
{
	return a.d < b.d;
}

int wall[1000010*4];
int next[1000010*4];

int main()
{
	//init();
	
	//printf("Input File Name ?");
	//char FileName[128];
	//scanf("%s", FileName);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		int d, n, w, e, s, dd, dp, ds;
		int N;
		scanf("%d", &N);
		int i, j, k;
		int num = 0;
		Rec.clear();
		used.clear();
		ID.clear();
		for(i = 0; i < N; i ++)
		{
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			for(j = 0; j < n; j ++)
			{
				att[num].d = d+dd*j;
				att[num].w = w+dp*j;
				att[num].e = e-1+dp*j;
				att[num].s = s+ds*j;
				
				if(used[att[num].w] != Case)
				{
					used[att[num].w] = Case;
					Rec.push_back(att[num].w);
				}
				
				if(used[att[num].e] != Case)
				{
					used[att[num].e] = Case;
					Rec.push_back(att[num].e);
				}
				
				num ++;
			}
		}
		sort(Rec.begin(), Rec.end());
		for(i = 0; i < Rec.size(); i ++)
		{
			ID[Rec[i]] = i+1;
		}
		int wlen = 610;
		
		for(i = 0; i < num; i ++)
		{
			att[i].w = att[i].w+300;
			att[i].e = att[i].e+300;
		}
		
		sort(att, att+num, cmp);
		
		memset(next, 0, sizeof(next));
		int ans = 0;
		int day = -1;
		for(i = 0; i < num; i ++)
		{
			if(att[i].d != day)
			{
				//printf("%d %d %d %d\n", att[i].d, att[i].w, att[i].e, att[i].s);
				for(j = 0; j < wlen; j ++)
				{
					wall[j] = next[j];
					//if(wall[j] > 0)printf("%d ", wall[j]);
				}
				//putchar('\n');
				day = att[i].d;
			}
			for(j = att[i].w; j <= att[i].e; j ++)
			{
				if(wall[j] < att[i].s)
				{
					ans ++;
					break;
				}
			}
			for(j = att[i].w; j <= att[i].e; j ++)
			{
				next[j] = max(next[j], att[i].s);
			}
		}
		
		printf("Case #%d: %d\n", Case, ans);
	}
	
	return 0;
}
