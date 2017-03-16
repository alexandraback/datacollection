#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;


int number_of_cases;

int L;

long long X;

string sequence;

char buffer[100005];

int multiplication_table[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};


struct quaternion{
    char value;
    int sign;

};




int value_to_index(char c){
    if (c=='1') return 0;
    return c-'i'+1;

}

char array_to_value(int index){
    index=abs(index);
    if (index==1) return '1';
    return 'i'+index-2;

}


quaternion multiply(quaternion number1,quaternion number2 ){
    
    quaternion result;
    result.sign=number1.sign*number2.sign;
    
    if (multiplication_table[value_to_index(number1.value)][value_to_index(number2.value)]<0) result.sign*=-1;
    
    result.value= array_to_value(multiplication_table[value_to_index(number1.value)][value_to_index(number2.value)]);
    
    return result;
    
}

string solve(){
    scanf("%d %lld\n",&L,&X);
    scanf("%s",buffer); sequence=buffer;
    
    long long first_i=X*L;
    long long last_k=-1;
    
    quaternion value_L_segment={'1',1};
  //  quaternion minus_one={'1',-1};
    
    for (int i=0;i<L;i++){
        quaternion q={sequence[i],1};
        value_L_segment=multiply(value_L_segment,q);
    //    printf("L segment %c %d\n",value_L_segment.value,value_L_segment.sign);
        
    }
    
    
    
    quaternion value_XL_segment={'1',1};
    
    quaternion segments[4];
    
    for (int i=0;i<4;i++) segments[i]=value_XL_segment=multiply(value_XL_segment, value_L_segment);
    
    if (segments[(X-1)%4].value!='1') return "NO";
    if (segments[(X-1)%4].sign!=-1) return "NO";
    
    quaternion current_value={'1',1};
    
    for (int i=0;i<L;i++){
        quaternion q={sequence[i],1};
        current_value=multiply(current_value, q);
        if (current_value.value=='i'&&current_value.sign==1) first_i=min(first_i,(long long)i);
        for (int j=0;j<4;j++){
            
            quaternion q=multiply(segments[j], current_value);
            
            if (q.value=='i'&&q.sign==1) first_i=min(first_i,(long long)i+(j+1)*L);
            
        
        }
    
    }
    
    current_value.value='1';
    current_value.sign=1;
    
    for (int i=L-1;i>=0;i--){
        quaternion q={sequence[i],1};
        current_value=multiply(q,current_value);
        
        if (current_value.value=='k'&&current_value.sign==1) last_k=max(last_k,(X-1)*L+i);
        for (int j=0;j<4;j++){
            
            quaternion q=multiply(current_value,segments[j]);
            
            if (q.value=='k'&&q.sign==1) last_k=max(last_k,(X-1)*L+i-(long long)(j+1)*L);
            
            
        }

        
    }
    
    
    if (first_i<last_k) return "YES"; else return "NO";


}

int main() {
    scanf("%d",&number_of_cases);
    
    for (int case_number=1;case_number<=number_of_cases;case_number++) printf("Case #%d: %s\n",case_number,solve().c_str());

    return 0;
}
