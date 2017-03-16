#include<iostream>
using namespace std;


int main (){
    int t;
    int num_t = 1;
    cin>>t;
    while (num_t <= t){
        int x, y;
        cin>>x>>y;
        cout<<"Case #"<<num_t<<": ";
        if (x >= 0){
            while (x>0){
                cout<<'W'<<'E';
                x--;
            }
        }
        else {
            while (x<0){
                cout<<'E'<<'W';
                x++;
            }
        }
        if (y >= 0){
            while (y>0){
                cout<<'S'<<'N';
                y--;
            }
        }
        else {
            while (y<0){
                cout<<'N'<<'S';
                y++;
            }
        }
        cout<<"\n";
        num_t++;
    }
    return 0;
}
