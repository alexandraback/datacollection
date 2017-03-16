#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define INF (1LL << 50)
struct segval{
    segval(){
	min = all = 0;
	left = right = 0;
    }
    long long min, all;
    segval *left, *right;
};
int feald[1050000];
segval segvals[1000000];
long long segp = 1;
segval *root = segvals;
struct Q{
    Q(long long a, long long b, long long c, long long x){
	d = a;w = b;e = c;s = x;
    }
    long long d, w, e, s;
};

bool compQ(const Q &a, const Q &b){
    return a.d < b.d;
}

void make_child(segval *r){
    if(r->left == 0)
	r->left = segvals + segp++;
    if(r->right == 0)
	r->right = segvals + segp++;
}

long long minimum(long long left, long long right, long long bottom = 0, long long top = (1LL << 31), segval *r = root){
    int res = 1 << 30;
    for(int i = left; i < right;i++)
	res = min(res, feald[i]);
    return res;
}

void setval(long long left, long long right, long long val, long long bottom = 0, long long top = (1LL << 31), segval *r = root){
    for(int i = left;i < right;i++){
	feald[i] = max(feald[i], (int)val);
    }
}

vector<Q> query;
int main(){
    int T, N, d, n, w, e, s, dd, dp, ds;
    cin >> T;
    for(long long t = 1;t <= T;t++){
	root->min = root->all = 0;
	root->left = root->right = 0;
	fill(feald, feald + 1050000, 0);
	cin >> N;
	query.clear();
	for(long long i = 0;i < N;i++){
	    cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
	    w += 205000;
	    e += 205000;
	    for(;n--;){
		query.push_back(Q(d, w, e, s));
		d += dd;
		w += dp;e += dp;
		s += ds;
	    }
	}
	sort(query.begin(), query.end(), compQ);
	long long res = 0;
	long long setpos = 0;
	for(long long i = 0;i < query.size();i++){
	    Q tmp = query[i];
	    if(minimum(tmp.w, tmp.e) < tmp.s)res++;
	    if(i == query.size() - 1 || query[i].d != query[i + 1].d){
		while(setpos <= i){
		    tmp = query[setpos];
		    setval(tmp.w, tmp.e, tmp.s);
		    setpos++;
		}
	    }
	}
	cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
