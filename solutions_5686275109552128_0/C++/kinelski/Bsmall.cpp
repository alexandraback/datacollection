#include <stdio.h>
#include <queue>
using namespace std;

int Min (int x, int y){
    if (x < y) return x;
    return y;
}

int time(priority_queue<int> pq){
    if (pq.size() == 0) return 0;
    if (pq.top() == 1) return 1;

    priority_queue<int> norm, aux;
    aux = pq;

    int top = pq.top();
    int half = top/2;
    if (pq.top()%2 == 1) half++;

    pq.pop();
    pq.push(top/2);
    pq.push(half);

    while (aux.size() > 0){
        if (aux.top() > 1) norm.push(aux.top() - 1);
        aux.pop();
    }

    return 1 + Min(time(pq),time(norm));
}

int main(){
    int t, d, p;

    scanf ("%d", &t);
    for (int k=1; k<=t; k++){
        scanf ("%d", &d);
        priority_queue<int> pq;

        for (int i=1; i<=d; i++){
            scanf ("%d", &p);
            pq.push(p);
        }

        printf ("Case #%d: %d\n", k, time(pq));
    }
}
