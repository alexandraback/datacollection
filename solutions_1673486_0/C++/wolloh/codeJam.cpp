#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

#ifdef _MSC_VER
typedef unsigned __int64 uint64;
#else
typedef unsigned long long uint64;
#endif


/* 2010 google code jam-- Theme Park 
int main(void)
{
    int i,j,k,m,n;
    int testNumber;
    int roundNumber;
    int groupNumber;
    int n32GroupCountTable[1001];
    uint64 u64SumTable[1001];
    int nextIndex[1001];
    int traverseCount[1001];
    uint64 traverseSum[1001];
    int sizeK;
    int currentRound;
    int cycleNumber;
    int cycleStartIndex;
    uint64 cycleSum;
    uint64 u64CurrentSum;
    uint64 answer;
    int previousCount;
    int count2Index[1001];
    uint64 KeyTable[1001];
    
    FILE * fIn = fopen("D:\\C-large.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);
    
    for(i = 0; i < testNumber; i++)
    {
        for(j = 0; j < 1001; j++)
        {
            n32GroupCountTable[j] = 0;
            u64SumTable[j] = 0;
            nextIndex[j] = 0;
            traverseCount[j] = 0;
            traverseSum[j] = 0;
            count2Index[j] = 0;
            KeyTable[j] = 0;
        }
        roundNumber = 0;
        groupNumber = 0;
        sizeK = 0;
        currentRound = 0;
        u64CurrentSum = 0;
        cycleNumber = 0;
        cycleStartIndex = -1;
        cycleSum = 0;
        answer = 0;
        
        fscanf(fIn,"%d %d %d",&roundNumber, &sizeK, &groupNumber);
        for(j = 0; j < groupNumber; j++)
        {
            fscanf(fIn,"%d",&n32GroupCountTable[j]);
        }

        for(j = 0; j < groupNumber; j++)
        {
            int tempSum = n32GroupCountTable[j];
            
            for(m = (j+1)%groupNumber; m != j; m = (m+1)%groupNumber)
            {
                tempSum += n32GroupCountTable[m];
                
                if(tempSum > sizeK)
                {
                    break;
                }
            }
            
            if(tempSum > sizeK)
            {
                tempSum -= n32GroupCountTable[m];
            }
            
            u64SumTable[j] = tempSum;
            nextIndex[j] = m;
        }

        int index = 0;
        int tempTraverseCount = 1;
        uint64 tempTraverseSum = 0;

        for(;;tempTraverseCount++)
        {
            if(traverseCount[index])
            {
                cycleStartIndex = index;
                cycleNumber = tempTraverseCount - traverseCount[index];
                cycleSum = tempTraverseSum - traverseSum[index];
                previousCount = traverseCount[index] - 1;
                break;
            }
            
            count2Index[tempTraverseCount] = index;
            traverseCount[index] = tempTraverseCount;
            traverseSum[index] = tempTraverseSum;
            tempTraverseSum += u64SumTable[index];
            KeyTable[tempTraverseCount] = tempTraverseSum;
            index = nextIndex[index];
        }

        if(roundNumber < previousCount)
        {
            int tempIndex = count2Index[roundNumber];
            answer = traverseSum[tempIndex] + u64SumTable[tempIndex];
        }
        else
        {
            int q,r;
            roundNumber -= previousCount;
            q = roundNumber/cycleNumber;
            r = roundNumber%cycleNumber;
            answer = (q * cycleSum);
            
            r = r + previousCount;
            answer = answer + KeyTable[r];
        }

        fprintf(fOut,"Case #%d: %lld\n",i+1,answer);
    
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
}

*/

/*Snapper Chain
 int main(void)
{
    int i,j,k,m,n;
    int testNumber;
    int Nth;
    int Kcount;
    int completeN;
    
    FILE * fIn = fopen("D:\\A-large.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);
    
    for(i = 0; i < testNumber; i++)
    {
        
        fscanf(fIn,"%d %d",&Nth,&Kcount);
        completeN = (1 << Nth);
        Kcount %= completeN;
        
        if((completeN -1) == Kcount)
        {
            fprintf(fOut,"Case #%d: ON\n",i+1);
        }

        else
        {
            fprintf(fOut,"Case #%d: OFF\n",i+1);
        }
    
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
}  */

