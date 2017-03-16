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
#define VAL 2000047

typedef long long ll;
typedef pair<int, int> pii;

int A[23];
int X[2][VAL];

int extra(){
    int N = 0;
    scanf("%d", &N);
    For(i,N) scanf("%d", A+i);
    For(k, 2) For(i,VAL) X[k][i] = -1;
    X[0][0] = 0;
    
    vector<int> one;
    vector<int> two;

    For(i,N) {
        For(j,VAL/2){
            if (X[i%2][j]>=0){
                X[(i+1)%2][j] = X[i%2][j];
                if((j-A[i]>=0) && (X[i%2][j-A[i]]<0 || j-A[i]==0)) X[(i+1)%2][j-A[i]] = j;
                if((j+A[i]<VAL/2) && (X[i%2][j+A[i]]<0)) X[(i+1)%2][j+A[i]] = j;
            }
        }
        //For(k,20) printf("%d%c",X[(i+1)%2][k],(k==19)?'\n':' ');
        if (X[(i+1)%2][0]!=0) {
            int x = 0, y, z;
            do{
                y = X[(i+1)%2][x];
                z = y-x;
                if (z>0) one.push_back(z);
                else two.push_back(-z);
                x = y;
            } while (x!=0);
            sort(one.begin(), one.end());
            sort(two.begin(), two.end());
            For(k,one.size()) printf("%d%c",one[k],(k==one.size()-1)?'\n':' ');
            For(k,two.size()) printf("%d%c",two[k],(k==two.size()-1)?'\n':' ');
            return 0;
        }
    }
    printf("Impossible\n");
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d:\n",i+1);
        extra();
    }
}
