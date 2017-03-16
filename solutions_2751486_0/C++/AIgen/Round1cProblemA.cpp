#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define LL long long

int start[1000006];
int stop[1000006];


int main (){
    int t;
    cin>>t;
    int num_t = 1;
    while (num_t <= t){
        string str;
        cin>>str;
        int n;
        cin>>n;
        int num_start = 0;
        int last_pos = 0;
        for (int i=0;i<str.size();++i){
            if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u') ){
                last_pos =i+1;
            }
            else{
                if (last_pos == (i-(n-1))){
                    start[num_start] = last_pos;
                    stop[num_start] = i;
                    num_start ++;
                    last_pos++;
                }
            }
        }

        /*for (int i=0;i<num_start;++i){
            cout<<start[i]<<","<<stop[i]<<"\n";
        }*/

        LL ans = 0;
        for (int i=0;i<num_start;++i){
            if (i>0){
                ans += ((start[i] - start[i-1]) * (str.size() - stop[i]));
            }
            else {
                ans += ((start[i] + 1) * (str.size() - stop[i]));
            }
        }
        cout<<"Case #"<<num_t<<": "<<ans<<"\n";


        num_t++;
    }
    return 0;
}

