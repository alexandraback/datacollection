#include <iostream>
#include <queue>
using namespace std;
int flip(int x){
    int y = 0;
    while(x != 0){
        y *= 10;
        y += x%10;
        x /= 10;
    }
    return y;
}
class per{
    public:
    int i;
    int cost;
    per(int I, int COST){
        i = I;
        cost = COST;
    }
    bool operator<(const per & a) const{
        return i > a.i;
    }
};
int main(){
    int tests = 0;
    cin >> tests;
    for(int t=0;t<tests;t++){
        int num = 0;
        cin >> num;
        priority_queue<per> pq;
        pq.push(per(1,1));
        vector<bool> visited(1000000);
        while(true){
            per i = pq.top();
            // cout << i.i << " " << i.cost << endl;
            pq.pop();
            if(i.cost == num){
                cout << "Case #"<<t+1<<": " << i.i << endl;
                break;
            }
            if(visited[i.cost]) continue;
            visited[i.cost] = true;
            int fi = flip(i.cost);
            if(fi <= num and fi > i.cost)
                pq.push(per(i.i+1,fi));
            pq.push(per(i.i+1,i.cost+1));
        }
    }
}