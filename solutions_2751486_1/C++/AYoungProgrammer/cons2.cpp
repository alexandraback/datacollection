#include <iostream>
#include <fstream>
using namespace std;

int main(){

    freopen("cons.in","r",stdin);
    freopen("cons2.out","w",stdout);
    int n;
    cin>>n;

    for(int t=0;t<n;t++){
        string str;
        cin>>str;

        int n;
        cin>>n;
        long long total = 0;
        long long consts =0;
        /*
        for(i=0;i<n;i++){
            if(str[i]=='a'||str[i]=='o'||str[i]=='u'||str[i]=='e'||str[i]=='i'){
                consts=0;
            }
            else consts++;
        }*/
        int start = 0;
        int i;
        for(i=0;i<str.length();i++){
            if(str[i]=='a'||str[i]=='o'||str[i]=='u'||str[i]=='e'||str[i]=='i'){
                consts=0;
            }
            else consts++;
            if(consts>=n){

                total+=((i-n+1)-start+1)*(str.length()-i);
                //cout<<i<<" "<<start<<" "<<((i-n+1)-start+1)<<" "<<(str.length()-i)<<" "<<total<<endl;
                start = i-n+2;
            }
        }
        //printf("Case #%d: %d\n",t+1,total);
        cout<<"Case #"<<(t+1)<<": "<<total<<endl;

    }

}
