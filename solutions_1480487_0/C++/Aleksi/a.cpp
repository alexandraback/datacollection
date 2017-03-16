#include<iostream>
#include<algorithm>
#include<utility>
#include<iomanip>
#include<vector>

using namespace std;



double maxmin(vector<int> js,int x,double lv){


    double jmax = 0;
    for(int i=0;i<js.size();i++){
        jmax = max(jmax,double(js[i]));
    }

    if(js.size()==1)return lv*x+js[0];


    double left = jmax;
    double right = x*2;
    int iters = 100;
    while(iters --> 0){
        double sum = 0;
        double s= (left+right)/2;
        for(int i=0;i<js.size();i++){
            double r = (s-js[i])/double(x);
            if(r<0){
                r=0;
            }
            sum+=r;
        }
        if(sum > lv){
            right = s;
        }else{
            left = s;
        }
    }
    return left;
}

vector<double> solve(vector<int> js){

    int x=0;
    double jmax =0;
    for(int i=0;i<js.size();i++){
        x+=js[i];
        jmax= max(jmax,double(js[i]));
    }



    vector<double> ret(js.size(),0);

    if(js.size()<2)return ret;


    int iters = 10000;
    double sum = 0;

    vector<int> js2 = js;
    for(int i=0;i<js.size();i++){
        double left = 0;
        double right = 1;
        //cout<<js2[i]<<"\n";
        swap(js2[i],js2.back());
        js2.pop_back();
        int iters = 100;

        while(iters-->0){
            double s = (left+right)/2;
            double mm = maxmin(js2,x,1-s);
            double score = s*x+js[i];
            //cout<<"b="<<s<<" mm="<<mm<<" score="<<score<<"\n";
            if(score<=mm){
                left = s;
            }else{
                right = s;
            }
        }
        ret[i]=left;

        js2.push_back(js[i]);
        swap(js2[i],js2.back());
    }
    return ret;
}

int main(){
	int t;
    cin>>t;
    for(int cn=1;cn<=t;cn++)
    {
        vector<int> judge;
        int n;
        cin>>n;
        judge.resize(n);
        for(int i=0;i<n;i++)
            cin>>judge[i];

        vector<double> solution =  solve(judge);
        //cout<<"ss = "<<solution.size()<<"\n";
        
        cout<<"Case #"<<cn<<": ";
        for(int i=0;i<solution.size();i++)
            cout<<setprecision(8)<<fixed<<100*solution[i]<<" ";
        cout<<"\n";
    }
}
