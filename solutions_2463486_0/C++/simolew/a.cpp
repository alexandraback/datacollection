#include<iostream>
#include<vector>
using namespace std;
// use a script to find final solution
vector<int> number;
vector<int> current;

void push(int a) {
    current.push_back(a);
}
void pop() {
    current.pop_back();
}
int dyn(int sum, int place, int totallength, bool exact, bool fix, int mn) {
    if(sum<0) return 0;
 //   cout<<"sum="<<sum<<",place="<<place<<"totallength="<<totallength<<",exact="<<exact<<",fix="<<fix<<", mn="<<mn<<endl;
 //   for(int i=0;i<current.size();i++) cout<<current[i];
 //   cout<<endl;
    int ans=0;
    if(totallength % 2 ==1 && place*2 == totallength-1) {
        if(fix) {
            for(int num=mn;num<=4 && num < number[place];num++) {
                if(sum-num*num>=0) ans++;                
            }
        } else if(exact) {
            for(int num=mn;num<=4 && num <= number[place];num++) {
                if(sum-num*num>=0) ans++;                
            }
        }
        else {
            for(int num=mn;num<=4;num++) {
                if(sum-num*num>=0) ans++;                
            }
        }
    } else if(totallength % 2 == 0 && place >= totallength/2) {
        if(fix) ans=0;
        else ans=1;
    }else if(fix) {

        for(int num=mn;num <= number[place];num++) {
            if(number[place] == num) {
                push(num);
                ans+= dyn(sum-2*num*num,place+1,totallength,true, true,0);
                pop();
            } else {
                push(num);
                
                ans += dyn(sum-2*num*num,place+1,totallength,false, false,0);
                pop();
            }
        }
    } else if(exact) {
        for(int num=mn;num <= number[place];num++) {
            if(number[place]==num && number[totallength-1-place] < num) {
                push(num);
                ans+= dyn(sum-2*num*num,place+1,totallength,true,true,0);
                pop();
            } else if(number[place]==num) {
                push(num);
                ans+= dyn(sum-2*num*num,place+1,totallength,true,false,0);
                pop();

            } else {
                push(num);
                ans+= dyn(sum-2*num*num,place+1,totallength,false,false,0);
                pop();
            }
        }

    }
    else {
        for(int num=mn;num<=4;num++)  {
            ans += dyn(sum-2*num*num,place+1,totallength,false,false,0);
        }
    }
    return ans;

}

int main() {
    string s="100000";
    cin>>s;
    /*if(s=="1") cout<< 1<<endl;
    if(s=="2") cout<< 1<<endl;
    if(s=="3") cout<< 2<<endl;
    if(s=="4") cout<< 2<<endl;
    if(s=="5") cout<< 2<<endl;
    if(s=="6") cout<< 2<<endl;
    if(s=="7") cout<< 2<<endl;
    if(s=="8") cout<< 2<<endl;
    if(s=="9") cout<< 2<<endl;*/

    for(int i=0;i<s.size();i++) number.push_back(s[i]-'0');
    int ans = dyn(9,0,s.size(),true,false,1);
    for(int i=s.size()-1;i>=1;i--) {
        ans += dyn(9,0,i,false,false,1);
    }
    cout<<ans<<endl;
    
}
