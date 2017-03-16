

#include <iostream>
#include <vector>
using namespace std;
bool tryyy(int t, int r, int c){
    if (r * c % t !=0)
        return false;
    if (r==1){
        if (t>=3)
            return false;
        return true;
    }
    if(r == 2){
        if(t >= 4)
            return false;
        return true;
    }
    if( r == 3){
        if (t <=4)
            return true;
    }
    if (t>=7)
        return false;
    return true;
}
void solve(int icase){
    int t, r, c;
    cin >>t >> r >> c;
    if(r > c)
        swap(r, c);
    bool q = tryyy(t, r, c);
    cerr << q <<endl;
    if(q)
        printf("Case #%d: GABRIEL\n", icase );
    else
        printf("Case #%d: RICHARD\n", icase);

}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve(i+1);

    }

}
