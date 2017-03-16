#include <iostream>
#include <fstream>
using namespace std;

//ifstream cin("input.in");
//ofstream cout("output1.txt");

double pi = 3.14159265358979323;

long long cases;
long long radius, paint;

int main(){
    cin>>cases;
    for(int c = 1; c <= cases; c++){
        cin>>radius>>paint;
        long long high = 1000000000, low = 0, ans = -1;
        while(high-low>1 && ans == -1){
            long long mid = (high+low)/2;

            if(2*mid*radius + mid*mid*2 - 1*mid == paint){
                ans = mid;
            }else if (2*mid*radius + mid*mid*2 - 1*mid < paint){
                low = mid;
            }else{
                high = mid;
            }
        }
        cout<<"Case #"<<c<<": "<<max(low,ans)<<"\n";
    }
}
