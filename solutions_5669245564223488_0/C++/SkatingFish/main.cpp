//
//  main.cpp
//  1c_b
//
//  Created by Liubing Yu on 5/11/14.
//  Copyright (c) 2014 Liubing Yu. All rights reserved.
//

//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;


int main(int argc, const char * argv[])
{
    long long p,q,common_f,res,maxn;
    maxn=1e9+7;
    int i,j,errorI,T,sum,k,m,len;
    long long fa[101];// n!
    long long gr[101];// 2^n
    int x[26];// the number of each section with only one character
    int y[26];//starting array
    int z[26];//ending array
    int w[26];//list middle
    int v[26];// the number of each section with only one character
    
    int was[26];//visited
    int visit[31];//visited
    int group;// total number of groups
    char ch;
    string s[100],temp;
    ifstream fin;    // Input file stream
    ofstream fout;   //Output file stream
    fin.open ("/Users/liubingyu/Desktop/B-small-attempt0.in.txt");
    fout.open("/Users/liubingyu/Desktop/B-small-attempt0.out.txt");
    fa[0]=1;
    gr[0]=1;
    for(j=1;j<101;j++){
        fa[j]=(fa[j-1]*j)%maxn;
      //  cout<<fa[j]<<endl;
        gr[j]=(gr[j-1]*2)%maxn;
    }
    
    fin>>T;
    cout<<T<<endl;
    for(j=0;j<T;j++){
        fin>>sum;
        errorI=0;
        for(int i3=0; i3<26;i3++){
           x[i3]=0;
            y[i3]=30;
            z[i3]=30;
            w[i3]=0;
        }
        for(int i=0; i<sum;i++){
            fin>>temp;
            cout<<temp<<endl;
            memset (v, 0, sizeof (v));
            ch=temp[0];
            len=temp.size();
            if(w[ch-'a']){
                errorI=1; /// some middle character appear in the head or middle, or end again
            }
          //  cout<<errorI<<endl;
            for(int i1 = 1; i1 < temp.size(); i1++){
                if(w[ch-'a']){
                    errorI=1;/// some middle character appear in the head or middle, or end again
                }
                
                if(ch!=temp[i1]){
                    if(v[ch-'a']==1){
                        errorI=1;/// not consequent appear
                    }
                    v[ch-'a']=0;
                    ch=temp[i1];
                }
                
                if(ch!=temp[0]&&ch!=temp[len-1]){
                    w[ch-'a']=1;
                }
            }
         //   cout<<temp[0]-'a'<<y[temp[0]-'a']<<endl;
            ch=temp[0];
            if(temp[0]==temp[len-1]){
                x[ch-'a']++;
            }
            else{
                if(y[temp[0]-'a']!=30||z[temp[len-1]-'a']!=30){
                    errorI=1;
                }
                y[temp[0]-'a']=temp[len-1]-'a';
                z[temp[len-1]-'a']=temp[0]-'a';
            }
         //   cout<<errorI<<endl;
        }
        if(errorI){
            fout<<"Case #"<<j+1<<": 0\n";
            cout<<"Case #"<<j+1<<": 0\n";
        }
        else{
            group=0;
            res=1;
            memset (was, 0, sizeof (was));
            for(int i=0; i<26;i++){
               // cout<<i<<endl;
                if(was[i])continue;
                if(y[i]==30&&z[i]==30){
                    res=(res*fa[x[i]])%maxn;
                    if(x[i])group++;
                    was[i]=1;
                    // cout<<i<<endl;
                    continue;
                }
                int i2=i;
                group++;
                memset (visit, 0, sizeof (visit));
                while(z[i2]!=30&&visit[i2]==0){
                    visit[i2]=1;
                    i2=z[i2];//find the starting point
                }
                if(z[i2]!=30){
                    fout<<"Case #"<<j+1<<": 0\n";
                    cout<<"Case #"<<j+1<<": 0\n";
                    continue;
                }
                while(i2!=30){
                    cout<<i2<<endl;
                    was[i2]=1;//visited
                    res=(res*fa[x[i2]])%maxn;
                    i2=y[i2];
                }
            }
            cout<<group<<endl;
            res=(res*gr[group-1])%maxn;
            fout<<"Case #"<<j+1<<": "<<res<<"\n";
            cout<<"Case #"<<j+1<<": "<<res<<"\n";
        }
        
        
    }
    fin.close();
    fout.close();
    // insert code here...
    // std::cout << "Hello, World!\n";
    return 1;
}