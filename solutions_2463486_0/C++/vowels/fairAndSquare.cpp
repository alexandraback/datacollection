#include<iostream>
using namespace std;

bool isPalin(long long int num)
{

    long long int n = num;
    long long int  rev = 0;
    while (num > 0)
    {
        int dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    if(n==rev)
    {
        return true;
    }
    return false;
}

bool allDigits9(char arr[] , int length)
{
    int j = length-1;
    while(j>=0)
    {
        if(arr[j--]!='9')
        {
            return false;
        }
    }
    return true;
}

//called if all digits are not 9
void addone(char arr[] , int length)
{
    bool toRipple = true;
    int i = length -1;
    while(1)
    {
        if(arr[i]=='9')
        {
            arr[i]='0';
        }
        else
        {
            arr[i]++;
            break;
        }
        i--;
    }
}

//in this case input won't be all 9's
int incrementTheArray(char arr[], int length)
{
    bool isEven = false;
    if(length%2==0)
    {
        isEven = true;
    }
    bool toRipple = true;
    int i;
    int j;
    int len = length;
    if(isEven)
    {
        i = length/2;
        i--;
        j=i+1;
    }
    else
    {
        i= (length-1)/2;
        j=i+1;
        if(arr[i]=='9')
        {
            arr[i]='0';
        }
        else
        {
            arr[i]++;
            toRipple = false;
        }
        i--;
    }
    while(toRipple && i>=0 )
    {
        if(arr[i]=='9')
        {
            arr[i]='0';
            arr[j]='0';
            i--;
            j++;
        }
        else
        {
            arr[i]++;
            arr[j]++;
            i--;
            j++;
            toRipple= false;
        }
    }


    if(toRipple && i < 0)
    {
        while(1);
        //printf("code shouldn't come here \n");
        //arr[j++]=1;
        //arr[0]=1;
        //len++;
    }
    
    //print(arr,len);
    return len;
    
}

bool isPalindrome(char arr[], int length)
{
    int high = length-1;
    int low =0;
    while(high > low)
    {
        if(arr[high--]!=arr[low++])
        {
            return false;
        }
    }
    return true;
}


int makePalindrom(char arr[] , int length)
{
    //for(int i=0 ; i<length ; i++)
    //{
        //cout<<arr[i]<< " ";
    //}
    //cout<<endl;
    bool isEven = false;
    if(length%2==0)
    {
        isEven = true;
    }
    //int low =0;
    //int high =length -1;
    bool newNumIsLarger = false;
    int isFirstValidComparision = 1;
    bool newNumIsSmaller = false;
    int len = length;

    bool isPalin1 = isPalindrome(arr,length);
    //1322
    //2431
    //1331
    int i = 0;
    int j = 0;
    if(isEven)
    {
        i=length/2 -1;
        j=i+1;
    }
    else
    {
        i = (length - 1)/2;
        j = i+1;
        i--;
    }
    while(i>=0)
    {
        if((arr[i]>arr[j]) &&isFirstValidComparision)
        {
            newNumIsLarger = true;
            isFirstValidComparision = false;
        }
        else if ((arr[i]<arr[j]) &&isFirstValidComparision)
        {
            newNumIsSmaller = true;
            isFirstValidComparision = false;
        }
        arr[j++] = arr[i--];
    }
    if((newNumIsSmaller == newNumIsLarger)) // number is palindrome
    {
        if(allDigits9(arr,len))
        {
            arr[0]='1';
            for(int i=1;i<length;i++)
            {
                arr[i] = '0';
            }
            arr[length]='1';
            return 1+length;
        }
        if(len==1)
        {   //single digit number not equal to 9
            arr[0]++;
            return 1;
            //printf("%c\n",arr[0]+1);
            //return;
        }
        addone(arr,len);
        return makePalindrom(arr,len);
    }
    else if(newNumIsLarger) // new number is larger
    {
        return len;   
    }

    return incrementTheArray(arr,len);

}

int digits(long long int num)
{
    int dig=0;
    while(num>0)
    {
        dig++;
        num/=10;
    }
    return dig;
}

long long int makeNextpalin(long long int num)
{
    //cout<<"num "<< num<<endl;
    char arr[16];
    //int index=0;
    //while(num>0)
    //{
        //arr[index++]=(char) (((int)'0')+num%10);
        //num/=10;
    //}
    long long int  rev = 0;
    int dig = digits(num);
    while (num > 0)
    {
        int dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    //cout<<"rev "<<rev<<endl;
    int index=0;
    int dig2 = digits(rev);
    for(int i=0; i< index; i++)
    {
        arr[i] = arr[i]+'0';
    }
    while(rev>0)
    {
        arr[index++] = (char) (((int)'0')+rev%10);
        rev=rev/10;
    }
    index+=dig-dig2;

    
    index = makePalindrom(arr, index);
    //for(int i=0 ; i<index; i++)
    //{
        //cout<<arr[i]<< " ";
    //}
    long long int num1=0;
    index--;
    while(index>=0)
    {
        num1*=10;
        num1 += arr[index--] - '0';
    }
    return num1;

}

long long int nextPalin(long long int sqrNum, long long int high)
{
    //if(sqrNum==0)
    //{
        //return 1;
    //}
    //cout<< " input to nextPain fxn is "<<sqrNum<<endl;
    long long int next = sqrNum+1;
    if(!isPalin(next))
    {
        next = makeNextpalin(next);
        //cout<<next<<endl;
    }
    long long int temp = next*next;
    while(temp <= high && (!isPalin( temp)))
    {
        next = makeNextpalin(next);
        //cout<<" next "<<next<<endl;
        temp=next*next;
    }

    if(temp > high)
    {
        //cout <<"temp "<<temp<<endl;
        //cout <<"next"<<next<<endl;
        return -1;
    }

    if(isPalin(temp))
    {
        return next;
    }
    
}

int main()
{
    int t;
    cin>>t;
    for(int q=1;q<t+1;q++)
    {
        long long int counter=0;
        long long int low;
        long long int high;
        cin>>low>>high;
        //if(q==75)
            //{
                //cout<<low <<" "<<high<<endl;
            //}
        long long int sqrNum=1;
        while(sqrNum*sqrNum <low)
        {
            sqrNum++;
        }
        sqrNum--;
            //cout<<sqrNum<<" sqrNum " <<endl;
        while((sqrNum = nextPalin(sqrNum, high))!=-1)
        {
            //cout<<sqrNum<<" sqrNum " <<endl;
            counter++;
        }
        cout<<"Case #"<<q<<": "<<counter<<endl;
    }
    return 0;
}
