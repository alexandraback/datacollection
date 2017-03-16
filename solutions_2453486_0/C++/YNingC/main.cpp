//
//  main.cpp
//  GCJ_Q_A
//
//  Created by Ningchen Ying on 4/13/13.
//  Copyright (c) 2013 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char ync[5][5];

int main(int argc, const char * argv[])
{
    //freopen("A.in","r",stdin);
	freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_A/GCJ_Q_A/A-small-attempt1.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_A/GCJ_Q_A/A-small-attempt1.out","w",stdout);
	//freopen("A-small-attempt0.in","r",stdin); freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        for(int i=0;i<4;i++) scanf("%s",ync[i]);
        int flag=0;
        /*
         X won 1
         O won 2
         Draw 0
         Game has not completed 4
         
        */
        
        int xx=0,oo=0,tt=0,pp=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(ync[i][j]=='X') xx++;
                else if(ync[i][j]=='O') oo++;
                else if(ync[i][j]=='T') tt++;
                else pp++;
            }
        }
        for(int i=0;i<4;i++){
            int x=0,o=0,t=0,p=0;
            for(int j=0;j<4;j++){
                if(ync[i][j]=='X') x++;
                else if(ync[i][j]=='O') o++;
                else if(ync[i][j]=='T') t++;
                else p++;
            }
            //cout<<x<<" "<<o<<" "<<t<<endl;
            if(x+t==4) flag=1;
            if(o+t==4) flag=2;
            if(x+t+p==4 && flag==0) flag=4;
            if(o+t+p==4 && flag==0) flag=4;
            if(p==4 && flag==0) flag=4;
        }
        //cout<<flag<<endl;
        for(int i=0;i<4;i++){
            int x=0,o=0,t=0,p=0;
            for(int j=0;j<4;j++){
                if(ync[j][i]=='X') x++;
                else if(ync[j][i]=='O') o++;
                else if(ync[j][i]=='T') t++;
                else p++;
            }
            if(x+t==4) flag=1;
            if(o+t==4) flag=2;
            if(x+t+p==4 && flag==0) flag=4;
            if(o+t+p==4 && flag==0) flag=4;
            if(p==4 && flag==0) flag=4;
        }
        //cout<<flag<<endl;
        int x=0,o=0,t=0,p=0;
        for(int i=0;i<4;i++){
            if(ync[i][i]=='X') x++;
            else if(ync[i][i]=='O') o++;
            else if(ync[i][i]=='T') t++;
            else p++;
            if(x+t==4) flag=1;
            if(o+t==4) flag=2;
            if(x+t+p==4 && flag==0) flag=4;
            if(o+t+p==4 && flag==0) flag=4;
            if(p==4 && flag==0) flag=4;
        }
        //cout<<flag<<endl;
        x=0,o=0,t=0,p=0;
        for(int i=0;i<4;i++){
            if(ync[i][3-i]=='X') x++;
            else if(ync[i][3-i]=='O') o++;
            else if(ync[i][3-i]=='T') t++;
            else p++;
            if(x+t==4) flag=1;
            if(o+t==4) flag=2;
            if(x+t+p==4 && flag==0) flag=4;
            if(o+t+p==4 && flag==0) flag=4;
            if(p==4 && flag==0) flag=4;
        }
        //cout<<x<<" "<<o<<" "<<t<<endl;
        //cout<<flag<<endl;
        if(pp!=0 && flag==0) flag=4;
        if(flag==1) printf("Case #%d: X won\n",ca);
        else if(flag==2) printf("Case #%d: O won\n",ca);
        else if(flag==4) printf("Case #%d: Game has not completed\n",ca);
        else printf("Case #%d: Draw\n",ca);
    }
    
    return 0;
}

