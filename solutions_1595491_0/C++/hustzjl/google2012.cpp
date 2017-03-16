//#define __DEBUG_MOD__
//#include "Header.h"

//==============header.h begin===================================
#ifndef __HEADER_H
#define __HEADER_H


#include <stdio.h>
#include <string.h>  //for strcmp
#include <iostream>
using namespace std;// IM:bug:如果没有这句std;,报错： `stack' undeclared (first use this function) 


//这两个宏用于控制Debug.h中的函数的行为,必须写在#include"Debug.h"的前面,否则不生效
//#define __DEBUG_MOD__
//#define __ONLINE__  //定义了online后就自动注释掉了__DEVCPP_GETCHAR__


#ifndef __ONLINE__
#define __DEVCPP_GETCHAR__
#endif


#define IN  //说明是该参数是输入的
#define OUT //说明是该参数是输出的
#define INOUT //说明是该参数是既是输入，也是输出


//#include "Debug.h"
//==============Debug.h===================================
#ifndef __DEBUG_HEAD_H
#define __DEBUG_HEAD_H
#include <stdio.h>
#include <string.h> //IM: bug:memset要用到这个
#include <stdarg.h>  //IM: va_list要用,变长参数

enum //IM:不一定要写RETVALUE 
{
    SUCCESS = 0,
    FAIL = 1
};

#define FREE_PTR(p) free(p);p=NULL;
#define DELETE_PTR(p) delete p;p=NULL;
#define DELETE_PTR_ARRAY(p) delete[] p;p=NULL;


//被.cpp中的这两个宏控制了函数中的行为
//#define __DEBUG_MOD__
//#define __ONLINE__
static FILE* s_fpLog = stdout; //stderr;
//只要定义了online模式，或者是线下模式且没有定义调试模式，都不打印debug信息, 否则打印debug信息
void DEBUG(const char *fmt, ...)
{
//#if (defined(_DEBUG) && defined(_UNITTEST))
#if (!defined(__ONLINE__) && defined(__DEBUG_MOD__))
    //fprintf(s_fpLog,"Debug: ");
    va_list	ap;
    if (s_fpLog) {
        //s_lock.Lock(); 
        //fprintf(s_fpLog, "[%d]", thread_getid());
        va_start(ap, fmt);
        vfprintf(s_fpLog, fmt, ap);
        va_end(ap);
        //s_lock.Unlock();
        fflush(s_fpLog);
    }
//endif的逻辑相当于:#if (defined(__ONLINE__) ||  !defined(__DEBUG_MOD__)),就是只要定义了online模式，或者是线下模式且没有定义调试模式，都不打印debug信息, 否则打印debug信息
#endif
}


void OUTPUT(const char *fmt, ...)
{
//#if (!defined(__ONLINE__) && defined(__DEBUG_MOD__))
    //fprintf(s_fpLog,"Debug: ");
    va_list	ap;
    if (s_fpLog) {
        //s_lock.Lock(); 
        //fprintf(s_fpLog, "[%d]", thread_getid());
        va_start(ap, fmt);
        vfprintf(s_fpLog, fmt, ap);
        va_end(ap);
        //s_lock.Unlock();
        fflush(s_fpLog);
    }
//#endif
}


const int MAXFILENAME = 100;
char g_StrFileIn[MAXFILENAME] = "";
char g_StrFileOut[MAXFILENAME] = "";
void SetFileInOutName(char *strNS)
{
#ifndef __ONLINE__
    //char strNS[MAXFILENAME] = "NS_Graph_Kruskal";//namespace的名称
    sprintf(g_StrFileIn,"%s.In.txt",strNS);
    sprintf(g_StrFileOut,"%s.Out.txt",strNS);
    printf("%s %s %s\n",__FUNCTION__,g_StrFileIn,g_StrFileOut);
#endif
}
int ReopenStdin()
{
#ifndef __ONLINE__
    FILE *in = freopen(g_StrFileIn,"r",stdin);
    if(!in){
        printf("Open %s Error!\n",g_StrFileIn);
        return 0;
    };
    return 1;
#endif
}
int ReopenStdout()
{
#ifndef __ONLINE__
    FILE *out = freopen(g_StrFileOut,"w",stdout);
    if(!out){
        printf("Open %s Error!\n",g_StrFileOut);
        return 0;
    };
    return 1;
#endif
}
int ReopenStdinStdout()
{
    if(ReopenStdin()){
        return ReopenStdout();
    }
    return 0;
}


