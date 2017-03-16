#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <math.h>

using namespace std;

int main()
{
    int tests;
    int boxtype[3];
    int boxamount[3];
    int toytype[3];
    int toyamount[3];

    cin >> tests;
    for(int i=1;i<=tests;i++){
        int boxCount, toyCount;
        cin >> boxCount >> toyCount;
        for(int j=0;j<boxCount;j++){
            cin >> boxamount[j] >> boxtype[j];
        }
        int k=0;
        for(int j=0;j<toyCount;j++){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            if(tmp2==boxtype[0]||tmp2==boxtype[2]||tmp2==boxtype[2]){
                toyamount[k]=tmp1;
                toytype[k]=tmp2;
                k++;
            }
        }
        int sum=0;
        if(k==3){
            if(boxtype[0]==toytype[0]){
                if(boxtype[1]==toytype[1]){
                    sum=min(boxamount[0],toyamount[0])+min(boxamount[1],toyamount[1])+min(boxamount[2],toyamount[2]);
                }else{
                    sum=min(boxamount[0],toyamount[0])+max(min(boxamount[1],toyamount[2]),min(boxamount[2],toyamount[1]));
                }
            }else if(boxtype[0]==toytype[1]){
                if(boxtype[1]==toytype[2]){
                    sum=max(min(boxamount[0],toyamount[1])+min(boxamount[1],toyamount[2]),min(boxamount[2],toyamount[0]));
                }
                else{
                    sum=min(boxamount[2],toyamount[2])+max(min(boxamount[1],toyamount[0]),min(boxamount[0],toyamount[1]));
                }
            }else{
                if(boxtype[1]==toytype[0]){
                    sum=max(min(boxamount[1],toyamount[0])+min(boxamount[2],toyamount[1]),min(boxamount[0],toyamount[2]));
                }else{
                    sum=max(max(min(boxamount[0],toyamount[2]),min(boxamount[1],toyamount[1])),min(boxamount[2],toyamount[0]));
                }
            }
        }else if(k==2){
            if(boxtype[0]==toytype[0]){
                if(boxtype[1]==toytype[1]){
                    sum=min(boxamount[0],toyamount[0])+min(boxamount[1],toyamount[1]);
                }else{
                    sum=min(boxamount[0],toyamount[0])+min(boxamount[2],toyamount[1]);
                }
            }else if(boxtype[0]==toytype[1]){
                if(boxtype[1]==toytype[0]){
                    sum=max(min(boxamount[1],toyamount[0]),min(boxamount[0],toyamount[1]));
                }else{
                    sum=max(min(boxamount[2],toyamount[0]),min(boxamount[0],toyamount[1]));
                }
            }else{
                if(boxtype[1]==toytype[0]){
                    sum=min(boxamount[1],toyamount[0])+min(boxamount[2],toyamount[1]);
                }else{
                    sum=max(min(boxamount[1],toyamount[1]),min(boxamount[2],toyamount[0]));
                }
            }
        }else if(k==1){
            if(boxtype[0]==toytype[0]){
                sum=min(boxamount[0],toyamount[0]);
            }else if(boxtype[1]==toytype[0]){
                sum=min(boxamount[1],toyamount[0]);
            }else{
                sum=min(boxamount[2],toyamount[0]);
            }
        }else{
            sum=0;
        }
        cout << "Case #" << i << ": " << sum << endl;

    }
    return 0;
}
