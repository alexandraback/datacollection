struct Point{
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) { }
};

double torad(double deg){
    return deg/180 * PI;
}

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B){
    return Vector(A.x+B.x, A.y+B.y);
}

Vector operator - (const Point& A, const Point& B){
    return Vector(A.x-B.x, A.y-B.y);
}

double Cross(const Vector& A, const Vector& B){
    return A.x*B.y - A.y*B.x;
}

Vector Rotate(const Vector& A, double rad){
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

bool operator < (const Point& p1, const Point& p2){
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool operator == (const Point& p1, const Point& p2){
    return p1.x == p2.x && p1.y == p2.y;
}

double dis(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

// 点集凸包
// 如果不希望在凸包的边上有输入点，把两个 <= 改成 <
// 如果不介意点集被修改，可以改成传递引用
vector<Point> ConvexHull(vector<Point> p){
    // 预处理，删除重复点
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    int m = 0;
    vector<Point> ch(n+1);
    for(int i = 0; i < n; i++){
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--){
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    ch.resize(m);
    return ch;
}

// 多边形的有向面积
double PolygonArea(vector<Point> p){
    double area = 0;
    int n = p.size();
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i]-p[0], p[i+1]-p[0]);
    return area/2;
}

vector<Point> v;

double max(double a,double b){
    return a>b?a:b;
}

int main(){//求平面最远点对的距离
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        double a,b;
        scanf("%lf%lf",&a,&b);
        v.push_back((Point){a,b});
    }
    v=ConvexHull(v);
    int m=v.size();
    double ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            ans=max(ans,dis(v[i],v[j]));
        }
    }
    printf("%.0f\n",ans);
    return 0;
}