/* Fair Warning 
#define MAX_NUMBER "999999999999999999999999999999999999999999999999999"

typedef struct bigNum
{
    char number[51];
    int len;
}sBigNumberData;

void inverseStr(char* str, int len)
{
    int i,j;
    char temp;
    
    for(i = len -1, j = 0; i != j; i--, j++)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int bigNumCmp(char* Bn1, char* Bn2)
{
    int i;
    for(i = 50; i >= 0; i++)
    {
        if(Bn1[i] > Bn2[i])
        {
            return 1;
        }    
        if(Bn1[i] < Bn2[i])
        {
            return 2;
        }
    }
    return 0;
}

int isZero(char* Bn)
{
    int i;
    for(i = 0; i < 51; i++)
    {
        if(Bn[i] > '0')
        {
            return 0;
        }
    }
    return 1;
}

void wSubtract(char* a, char* b, char* c)
{
    int i;
    int lenA;
    int lenB;

    if(2 == bigNumCmp(a,b))
    {
        strcpy(c,a);
    }
    else
    {
        for(i = 0; i < 51; i++)
        {
        
        }
    }
    return;
}
void wAsubtract(char* a, char* b, char* c)
{
    if(1 == bigNumCmp(a,b))
    {
    
    }
    else
    {
    
    }
}

void modR(char* a, char* r)
{
    
}

void wgcd(char* Bn1, char* Bn2)
{
    char r[51], temp[51];
    
    for(strcpy(r, Bn2); !isZero(r);)
    {
        strcpy(temp,r);

    }
}

int main(void)
{
    int i,j,k,m,n;
    int testNumber;
    int bigEventNumber;
    sBigNumberData bigEventTable[1000];
    sBigNumberData commonFactor;
    sBigNumberData temp;
    sBigNumberData answer;
    sBigNumberData smallest;

    strcpy(smallest.number, MAX_NUMBER);
    smallest.len = 51;

    FILE * fIn = fopen("D:\\B-small-attempt0.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);
    
    for(i = 0; i < testNumber; i++)
    {
        fscanf(fIn,"%d",&bigEventNumber);
        
        for(j = 0; j < bigEventNumber; j++)
        {
            fscanf(fIn,"%s",&(bigEventTable[j].number));
            bigEventTable[j].len = strlen(bigEventTable[j].number);
            
            if(bigNumCmp(smallest,bigEventTable[j]))
            {
            }
        }
        commonFactor = wsubtract(bigEventTable[0],bigEventTable[1]);
        
        for(j = 0; j < bigEventNumber; j++)
        {
            for(k = j+1; k < bigEventNumber; k++)
            {
                temp = wsubtract(bigEventTable[j],bigEventTable[k]);
                commonFactor = wgcd(commonFactor, temp);
            }
        }

        if(0 == wmod(smallest,commonFactor))
        {
            answer.len = 1;
            answer.number[0] = '0';
        }
        else
        {
            answer = wsubtract(commonFactor, wmod(smallest,commonFactor));
        }
        fprintf(fOut,"Case #%d: %s\n",i+1,answer.number);  
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
} 

*/
/*
int getDistance(char* oldPath, char* newPath)
{
    int i, j;
    
    char slash = '/';
    char* oldPtr = ++oldPath;
    char* newPtr = ++newPath;
    int distance = 0;
    
    for(;(*oldPtr != 0) && (*oldPtr == *newPtr) && (*newPtr != 0); 
        oldPtr++, newPtr++);

    if(*newPtr != 0)
    {
        distance = 1;
    }
    if((*oldPtr == 0) && (slash == *newPtr))
    {
        newPtr++;
    }

    for(;*newPtr != 0; newPtr++)
    {       
        if(slash == *newPtr)
        {
            distance++;
        }
    }

    return distance;
}
int main(void)
{
    int i,j,k,m,n,p1,p2;
    int oldNum;
    int newNum;
    int testNumber;
    int minDistance;
    int tempDistance;
    int answer;
    char temp[2];
    char oldPath[201][201];
    char newPath[201][201];

    temp[0] = 0;
    temp[1] = 0;
    FILE * fIn = fopen("D:\\A-small-attempt0.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);
    
    for(i = 0; i < testNumber; i++)
    {
        answer = 0;
        for(p1 = 0; p1 < 200; p1++)
        {
            for(p2 = 0; p2 < 200; p2++)
            {
                oldPath[p1][p2] = 0;
                newPath[p1][p2] = 0;
            }
        }
        fscanf(fIn,"%d %d",&oldNum,&newNum);
        for(j = 0; j < oldNum; j++)
        {
            fscanf(fIn,"%s",oldPath[j]);
        }
        
        for(j = 0; j < newNum; j++)
        {
            fscanf(fIn,"%s",newPath[j]);
        }

        for(j = 0; j < newNum; j++)
        {
            minDistance = getDistance(temp, newPath[j]);
            for(k = 0; k < oldNum; k++)
            {
                tempDistance = getDistance(oldPath[k],newPath[j]);
                if(tempDistance < minDistance)
                {
                    minDistance = tempDistance;    
                }
            }

            for(k = 0; k < j; k++)
            {
                tempDistance = getDistance(newPath[k],newPath[j]);
                if(tempDistance < minDistance)
                {
                    minDistance = tempDistance;    
                }   
            }

            answer += minDistance;
        }

        fprintf(fOut,"Case #%d: %d\n",i+1,answer);  
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
} 
*/
/*

int getOrder(int a, int index)
{
    int count = 0;
    
    for(int i = 0; i < index; i++)
    {
        if((a & (1 << i)))
        {
            count++;
        }
    }

    return count;
}
int main(void)
{
    int i,j,k,m;
    int testNumber;
    int N;
    int answer;
    int Num = 1;
    int answerArray[26];
    int order;
    
    FILE * fIn = fopen("D:\\test.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);
    
    for(i = 0; i < 26; i++)
    {
        answerArray[i] = -1;
    }
    for(i = 0; i < testNumber; i++)
    {
        fscanf(fIn,"%d",&N);
        Num = 1 << N;
        answer = 0;
        
        if(-1 != answerArray[N])
        {
            answer = answerArray[N];
        }

        else
        {
            for(j = 1; j < Num; j++)
            {
                for(order = getOrder(j,N); order != 1;)
                {
                    if(!(j&(1<<(order-1))))
                    {
                        break;
                    }
                    order = getOrder(j,order-1);
                }

                if(1 == order)
                {
                    answer++;
                }
            }
            answerArray[N] = answer;
        }


        fprintf(fOut,"Case #%d: %d\n",i+1,answer);  
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
} 

*/

