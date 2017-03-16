/*
 * Author: NomadThanatos
 * Created Time:  2012-5-6 18:07:25
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())

typedef long long lint;

const int MAXINT = -1u>>1;

const int MAXN = 100 + 50;
lint f[MAXN][MAXN];

struct Node {
	int type,id;
	lint num;
	void input(const int &_id) {
		id = _id;
		scanf("%I64d%d",&num,&type);
		//num = num / 10000;
	}
}toy[MAXN],box[MAXN];

vector<Node> addtoy,addbox;

int main() {
	freopen("C.out","w",stdout);
	int T;
	int N,M;
	scanf("%d",&T);
	for(int t = 0 ; t < T ; t++) {
		scanf("%d%d",&N,&M);
		memset(f,0,sizeof(f));
		for(int i = 1 ; i < N + 1 ; i++) {
			toy[i].input(i);
		}
		for(int j = 1 ; j < M + 1 ; j++) {
			box[j].input(j);
		}
		for(int i = 1 ; i < N + 1 ; i++) {
			for(int j = 1 ; j < M + 1 ; j++) {
				//f[i][j] = max(f[i][j],f[i - 1][j]);
				//f[i][j] = max(f[i][j],f[i][j - 1]);
				//f[i][j] = max(f[i][j],f[i - 1][j - 1]);
				if (toy[i].type == box[j].type) {
					lint tottoy = toy[i].num;
					lint totbox = box[j].num;
					addtoy.clear();
					addbox.clear();
					f[i][j] = max(f[i][j],f[i - 1][j - 1] + min(tottoy,totbox));
					for(int ii = i - 1 ; ii > 0 ; ii--) {
						if (toy[ii].type == toy[i].type) {
							addtoy.push_back(toy[ii]);
						}
						if ((int)(addtoy.size()) > 1) {
							addtoy.back().num += addtoy[(int)(addtoy.size()) - 2].num;
						}
					}
					for(int jj = j - 1 ; jj > 0 ; jj--) {
						if (box[jj].type == box[j].type) {
							addbox.push_back(box[jj]);
						}
						if ((int)(addbox.size()) > 1) {
							addbox.back().num += addbox[(int)(addbox.size()) - 2].num;
						}
					}
					for(int ii = 0 ; ii < (int)addtoy.size() ; ii++) {
						for(int jj = 0 ; jj < (int)addbox.size() ; jj++) {
							f[i][j] = max(f[i][j],f[addtoy[ii].id - 1][addbox[jj].id - 1] + min(tottoy + addtoy[ii].num,totbox + addbox[jj].num));
						}
					}
				}
			}
		}
		lint res = 0;
		for(int i = 1 ; i < N + 1 ; i++) {
			for(int j = 1 ; j < M + 1 ; j++) {
				//printf("%I64d ",f[i][j]);
				res = max(res,f[i][j]);
			}
			//printf("\n");
		}
		//cout << "Case #" << t + 1 << ": " << res << endl;
		printf("Case #%d: %I64d\n",t + 1, res);
	}
    return 0;
}

