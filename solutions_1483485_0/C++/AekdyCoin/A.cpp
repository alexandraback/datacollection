#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;

char A[ 99999];
char ans[] = "yhesocvxduiglbkrztnwjpfmaq";
int main(){
    //freopen("D:\\GCJ\\A.in","r",stdin);
    //freopen("D:\\GCJ\\A.out","w",stdout); 
    int T, cas = 0;
    cin >> T;
    gets(A);
    while(T --) {
        gets(A);    
        printf("Case #%d: ", ++ cas);   
        for(int i = 0; A[ i ]; ++ i) if( A[i] >= 'a' && A[i] <= 'z') A[i] = ans[ A[i]-'a'];
        puts(A);
    }
    return 0;
}