/*
int main(void)
{
    int i,j,k,m;
    int testNumber;
    int wireCount;
    int answer;
    int aW[20000];
    int bW[20000];
    
    FILE * fIn = fopen("D:\\A-large.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);

    for(i = 0; i < testNumber; i++)
    {      
        fscanf(fIn,"%d",&wireCount);
        answer = 0;
        
        for( j = 0; j < wireCount; j++)
        {
            fscanf(fIn,"%d %d",&aW[j],&bW[j]);
        }

        for( j = 0; j < wireCount; j++)
        {
            for(k = 0; k < j; k++)
            {
                if(((aW[j] > aW[k]) && (bW[j] < bW[k])) || 
                    ((aW[j] < aW[k]) && (bW[j] > bW[k])))
                {
                    answer++;
                }
            }
        }

        fprintf(fOut,"Case #%d: %d\n",i+1,answer);  
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
} 


int logN(int base, int shit)
{
    int count = 0;
    int remainder = 0;
    
    if((shit % base != 0) && (shit != 1))
    {
        remainder++;   
    }

    for(;shit >= base;)
    {
        if(shit % base != 0)
        {
            remainder++;   
        }
        shit /= base;
        count++;
    }

        if((shit % base != 0) && (shit != 1))
        {
            remainder++;   
        }

    if(remainder) count++;

    return count;
}

int main(void)
{
    int i,j,k,m;
    int testNumber;
    int answer;
    int base;
    int smallNum;
    int bigNum;
    int quotient;
   
    
    FILE * fIn = fopen("D:\\B-large.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);

    for(i = 0; i < testNumber; i++)
    {      
        fscanf(fIn,"%d %d %d",&smallNum, &bigNum, &base);
        quotient = bigNum/smallNum;
        if( (bigNum % smallNum) )
        {
            quotient += 1;   
        }

        quotient = logN(base,quotient);
        answer = logN(2,quotient);

        fprintf(fOut,"Case #%d: %d\n",i+1,answer);  
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
}
*/
/*
int teamNumber;
int roundNumber;
int price[1024];
int isBought[1024];
int priceTable[10][1024];
int isBoughtTable[10][1024];
int pp;
int mm[1024];
int buyNumber[1024];
int tempRoundNumber;

int getPrice(int round, int team, int endRound)
{
    int i, j;

    int indexStart = 1<<team/1 << round;
    for(i = ; i < )
    {
    
    }
}
int table2Index(int i,int k)
{
    int index;
    int tempSum = 0;
    
    for(j = 0; j < i; j++)
    {        
        tempSum = tempSum + ( 1<< ((pp -1) -j) );
    }
    
    index = ( k/(1<<(i+1)) )+1;
    index = index + tempSum;

    return index;
}
int getBuyNumber(int index)
{
    int answer = 0;
    for(int i = 0; i < pp; i++)
    {
        if(1 == isBoughtTable[i][index])
        {
            answer++;
        }   
    }
    return answer;
}

int findShortest(int teamIndex)
{
    int min = 100001;
    int max = 0;
    int index = -1;
    int i;
    int tempIndex;
    for(i = 0; i < pp; i++)
    {
        if(1 == isBoughtTable[i][teamIndex])
        {
            continue;
        }
        if(priceTable[i][teamIndex] < min)
        {
            min = priceTable[i][teamIndex];
            index = i;
        }
    }

    tempIndex = table2Index(index, teamIndex);
    isBought[tempIndex] = 1;
    
    int priceIndex = tempIndex;

    for(i = index; i < pp; i++)
    {   
        int temp1 = table2Index(i,teamIndex);
        int temp2 = getPrice(index,teamIndex,i);
        if(0 == isBoughtp[temp1] && 
            max < (temp2 - price[temp1]))
        {
            max = temp2 - price[temp1];
            priceIndex = temp1;
        }
    }

    if(priceIndex != tempIndex)
    {
        isBought[tempIndex] = 0;
        isBought[priceIndex] = 1;
    }

}

int main(void)
{
    int i,j,k,m;
    int testNumber;
    int answer;
    int tempSum;
    int index;
    
    FILE * fIn = fopen("D:\\test.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);

    for(i = 0; i < testNumber; i++)
    {      
        fscanf(fIn,"%d",&pp);
        
        teamNumber = (1<<pp);
        for(j = 0; j < teamNumber; j++)
        {
            fscanf(fIn,"%d",&mm[j]);
            mm[j] = pp - mm[j];
            buyNumber[j] = 0;
        }

        roundNumber = teamNumber - 1;
        for(j = 0; j < roundNumber; j++)
        {
            fscanf(fIn,"%d",&price[j]);
            isBought[j] = 0;
        }

        tempSum = 0;
        for(j = 0; j < pp; j++)
        {
            for(k = 0; k < teamNumber; k++)
            {
                index = ( k/(1<<(j+1)) )+1;
                index = index + tempSum;
                priceTable[j][k] = price[index];
                isBoughtTable[j][k] = 0;
            }
            tempSum = tempSum + ( 1<< ((pp -1) -j) );
        }

        for(j = 0; j < teamNumber; j++)
        {
            for(;(getBuyNumber(j)) < mm[j];)
            {
                findShortest(j);        
            }
            
            tempSum = 0;
            for(j = 0; j < pp; j++)
            {
                for(k = 0; k < teamNumber; k++)
                {
                    index = ( k/(1<<(j+1)) )+1;
                    index = index + tempSum;
                    isBoughtTable[j][k] = isBought[index];
                }
                tempSum = tempSum + ( 1<< ((pp -1) -j) );
            }
        }

        fprintf(fOut,"Case #%d: %d\n",i+1,answer);  
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
}

*/

