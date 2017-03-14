#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int T;
int H,W;
int D;
char map[50][50];
int count;
double x,y;
vector<double> x_list;
vector<double> y_list;

int main(){
	cin >> T;
	for (int times = 0; times < T; ++ times){
		count = 0;
		x_list.clear();
		y_list.clear();
		cin >> H >> W >> D;
		for (int i = 0; i < H; ++i){
			for (int j = 0; j < W; ++j){
				cin >> map[i][j];
				if (map[i][j] == 'X'){
					x = j-0.5;
					y = i-0.5;
				}
			}
		}
		for (int i = -D; i <= D; ++i){
			for (int j = -D; j <=D; ++j){
				if (i==0 && j==0) continue;
				double ghostX = i*(W-2) + (i % 2 == 0 ? x : W-2-x);
				double ghostY = j*(H-2) + (j % 2 == 0 ? y : H-2-y);
				x_list.push_back(ghostX);
				y_list.push_back(ghostY);
			}
		}
		for (int i = 0; i < x_list.size(); ++i){
			double x1 = x_list[i];
			double y1 = y_list[i];
			bool blocked = false;
			for (int j = 0; j < x_list.size(); ++j){
				if (j==i) continue;
				double x2 = x_list[j];
				double y2 = y_list[j];
				double t = 0;
				if (fabs(y2-y1)<1e-9){
					t = (x2-x)/(x1-x);
				} else {
					t = (y2-y)/(y1-y);
				}
				if (fabs(t*(x1-x) - (x2-x)) < 1e-9 &&
					fabs(t*(y1-y) - (y2-y)) < 1e-9 &&
					t > 0 && t < 1) {
					blocked = true;
					break;
				}
			}
			if (!blocked) {
				double d = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
				if (d <= D + 1e-9) {
					++ count;
				}
			}
		}
		cout<<"Case #" << (times + 1) << ": "<<count<<endl;
	}
}