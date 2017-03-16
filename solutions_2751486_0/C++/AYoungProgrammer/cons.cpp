#include <iostream>

using namespace std;

int numConsts(string str){
    int count = 0;
    int i;
    int streak = 0;
    for(i=0;i<str.length();i++){
        if(str[i]=='a'||str[i]=='o'||str[i]=='u'||str[i]=='e'||str[i]=='i'){
            count = 0;
        }else count++;
        streak = max(streak,count);
    }
    return streak;
}

int main(){
    freopen("cons.in","r",stdin);
    freopen("cons.out","w",stdout);
    int n;
    cin>>n;

    for(int t=0;t<n;t++){
        string str;
        cin>>str;

        int n;
        cin>>n;

        int i,j;
        int count = 0;
        for(i=0;i<str.length();i++){
            for(j=1;j+i<=str.length();j++){
              // cout<<str.substr(i,j)<<endl;
                if(numConsts(str.substr(i,j))>=n){
                    count++;
                   // cout<<"this one ^^^"<<endl;
                    //cout<<str.substr(i,j)<<endl;
                }
            }
        }
        printf("Case #%d: %d\n",t+1,count);

    }


}
