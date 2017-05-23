#include<cstdio>
#include<cstring>
#include<string>
#include<list>
#include<iostream>
using namespace std;

int R, C, M, E, e, re[55];

void prt(char c, int num, int line){
    string s;
    s.append(num, c);
    if(line==1)
        cout<<s<<endl;
    else
        cout<<s;
}
pair<list<int>, bool> cut(pair<list<int>, bool> l, list<int> l2, int a){
    l.first.splice(l.first.begin(), l2);
    l.first.insert(l.first.begin(), a);
    l.second = true;
    return l;
}
pair<list<int>, bool> refind2(int r, int most, int useable){
    pair<list<int>, bool> l, l2, l3, l4;
    if(most<2||r*most<useable||useable<0){
        l.second = false;
    }else if(useable==0){
        l.second = true;
    }else{
        l2 = refind2(r-1, most, useable-most);
        l3 = refind2(r-1, most-1, useable-most);
        l4 = refind2(r, most-1, useable);
        if(l2.second){
            l = cut(l, l2.first, most);
        }else if(l3.second){
            l = cut(l, l3.first, most);
        }else if(l4.second){
            l.first.splice(l.first.begin(), l4.first);
            l.second = true;
        }else
            l.second = false;
    }return l;
}
void reFind(){
    for(int i=C; i>=2; i--){
        if(E>=2*i){
            pair<list<int>, bool> l = refind2(R-2, i, E-2*i);
            if(l.second){
                re[0] = re[1] = i;
                int j = 2;
                while(!l.first.empty()){
                    re[j++] = l.first.front();
                    l.first.pop_front();
                }break;
            }
        }
    }
    putchar('c');   prt('.', re[0]-1, 0);
    for(int i=0; i<R; i++){
        if(i>0)
            prt('.', re[i], 0);
        prt('*', C-re[i], 1);
    }
}

void normal(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(i==0&&j==0)
                putchar('c');
            else if(e<E){
                putchar('.');
                e++;
            }else
                putchar('*');
        }putchar('\n');
    }
}
int main(){

    int t, ca=1;
    scanf("%d", &t);

    for(; t>0; t--){
        printf("Case #%d:\n", ca++);
        scanf("%d%d%d", &R, &C, &M);
        memset(re, 0, sizeof(re));
        E = R*C-M;
        e = 1;
        if(R==1||C==1||E==1){
            normal();
        }else if((R==2||C==2)&&(E%2==0&&E!=2)){
            reFind();
        }else if((R>2&&C>2)&&(E!=2&&E!=3&&E!=5&&E!=7)){
            if(E>=2*C&&E%C!=1)
                normal();
            else
                reFind();
        }else
            printf("Impossible\n");
    }
    return 0;
}
