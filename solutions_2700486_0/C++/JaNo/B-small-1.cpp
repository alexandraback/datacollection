//Fruit of Light
//FoL CC
//Apple Strawberry

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define ForEach(it, i) for(typeof i.begin() it = i.begin(); it!=i.end(); ++it)
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;

double overtwo(int n, int a){
    long double x = 1, sum = 0;
    int y = n, z = 1;
    For(i, n-a) {
       // printf("%Lf %Lf\n", x, sum);
        sum+=x;
        x = x*double(y)/double(z);
        y--;
        z++;
    }
//    printf("%Lf %Lf\n", x, sum);
    For(i, n) {
        sum/=2;
    }
    return sum;
}

int n,x,y;
int extra(){
    scanf("%d%d%d",&n,&x,&y);
    if (x<0) x = -x;
    int L = 0;
    int p = 0, s = 0;
    while(s+p+p+1<=n) {
        s+=p+p+1;
        p+=2;
        L+=1;
    }
    double prav;
    if ((x+y)/2<L) prav = 1.0;
    else if ((x+y)/2==L) {
        int rest = n-s;
        int H = L*2;
        while(rest>H) {
            rest-=2;
            y--;
            H--;
        }
        if (y<0) prav = 1.0;
        else{ 
            prav = overtwo(rest, y);
        }
    }else {
        prav = 0.0;
    }
    printf("%.10lf\n",prav);
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
