#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;


int main(){
    int test;
    cin>>test;
    long long ans;
    for(int te=0;te < test; te++){
        long long x, y;
        cin>>x>>y;
        vector<char> directions;
        int tempx = 0;
        int tempy = 0;
        bool te = false;
        int count = 0;
        while(tempx != x){
            count += 1;
            if(te){
                tempx += count;
                directions.push_back('N');
                te = !te;
            }
            else{
                tempx -= count;
                directions.push_back('S');
                te = ~te;
            }
        }

        te = false;
        count = 0;
        while(tempy != y){
            count += 1;
            if(te){
                tempy += count;
                directions.push_back('E');
                te = !te;
            }
            else{
                tempy -= count;
                directions.push_back('W');
                te = !te;
            }
        }
        cout<<"Case #"<<te + 1<<": ";
        for(int i=0; i< directions.size();i++)
            cout<<directions[i];
        cout<<endl;
    }

}
