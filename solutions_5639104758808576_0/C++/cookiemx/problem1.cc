#include <iostream>

using namespace std;

int main(){
    int cases,level;
    cin>>cases;
    char people;
    for(int i =0;i<cases;i++){
        cin>>level;
	int a[level+1];
        for(int j =0;j< level+1;j++){
            cin>>people;
            a[j] = people - 48;
        }
        int sum=0,needed=0;
	for(int k = 0; k <level +1;k++){
            if(sum<k && a[k]!=0){
                 needed += (k-sum);
                 sum = k;
            }
            sum += a[k];
       }
        cout<<"Case #"<<i+1<<": "<<needed<<endl;
    }
}
