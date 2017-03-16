#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>

using namespace std;

typedef struct box{
    long long box_quan[100];
    int box_type[100];    
}Box;
    
typedef struct toy{
    long long toy_quan[100];
    int toy_type[100];    
}Toy;
long long cur,largest;
    
long long find_max(int box_no, int toy_no,int n,int m,Box box,Toy toy){
    if(box_no==n || toy_no==m)
        return 0;
    long long cur_match=0;
    /*
    printf("%d %d\n",box_no,toy_no);
    for(int i=0;i<n;i++){
        printf("%lld %d ",box.box_quan[i],box.box_type[i]);    
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%lld %d ",toy.toy_quan[i],toy.toy_type[i]);    
    }
    printf("\n");
    printf("%lld\n\n\n",largest);          
    */
    if( box.box_type[box_no]==toy.toy_type[toy_no] && box.box_quan[box_no]!=0 && toy.toy_quan[toy_no]!=0){
        if(box.box_quan[box_no]>toy.toy_quan[toy_no]){
            cur_match=toy.toy_quan[toy_no];
            box.box_quan[box_no]-=toy.toy_quan[toy_no];
            toy.toy_quan[toy_no] = 0;  
            toy_no+=1;  
        }        
        else{
            cur_match=box.box_quan[box_no];   
            toy.toy_quan[toy_no] -= box.box_quan[box_no];
            box.box_quan[box_no] = 0;  
            box_no+=1;   
        }
        cur=cur_match + find_max(box_no,toy_no,n,m,box,toy);
        if(cur>largest)
            largest=cur;
        return cur;
    } 
    else{
        long long a=find_max(box_no+1,toy_no,n,m,box,toy);
        long long b=find_max(box_no,toy_no+1,n,m,box,toy);
        if( max(a , b)>largest) largest=max(a,b);
        return max(a,b);
    }   
       
        
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);   
    
    int t,tests,i,j;
    
    int n,m;
    Box box;
    Toy toy;
    scanf("%d",&tests);
    
    for(t=1;t<=tests;t++){
        largest=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%lld%d",&box.box_quan[i],&box.box_type[i]);
        }    
        for(i=0;i<m;i++){
            scanf("%lld%d",&toy.toy_quan[i],&toy.toy_type[i]);
        }    
        find_max(0,0,n,m,box,toy);
        printf("Case #%d: %lld\n",t,largest);
    }   
    return 0;
}