#endif
//===================Debug.h end==============================


//#include "Func.h"
//==============Func.h ===================================
#ifndef _FUNC_H
#define _FUNC_H

#define ASSERT(c) assert(c)
#define FUNCBEGIN printf("===BEGIN %s (%s:%d)====\n",__FUNCTION__,__FILE__,__LINE__);
#define FUNCEND printf("===END %s (%s:%d)====\n",__FUNCTION__,__FILE__,__LINE__);
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))
/*
  #include <stdlib.h>
  void qsort( void *buf, size_t num, size_t size, int (*compare)(const void *, const void *) ); 
  功能： 对buf 指向的数据(包含num 项,每项的大小为size)进行快速排序。如果函数compare 的第一个参数小于第二个参数，返回负值；如果等于返回零值；如果大于返回正值。函数对buf 指向的数据按升序排序。 
//递增，参考上面qsort说明 (X)。  错误,实际上是降序排列
5 6 2 3 9 7 2 1
qsort输出:9 7 6 5 3 2 2 1
The return value of this function should represent whether elem1 is considered less than, equal, or grater than elem2 by returning, respectivelly, a negative value, zero or a positive value.
*/
int compare_more(const void *a,const void *b)
{
    //return (a<b);
    /*
      报错:const void*' is not a pointer-to-object type  
      还有一个问题，不可以对   void   指针执行取值操作。
      return ((int)(*a)-(int)(*b));
      要先强制转换该指针，然后再取值 
      //return *((int*)a)-*((int*)b);   
      */
    return *((int*)a) < *((int*)b);    //
}


int QSortGreater(const void *a,const void *b)
{
//qsort排序最好的函数，因为如果用>,<无法表达为0的情况，用-号又有可能有越界的危险，所以这个我看到的最好的。
//return *(int*)a-*(int*)b;
    const int m = *(const int*)a;
    const int n = *(const int*)b;
    return m>n?1:(m==n?0:-1);
}
/*
  5 6 2 3 9 7 2 1
  qsort(a,N,sizeof(int),Greater);
  输出:
  1 2 2 3 5 6 7 9
  升序
*/
int Greater(const void *a,const void *b)
{
    //IM 2012-2-4后面的建议是错误的: 建议采用>,而非-，因为减号可能存在越界的问题，比如一个是很小的，另一个是很大的，相减后就越界了。
    /*Poj.cpp:namespace Qsort_Learn中:大于小于号来比较，有问题
      [0]=4 | [1]=9 | [2]=9 | [3]=2 | [4]=12 | [5]=11 | [6]=11 | [7]=7 | [8]=1 | [9]=12 | [10]=7 | [11]=3 | [12]=3 | [13]=
      4 | [14]=0 | [15]=8 | [16]=1 | [17]=6 | [18]=8 | [19]=1 |
      After qsort:[19]=1 | [16]=1 | [14]=0 | [3]=2 | [13]=4 | [12]=3 | [11]=3 | [0]=4 | [8]=1 | [10]=7 | [7]=7 | [18]=8 | [17]
      =6 | [1]=9 | [2]=9 | [15]=8 | [5]=11 | [6]=11 | [9]=12 | [4]=12 |
      改为减号后可以:
      After qsort:[17]=0 | [8]=0 | [12]=1 | [10]=1 | [5]=2 | [6]=2 | [11]=2 | [2]=2 | [16]=3 | [0]=3 | [18]=4 | [4]=5 | [14]=7
      | [19]=7 | [7]=8 | [13]=8 | [1]=9 | [3]=9 | [9]=11 | [15]=12 |
    */
    return *(int*)a - *(int*)b;
    //return *(int*)a > *(int*)b;
}
//降序
int compare_less(const void *a,const void *b)
{
    return   *((int*)b) - *((int*)a);
    //return   *((int*)b) > *((int*)a);
}
//字符串升序
int CompStrGreater(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);//需要string.h
}
int PrintInt(int v)
{
//        cout << "Visit:" << v << endl;
    printf("%d ",v);
}
int PrintStr(const char *a)
{
    printf("%s",a);
}