/*
#define setZero(a,b) do{while((a) != (b)){*(a)++ = 0;} }while(0) //70'
#define MAX_UNICODE      65536
typedef unsigned short* (*pfnGetName)(int n32ID);

unsigned short sg_BinaryTree[5000];
unsigned short sg_SumTable[5000];
unsigned short sg_DataTable[350000];

typedef struct sSearchItem
{
    int n32DataCount;
    int n32WordCount;
    int n32TreeSize;
    int n32State;
    int n32MaxDataCount;
    int n32MaxTreeSize;
    int n32MaxDataSize;
    unsigned short* pu16Tree;
    unsigned short* pu16SumTable;
    unsigned short* pu16DataTable;
    pfnGetName      pGetName;
}sSearchData, *psSearchDataPtr;

sSearchData BusData;



int ssStrParser(unsigned short *pu16InStr, unsigned short *pu16OutStr)
{

    unsigned short u16Space = ' ';
    unsigned short *pu16Str;
    int tmpLength = 0;

    for(pu16Str = pu16OutStr; (*pu16InStr) && (tmpLength < 700); pu16InStr++)
    {
        if(u16Space != *pu16InStr)
        {
            *pu16Str++ = *pu16InStr;
            tmpLength++;
        }
    }

    *pu16Str = 0;
    return (int)(pu16Str - pu16OutStr);
}

void separate(int *inArray, int left, int right)
{
    int midIndex, midValue;
    midIndex = (left+right) <1;

    if(left == midIndex)
    {
        return;
    }

    midValue = inArray[midIndex];

    int leftIndex = left;
    int rightIndex = right;

  
    while(leftIndex < rightIndex)
    {
        while(inArray[leftIndex++] <= midValue && 
              leftIndex < rightIndex);
        while(inArray[rightIndex--] > midValue &&
              leftIndex < rightIndex);
     
        if(leftIndex < rightIndex)
        {
            int temp = inArray[leftIndex];
            inArray[leftIndex] = inArray[rightIndex];
            inArray[rightIndex] = temp;
        }
    }
    
    separate(inArray, left, leftIndex);
    separate(inArray, leftIndex, right);

    return;
}

int quickSort(int *inArray, int inSize)
{
    separate(inArray, 0, (inSize-1));
    return 1;
}

int ssIndexer(psSearchDataPtr psSearchData)
{
    int i;
    int j;
    int strLen;
    int n32MaxDataCount;

    unsigned short au16BigTree[MAX_UNICODE];
    unsigned short repeatArray[MAX_UNICODE];
    unsigned short* pu16Tree = psSearchData->pu16Tree;
    unsigned short* pu16SumTable = psSearchData->pu16SumTable;
    unsigned short* pu16DataTable = psSearchData->pu16DataTable;
    unsigned short* pu16TreeEnd = pu16Tree + psSearchData->n32MaxTreeSize;
    unsigned short* pu16SumTableEnd = pu16SumTable + psSearchData->n32MaxTreeSize;
    unsigned short* pu16DataTableEnd = pu16DataTable + psSearchData->n32MaxDataSize;
    unsigned short* pu16BigTreeEnd = au16BigTree + MAX_UNICODE;
    unsigned short* pu16Name;
    unsigned short* isRepeat = repeatArray;
    unsigned short* repeatArrayEnd = isRepeat+ MAX_UNICODE;
    unsigned short  u16Name[700];
    pfnGetName pfGetDataName = psSearchData->pGetName;
    unsigned short* pu16Temp = au16BigTree;
    setZero(pu16Tree, pu16TreeEnd);
    setZero(pu16SumTable, pu16SumTableEnd);
    setZero(pu16DataTable, pu16DataTableEnd);
    setZero(pu16Temp, pu16BigTreeEnd);


    pu16Tree      = psSearchData->pu16Tree;
    pu16SumTable  = psSearchData->pu16SumTable;
    pu16DataTable = psSearchData->pu16DataTable;
    n32MaxDataCount = psSearchData->n32MaxDataCount;

    for(i = 0; i < n32MaxDataCount; i++)
    {
        pu16Name = pfGetDataName(i);

        if(NULL == pu16Name)
        {
            continue;
        }

        strLen = ssStrParser(pu16Name, u16Name);
        
        isRepeat = repeatArray;
        setZero(isRepeat, repeatArrayEnd);
        for(j = 0; j < strLen; j++)
        {
            repeatArray[u16Name[j]]++;
            
            if(1 == repeatArray[u16Name[j]])
            {
                au16BigTree[ u16Name[j] ]++;
            }
        }
    }

    for(i = 0; i < MAX_UNICODE && (!au16BigTree[i]); i++);

    if(MAX_UNICODE == i)
    {
        psSearchData->n32TreeSize = 0;
        return 1;
    }

    *pu16Tree++ = i;
    *pu16SumTable++ = au16BigTree[i];
    au16BigTree[i] = 0;

    for(;i < MAX_UNICODE; i++)
    {

        if(au16BigTree[i])
        {
            *pu16Tree++ = i;

            *pu16SumTable = (au16BigTree[i] + *(pu16SumTable-1));
            au16BigTree[i] = *(pu16SumTable-1);
            printf("(pu16SumTable = %d)",*pu16SumTable);
            pu16SumTable++;      
        }

    }


    psSearchData->n32TreeSize  = (int)(pu16Tree - psSearchData->pu16Tree);

    printf("Tree size = %d\n", psSearchData->n32TreeSize);

    psSearchData->n32WordCount = *(pu16SumTable-1);

    for(i = 0; i < n32MaxDataCount; i++)
    {
        pu16Name = pfGetDataName(i);

        if(NULL == pu16Name)

        {
            continue;
        }

        strLen = ssStrParser(pu16Name, u16Name);
        isRepeat = repeatArray;
        setZero(isRepeat, repeatArrayEnd);
        for(j = 0; j < strLen; j++)
        {
            repeatArray[u16Name[j]]++;
            
            if(1 == repeatArray[u16Name[j]])
            {
                pu16DataTable[ au16BigTree[ u16Name[j] ] ] = i;
                au16BigTree[ u16Name[j] ]++;
            }
        }

    }

    return 1;
}

static unsigned short LineStop[496][686];
static unsigned short LineName[496][17];
unsigned short buffer[891200];
        
unsigned short* ssGetName(int index)
{
    if(index < 496)
    {
        return  LineStop[index];
    }

    else
    {
        return 0;
    }
}

int ssInitBus()
{
    if(BusData.n32State)
    {
        return true;
    }
    BusData.n32DataCount  = 497;
    BusData.pGetName      = ssGetName;
    BusData.n32State      = 1;
    BusData.pu16Tree      = sg_BinaryTree;
    BusData.pu16SumTable  = sg_SumTable;
    BusData.pu16DataTable = sg_DataTable;
    BusData.n32MaxDataCount = 500;
    BusData.n32MaxDataSize = 350000;
    BusData.n32MaxTreeSize = 4000;

    return ssIndexer(&BusData);
}

int main(void)
{
    int index = 0;
    unsigned short semicolon = ';';
    unsigned short colon = ':';
    unsigned short dash = '-';
    unsigned short other1 = '>';
    unsigned short temp;
    unsigned short unicodeHeader = 0xFEFF;
    int a[10];
    int b[10];

    int maxNameLength = 0;
    int maxStopLength = 0;
    int bufferIndex = 0;
    
    FILE * fIn = fopen("D:\\AllStopInfo_ut16.txt", "rb");
    FILE * fOut = fopen("D:\\tables_good.txt", "w");
    fread(buffer, sizeof(unsigned short), 891200, fIn);
    
    for(temp = buffer[bufferIndex];semicolon != temp;temp = buffer[++bufferIndex]);
    
    for(;;index++)
    {
        
        if(semicolon != temp) break;
        
        // temp == ;
        int j = 0;
        for(temp = buffer[++bufferIndex]; 0 != temp && colon != temp;temp = buffer[++bufferIndex])
        {
            LineName[index][j++] = temp;            
        }

         if(j > maxNameLength)
        {
            maxNameLength = j;    
        }

        if(colon != temp)  break;

        //temp == : 
        for(j = 0, temp = buffer[++bufferIndex];  0 != temp && semicolon != temp; temp = buffer[++bufferIndex])
        {
            if(dash == temp || other1 == temp) continue;
            LineStop[index][j++] = temp;   
        }
        
        if(j > maxStopLength)
        {
            maxStopLength = j;    
        }

        if(semicolon != temp) break;
    
    }

    printf("line number :%d, max line name = %d, max stop name = %d\n", ,maxNameLength,maxStopLength);
    ssInitBus();

    for(int i = 0; i < 496; i ++)
    {
        fprintf(fOut, "{");
        for(int j = 0; j< 17; j++)
        {
            fprintf(fOut, "0x%x,", LineName[i][j]);    
        }
        fprintf(fOut, "0x0},\n"); 
    }



    fprintf(fOut,"\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
    
    for(int i = 0; 0 != sg_BinaryTree[i]; i++)
    {
        fprintf(fOut, "0x%x, ", sg_BinaryTree[i]);        
        if(7 == (i%8)) fprintf(fOut,"\n");
    }

    fprintf(fOut,"\n\n\n\n\n\n\n\n\n\n\n\n\n");

    for(int i = 0; 0 != sg_SumTable[i]; i++)
    {
        fprintf(fOut, "0x%x, ", sg_SumTable[i]);        
        if(7 == (i%8)) fprintf(fOut,"\n");
    }

    fprintf(fOut,"\n\n\n\n\n\n\n\n\n\n\n\n\n");

    for(int i = 0; i < 0xaca0; i++)
    {
        fprintf(fOut, "0x%x,", sg_DataTable[i]);        
        if(7 == (i%8)) fprintf(fOut,"\n");
    }

    fclose(fIn);
    fclose(fOut);
    memcpy(a,b,12);
    int aa;
    int *p;
    if(aa = (int)(p))
    {
       printf("ya");
    }
    return 1;
}
*/
/*
static int mn[512][512];
static int mnMax[512][512];
static int maxArr[512*512];
static int countArr[512*512];
static int sizeArr[512*512];

static int maxArrIndex;
static int sizeArrIndex;
static int countArrIndex;

void str2array(char* str, int* arr, int n4)
{
    int i, j;
    
    for(i = 0, j =0; i < n4; i++)
    {
        switch (str[i])
        {
        case '0':
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 0;
            break;
        case '1':
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 1;
            break;
        case '2':
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 0;
            break;
        case '3':
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 1;
            break;
        case '4':
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 0;
            break;
        case '5':
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 1;
            break;
        case '6':
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 0;
            break;
        case '7':
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 1;
            break;
        case '8':
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 0;
            break;
        case '9':
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 0;
            arr[j++] = 1;
            break;
        case 'A':
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 0;
            break;
        case 'B':
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 1;
            arr[j++] = 1;
            break;
        case 'C':
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 0;
            break;
        case 'D':
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 0;
            arr[j++] = 1;
            break;
        case 'E':
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 0;
            break;
        case 'F':
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 1;
            arr[j++] = 1;
            break;
        }

    }
}

int computeMax(int mIndex, int nIndex, int m, int n)
{
    int right, down;
    int rowIndex, columnIndex;

    if(mn[mIndex][nIndex] == -1)
    {
        mnMax[mIndex][nIndex] = 0;
    }

    else if((mIndex + 1) == m || (nIndex + 1) == n)
    {
        mnMax[mIndex][nIndex] = 1;
    }
    
    else if(mn[mIndex][nIndex] == mn[mIndex+1][nIndex] ||
            mn[mIndex][nIndex] == mn[mIndex][nIndex+1])
    {
        mnMax[mIndex][nIndex] = 1;
    }

    else if(-1 == mn[mIndex+1][nIndex] ||
            -1 == mn[mIndex][nIndex+1])
    {
        mnMax[mIndex][nIndex] = 1;
    }

    else
    {
        right = mnMax[mIndex+1][nIndex];
        down = mnMax[mIndex][nIndex+1];

        if(down > right)
        {
            mnMax[mIndex][nIndex] = right + 1;
        }
        
        else if(right > down)
        {
            mnMax[mIndex][nIndex] = down + 1;    
        }
        
        else //right == down
        {
            rowIndex = mIndex + right;
            columnIndex = nIndex + right;

            if( mn[rowIndex][columnIndex] == mn[rowIndex][columnIndex-1] ||
                mn[rowIndex][columnIndex] == mn[rowIndex-1][columnIndex] ||
                mn[rowIndex][columnIndex] == -1)
            {
                mnMax[mIndex][nIndex] = right;
            }
            else
            {
                mnMax[mIndex][nIndex] = right+1;
            }
        }
    }
    return mnMax[mIndex][nIndex];
}

void countTF(int m,int n)
{
    int i,j;
    int countT;

    countT = 0;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mn[i][j] == -1)
            {
                printf("_");
                countT++;
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }

    printf("%d", countT);
    return;
}

int getMax(int m, int n)
{
    int tempMax, max;
    int ii, jj;
    max = 0;
    maxArrIndex = 0;


    for(ii = m-1; ii >=0; ii--)
    {
        for(jj = n-1; jj >= 0; jj--)
        {
            tempMax = computeMax(ii,jj, m, n);
            if(tempMax > max)
            {
                max = tempMax;
                maxArr[0] = (ii*n) + jj;
                maxArrIndex = 1;
            }
            else if(tempMax == max)
            {
                maxArr[maxArrIndex++] = (ii*n) + jj;    
            }
        }
    }

    return max;
}

void cutMatrix(int m, int n, int size)
{
    int right, bottom, i;

    right = n + size;
    bottom = m + size;
    
    for(; n < right; n++)
    {
        for(i = m; i < bottom; i++)
        {
            mn[i][n] = -1;
        }
    }

}

int main(void)
{

    char str[129];
    int i,j,k,m,n,n4,ii,jj,iii,jjj,mm,nn;
    int testNumber;
    int answer;
    int max;
    
    FILE * fIn = fopen("D:\\C-large-practice.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);

    for(i = 0; i < 262144; i++)
    {
        maxArr[i] = -1;    
    }

    for(i = 0; i < testNumber; i++)
    {      
        fscanf(fIn,"%d %d",&m,&n);
      
        n4 = n >> 2;
        max = 0;
        maxArrIndex = 0;
        sizeArrIndex = 0;

        for(j = 0; j < m; j++)
        {
            fscanf(fIn,"%s",str);
            str2array(str, mn[j], n4);
        }

        max = getMax(m,n);
        while(max != 0)
        {
            countArr[sizeArrIndex] = 0;           
            for(jjj = maxArrIndex-1; jjj >= 0; jjj--)
            {
                mm = maxArr[jjj]/n;
                nn = maxArr[jjj]%n;

                if(mn[mm][nn] == -1)
                {
                    continue;    
                }

                if(mn[mm + max - 1][nn] == -1 ||
                   mn[mm][nn + max - 1] == -1)
                {
                    continue;
                }
                cutMatrix(mm, nn, max);
                countArr[sizeArrIndex]++;            

            }

            sizeArr[sizeArrIndex++] = max;
            
            if(max == 1)
            {
                break;
            }
            max = getMax(m,n);

        }
     
        answer = sizeArrIndex;
        fprintf(fOut,"Case #%d: %d\n",i+1,answer);
        for(iii = 0; iii < answer; iii++)
        {
            fprintf(fOut, "%d %d\n", sizeArr[iii], countArr[iii]);
        }
        
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
}
*/
/*
int main(void)
{

    int i,j,N,S,P;
    int nonSurprise,surprise;
    int arrN[101];
    int testNumber;
    int answer;
    
    FILE * fIn = fopen("D:\\B-larg.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);

    for(i = 0; i < testNumber; i++)
    {      
        fscanf(fIn,"%d %d %d",&N,&S,&P);
        answer = 0; 
        nonSurprise = 3*P - 2;
        surprise = nonSurprise - 2;

        for(j = 0; j < N; j++)
        {
            fscanf(fIn, "%d", &arrN[j]);
            
            if(arrN[j] < P)
            {
                continue;
            }
            else if(arrN[j] >= nonSurprise) 
            {
                answer++;
            }

            else if(arrN[j] >= surprise)
            {
                if(S > 0)
                {
                    S--;
                    answer++;
                }
            }
        }

        fprintf(fOut,"Case #%d: %d\n",i+1,answer);
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
}

*/

