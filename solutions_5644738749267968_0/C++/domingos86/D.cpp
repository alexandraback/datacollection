#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

typedef long long ll;

void heapdown(float* vec, int beg, int fin){
    int root = beg;
    int child,swap;
    float trans;
    while(root*2+1<=fin){
        child=root*2+1;
        swap=root;
        if(vec[swap]>vec[child]) swap=child;
        if((child+1<=fin)&&(vec[swap]>vec[child+1])) swap=child+1;
        if(swap!=root){
            trans=vec[root];
            vec[root]=vec[swap];
            vec[swap]=trans;
            root=swap;
        }else root=fin;
    }
}

void heapify(float* vec, int N){
    int start=(N-2)/2;
    while(start>=0){
        heapdown(vec, start, N-1);
        start--;
    }
}

void heapsort(float* vec, int N){
    heapify(vec,N);
    int end=N-1;
    float trans;
    while(end>0){
        trans=vec[end];
        vec[end]=vec[0];
        vec[0]=trans;
        end--;
        heapdown(vec,0,end);
    }
}


int main(){

    int T;
    cin >> T;

    int N;
    float *Naomi, *Ken;
    int gap,gap2,Nt,Kt,decwins;

    for(int i=1;i<=T;i++){
        cin >> N;
        Naomi = (float*)malloc(N*sizeof(float));
        Ken = (float*)malloc(N*sizeof(float));
        for(int j=0;j<N;j++) cin >> Naomi[j];
        for(int j=0;j<N;j++) cin >> Ken[j];
        heapsort(Naomi,N);
        heapsort(Ken,N);
        gap=0;
        Nt=0;
        Kt=0;
        while((Nt<N)&&(Kt<N)){
            if(Naomi[Nt]>Ken[Kt]){
                Nt++;
            }else Kt++;
            if(Nt-Kt>gap) gap++;
        }
        if((Nt==N)&&(N-Kt>gap)) gap=N-Kt;

        /*for(int j=0;j<N;j++) cout << Naomi[j] << " ";
        cout << endl;
        for(int j=0;j<N;j++) cout << Ken[j] << " ";
        cout << endl;*/

        //Nt=N-1;
        //Kt=N-1;
        //decwins=0;

        gap2=0;
        Nt=0;
        Kt=0;
        while((Nt<N)&&(Kt<N)){
            if(Naomi[Nt]<Ken[Kt]){
                Kt++;
            }else Nt++;
            if(Kt-Nt>gap2) gap2++;
        }
        if((Kt==N)&&(N-Nt>gap2)) gap2=N-Nt;
        decwins=N-gap2;


        free(Naomi);
        free(Ken);
        cout << "Case #" << i << ": " << decwins << " " << gap << endl;
    }

    return 0;
}
