#include <iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int t;
    in>>t;

    for(int q=0;q<t;q++){

        int n;
        int ar[2000][2];
        int done[2000]={0,};
        int lvl=0;
        int imp=0;
        int b=0;
        in>>n;


        for(int i=0;i<n;i++){
            in>>ar[i][0]>>ar[i][1];
        }

        //cout<<"Case #"<<q+1<<": "<<endl;


        while(lvl<2*n && imp==0){
            b++;
            int tosol=-1;

            //lvl 0 to 2
            for(int j=0;j<n;j++){
                if(lvl>=ar[j][1] && done[j]==0) tosol=j;
            }

            if(tosol>=0){
                done[tosol]=2;
                lvl+=2;
               // cout<<tosol<<' '<<'1'<<endl;
            }
            else{
                for(int j=0;j<n;j++){
                    if(lvl>=ar[j][1] && done[j]==1) tosol=j;
                }

                if(tosol>=0){
                    done[tosol]=2;
                    lvl+=1;
                    //cout<<tosol<<' '<<'2'<<endl;
                }
                else{
                    for(int j=0;j<n;j++){
                        if(lvl>=ar[j][0] && done[j]==0){
                            if(tosol<0)tosol=j;
                            else if(ar[j][1]>ar[tosol][1]) tosol=j;
                        }
                    }
                    if(tosol>=0){
                        done[tosol]=1;
                        lvl+=1;
                        //cout<<tosol<<' '<<'3'<<endl;
                    }
                    else imp=1;
                }

            }

        }

        if(imp) out<<"Case #"<<q+1<<": "<<"Too Bad"<<endl;
        else out<<"Case #"<<q+1<<": "<<b<<endl;


    }

    return 0;

}
