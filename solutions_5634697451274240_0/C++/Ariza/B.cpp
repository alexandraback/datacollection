#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string STR;
int recur(int idx, char prev){
//    cout << "CHK " << idx << " ";
    if (idx==-1) return 0;
    int next=-1;
    for (int i=idx;i>=0;--i){
        if (STR[i]!=STR[idx]){
            next=i;
            break;
        }
    }
//    cout << "NEXT " << next << endl;
    if (next==-1){
        return 1;
    }
    else{
        return recur(next,STR[idx])+(1);
    }
}

void solve(){
    printf(" ");
    cin >> STR;
    int start=-1;
    for (int i=STR.size();i>=0;--i){
        if (STR[i]=='-'){
            start=i;
            break;
        }
    }
    printf("%d\n",recur(start,'+'));
}

int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
