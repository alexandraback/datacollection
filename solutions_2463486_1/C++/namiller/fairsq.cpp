//
//  main.cpp
//  palindrome
//
//  Created by Nolan Miller on 4/12/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct carray {
    char* c;
    int l;
    bool g;
};
bool lessthan(carray in1,carray in2){
    if (in1.l>in2.l) {
        return 0;
    }
    if (in1.l<in2.l) {
        return 1;
    }
    for (int i =0; i<in1.l; i++) {
        if (in1.c[i]>in2.c[i]) {
            return 0;
        }
        if (in1.c[i]<in2.c[i]) {
            return 1;
        }
    }
    return 1;
}
bool equals(carray in1,carray in2){
    if(in1.l != in2.l){
        return 0;
    }
    for (int i = 0; i<in2.l; i++) {
        if (in1.c[i] !=in2.c[i]) {
            return 0;
        }
    }
    return 1;
}



bool isPalandrome(carray in){
    for (int i = 0; i<=in.l/2; i++) {
        if(in.c[i] != in.c[in.l-i-1]){
            return 0;
        }
    }
    return 1;
}

carray square(carray in){
    carray out;
    out.c = new char[in.l*2-1];
    out.l = in.l*2-1;
    out.g = 1;
    for (int i = 0; i<in.l*2; i++) {
        out.c[i] = 0;
    }
    for (int i = 0; i<in.l; i++) {
        for (int ii = 0; ii<in.l; ii++) {
            //don't have to go right to left because its a palindrome
            out.c[ii+i] += in.c[i]*in.c[ii];
            if(out.c[ii+i] >=10){
                out.g = 0;
                return out;
            }
        }
    }
    return out;
}
void print1d(char* array,int l){
    for(int i =0;i<l;i++){
        cout<<int(array[i])<<" ";
    }
    cout<<endl;
}
void print1d(carray in){
    for(int i = 0;i<in.l;i++){
        cout<<int(in.c[i])<<" ";
    }
    cout<<endl;
}

void next(carray* in){
    bool all9 = 1;
    for (int i = 0; i<in->l; i++) {
        if (in->c[i] != 9) {
            all9 =0;
            break;
        }
    }
    if (all9) {
        in->l++;
        delete[] in->c;
        in->c = new char[in->l];
        for (int i = 0; i<in->l; i++) {
            in->c[i] = 0;
        }
        in->c[0] = in->c[in->l-1] = 1;
        return;
    }
    else{
        //even
        int p = in->l/2;
        if (in->l %2 == 0) {
            p--;
            while (in->c[p]==9) {
                in->c[p] = in->c[in->l-p-1] = 0;
                p--;
            }
            in->c[p]++;
            in->c[in->l-p-1]++;
        }
        else {
            if(in->c[p] == 9){
                in->c[p] = 0;
                p--;
                while (in->c[p] ==9) {
                    in->c[p] = in->c[in->l-p-1] = 0;
                    p--;
                }
                in->c[p]++;
                in->c[in->l-p-1]++;
            }
            else
                in->c[p]++;
        }
    }
    return;
}
void nextg(carray* in){
    bool all2 = 1;
    for (int i = 0; i<in->l; i++) {
        if (in->c[i] != 2) {
            all2 =0;
            break;
        }
    }
    if (all2) {
        in->l++;
        delete[] in->c;
        in->c = new char[in->l];
        for (int i = 0; i<in->l; i++) {
            in->c[i] = 0;
        }
        in->c[0] = in->c[in->l-1] = 1;
        return;
    }
    else{
        //even
        int p = in->l/2;
        if (in->l %2 == 0) {
            p--;
            while (in->c[p]==2) {
                in->c[p] = in->c[in->l-p-1] = 0;
                p--;
            }
            in->c[p]++;
            in->c[in->l-p-1]++;
        }
        else {
            if(in->c[p] == 2){
                in->c[p] = 0;
                p--;
                while (in->c[p] ==2) {
                    in->c[p] = in->c[in->l-p-1] = 0;
                    p--;
                }
                in->c[p]++;
                in->c[in->l-p-1]++;
            }
            else
                in->c[p]++;
        }
    }
    return;
}
carray froot(carray in){
    carray out;
    if (in.l  == 1) {
        out.l = 1;
        out.c = new char;
        out.c[0] = ceil(sqrt(in.c[0]));
        if (out.c[0] ==0) {
            out.c[0]++;
        }
        if (out.c[0] >=3) {
            delete out.c;
            out.c = new char[2];
            out.l = 2;
            out.c[0] = out.c[1] = 1;
        }
        return out;
    }
    else{
        out.l = in.l/2;
        out.c = new char[out.l];
        for (int i = 0; i<out.l; i++) {
            out.c[i] = 0;
        }
        out.c[0] = out.c[out.l-1] = 1;
    }

    
    carray tmp;
    tmp = square(out);
    while (lessthan(tmp, in)){
        delete tmp.c;
        nextg(&out);
        tmp = square(out);
        if (equals(tmp, in)) {
            return out;
        }
    }
    delete tmp.c;
    return out;
}
carray read(){
    carray s;
    vector<char> in;
    char ttt;
    do {
        cin>>ttt;
        if (ttt != ' '&& ttt!= '\n'&& ttt!=EOF) {
            in.push_back(ttt);
        }
        else
            break;
    } while (cin.peek() != ' '&& cin.peek()!= '\n'&& cin.peek()!=EOF);

    s.l = int(in.size());
    s.c = new char[s.l];
    for (int i = 0; i<s.l ; i++) {
        s.c[i] = in[i]-'0';
    }
    return s;
}


int main(int argc, const char * argv[])
{

    
    int len;
    cin>>len;
    for (int it = 0; it<len; it++) {
        
        carray s;
        carray e;
        s = read();
        e = read();
        carray test = froot(s);
        int ret = 0;
        carray sq = square(test);
        while (lessthan(sq, e)) {
            if (isPalandrome(sq)) {
                ret++;
            }
            nextg(&test);
            delete [] sq.c;
            sq = square(test);
        }
        if (equals(sq, e)) {
            ret++;
        }
        if (s.c[0] <=9 && s.l ==1 && (e.c[0] >=9 ||e.l>1)) {
            ret++;
        }
        cout<<"Case #"<<it+1<<": "<< ret <<endl;
        delete [] sq.c;
    }
    

    return 0;
}


