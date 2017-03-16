#include <iostream>
#define MAX_V 110
using namespace std;

bool used[MAX_V];
bool knap[MAX_V];

int c,d,v;

int add(int n){
    int comp = 0;
    used[n] = true;
    for(int i=v-n;i>=0;--i)
        if(knap[i] && !knap[i + n]){
            knap[i+n] = true;
            comp++;
        }
    return comp;
}

int findPos(int n){
    int count = 0;
    for(int i=0;i<=v-n;++i)
        if(knap[i] && !knap[i+n])
            count++;
    return count;
}

int posMax(){
    int max = -1;
    int maxInd = -1;
    for(int i=1;i<=v;++i){
        if(used[i])
            continue;
        
        int temp = findPos(i);
        if(temp > max){
            max = temp;
            maxInd = i;
        }
    }
    return maxInd;
}

void writeKnap(){
    for(int i=0;i<=v;++i)
        cout << knap[i] << " ";
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    for(int i=1;i<=T;++i){
        cin >> c >> d >> v;
        int rem = 0;
        int res = 0;
        rem = v;
        
        knap[0] = true;
        for(int j=1;j<=v;++j){
            knap[j] = false;
            used[j] = false;
        }
        
        for(int j=0;j<d;++j){
            int num;
            cin >> num;
            rem -= add(num);
        }
        //writeKnap();
        
        while(rem){
            int m = posMax();
            //cout << m << endl;
            rem-=add(m);
            res++;
        }
        
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}