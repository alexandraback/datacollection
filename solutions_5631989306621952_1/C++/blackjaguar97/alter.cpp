#include<bits/stdc++.h>
using namespace std;
bool is[2000];
int main(){
   // freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int T , Tn=0;
    cin>>T;
    while(T--){
        //cout<<T<<endl;
        deque < char > Q;
        printf("Case #%d: ",++Tn);
        string str;
        memset(is , 0 , sizeof(is));
        cin>>str;
        int n = str.size();
       // reverse(str.begin() , str.end());
        int mx=-1;
        for(int j=0;j<str.size();j++){
            if(str[j] >= mx)
                is[j]=1;
            mx = max(mx , (int) (str[j]) );
        }
        for(int j=0;j<n;j++){
            if(is[j]) {
                Q.push_front(str[j]);
            }
            else Q.push_back(str[j]);
        }
        for(int j=0;j<Q.size();j++)
            putchar(Q[j]);
        puts("");

    }

}

