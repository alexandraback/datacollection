#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>       /* time */
#include <algorithm>
#include <list>
#include <utility>
#include <climits>


using namespace std;

pair<string, string> getMinimal(string c, string j, long long int index, long long int balance);
long long int getDifference(string c, string j);

int main()
{
  ofstream outfile;
  outfile.open ("closematch.out");
  std::ifstream infile;
  infile.open ("data.in", std::ifstream::in);
  std::string   line;
  getline(infile, line);
  std::stringstream  lineStream(line);
  long long int T;
  lineStream>>T;
  for(long long int i=0;i<T;i++){
	string c,j;
	getline(infile, line);
	std::stringstream  Stream1(line);
	Stream1>>c>>j;
	pair<string, string> res=getMinimal(c,j,0,0);
    outfile<<"Case #"<<i+1<<": "<<res.first<<" "<<res.second<<endl;
  }

  infile.close();
  outfile.close();
  return 0;
}


pair<string, string> getMinimal(string c, string j, long long int index, long long int balance){
	pair<string, string> result;
	if(index==c.length()){
        result=make_pair(c,j);
	}else{
        if(balance<0){
            if(c[index]=='?') c[index]='9';
            if(j[index]=='?') j[index]='0';
            result=getMinimal(c,j,index+1,balance);
        }
        if(balance>0){
            if(c[index]=='?') c[index]='0';
            if(j[index]=='?') j[index]='9';
            result=getMinimal(c,j,index+1,balance);
        }
        if(balance==0){
            if(c[index]!='?' && j[index]!='?'){
                if(c[index]>j[index]){
                    result=getMinimal(c,j,index+1,1);
                }else if(c[index]<j[index]){
                    result=getMinimal(c,j,index+1,-1);
                }else{
                    result=getMinimal(c,j,index+1,0);
                }
            }
            if(c[index]=='?' && j[index]!='?'){
               long long int d1,d2,d3;
               pair<string, string> v1, v2, v3;
               if(j[index]!='0'){
                    c[index]=j[index]-1;
                    v1=getMinimal(c,j,index+1,-1);
                    d1=getDifference(v1.first,v1.second);
               }else d1=LONG_LONG_MAX;
               if(j[index]!='9'){
                    c[index]=j[index]+1;
                    v3=getMinimal(c,j,index+1,1);
                    d3=getDifference(v3.first,v3.second);
               }else d3=LONG_LONG_MAX;
               c[index]=j[index];
               v2=getMinimal(c,j,index+1,0);
               d2=getDifference(v2.first,v2.second);
               if(d1<=d2 && d1<=d3){
                   result=v1;
               }else{
                   if(d2<=d3){
                       result=v2;
                   }else{
                       result=v3;
                   }
               }
            }
            if(c[index]!='?' && j[index]=='?'){
               pair<string, string> v1, v2, v3;
               long long int d1,d2,d3;
               if(c[index]!='0'){
                    j[index]=c[index]-1;
                    v1=getMinimal(c,j,index+1,1);
                    d1=getDifference(v1.first,v1.second);
               }else d1=LONG_LONG_MAX;
               if(c[index]!='9'){
                    j[index]=c[index]+1;
                    v3=getMinimal(c,j,index+1,-1);
                    d3=getDifference(v3.first,v3.second);
               }else d3=LONG_LONG_MAX;
               j[index]=c[index];
               v2=getMinimal(c,j,index+1,balance);
               d2=getDifference(v2.first,v2.second);
               if(d1<=d2 && d1<=d3){
                   result=v1;
               }else{
                   if(d2<=d3){
                       result=v2;
                   }else{
                       result=v3;
                   }
               }
            }
            if(c[index]=='?' && j[index]=='?'){
                pair<string, string> v1, v2, v3;
                c[index]='0';
                j[index]='0';
                v1=getMinimal(c,j,index+1,balance);
                c[index]='0';
                j[index]='1';
                v2=getMinimal(c,j,index+1,-1);
                c[index]='1';
                j[index]='0';
                v3=getMinimal(c,j,index+1,1);
                long long int d1,d2,d3;
                d1=getDifference(v1.first,v1.second);
                d2=getDifference(v2.first,v2.second);
                d3=getDifference(v3.first,v3.second);
                if(d1<=d2 && d1<=d3){
                    result=v1;
                }else{
                    if(d2<=d3){
                        result=v2;
                    }else{
                        result=v3;
                    }
                }
            }
        }
	}
    return result;

}

long long int getDifference(string c, string j){
    long long int a,b;
    std::istringstream ss(c);
    ss >> a;
      std::istringstream ss2(j);
    ss2 >> b;
    if(a>b) return a-b;
    else return b-a;
}

