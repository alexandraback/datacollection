#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <stack>
#include <cstdlib>
#include <set>
#include <iterator>
using namespace std; 
const int INF = ~(1<<31);
const double EPS = 10e-6;
#define mp make_pair
#define pb push_back
#define ppb pop_back
 
int gcd(int a, int b){
    if(b>a) { b+=a; a=b-a; b=b-a; }
    if(b==0) return a;
    else return gcd(b, a%b);
 }
 
int lcm(int a, int b){
    return a / gcd(a, b) * b;
 }
 
 struct point{
    double x, y;
    point(){ 
        x = 0; 
        y = 0; 
    }
    point(double a, double b){
        x = a;
        y = b;
    }
    friend bool operator == (point a, point b){
        return a.x == b.x && a.y == b.y;
    }
 };
 
 struct vect{
    double x, y;
    vect(double a, double b){
        x = a;
        y = b;
    }
    vect(double ax, double ay, double bx, double by){
        x = bx - ax;
        y = by - ay;
    }
    vect(point a, point b){
        x = b.x - a.x;
        y = b.y - a.y;
    }
    double len(){
        return sqrt(x * x + y * y);
    }
 };
 
 struct line{
	 double a, b, c;
	 line(){
		 a = 0;
		 b = 0;
		 c = 0;
	 }
	 line(int x, int y, int z){
		 a = x + 0.0;
		 b = y + 0.0;
		 c = z + 0.0;
	 }
	 line(double x, double y, double z){
		 a = x;
		 b = y;
		 c = z;
	 }
	 line(point f, point g){
		 double va = f.x - g.x;
		 double vb = f.y - g.y;
		 a = vb; 
		 b = -va;
		 c = (- a) * f.x - b * f.y;
	 }
 };
 
double dist(point a, point b){
    return sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) + 0.0);
 }
 
double dist(pair<int, int> a, pair<int, int> b){
	return sqrt((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second) + 0.0);
 }
 
double dot(vect v1, vect v2){
    return v1.x * v2.x + v1.y * v2.y;
 }
 
double cross(vect v1, vect v2){
    return v1.x * v2.y - v1.y * v2.x;
 }
 
 
int sign(double a){
    if(a > 0) return 1;
    else if(a < 0) return -1;
    else return 0;
 }
 
int sign(int a){
    if(a > 0) return 1;
    else if(a < 0) return -1;
    else return 0;
 }
 
 bool intersect (int a, int b, int c, int d) {
    if (a > b)  swap (a, b);
    if (c > d)  swap (c, d);
    return max(a,c) <= min(b,d);
 }
 
 bool segm_intersect(point a, point b, point c, point d){
	vect ab(a, b), cd(c, d), ac(a, c), ad(a, d), bc(b, c), bd(b, d), ca(c, a), cb(c, b);
	if(sign(cross(ab, ac)) * sign(cross(ab, ad)) <= 0 && sign(cross(cd, ca)) * sign(cross(cd, cb)) <= 0 
		&& intersect((int)a.x, (int)b.x, (int)c.x, (int)d.x) && intersect((int)a.y, (int)b.y, (int)c.y, (int)d.y)) 
			return true;
	else return false;
 }
 
 bool pt_in_sgm(point t, point a, point b){
	vect v1(t, a), v2 (t, b);
	if(cross(v1, v2) == 0 && dot(v1, v2) < 0) return true;
	else return false;
 }
 
 bool pt_on_line(point t, line l){
	 if(fabs(l.a * t.x + l.b * t.y + l.c) < EPS) return true;
	 else return 0;
 }
 
 pair<char, point > line_intersect(point a, point b, point c, point d){
	line f(a, b), g(c, d);
	if(pt_on_line(c, f) && pt_on_line(d, f)) return make_pair(2, point(0, 0));
	else {
		vect v1(f.a, f.b), v2(g.a, g.b);
		if(fabs(cross(v1, v2)) < EPS) return make_pair(0, point(0, 0));
		else{
			double x = (g.c * f.b - f.c * g.b) / (f.a * g.b - g.a * f.b);
			double y = (g.c * f.a - f.c * g.a) / (f.b * g.a - f.a * g.b);
			return make_pair(1, point(x, y));
		}
	}
 }
 
 point reflect(point t, line l){
	if(pt_on_line(t, l)) return t;
	else{
		line k;
		k.a = l.b;
		k.b = - l.a;
		k.c = ( - k.a ) * t.x - k.b * t.y;
		point c;
		c.x = (k.c * l.b - l.c * k.b) / (l.a * k.b - k.a * l.b);
		c.y = (k.c * l.a - l.c * k.a) / (l.b * k.a - l.a * k.b);
		return point(2 * c.x - t.x, 2 * c.y - t.y); 
	}
 }
 
