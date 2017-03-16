#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, star, ans;
pair<int,int> a[1000];
bool clear[1000], star2[1000], done;


bool comp(const pair<int,int> p, const pair<int,int> q){
    if(p.second == q.second){
	return p.first < q.first;
    }else{
	return p.second < q.second;
    }
}

void solve(int n){
    if(!star2[n] && !clear[n] && star >= a[n].second){
	ans++;
	star += 2;
	star2[n] = clear[n] = true;
	done = true;
    }else if(!star2[n] && clear[n] && star >= a[n].second){
	ans++;
	star++;
	star2[n] = true;
	done = true;
    }else if(!star2[n] && !clear[n] && star >= a[n].first){
	ans++;
	star++;
	clear[n] = true;
	done = true;
    }
}

bool check(){
    for(int hoge = 0; hoge < N; hoge++){
	if(!star2[hoge]){
	    return false;
	}
    }
    return true;
}

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
	ans = star = 0;
	memset(clear, false, sizeof(clear));
	memset(star2, false, sizeof(star2));
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
	    scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + N, comp);
	while(!check()){
	    done = false;
	    for(int i = 0; i < N; i++){
		if(done) break;
		solve(i);
	    }
	    if(!done){
		break;
	    }
	}
	if(ans == 0) printf("Case #%d: Too Bad\n", t);
	else printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
