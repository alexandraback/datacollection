#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <string>
#include <set>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <iterator>
#include <bitset>
#include <cctype>
#include <cmath>
#include <functional>
#include <iomanip>
#include <list>
#include <numeric>
#include <stack>
#include <utility>
#include <cassert>
#include <conio.h>
using namespace std;
#define ll long long

class amit {
public:
	int sx;
	int sy;
	string ans;
	int jump;
	amit() {}
	amit(int a,int b, int c, string d) { sx=a; sy=b; jump=c; ans=d; }
};
string amit_ans[201][201];
bool found[201][201];

void main2() {

	int t;
	cin>>t;

	queue<amit> data;
		set<pair<int,int>> used;
		amit init(0,0,1,"");
		data.push(init);

		int step = 0;
		//cout<<z<<" "<<x<<" "<<y<<endl;
		while(step<200000) {
			step++;
			amit cur = data.front();
			if(abs(cur.sx)<=100 && abs(cur.sy)<=100 && !found[cur.sx+100][cur.sy+100]) {
				amit_ans[cur.sx+100][cur.sy+100] = cur.ans;
			}
			if(cur.jump>501) {
				data.pop();
				continue;
			}
			pair<int,int> cur11 = make_pair(cur.sx+cur.jump,cur.sy);
			if(used.find(cur11)==used.end()) {
				amit cur1(cur.sx+cur.jump,cur.sy,cur.jump+1,cur.ans+"E");
				used.insert(cur11);
				data.push(cur1);
			}
			pair<int,int> cur21 = make_pair(cur.sx-cur.jump,cur.sy);
			if(used.find(cur21)==used.end()) {
				amit cur2(cur.sx-cur.jump,cur.sy,cur.jump+1,cur.ans+"W");
				used.insert(cur21);
				data.push(cur2);
			}
			pair<int,int> cur31 = make_pair(cur.sx,cur.sy+cur.jump);
			if(used.find(cur31)==used.end()) {
				amit cur3(cur.sx,cur.sy+cur.jump,cur.jump+1,cur.ans+"N");
				used.insert(cur31);
				data.push(cur3);
			}
			pair<int,int> cur41 = make_pair(cur.sx,cur.sy-cur.jump);
			if(used.find(cur41)==used.end()) {
				amit cur4(cur.sx,cur.sy-cur.jump,cur.jump+1,cur.ans+"S");
				used.insert(cur41);
				data.push(cur4);
			}
			data.pop();
		}


	for(int z=0; z<t; z++) {
		int x,y;
		cin>>x>>y;
		printf("Case #%d: %s\n",(z+1),amit_ans[x+100][y+100].c_str());
	}
}


void main3() {



}



int main() {
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	main2();




	//printf("Program End\n");
	//_getch();
	return 0;
}