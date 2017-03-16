/********************************** INCLUDES **********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/******************************* PRIVATE MACROS *******************************/
//#define DBG_ENABLE

#ifdef DBG_ENABLE
#define DBG_PRINTF(...)      printf(__VA_ARGS__)
#else
#define DBG_PRINTF(...)      do{}while(0);
#endif

#define NUM_OF_ARGUMENT         3
#define IN_FILE_NAME_INDEX      1
#define OUT_FILE_NAME_INDEX     2


/******************************** PRIVATE TYPES *******************************/


/*********************** PRIVATE FUNCTIONS DECLARATIONS ***********************/
static int readNumStrFromFileToInt(FILE* inFile, int* num);
static int readNumStrFromFileToUInt(FILE* inFile, unsigned int* num);
static int readNumStrFromFileToLongLong(FILE* inFile, long long* num);
static int readNumStrFromFileToULongLong(FILE* inFile, unsigned long long* num);
static int readNumStrFromFileToDouble(FILE* inFile, double* num);
static int readNumStrFromFileToCharArray(FILE* inFile, char* buffer, int len);
static void outputCaseIntResult(FILE* outFile, int caseNum, int result);
static void outputCaseUIntResult(FILE* outFile, int caseNum, unsigned int result);
static void outputCaseLongLongResult(FILE* outFile, int caseNum, long long result);
static void outputCaseULongLongResult(FILE* outFile, int caseNum, unsigned long long result);
static void outputCaseStrResult(FILE* outFile, int caseNum, char* result);


/*********************** PRIVATE (GLBL) DATA DEFINITIONS **********************/


/*************************** PUBLIC DATA DEFINITIONS **************************/


/************************ PRIVATE FUNCTIONS DEFINITIONS ***********************/
/*============================================================================*/
/* Helper function start                                                      */
/*============================================================================*/
/*========
 * Read a number from input file to an integer
 *
 * Range of valid integer: from -2147483648 to 2147483647
 */
static int readNumStrFromFileToInt(FILE* inFile, int* num)
{
    int read;
    int isReadingInt = 0;
    int isNegNum = 0;
    int tmpNum = 0;
    
    while (!feof(inFile))
    {
        read = fgetc(inFile);

        if (isdigit(read))
        {
            isReadingInt = 1;
//            DBG_PRINTF("read = %d tmpNum = %d\n",read, tmpNum);
            tmpNum = tmpNum*10 + (read - '0');
        }
        else if (read == '-')
        {
            isReadingInt = 1;
            isNegNum = 1;
        }
        else
        {
            if (isReadingInt)
            {
                break;
            }
        }
    }
    
//    DBG_PRINTF("tmpNum = %d\n",tmpNum);
    if (isReadingInt == 0)
        return 0;
    else
    {
        *num = (isNegNum)? tmpNum*(-1) : tmpNum;
//        DBG_PRINTF("%d\n",*num);
        return 1;
    }
}

/*========
 * Read a number from input file to an unsigned integer
 *
 * Range of valid unsigned integer: from 0 to 4294967295
 */
static int readNumStrFromFileToUInt(FILE* inFile, unsigned int* num)
{
    int read;
    int isReadingInt = 0;
    unsigned int tmpNum = 0;
    
    while (!feof(inFile))
    {
        read = fgetc(inFile);

        if (isdigit(read))
        {
            isReadingInt = 1;
//            DBG_PRINTF("read = %d tmpNum = %u\n",read, tmpNum);
            tmpNum = tmpNum*10 + (read - '0');
        }
        else
        {
            if (isReadingInt)
            {
                break;
            }
        }
    }
    
//    DBG_PRINTF("tmpNum = %u\n",tmpNum);
    if (isReadingInt == 0)
        return 0;
    else
    {
        *num = tmpNum;
//        DBG_PRINTF("%u\n",*num);
        return 1;
    }
}

/*========
 * Read a number from input file to a long long integer
 *
 * Range of valid integer: from --9223372036854775808 to 9223372036854775807
 */
