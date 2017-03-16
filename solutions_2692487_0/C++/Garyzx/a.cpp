#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int ncases;
    cin>>ncases;
    for(int caseNum=0; caseNum < ncases; caseNum++) {
        int length;
        long long size, sizes[100];
        cin>>size>>length;
        for(int n=0; n<length; n++) {
            cin>>sizes[n];
        }
        sort(sizes, sizes+length);
        int ops = 0, best = 1000;
        for(int n=0; n<length; n++) {
            //cout<<n<<" "<<size<<" "<<sizes[n]<<endl;
            if(size > sizes[n]) {
                size += sizes[n];
                if(n == length-1 && best > ops)
                    best = ops;
            }
            else {
                if(best > length - n + ops)
                    best = length - n + ops;
                size = size*2 - 1;
                n--;
                ops++;
            }
            if(size == 1)
                break;
        }
        cout<<"Case #"<<caseNum+1<<": "<<best<<"\n";
    }
}