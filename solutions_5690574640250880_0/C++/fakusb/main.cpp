#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>


using namespace std;

int T;
int R,C,M;
vector<int> a;

bool isValid(){
    for(int i=0;i<R;i++){
        //not incrementable(debug, should be handel in increment)
        if(i > 0 && a[i-1]<a[i]){
            return false;
        }

        //only 1 non-bomb left
        if(a[i]==C-1){
            return false;
        }
    }

    //no space to click
    if(a[R-2]>C-2 || a[R-1]>C-2)
        return false;
    if(a[R-2]!=a[R-1])
        return false;
    
    return true;

}

bool increment(){
    int toMove = a[R-1];
    a[R-1]=0;
    for(int i=R-2;i>=0;i--){

        //if there is something that could be moved
        if(a[i]>a[i+1]){
            //try to increment here
            a[i]--;
            toMove++;
            int t = min(C-1,a[i]);
            //if not all mines can be placed or there is no fundamental change
            if(t*(R-(i+1))<toMove || (a[i]>3 && C+1-a[i]>3)){
                toMove+=a[i];
                a[i]=0;
                continue;
            }
            int j = i;
            while(toMove>0){
                j++;
                
                t = min(toMove,t);
                a[j]=t;
                toMove-=t;
            }
            //if(isValid())
                return true;
            //else
                //return increment();
        }
        else{
            toMove+=a[i];
            a[i]=0;
        }
    }
    return false;
}

void showGame(){
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(r==R-1 && c==C-1){
                cout<<"c";
            }
            else if (c<a[r]){
                cout<<"*";
            }
            else{
                cout<<".";
            }
        }
        cout<<endl;
    }
}

void solve(){
    int noMine = R*C-M;
    //one is 1
    if(R==1 || C==1){
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(r==0 && c==0){
                    cout<<"c";
                    noMine--;
                }
                else if(noMine>0){
                    noMine--;
                    cout<<".";
                }
                else
                    cout<<"*";
            }
            cout<<endl;
        }
        return;
    }
    //one is 1
    if(noMine==1){
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(r==0 && c==0){
                    cout<<"c";
                }
                else
                    cout<<"*";
            }
            cout<<endl;
        }
        return;
    }
    a.clear();
    a.resize(R,0);
    for(int i=0;i<M/C;i++){
        a[i]=C;
    }
    a[M/C]=M % C;
    bool canIncrement=true;
    while(!isValid() && canIncrement){
        //showGame();
        //cout<<endl;
        canIncrement=increment();
        
    }
    if(!canIncrement){
        cout<<"Impossible"<<endl;
    }
    else{
        showGame();
    }
}



int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>R>>C>>M;
        cout<<"Case #"<<t<<":"<<endl;
        solve();
    }
    return 0;
}

