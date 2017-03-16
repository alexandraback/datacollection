#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define sc scanf
#define pr printf

const double eps = 1e-12;
const double PI = 3.1415926535898;
const int alphabet = 256;
const int MN = 510;
const long long inf = (1LL<<60);

using namespace std;
struct pt{
    double x, y;
};
inline double sqr(double X){
    return (X*X);
}
inline double dist(pt a, pt b){
    return sqrt( sqr(a.x-b.x) + sqr(a.y-b.y) + eps);
}
inline double vector_m(pt a, pt b, pt c){
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
inline double scalar_m(pt a, pt b, pt c){
    return (b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y);
}
pt IntersectionOfLines(double A1, double B1, double C1, double A2, double B2, double C2){
    double D = A2*B1 - A1*B2;
    pt ans;
    if(fabs(D)<eps){
        ans.x = -inf;
        ans.y = -inf;
    }
    else{
        ans.x = (C1*B2 - C2*B1)/D;
        ans.y = (A1*C2 - A2*C1)/D;
    }
    return ans;
}
inline bool intersect(double a, double b, double c, double d){
    if(a>b)swap(a, b);
    if(c>d)swap(c, d);
    return (max(a, c)-min(b, d))<eps;
}
inline bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool d[MN][MN][MN];
vector<char>ans;
main(){
	freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);
	//freopen("paint.in", "r", stdin);	freopen("paint.out", "w", stdout);
	int T;
	sc("%d", &T);
	for(int k=1; k<=T; k++){
        pr("Case #%d: ", k);
        int x, y;
        sc("%d%d", &x, &y);
        x += 100;
        y += 100;
        d[0][100][100] = true;
        for(int s=1; s<MN; s++){
            for(int i=0; i<MN; i++){
                for(int j=0; j<MN; j++){
                    d[s][i][j] = false;
                    if(i+s<MN && d[s-1][i+s][j]){
                        d[s][i][j] = true;
                    }
                    else if(j+s<MN && d[s-1][i][j+s]){
                        d[s][i][j] = true;
                    }
                    else if(i-s>=0 && d[s-1][i-s][j]){
                        d[s][i][j] = true;
                    }
                    else if(j-s>=0 && d[s-1][i][j-s]){
                        d[s][i][j] = true;
                    }
                }
            }
            if(d[s][x][y]){
                ans.clear();
                while(s){
                    if(x+s<MN && d[s-1][x+s][y]){
                        ans.pb('W');
                        x += s;
                    }
                    else if(y+s<MN && d[s-1][x][y+s]){
                        ans.pb('S');
                        y += s;
                    }
                    else if(x-s>=0 && d[s-1][x-s][y]){
                        ans.pb('E');
                        x -= s;
                    }
                    else if(y-s>=0 && d[s-1][x][y-s]){
                        ans.pb('N');
                        y -= s;
                    }
                    s--;
                }
                break;
            }
        }
        if(ans.empty()){
            pr("Ops\n");
            return 0;
        }
        for(int i=(int)ans.size()-1; i>=0; i--){
            pr("%c", ans[i]);
        }
        pr("\n");
	}
	return 0;
}
