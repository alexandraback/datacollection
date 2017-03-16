
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#define M 1002
#define OFF (M>>1)

typedef long long LL;
using namespace std;


template<class node>
class segtree{/*{{{*/
	template<bool b>class param{};
	inline void spltdwn(int idx,param<true>){splt(idx);}
	inline void splt(int idx){/*{{{*/
		idx>>=1;
		if(idx>0)splt(idx);
		tree[idx].split(tree[idx<<1],tree[(idx<<1)|1]);
	}/*}}}*/
	inline void spltdwn(int,param<false>){};
	inline void split(node& a, node& b, node& c, param<true> ){ a.split(b,c);}//was returned earlier
	inline void split(node&, node&, node&, param<false>){}
	template<typename t,void (t::*)(t&,t&)> class T{};
	template<typename t> static char test(T<t,&t::split>*){return 0;}
	template<typename t> static long double test(...){return 0;}
	int u,v;
	node query(int root, int left_range, int right_range){/*{{{*/
		if(u<=left_range && right_range<=v)
			return tree[root];
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		node res;
		if(u>=mid)res=query(r,mid,right_range);
		else if(v<=mid)res=query(l,left_range,mid);
		else{
			node n1 = query(l,left_range,mid),
				 n2 = query(r,mid,right_range);
			res.merge(n1,n2);
		}
		return res;
	}/*}}}*/
 	template<void(*fn)(node&)>
	void local_update(int root, int left_range,int right_range){/*{{{*/
		if(u<=left_range && right_range<=v){
			return fn(tree[root]);
		}
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		if(v>mid)local_update<fn>(r,mid,right_range);
		if(u<mid)local_update<fn>(l,left_range,mid);
		tree[root].merge(tree[l],tree[r]);
	}/*}}}*/
	void mrgup(int idx){/*{{{*/
		idx>>=1;
		while(idx>0)
			tree[idx].merge(tree[idx<<1],tree[(idx<<1)|1]),
			idx>>=1;
	}/*}}}*/
public:
	static bool const has_split = (sizeof(test<node>(0))==sizeof(char));
	int N;
	int leftmost_leaf, rightmost_leaf;
	node* tree;
	node identity;
	~segtree(){
		delete tree;
	}
	void init(int n, const node a[], const node& identity){/*{{{*/
		this->identity = identity;
		N=0;
		while((1<<N)<n)N++;
		leftmost_leaf = 1<<N;
		rightmost_leaf = leftmost_leaf<<1;
		tree = new node[rightmost_leaf];
		for(int i=0;i<n;i++)
			tree[i+leftmost_leaf] = a[i];
		for(int i=n+leftmost_leaf;i<rightmost_leaf;i++)
			tree[i]=identity;
		for(int i=leftmost_leaf-1;i;i--)
			tree[i].merge(tree[i<<1],tree[(i<<1)|1]);
	}/*}}}*/
	node query(int u, int v){//[u,v]/*{{{*/
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return query(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	node query(int u){//faster version of query(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		return tree[u];
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u, int v){/*{{{*/
		//0-indexed
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return local_update<fn>(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u){//faster version of update(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		fn(tree[u]);
		mrgup(u);
	}/*}}}*/
	void split_down(int leaf_idx){/*{{{*/
		spltdwn(leaf_idx+leftmost_leaf,param<has_split>());
	}/*}}}*/
	void merge_up(int leaf_idx){/*{{{*/
		mrgup(leaf_idx+leftmost_leaf);
	}/*}}}*/
	bool is_leaf(int tree_idx){return tree_idx>=leftmost_leaf;}

};/*}}}*/


struct node{
    int mi;
    void split(node& a,node &b)
    {
        a.mi = max(a.mi,mi);
        b.mi = max(b.mi,mi);
    }
	void merge(node& l, node& r)
	{
	    mi = min(l.mi,r.mi);
	}
};
int v;
void updateV(node &x)
{
    x.mi = max(x.mi,v);
}
node arr[M];
segtree<node> S;

struct attack {
    int w,e,s,t,att;
};

multimap<int,attack> T;
set<int> days;
int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    int tribes,n,w,e,delS,delP,s,d,delD;
    attack at;
    set<int>::iterator st;
    pair<multimap<int,attack>::iterator,multimap<int,attack>::iterator> mtr;
    multimap<int,attack>::iterator mt;
    for(int casenum=1;casenum<=t;casenum++)
    {
        T.clear();
        days.clear();
        scanf("%d",&tribes);
        for(int i=0;i<tribes;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&delD,&delP,&delS);
            for(int j=0;j<n;j++)
            {
                at.e = (e+delP*j)*2;
                at.w = (w+delP*j)*2;
                at.s = s+delS*j;
                at.t = i;
                at.att = j;
                T.insert(pair<int,attack>(d+delD*j,at));
                days.insert(d+delD*j);
            }
        }
        //init seg tree
        for(int i=0;i<M-1;i++)
            arr[i].mi = 0;
        arr[M-1].mi = (1<<30);
        S.init(M-1,arr,arr[M-1]);
        int ans = 0;
        for(st=days.begin();st!=days.end();st++)
        {
            mtr = T.equal_range(*st);
            for(mt = mtr.first;mt!=mtr.second;mt++)
            {
                at = mt->second;
                //printf("%d %d %d %d\n",at.w+OFF,at.e+OFF,at.s,S.query(at.w+OFF,at.e+OFF).mi);
                if(S.query(at.w+OFF,at.e+OFF).mi<at.s)
                    ans++;
            }
            for(mt = mtr.first;mt!=mtr.second;mt++)
            {
                at = mt->second;
                v = at.s;
                S.update<&updateV>(at.w+OFF,at.e+OFF);
            }
        }
        printf("Case #%d: %d\n",casenum,ans);
    }
    return 0;
}
