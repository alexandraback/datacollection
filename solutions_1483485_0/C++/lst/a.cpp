/**
* AliTokenizer 接口示例程序 
* 切分中文文本"菊花茶的作用", 打印出分词结果 
*/
#include <iostream>
#include "ali_tokenizer.h"
#include "ali_tokenizer_define.h"
using namespace std;
using namespace ws;

int main()
{
        //step1: 创建工厂
        AliTokenizerFactory tokenizerFactory;
        tokenizerFactory.Init("/usr/local/libdata/AliWS/conf/AliTokenizer.conf"); 
        //step2: 获取淘宝中文分词
        AliTokenizer *tokenizer = tokenizerFactory.GetAliTokenizer("TAOBAO_CHN"); 
        //step3: 创建分词结果对象
        SegResult *pSegResult = tokenizer->CreateSegResult();
        //step4: 分词 
        const char * text  = "菊花茶的作用"; 
        tokenizer->Segment(text, strlen(text), UTF8 , SEG_TOKEN_SEMANTIC|SEG_TOKEN_RETRIEVE, pSegResult) ;
        //step5: 输出或处理分词结果 
        string res;
        SegToken* pToken = pSegResult->GetFirstToken(MAIN_LIST);
        while (pToken)
        {
                res += string((const char*)pToken->pWord, pToken->length);
                res += " ";
                pToken = pToken->pRightSibling;
        }
        cout << res << endl;
        //step6: 释放内存空间 
        tokenizer->ReleaseSegResult(pSegResult);  //释放分词结果 
        
        return 0;
}