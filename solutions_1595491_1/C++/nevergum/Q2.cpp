#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;


bool comp(int a, int b){
    return a>b;
}


int main(){

    ifstream infile("file.in");
    ofstream outfile("file.out");

    int T,N,S,p;
    infile>>T;
    for(int t=1;t<=T;t++){
        infile>>N>>S>>p;
        vector<int> googlers;
        int num;
        for(int i=0;i<N;i++){
            infile>>num;
            googlers.push_back(num);
        }

        if(p==0) outfile<<"Case #"<<t<<": "<<googlers.size()<<endl;
        else{
            sort(googlers.begin(),googlers.end(),comp);
        
            int shred1=3*p-2;
            int shred2=max(3*p-4,1);

            int count1=0, count2=0;
            for(int i=0;i<googlers.size();i++){
                if(googlers[i]>=shred1) count1++;
                else if(googlers[i]>=shred2) count2++;
                else break;
            }
            outfile<<"Case #"<<t<<": "<<count1+min(count2,S)<<endl;
        }
    }
}
