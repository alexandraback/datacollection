#include<fstream>


using namespace std;

int main(){

    
    ifstream infile("file.in");
    ofstream outfile("file.out");
    
    int T,A,B;
    double p[100000];
    infile>>T;

    outfile.setf(ios::fixed,ios::floatfield);
    outfile.precision(6);

    for(int t=1;t<=T;t++){
        infile>>A>>B;
        for(int i=0;i<A;i++)
            infile>>p[i];
        
        double best=100000, ans=0;
        
        double q[100000];
        q[0]=1;
        for(int i=1;i<=A;i++)
            q[i]=q[i-1]*p[i-1]; //q[i]=the first i letter are correct
        
        best=B+2;
        //key stroks for deleting 0-A letters
        for(int i=0;i<=A;i++){
            ans=(B-A+1+2*i)+(B+1)*(1-q[A-i]);
            best=min(best,ans);
        }

        //key stroks for enter
        //best=min(best, (B+2));
        outfile<<"Case #"<<t<<": "<<best<<endl;
    }
}    
