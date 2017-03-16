#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
using namespace std;
bool bigger(int i,int j) {return i<j;}
void print(vector<int> vec)
{
for(int i=0;i<vec.size();i++)
    cout<<vec[i]<<" ";
cout<<endl;

}
int main()
{
    ifstream input;
    input.open("B-large.in");
    ofstream output;
    output.open("outputlarge.txt");
    int cse=1;
    int t;
    input>>t;


    while(cse<=t)
    {
        int ans=0;
        int d;
        int time=0;
        vector<int> p,q;
        input>>d;
        for(int i=0;i<d;i++){int a;input>>a;p.push_back(a);q.push_back(a);}
        int z=*max_element(p.begin(),p.end(),bigger);
        ans=z;
                do{sort(p.begin(),p.end(),bigger);
        int i=0;
        for(i=0;i<p.size();i++){if(p[i]==p[p.size()-1]){break;}}
        time+=p.size()-i;
        if(p[i]%2==0){vector<int> t ((p.size()-i)*2,p[i]/2);p.erase(p.begin()+i,p.end());
        p.insert(p.begin(),t.begin(),t.end());
        }
        else {vector<int> t ((p.size()-i),(p[i]-1)/2);vector<int> s ((p.size()-i),(p[i]+1)/2);
        p.erase(p.begin()+i,p.end());
        p.insert(p.begin(),t.begin(),t.end());
        p.insert(p.begin(),s.begin(),s.end());
        }

        ans=min(ans,time+*max_element(p.begin(),p.end(),bigger));

if(time>z+2){break;}

        }while(*max_element(p.begin(),p.end(),bigger)>1);

        int time1=0;
    do{sort(q.begin(),q.end(),bigger);
         //for(int i=0;i<q.size();i++)
           //output<<q[i]<<" ";
        //output<<endl;
        int i=0;
        for(i=0;i<q.size();i++){if(q[i]==q[q.size()-1]){break;}}

        int group=ceil(sqrt(q[i]));
        int num=q[i]/group;

        int lastgroup=q[i]%group;
        if(lastgroup!=0){time1+=num*(q.size()-i);}
        else {time1+=(num-1)*(q.size()-i);}
        vector<int> t ((q.size()-i)*num,group);vector<int> s ((q.size()-i),lastgroup);
        q.erase(q.begin()+i,q.end());
        q.insert(q.begin(),t.begin(),t.end());
        if(lastgroup!=0){q.insert(q.begin(),s.begin(),s.end());}
       // cout<<"time:"<<time1<<endl;
        //print(q);


        ans=min(ans,time1+*max_element(q.begin(),q.end(),bigger));

if(time1>z+2){break;}

        }while(*max_element(q.begin(),q.end(),bigger)>2);

        output<<"Case #"<<cse<<": "<<ans<<endl;
        cout<<"Case #"<<cse<<": "<<ans<<endl;
        cse++;
    }

    return 0;
}