template <class T>
/*print int array
  format=%d or %c or ...
bug:参数可以改进为,int flagIndex,int LogLevel,char *format 
应用方最不想写的放在最后面
*/
void PrintArray(T *a,int size,int flagIndex = 1,const char *format="%d") 
{
    int first = 1;
    char strIndex[]="[%d]="; //"\"[%d]=";
    //int len = strlen(format)+1+strlen(strIndex) + 1; //last 1:len of \"
    //char *str = (char*)malloc(len*sizeof(char));
    char str[10];
    if(flagIndex){
        snprintf(str,sizeof(str)-1,"%s%s",strIndex,format); //"%s%s\"",
    }else{
        snprintf(str,sizeof(str)-1,"%s",format);
    }
    //cout << str << endl; ;//"[%d]=%d"
    for(int i = 0;i<size;i++){
        if(first){
            first = 0;
        }else{
            DEBUG(" ");
        }
        if(flagIndex){
            DEBUG(str,i,a[i]);
        }else{
            DEBUG(str,a[i]);
        }
    }
    DEBUG("\n");
}




/*
  flag表示是否打印下标值
  打印，则为1，否则不为1
  
  这里有一个陷阱，因为我们打印二维数据是用                                      
  *((int*)a + M*i + j)                                                          
  而我们申请的是int a[MAXN][MAXN];                                                
  but in fact we only use [N][N],so *((int*)a + M*i + j) is not correct.
  如果传递的参数是(N,N),实际会按照[MAXN*MAXN]一行一行打印
  修复之.
  Now only support N*N Matrix
*/
void PrintTwoArray(int **array,int Row,int Col,int flag=0)
{
    int first = 1;
    for(int i = 0;i<Row;i++){
        for(int j = 0;j<Col;j++){
	  if(first){first = 0;}
	  else{DEBUG(" ");}
	  if(flag == 1){
//   *((int*)array + n*i + j);
              DEBUG("[%d,%d]=%d",i,j,*((int*)array + Col*i + j));
                /*core:
                  (gdb) p a[0]
                  $9 = (int *) 0x0
                  (gdb) p a   
                  $10 = (int **) 0x501920
                */
                //TRACE2("[%d,%d]=%d",i,j,a[i][j]);
            }
            else{
                DEBUG("%4d",*((int*)array + Col*i + j));
            }
        }
        first = 1;
        DEBUG("\n");
    }
}
/*
  判断两个数组中的各个值是否相等
*/
//template class <T>
template <class T>
bool IsEqual(const T *a,int size_a,const T *b,int size_b)
{
    if(size_a != size_b)
    {
        return false;
    }
    for(int i=0;i<size_a;i++)
    {
        if(a[i] != b[i])
	{
            return false;
	}
    }
    return true;
}


template <class T>
void Swap(T *a,T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}



//主函数中要先调用srand(time(NULL));
#include <stdlib.h>
int Random(int m) //生成[0,m-1]之间的随机数
{
    int k = rand();
    double t = (double)k/RAND_MAX; //bug:k/RAND_MAX; 必须要用(double)来强制转换，否则全都为0
    //DEBUG("%d %d %lf ",k,RAND_MAX,t);
    return(int)(t*(m-1)+0.5); //IM,为什么不能是(int)(t*m)??
}




#include <vector>
int PrintVector(vector<int> &v)
{
    vector<int>::iterator iter;
    for(iter=v.begin() ; iter != v.end(); iter++) {
        cout << *iter << " ";
    }
}

#include <list>
int PrintList(list<int> &L,char *sep="=")
{
    list<int>::iterator iter;
    for(iter=L.begin() ; iter != L.end(); iter++) {
        cout << *iter << sep;
    }
    //cout << "end" << endl;
}

/*test N is prime or not
 */
#include <math.h>
bool IsPrime(int N)
{
    for(int i=2;i*i<=N;i++){
        if(!(N%i)){ //bug:不是N%i
            return false;
        }
    }
    return true;
}


//打印一个分行标记
#define PrintLineSep DEBUG("=================\n");
#endif
//==============Func.h end===================================


//==============Header.h end===================================

#endif



namespace NS_SpeakingInTongues
{
/*Speaking in Tongues
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up
*/
    int main()
    {
        //A-small.in.txt
        SetFileInOutName("NS_SpeakingInTongues");
        ReopenStdinStdout();
        char mapping[26] = {'y','h','e','s','o','c','v',  \
                            'x','d','u','i','g','l','b',  \
                            'k','r','z','t','n','w',      \
                            'j','p','f', 'm','a','q'};
        int N,i,j;
        //bug:这两个方法都无法跳过换行，导致后面的fgets第一次只取了一个换行符scanf("%d",&N);        //cin >> N; 

        const int MAXN = 110;
        char str[MAXN],ch;
        j=1;

        if(fgets(str,MAXN,stdin) == NULL){
            exit(0);
        }
        sscanf(str,"%d",&N);
        while((N--)>0){
            if(fgets(str,MAXN,stdin) == NULL){
                break;
            }
            i=0;
            printf("Case #%d: ",j++);
            while(str[i]!='\0'){
                ch = str[i];
                if(isalpha(ch)){
                    ch = tolower(ch);
                    ch = mapping[ch-'a'];
                }
                printf("%c",ch);
                i++;
            }
        }
    }
}


