#include <bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=17;
string str1 , str2;
int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int T , Tn=0;
    cin>>T;
    while(T--){
        bool swapped=0;
        cin>>str1>>str2;
        int n = str1.size() , pos = n+1;
        for(int j=0;j<n;j++){
            if(str1[j] != '?' && str2[j] != '?'){
                if(str1[j] > str2[j]){
                    swap(str1 , str2);
                    swapped = 1;
                    pos = j;
                    break;
                }
                if(str2[j] > str1[j]){
                    pos = j;
                    break;
                }
            }
        }
        for(int j=0;j<pos;j++){

            if(str1[j] == '?' && str2[j] == '?') str1[j] = str2[j] = '0';
            else if(str2[j] != '?') str1[j] = str2[j];
            else str2[j] = str1[j];
        }
        for(int j=pos;j<n;j++){
            if(str1[j] == '?') str1[j] = '9';
            if(str2[j] == '?') str2[j] = '0';
        }
        printf("Case #%d: ",++Tn);
        if(swapped) str1.swap(str2);
        cout<<str1<<' '<<str2<<endl;
    }
}

