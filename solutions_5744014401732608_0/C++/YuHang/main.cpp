//
//  main.cpp
//  google
//
//  Created by 張語航 on 2016/4/16.
//  Copyright © 2016年 張語航. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int main() {
    ifstream openfile;
    fstream outfile;
    openfile.open("/Users/yuhang/Desktop/1.in");
    outfile.open("/Users/yuhang/Desktop/1.out", ios::out);
    int T;
    int B,M;
    openfile >> T;
    for (int cases = 1; cases <= T; cases++) {
        int build[50][50]={0};
        outfile << "Case #" << cases << ": ";
        openfile>>B>>M;
        for(int i=B-2;i>=0;i--)
            build[i][B-1]=1;
        for(int i=B-2;i>0;i--){
            for(int j=B-1;j>0;j--){
                if(i==j)break;
                int temp=0;
                for(int k=j;k<=B-1;k++)
                    temp+=build[i][k];
                for(int k=0;k<i;k++)
                    build[k][i]=temp;
            }
        }
        
        int temp=0;
        for(int i=0;i<B;i++){
            temp+=build[0][i];
        }
        if(M>temp)outfile<<"IMPOSSIBLE"<<endl;
        else {
            outfile<<"POSSIBLE"<<endl;
            temp-=M;
            for(int i=B-1;i>0;i--){
                for(int j=i;temp>=pow(2,(i-1<0?0:i-1))&&j<B;){
                    if(build[i][j]){
                        build[i][j]--;
                        temp-=pow(2,(i-1<0?0:i-1));
                        for(int k=i;k>0;k--){
                            for(int l=0;l<k;l++)
                                build[l][k]-=pow(2,(i-1-k<0?0:i-1-k));
                        }
                    }else{j++;}
                }
            }
            for(int i=0;i<B;i++){
                for(int j=0;j<B;j++){
                    //cout<<build[i][j]<<" ";
                    outfile<<(build[i][j]?1:0)<<(j==B-1?"":" ");
                }
                outfile<<endl;
            }
        }
    }
    openfile.close();
    return 0;
}