static int readNumStrFromFileToLongLong(FILE* inFile, long long* num)
{
    int read;
    int isReadingInt = 0;
    int isNegNum = 0;
    long long tmpNum = 0;
    
    while (!feof(inFile))
    {
        read = fgetc(inFile);

        if (isdigit(read))
        {
            isReadingInt = 1;
//            DBG_PRINTF("read = %d tmpNum = %lld\n",read, tmpNum);
            tmpNum = tmpNum*10 + (read - '0');
        }
        else if (read == '-')
        {
            isReadingInt = 1;
            isNegNum = 1;
        }
        else
        {
            if (isReadingInt)
            {
                break;
            }
        }
    }
    
//    DBG_PRINTF("tmpNum = %lld\n",tmpNum);
    if (isReadingInt == 0)
        return 0;
    else
    {
        *num = (isNegNum)? tmpNum*(-1) : tmpNum;
//        DBG_PRINTF("%lld\n",*num);
        return 1;
    }
}

/*========
 * Read a number from input file to a unsigned long long integer
 *
 * Range of valid unsigned integer: from 0 to 18446744073709551615
 */
static int readNumStrFromFileToULongLong(FILE* inFile, unsigned long long* num)
{
    int read;
    int isReadingInt = 0;
    unsigned long long tmpNum = 0;
    
    while (!feof(inFile))
    {
        read = fgetc(inFile);

        if (isdigit(read))
        {
            isReadingInt = 1;
//            DBG_PRINTF("read = %d tmpNum = %llu\n",read, tmpNum);
            tmpNum = tmpNum*10 + (read - '0');
        }
        else
        {
            if (isReadingInt)
            {
                break;
            }
        }
    }
    
//    DBG_PRINTF("tmpNum = %llu\n",tmpNum);
    if (isReadingInt == 0)
        return 0;
    else
    {
        *num = tmpNum;
//        DBG_PRINTF("%llu\n",*num);
        return 1;
    }
}

/*========
 * Read a number from input file to a double
 *
 * Range of valid double: from (-)2.22507e-308 to (-)1.79769e+308
 *
 * Remark: double number calucalation seems introducing errors and the resultant
 *         number may not with the same value as the one written in file
 */
static int readNumStrFromFileToDouble(FILE* inFile, double* num)
{
    int read;
    int isReadingInt = 0;
    int isNegNum = 0;
    double tmpNum = 0.0;
    
    while (!feof(inFile))
    {
        read = fgetc(inFile);

        if (isdigit(read))
        {
            isReadingInt = 1;
//            DBG_PRINTF("read = %d tmpNum = %f\n",read, tmpNum);
            tmpNum = tmpNum*10.0 + (read - '0');
        }
        else if (read == '-')
        {
            isReadingInt = 1;
            isNegNum = 1;
        }
        else
        {
            if (isReadingInt)
            {
                break;
            }
        }
    }
    
//    DBG_PRINTF("tmpNum = %f\n",tmpNum);
    if (isReadingInt == 0)
        return 0;
    else
    {
        *num = (isNegNum)? tmpNum*(-1) : tmpNum;
//        DBG_PRINTF("%f\n",*num);
        return 1;
    }
}

/*========
 * Read a number from input file to a character array
 *
 * Note: the buffer length must include a space for the last NULL pointer
 */
static int readNumStrFromFileToCharArray(FILE* inFile, char* buffer, int len)
{
    int read;
    int isReadingInt = 0;
    int index = 0;
    
    while (!feof(inFile) && index < len)
    {
        read = fgetc(inFile);

        if (isdigit(read) || read == '-')
        {
            isReadingInt = 1;
//            DBG_PRINTF("read = %d\n",read);
            buffer[index++] = read;
        }
        else
        {
            if (isReadingInt)
            {
                break;
            }
        }
    }
    
    if (isReadingInt == 0)
        return 0;
    else
    {
        buffer[index] = 0;
//        DBG_PRINTF("buffer = %s\n",buffer);
        return 1;
    }
}

static void outputCaseIntResult(FILE* outFile, int caseNum, int result)
{
    fprintf(outFile, "Case #%d: %d\n", caseNum, result);
    fflush(outFile);
}

