#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

typedef vector<int> vi;

int main(){
	int tc;
	int x, y;
	queue<int> xq;
	queue<int> yq;
	queue<int> jq;
	queue<string> pq;
	int casenum = 1;

	cin >> tc;
	while(tc-- > 0){
		scanf("%d %d",&x,&y);

		while(!xq.empty()) xq.pop();
		while(!yq.empty()) yq.pop();
		while(!jq.empty()) jq.pop();
		while(!pq.empty()) pq.pop();

		xq.push(0);
		yq.push(0);
		jq.push(1);
		pq.push("");

		while(!xq.empty()){
			int cx = xq.front(); xq.pop();
			int cy = yq.front(); yq.pop();
			int cj = jq.front(); jq.pop();
			string cp = pq.front(); pq.pop();
			
			if (cx == x && cy == y){
				cout << "Case #" << casenum++ << ": " << cp << endl;
				break;
			}

			if(x >= cx+cj){
				xq.push(cx+cj);
				yq.push(cy);
				jq.push(cj+1);
				pq.push(cp+"E");
			} else if (x < cx+cj){
				xq.push(cx-cj);
				yq.push(cy);
				jq.push(cj+1);
				pq.push(cp+"W");
			}

			if(y >= cy+cj){
				xq.push(cx);
				yq.push(cy+cj);
				jq.push(cj+1);
				pq.push(cp+"N");
			} else if(y < cy+cj){
				xq.push(cx);
				yq.push(cy-cj);
				jq.push(cj+1);
				pq.push(cp+"S");
			}
		}
	}
}