double orient_sq(point x1, point x2, point x3){
	return (x1.x * ( x2.y - x3.y ) + x2.x * ( x3.y - x1.y ) + x3.x * ( x1.y - x2.y )) / 2.0;
}
 
double orient_sq(pair<int, int> x1, pair<int, int> x2, pair<int, int> x3){
	return (x1.first * ( x2.second - x3.second ) + x2.first * ( x3.second - x1.second ) + x3.first * ( x1.second - x2.second )) / 2.0;
}
 
vector<pair<int, int> > convex_hull (vector<pair<int, int> > points){
	vector<pair<int, int> > up, down;
	pair<int, int> last;
	sort(points.begin(), points.end());
	last = points.back();
	up.push_back(points[0]);
	down.push_back(points[0]);
	for(int i = 1; i < points.size(); i++){
		if(i == points.size() - 1 || orient_sq(up.back(), points[i], last) > 0){
			while(up.size() > 1 && orient_sq(up[up.size() - 2], up.back(), points[i]) <=  0) up.pop_back();
			up.push_back(points[i]);
		}
		if(i == points.size() - 1 || orient_sq(down.back(), points[i], last) <= 0){
			while(down.size() > 1 && orient_sq(down[down.size() - 2], down.back(), points[i]) >= 0) down.pop_back();
			down.push_back(points[i]);
		}
	}
	vector<pair<int,int> > ans;
	for(int i = 0; i < down.size(); i++)
		ans.push_back(down[i]);
	for(int i = up.size() - 2; i > 0; i--)
		ans.push_back(up[i]);
	return ans;
}

int str_parse(string s){
	return s[0] - '0';
}
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("qb.xml", "w", stdout);
	string tmp;
	int a, b;
	pair<string, string> holder = mp("<holder>", "</holder>");
	pair<string, string> item = mp("<item>", "</item>");
	pair<string, string> question = mp("<question>", "</question>");
	pair<string, string> answer = mp("<answer>", "</answer>");
	pair<string, string> comment = mp("<comment>", "</comment>");
	pair<string, string> author = mp("<author>", "</author>");
	pair<string, string> source = mp("<source>", "</source>");
	pair<string, string> pack = mp("<pack>", "</pack>");
	
	cout << "<?xml version='1.0'?>" << endl;

	while(!cin.eof()){
		//if(tmp[tmp.size() - 1] == '~') break;
		getline(cin, tmp);
		cout << item.first << endl;
		cout << question.first << tmp << question.second << endl;
		getline(cin, tmp);
		getline(cin, tmp);
		b = str_parse(tmp);
		while(b--){
			getline(cin, tmp);
			cout << answer.first << tmp << answer.second << endl;
		}
		getline(cin, tmp);
		cout << author.first << tmp << author.second << endl;
		getline(cin, tmp);
		cout << comment.first << tmp << comment.second << endl;
		getline(cin, tmp);
		cout << source.first << tmp << source.second << endl;
		getline(cin, tmp);
		cout << pack.first << tmp << pack.second << endl;
		cout << item.second << endl;
	}
	return 0;
}