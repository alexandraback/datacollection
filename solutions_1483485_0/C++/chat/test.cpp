#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;

void run(){
    char a1[27]="abcdefghijklmnopqrstuvwxyz";
    char a2[27]="yhesocvxduiglbkrztnwjpfmaq";
    
    char str[101];
    int len;
    
    gets(str);
    len=strlen(str);
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++)
            if(str[i]==a1[j]) {
                str[i]=a2[j];
                break;
            }
        
    }
    cout<<str;
}

int main(){
    int i,n;
    
    cin>>n;
    getchar();
    for(i=1;i<=n;i++){
        cout<<"Case #"<<i<<": ";
        run();
        cout<<endl;
    }
    
    return 0;
}
