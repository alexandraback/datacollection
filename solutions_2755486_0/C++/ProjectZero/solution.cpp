#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

long long arr[100000000];

const int INF = 1e9;
const int MAXSEGMENT = 2000000+100;
const int MAXN = 1000+20;
const int MAXDAY = 	676060+100;

struct segment_tree{
	int val,add;
}segment_tree[MAXSEGMENT];

void init(int node,int left,int right){
	segment_tree[node].val = segment_tree[node].add = 0;
	if(left == right) return ;
	init(2*node,left,(left+right)>>1);
	init(2*node+1,((left+right)>>1)+1,right);
}
int findmax(int node,int left_tree,int right_tree,int left,int right){
	//printf("(%d,%d) : (%d,%d)\n",left_tree,right_tree,left,right);
	if(left > right_tree || right < left_tree) return 0;
	if(left > right) return 0;
	if(left_tree == left && right_tree == right){
		return segment_tree[node].val + segment_tree[node].add;
	}
	
	int mid = (left_tree+right_tree)>>1;
	int val_left = findmax(2*node,left_tree,mid,left,min(right,mid));
	int val_right = findmax(2*node+1,mid+1,right_tree,max(mid+1,left),right);
	
	return val_left > val_right?val_left:val_right;
}

void update(int node,int left_tree,int right_tree,int left,int right,int val){
	//printf("(%d,%d) : (%d,%d)\n",left_tree,right_tree,left,right);
	if(left > right_tree || right < left_tree) return ;
	if(left > right) return ;
	if(left_tree == left && right_tree == right){
		segment_tree[node].add += val;
		return ;	
	}
	
	int mid = (left_tree+right_tree)>>1;
	update(2*node,left_tree,mid,left,min(right,mid),val);
	update(2*node+1,mid+1,right_tree,max(mid+1,left),right,val);

	segment_tree[node].val = max(segment_tree[2*node].val+segment_tree[2*node].add,segment_tree[2*node+1].val+segment_tree[2*node+1].add);
	segment_tree[node].add = 0;
}

int size_segment_tree;

struct att{
	int west,east;
	int strength,tribe;
};

struct att make(int w,int e,int s,int t){
	struct att tmp;
	tmp.west = w; tmp.east = e;
	tmp.strength = s; tmp.tribe = t;
	return tmp;
}

vector <struct att> V[MAXDAY];	// (n-tribe,height)
vector <int> dist;

int T,N;
int d[MAXN],n[MAXN],w[MAXN],e[MAXN],s[MAXN],delta_d[MAXN],delta_p[MAXN],delta_s[MAXN];

int main(){
	freopen("C-small-attempt5.in","r",stdin);
	freopen("C-small-output5.out","w",stdout);
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		printf("Case #%d: ",_i);
		dist.clear();
		
		for(int i=0;i<MAXDAY;i++) V[i].clear();
		
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			scanf("%d %d",&d[i],&n[i]); // day start  and  n day
			scanf("%d %d",&w[i],&e[i]); // west east most
			scanf("%d",&s[i]); // strength
			scanf("%d %d %d",&delta_d[i],&delta_p[i],&delta_s[i]);
			
			for(int j=d[i],k=1,str=s[i],left=w[i],right=e[i];k<=n[i];k++,j+=delta_d[i],str+=delta_s[i],left+=delta_p[i],right+=delta_p[i]){
				V[j].push_back(make(left,right,str,i));
				dist.push_back(left);
				dist.push_back(right);
			}
		}
		//printf("TEST1\n");
		
		sort(dist.begin(),dist.end());
		dist.erase(unique(dist.begin(),dist.end()),dist.end());
		size_segment_tree = dist.size();
		init(1,1,size_segment_tree);
		
		//printf("size_tree = %d\n",size_segment_tree);
		//for(int i=0;i<dist.size();i++) printf("[%d]",dist[i]);
		//printf("\n");
		memset(arr,0,sizeof(arr));
		
		int left,right,strength,ind_left,ind_right,valmax;
		long long valmin;
		long long ans = 0;
		for(int i=0;i<MAXDAY;i++){
			int size = V[i].size();
				
			for(int j=0;j<size;j++){
				left = V[i][j].west;
				right = V[i][j].east;
				strength = V[i][j].strength;
				
				valmin = arr[left];
				for(int k=left+1;k<right;k++) valmin = min(valmin,arr[k]);
				
				if(strength > valmin){
					//printf("[%d,%d] = %d\n",left,right,strength);
					ans++;
				}
			}
			for(int j=0;j<size;j++){
				left = V[i][j].west;
				right = V[i][j].east;
				strength = V[i][j].strength;
										
				for(int k=left;k<right;k++) arr[k] = max(arr[k],(long long)strength);
			}
			
			//if(i<10) printf("i = %d  ans = %lld\n",i,ans);
				//segment tree
			/*for(int j=0;j<size;j++){
				left = V[i][j].west;
				right = V[i][j].east;
				strength = V[i][j].strength;
				
				ind_left = lower_bound(dist.begin(),dist.end(),left)-dist.begin()+1;
				ind_right = lower_bound(dist.begin(),dist.end(),right)-dist.begin()+1;
				valmax = findmax(1,1,size_segment_tree,ind_left,ind_right);
				
				if(strength > valmax) ans++;
				//printf("[%d(%d),%d(%d)] valmax = %d\n",left,ind_left,right,ind_right,valmax);
			}
			for(int j=0;j<size;j++){
				left = V[i][j].west;
				right = V[i][j].east;
				strength = V[i][j].strength;
							
				ind_left = lower_bound(dist.begin(),dist.end(),left)-dist.begin()+1;
				ind_right = lower_bound(dist.begin(),dist.end(),right)-dist.begin()+1;
				valmax = findmax(1,1,size_segment_tree,ind_left,ind_right);
							
				if(strength > 0) update(1,1,size_segment_tree,ind_left,ind_right,strength);
			}*/
		}
		printf("%lld\n",ans);
	}
	
	
	return 0;
}