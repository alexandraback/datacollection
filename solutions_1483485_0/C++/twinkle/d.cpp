#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
   // freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    string turn = "yhesocvxduiglbkrztnwjpfmaq";
    char str[111];
    int n;
    cin >> n;
    gets(str);
    for(int i = 1;i <= n; i ++){
        gets(str);
        cout<<"Case #"<<i<<": ";
        int len = strlen(str);
        for(int j = 0; j < len; j ++){
            if(str[j] ==' ')cout<<' ';
            else    
                cout<<turn[str[j]-'a'];
        }
        cout<<endl;
    }
    return 0;
}
