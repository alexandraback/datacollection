#include <bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=(1<<20);
//int arr[MX] ;
string str[13]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int num[12] = {0 , 2 , 8 , 3 , 6 , 7 , 4 , 5 , 9 , 1};
//zero// two //// eight // three // six//   seven // four // five // nine // one
char let[15]= "ZWGHXSUVIO";
int n , T , Tn=0 , rem;
int cnt[300];
void fakss(int x){
    for(int j=0;j<str[x].size();j++){
        cnt[str[x][j]]--;
        if(cnt[str[x][j]] == 0) rem--;
    }
}
int main(){

    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);

    //for(int j=0;j<10;j++) sz[j] = strl
    cin>>T;
    while(T--){
        printf("Case #%d: ",++Tn);
        string ss;
        cin>>ss;
        memset(cnt , 0 , sizeof(cnt));
        for(int j=0;j<ss.size();j++) cnt[ss[j]]++;
        rem=0;
        for(int j=0;j<300;j++) if(cnt[j]) rem++;
        vector < int > v;
        for(int j=0;j<10;j++){
            while(cnt[let[j]]){
        //        cout<<num[j]<<endl;
                v.push_back(num[j]);
                fakss(num[j]);
            }
        }
        sort(v.begin() , v.end());
        for(int j=0;j<v.size();j++) printf("%d",v[j]);
        puts("");
    }

}