double pro[100000];
double successPro[100000];
double expected[100000];

int main(void)
{

    int i,j,A,B;
    int testNumber;
    double enter, answer;
    
    FILE * fIn = fopen("D:\\test1.in","r");
    FILE * fOut = fopen("D:\\test.out","w"); 
    
    fscanf(fIn,"%d",&testNumber);

    for(i = 0; i < testNumber; i++)
    {      
        fscanf(fIn,"%d %d",&A,&B);
        answer = 0; 

        fscanf(fIn, "%lf", &pro[0]);
        successPro[0] = pro[0];

        for(j = 1; j < A; j++)
        {
            fscanf(fIn, "%lf", &pro[j]);
            successPro[j] = pro[j] * successPro[j-1];            
        }

        expected[A-1] = ((((B*(2-successPro[A-1])) - A) + 2) - successPro[A-1]);
        enter = B + 2;

        if(expected[A-1] > enter) answer = enter;
        else answer = expected[A-1];

        for(j = A-2; j >= 0; j--)
        {
            expected[j] = expected[j+1] + (2 - ((B+1)*((1- pro[j+1])* successPro[j])));
            if(expected[j] < answer) answer = expected[j];
        }

        fprintf(fOut,"Case #%d: %.6lf\n",i+1,answer);
    }

    fclose(fIn);
    fclose(fOut);
    return 1;
}
