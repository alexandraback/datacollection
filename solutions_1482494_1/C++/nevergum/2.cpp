#include<fstream>
#include<algorithm>

using namespace std;


struct point{
    int easy, hard;
    bool killed;
};

point p[1100];


bool hardComp(point p1, point p2){
    return p1.hard<p2.hard;
}

int main(){

    
    ifstream infile("file.in");
    ofstream outfile("file.out");
    
    int T,N;
    infile>>T;

    for(int t=1;t<=T;t++){
        infile>>N;
        for(int i=0;i<N;i++){
            infile>>p[i].easy;
            infile>>p[i].hard;
            p[i].killed=false;
        }
        
        sort(p,p+N,hardComp);
        int pos=0;
        int count=0;
        int score=0;

        while(pos<N){

            int oldscore=score;
            while(pos<N && p[pos].hard<=score){
                if(!p[pos].killed) score+=2;
                else score+=1;
                count++;
                pos++;
            }
            
            if(pos<N){
                int search=N-1;
                while(search>=pos && (p[search].easy>score || p[search].killed) )
                    search--;
                if(search>=pos && p[search].easy<=score){
                    score++;
                    count++;
                    p[search].killed=true;
                }
            }
        
            if(score==oldscore) break;
        }
        
        outfile<<"Case #"<<t<<": ";
        if(pos==N)  outfile<<count<<endl;
        else outfile<<"Too Bad"<<endl;
    }  

}    
