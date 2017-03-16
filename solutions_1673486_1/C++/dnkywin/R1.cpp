#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
    ifstream in("R1.in");
    FILE *out = fopen("R1.out","w");
    int T;
    in>>T;
    for (int t=0;t<T;t++){
        int A,B;
        in>>A>>B;

        double probs[A];
        double products[A+1];
        products[0] = 1;
        for (int a=0;a<A;a++){
            in>>probs[a];
            products[a+1] = products[a] * probs[a];
        }
        double minexp = (double)B+2;
        for (int a=0;a<=A;a++){
            if (((double)(A-a)) + products[a] * ((double)(B-a+1)) + (1-products[a]) * ((double)(B-a+1+B+1)) < minexp){
                minexp = ((double)(A-a)) + products[a] * ((double)(B-a+1)) + (1-products[a]) * ((double)(B-a+1+B+1));
            }
        }

        fprintf(out,"Case #%d: %.7f\n",t+1,minexp);
    }


}
