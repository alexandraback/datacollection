#include<iostream>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N,S,P,T,temp,count;
    cin>>T;
    int a=T;
    while(T--)
    {
        cin>>N>>S>>P;
        count=0;
        for(int i=0;i<N;i++)
        {
            cin>>temp;
            if(P==0)
            {
                count++;
            }
            else if(P==1)
            {
                if(temp>0)count++;
            }
            else if(P==2)
            {
                if((temp==3||temp==2)&&S>0){count++;S--;}
                else if(temp>3)count++;
            }
            else if(P==3)
            {
                if((temp==5||temp==6)&&S>0){count++;S--;}
                else if(temp>6)count++;
            }
            else if(P==4)
            {
                if((temp==8||temp==9)&&S>0){count++;S--;}
                else if(temp>9)count++;
            }
            else if(P==5)
            {
                if((temp==11||temp==12)&&S>0){count++;S--;}
                else if(temp>12)count++;
            }
            else if(P==6)
            {
                if((temp==14||temp==15)&&S>0){count++;S--;}
                else if(temp>15)count++;
            }
            else if(P==7)
            {
                if((temp==17||temp==18)&&S>0){count++;S--;}
                else if(temp>18)count++;
            }else if(P==8)
            {
                if((temp==20||temp==21)&&S>0){count++;S--;}
                else if(temp>21)count++;
            }
            else if(P==9)
            {
                if((temp==23||temp==24)&&S>0){count++;S--;}
                else if(temp>24)count++;
            }
            else if(P==10)
            {
                if((temp==26||temp==27)&&S>0){count++;S--;}
                else if(temp>27)count++;
            }
        }
        cout<<"Case #"<<a-T<<": "<<count<<"\n";
    }
    
}