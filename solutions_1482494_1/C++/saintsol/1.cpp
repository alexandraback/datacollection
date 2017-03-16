#include<stdio.h>
#include<stdlib.h>
void q_sort(int numbers[],int b[], int left, int right)
{
  int pivot, l_hold, r_hold,pivot2;
 
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  pivot2=b[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      b[left]=b[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      b[right]=b[left];
      right--;
    }
  }
  numbers[left] = pivot;
  b[left]=pivot2;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, b,left, pivot-1);
  if (right > pivot)
    q_sort(numbers, b,pivot+1, right);
}
void quickSort(int numbers[],int b[], int array_size)
{
  q_sort(numbers,b, 0, array_size - 1);
}
int main(){
    int num,i,j,k,count,mem;
    long star;
    int a[100],b[100],c,diff,cmp;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&c);
        star=0;
        count=0;
        for(j=0;j<c;j++)
            scanf("%d %d",&a[j],&b[j]);   
        quickSort(b,a,c);
        for(j=0;star!=-1&&j<c;j++){

            if(b[j]==0){
                star+=2;
                a[j]=-1;
                count++;
            }
            else if(b[j]>0&&star>=b[j]){
                if(a[j]==-1){
                    star++;
                    count++;
                }
                else{
                    star+=2;
                    a[j]=-1;
                    count++;
                }
            }
            else{
                diff=-1;
                for(k=0;k<c;k++){
                    if(a[k]>-1&&star>=a[k]){
                        cmp=b[k]-a[k];
                        if(cmp>diff){
                            mem=k;
                            diff=cmp;
                        }
                    }
                }   
                if(diff==-1)
                    star=-1;
                else{
                    a[mem]=-1;
                    star++;
                    count++;
                }
                j--;
            }
        }
        printf("Case #%d: ",i+1);
        if(star==-1)
            printf("Too Bad\n");
        else
            printf("%d\n",count);
    }
    return 0;   
}