namespace NS_GoogleDancingWithGooglers
{
/*
Input
4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21
*/

    int main()
    {
        SetFileInOutName("NS_GoogleDancingWithGooglers");
        ReopenStdinStdout();
        int T,N,Surp,p,i,j,k,sum,count,SurpChoice=0,remain;
        scanf("%d",&T);
        j=1;
        while((T--)>0){
            scanf("%d %d %d",&N,&Surp,&p);
            //DEBUG("N=%d Surp=%d p=%d\n",N,Surp,p);
            printf("Case #%d: ",j++);
            count = 0;
            SurpChoice = 0;//表示在满足最大值大于p的情况下，可以被选为Surp但是也可以不选为Surp的choice
            for(i=0;i<N;i++){
                scanf("%d",&sum);
                //bug:如果sum<4的时候有问题，如果sum=0,k=-1，remain=2,但是实际上我们希望的是k=-2,a=k+1=-1,b=0,c=1或者是a=0,b=0,c=0
                if(sum>=4){
                    k=(int)(sum-4)/3;
                }else{
                    k=-(6-sum)/3;
                }
                
                remain = (sum+6-4)%3;//bug:(sum-4)%3这里的remain在sum<4的时候有问题，输入为2 1 1 8 0,sum=0 k=-1,remain=-1,后面的remain匹配不到0或1
                
                //DEBUG("sum=%d k=%d,remain=%d\n",sum,k,remain);
                //bug：我们需要保证我们的Surp数目必须是和输入的数目一致的.在输入为2 1 1 8 0时，在sum=0是，我们可能取0,0,0，结果导致Surp没有--，因此是错误的。
                if(p<=k+2){
                    if(remain==0){
                        //这个时候有两种选择:(k,k+2,k+2){Surp的选择将多一种}或(k+1,k+1,k+2)
                        if(k>=0){
                            count++;
                            SurpChoice++;
                            //Surp--;
                        }else if(k == -1){
                            count++;
                        }else{
                            //不符合要求
                        }
                    }else if(remain==1){
                        if(k+1>=0){
                            count++;
                            SurpChoice++;
                        }
                        //bug:在输入为2 1 1 8 0,然后sum=0 k=-1,remain=-1,k+2>=p:count++:2。因为(a,b,c)中会有值<0，所以上面加上了k+1>=0，因为如果c为k+2，则remain==0:a=k+1,remain==1:a=k+1,remain==2,a=k+2
                        //sum=0 k=-2,remain=2
                        //k+2>=p:count++:2 bug:这个时候满足要求了，但是我们取(0,0,0)
                        //DEBUG("k+2>=p:count++:%d\n",count);
                    }else{//remain==2 && k+2>=0)){z{
                        if(k+1>=0){
                            count++;
                            SurpChoice++;
                        }else if(k==-2){
                            count++;
                        }else{
                            //
                        }
                    }
                }else if(k+3<p || remain==0){//remain==0的时候不存在下面的p=k+3的情况
                    //DEBUG("Continue:k+3=%d p=%d remain=%d\n",k+3,p,remain);
                }else{ //p=k+3;
                    //sum=0 k=-1,remain=-1
                    //k+3=p:count++:2 Surp--=0
                    if(Surp>0 && k+1>=0){//在remain！=0且p==k+3时,必有a=p+1
                        Surp--;
                        count++;
                        //DEBUG("k+3=p:count++:%d Surp--=%d\n",count,Surp);
                    }
                }
            }
            //到这里可能Surp并没有变为<=0，这个时候说明我们需要从这些人中多选择一些Surp，而SurpChoice就记录了可以被选出来的Surp。但是不会影响到我们的count，因为选SurpChoice的时候我们的count也是正常的++，所以这里不需要对count--
            //DEBUG("Surp=%d SurpChoice=%d \n",Surp,SurpChoice);
            printf("%d\n",count);
        }
    }
}

int main()
{
    //NS_SpeakingInTongues::main();
    NS_GoogleDancingWithGooglers::main();
}