static void outputCaseUIntResult(FILE* outFile, int caseNum, unsigned int result)
{
    fprintf(outFile, "Case #%d: %u\n", caseNum, result);
    fflush(outFile);
}

static void outputCaseLongLongResult(FILE* outFile, int caseNum, long long result)
{
    fprintf(outFile, "Case #%d: %lld\n", caseNum, result);
    fflush(outFile);
}

static void outputCaseULongLongResult(FILE* outFile, int caseNum, unsigned long long result)
{
    fprintf(outFile, "Case #%d: %llu\n", caseNum, result);
    fflush(outFile);
}

static void outputCaseStrResult(FILE* outFile, int caseNum, char* result)
{
    fprintf(outFile, "Case #%d: %s\n", caseNum, result);
    fflush(outFile);
}

/*============================================================================*/
/* Helper function end                                                        */
/*============================================================================*/
int cmpFuncAccending (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

/************************* PUBLIC FUNCTION DEFINITIONS ************************/
void processAllTestCase(FILE* inFile, FILE* outFile)
{
    int numOfTestCase;
    int i, j;

    readNumStrFromFileToInt(inFile, &numOfTestCase);
    
    //Process all test cases
    for (i=0; i<numOfTestCase; i++)
    {
        int size;
        int numMotes;
        int result = 0;
//        int resultToRmAll = 0;
        
        //Process a test case
        readNumStrFromFileToInt(inFile, &size);
        readNumStrFromFileToInt(inFile, &numMotes);

        {
            int motes[numMotes];
            bool rmAll[numMotes];
            int resultAtRmAll[numMotes];

            memset(rmAll, 0, numMotes * sizeof(int));

            for (j=0; j<numMotes; j++)
            {
                readNumStrFromFileToInt(inFile, &motes[j]);
            }

            qsort(motes, numMotes, sizeof(motes[0]), cmpFuncAccending);

            DBG_PRINTF( "size=%d motes=", size);
            for (j=0; j<numMotes; j++)
                DBG_PRINTF( " %d", motes[j] );
            DBG_PRINTF( "\n");

            for (j=0; j<numMotes; j++)
            {
                if (size > motes[j])
                {
                    size += motes[j];
                }
                else
                {
                    if (size > 1)
                    {
                        rmAll[j] = true;
                        resultAtRmAll[j] = result;

                        while (motes[j] >= size)
                        {
                            result += 1;
                            size += size-1;
                        }

                        size += motes[j];
                    }
                    else
                    {
                        //can't add any mote
                        result = numMotes;
                        break;
                    }
                }
            }
            for (j=0; j<numMotes; j++)
            {
                if (rmAll[j])
                {
                    int tmpResult = resultAtRmAll[j] + numMotes - j;
                    if (tmpResult < result)
                    {
                        result = tmpResult;
                        break;
                    }
                }
            }
        }
        
        //Output Result, case num start from 1
        outputCaseIntResult(outFile, i+1, result);
    }
}

/* program in_file_name out_file_name */
int main( int argc, const char* argv[] )
{
    int i;
    FILE* inFile;
    FILE* outFile;

    DBG_PRINTF( "argc=%d\n", argc );
    if (argc != NUM_OF_ARGUMENT) {
        printf("Not enough Argument!!\ne.g. argv[0] <in_file_name> <out_file_name>\n");
        return 1;
    }
    
    for (i=0; i<argc; i++) {
        DBG_PRINTF("%s\n", argv[i]);
    }
    
    inFile = fopen(argv[IN_FILE_NAME_INDEX], "r");
    if ( inFile == NULL) {
        printf("Can't open input file %s\n", argv[IN_FILE_NAME_INDEX]);
        return 1;
    }
    
    outFile = fopen(argv[OUT_FILE_NAME_INDEX], "w");
    if ( outFile == NULL) {
        printf("Can't open output file %s\n", argv[OUT_FILE_NAME_INDEX]);
        return 1;
    }

    processAllTestCase(inFile, outFile);
   
    fclose(inFile);
    fclose(outFile);
    
    return 0;
}
