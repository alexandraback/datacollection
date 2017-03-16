#include <bits/stdc++.h>

using namespace std;

bool flag[1100] = {false};
int maior;
int grafo[1100];

int BFS(int x, int y, vector<int> agra[1100]){
    int dep;
    queue<pair<int, int> > fila;
    bool flag[1100] = {false};
    fila.push(make_pair(x, 0));
    while(!fila.empty()){
        dep = fila.front().second;
        x = fila.front().first;
        for(vector<int>::iterator it = agra[x].begin(), fim = agra[x].end(); it!=fim; it++){
            if(*it!=y && !flag[*it]){
                fila.push(make_pair(*it, dep+1));
                flag[*it] = true;
            }
        }
        fila.pop();
    }
    return dep;
}

void solvre(){
    int n;
    maior = 0;
    int x;
    scanf("%d", &n);
    stack<pair<int, int> > rec;
    vector<int> agra[1100];

    for(int i = 1; i<=n; i++){
        grafo[i] = 0;
    }
    for(int i = 1; i<=n; i++){
        scanf("%d", &grafo[i]);
        agra[grafo[i]].push_back(i);
        if(grafo[grafo[i]]==i){
            rec.push(make_pair(i, grafo[i]));
        }
        flag[i] = false;
    }
    int soma;

    for(int inicio = 1; inicio<=n; inicio++){
        x = grafo[inicio];
        soma = 1;
        while(!flag[x] && x!=inicio){
            flag[x] = true;
            x = grafo[x];
            soma++;
        }
        if(x==inicio){
            maior = max(maior, soma);
        }
        for(int i= 1; i<=n; i++) flag[i] = false;
    }

    soma = 0;
    while(!rec.empty()){
        soma+=2+BFS(rec.top().first, rec.top().second, agra)+BFS(rec.top().second, rec.top().first, agra);
        rec.pop();
    }
    maior = max(soma, maior);
    printf(" %d\n", maior);

}

int main(){
    int n;
    string s;

    cin>>n;
    for(int i = 1; i<=n; i++){
        printf("Case #%d:", i);
        solvre();
    }
}
