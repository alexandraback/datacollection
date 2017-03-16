#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,n) fr(i,0,n)
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
int r, n, m, k;

vector< vector<int> > pre[5*5*5*5];

void init(vector<int>& tmp, vector<int>& aux, int ind, int prod, int qtd){
//		if(tmp[ind] == 4) printf(">>>>> %d\n", prod);
	if(qtd > 3) return;
	pre[prod].pb(aux);
	if(ind < tmp.size()){
		init(tmp, aux, ind+1, prod, qtd);
		aux.pb(tmp[ind]);
		init(tmp, aux, ind+1, prod * tmp[ind], qtd+1);
		aux.pop_back();
	}
}

void init(){
	vector<int> tmp, aux;
	fr(i, 2, 6) rep(j, 3) tmp.pb(i);
	init(tmp, aux, 0, 1, 0);
	rep(i, 5*5*5*5) sort(pre[i].begin(), pre[i].end()), pre[i].resize(unique(pre[i].begin(), pre[i].end()) - pre[i].begin());
//	rep(i, 5*5*5*5){
//		if(pre[i].size()){
//			printf("> %d\n", i);
//			rep(j, pre[i].size()){
//			rep(k, pre[i][j].size()) printf("%d\n", pre[i][j][k]);
//			printf("_______\n");
//			}
//		}
//	}
}

vector<int> tg;

bool back(int ind, vector<int>& tmp){
	if(ind == tg.size()){
		int c = 0;
		rep(i, tmp.size()) if(tmp[i]) c += tmp[i];
		return c && c <= n;
	}
	if(tg[ind] == 1) return back(ind+1, tmp);
	
	rep(i, pre[tg[ind]].size()){
		int qtd = pre[tg[ind]][i].size();
		bool pode = true;
		rep(j, qtd){
			if(pre[tg[ind]][i][j] > m){
				pode = false;
				break;
			}
		}
		if(pode){
			vector<int> posto = vector<int>(tmp.size(), 0);
			vector<int> copia = tmp;
			if(posto.size() != tmp.size()) throw 1;
			
			rep(j, qtd){
				int num = pre[tg[ind]][i][j];
				++posto[num];
			}
			rep(j, qtd){
				int num = pre[tg[ind]][i][j];	
				tmp[num] = max(tmp[num], posto[num]);
			}
//			if(ind == 0) cout << "ake " << posto[3] << " " << tmp[3] << endl;
			if(back(ind+1, tmp)) return true;
			tmp = copia;
		}
	}
	
	return false;
}

void fill(vector<int>& resp){
	while(resp.size() < n) resp.pb(2 + rand() % (m-1));
}

void print(int num){
	cout << ">>>> " << num << endl;
	rep(i, pre[num].size()){
		rep(j, pre[num][i].size()) cout << pre[num][i][j] << endl;
		cout << "______" << endl;
	}
}

int main(){
	srand(1987);
	init();
//	print(36);
//		print(9);
//			print(4);
	
	ios::sync_with_stdio(false);
	int casos;
	 cin >> casos;
	 
	 rep(cas, casos){
	 	cout << "Case #" << (cas+1) << ":" << endl;
	 	cin >> r >> n >> m >> k;
	 	rep(i, r){
	 		tg.clear();
			rep(j, k){
				int x;
				cin >> x;
				tg.pb(x);
			}
			vector<int> rec = vector<int>(10, 0),resp;
			if(rec.size() == 0) throw 1;
			bool achou = back(0, rec);
//			cout << achou << endl;
			rep(i, rec.size()){
				while(rec[i] > 0) resp.pb(i), --rec[i];
			}
			fill(resp);
			rep(j, resp.size()) cout << resp[j];
			cout << endl;
			
		}	
//		cout << "Case #" << (cas+1) << ": " <<  cont << endl;
	 }
}


