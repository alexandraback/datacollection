#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define LEFT 0
#define RIGHT 1

int newColor=2;

struct collision {
	int s1, p1, s2, p2, idA, idB;
	collision(int s1, int p1, int s2, int p2, int idA, int idB) {
		this->s1 = s1;
		this->s2 = s2;
		this->p1 = p1;
		this->p2 = p2;
		if (s1 < s2) {
		this->s2 = s1;
		this->s1 = s2;
		this->p2 = p1;
		this->p1 = p2;
		}
		// S1 > S2
		this->idA = idA;
		this->idB = idB;
	}
};
bool operator<(const collision &me, const collision &that) {
	return (me.p2-me.p1)*(that.s1-that.s2) < (that.p2-that.p1) * (me.s1-me.s2);
}

int nCars;
vector<int> state;
vector<vector<bool> > isColliding;
vector<bool> seen;

bool recolor2(int x, int col) {
	if (seen[x]) {
		if (state[x] != col) return false;
		return true;
	}
	seen[x] = true;
	if ((col ^ state[x]) == 1) return false;
	for (int i = 0; i < nCars; i++) {
		if (i==x) continue;
		if ((state[x] ^ state[i]) < 2) {
			state[i] = (state[x] ^ state[i] ^ col);
		}
	}
	state[x] = col;
	int notCol = col ^ 1;
	for (int i = 0; i < nCars; i++) {
		if (isColliding[x][i] || isColliding[i][x]) {
			if (!recolor2(i,notCol)) return false;
		}
	}
	return true;
}
bool recolor(int x, int col) {
	seen = vector<bool>(nCars,false);
	return recolor2(x,col);
}

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		newColor = 2;
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);
		scanf("%d ",&nCars);
		vector<int> s, p;
		vector<int> nCover;
		state = vector<int>();
		vector<int> origstate = vector<int>();
		isColliding = vector<vector<bool> >(nCars, vector<bool>(nCars));
		nCover = vector<int>(nCars,0);
		for (int i = 0; i < nCars; i++) {
			char c; int speed,pos;
			scanf("%c %d %d ",&c,&speed,&pos);
			s.push_back(speed);
			p.push_back(pos);
			origstate.push_back(c=='L'?LEFT:RIGHT);
			state.push_back(newColor+=2);
		}
		multiset<collision> colls;
		for (int i = 0; i < nCars; i++) {
			for (int j = i+1; j < nCars; j++) {
				if (s[i] == s[j]) {
					if (p[i]+5 >= p[j] && p[j]+5 >= p[i]) {
						nCover[i]++;
						nCover[j]++;
						isColliding[i][j] = 1;
					}
					continue;
				}
				colls.insert(collision(s[i],p[i],s[j],p[j]+5,i,j));
				colls.insert(collision(s[i],p[i]+5,s[j],p[j],i,j));
			}
		}
		bool zeroFlag = true;
		bool failure = false;
		collision ans = collision(0,0,0,0,0,0);
		for (multiset<collision>::iterator itr = colls.begin(); itr != colls.end(); itr++) {
			//D("%d %d %d %d | %d %d (%.2f)\n",itr->s1,itr->p1,itr->s2,itr->p2,itr->idA,itr->idB,((double)itr->p2-itr->p1)/(itr->s1-itr->s2));
			if (itr->p2 < itr->p1) {
				isColliding[itr->idA][itr->idB] = !isColliding[itr->idA][itr->idB];
				if (isColliding[itr->idA][itr->idB]) {
					nCover[itr->idA]++;
					nCover[itr->idB]++;
				} else {
					nCover[itr->idA]--;
					nCover[itr->idB]--;
				}
			} else if (zeroFlag) {
				zeroFlag = false;
				for (int i = 0; i < nCars; i++) {
					if (nCover[i]) {
						recolor(i,origstate[i]);
					}
					recolor(i,state[i]);
				}
			}
			if (!zeroFlag) {
				// normal collision
				isColliding[itr->idA][itr->idB] = !isColliding[itr->idA][itr->idB];
				if (isColliding[itr->idA][itr->idB]) {
					nCover[itr->idA]++;
					nCover[itr->idB]++;
					if (!recolor(itr->idA,state[itr->idA])) {
						ans = *itr;
						failure = true;
					}
				} else {
					nCover[itr->idA]--;
					nCover[itr->idB]--;
				}
				if (failure) break;
				if (!nCover[itr->idA]) state[itr->idA] = (newColor+=2);
				if (!nCover[itr->idB]) state[itr->idB] = (newColor+=2);
			}
		}
		
		if (failure) {
		printf("Case #%d: %.6f\n",test,((double)ans.p2-ans.p1)/(ans.s1-ans.s2));
		} else {
		printf("Case #%d: Possible\n",test);
		}
	}
}
