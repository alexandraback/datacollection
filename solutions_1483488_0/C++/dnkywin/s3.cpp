#include<iostream>
#include<fstream>
using namespace std;

int numdigits(int a){
    if (a==0) return 0;
    else return numdigits(a/10)+1;
}

int main(){
    ifstream in("s3.in"); ofstream out("s3.out");

    int T;
    in>>T;
    for (int t=0;t<T;t++){
        int A,B;
        in>>A>>B;
        int c = numdigits(A);
        int ten = 1;
        for (int i=1;i<c;i++){
            ten*=10;
        }
        int num=0;
        for (int i=A;i<B;i++){
            int tmp=i;
            for (int j=1;j<c;j++){
                tmp = (tmp/ten) + 10*(tmp%ten);
                if ((tmp>i) && (B>=tmp)){
                    num++;
//                    cout<<num<<": "<<i<<" "<<tmp<<"\n";
                }
            }
            tmp = (tmp/ten) + 10*(tmp%ten);
            if (tmp!=i) cout<<"HELP!";
        }
        out<<"Case #"<<t+1<<": "<<num<<"\n";
    }

}
