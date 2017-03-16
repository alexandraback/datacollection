//
//  main.cpp
//  codeJam2013
//
//  Created by Guillaume Derval on 13/04/13.
//  Copyright (c) 2013 Guillaume Derval. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>

class Dico
{
private:
    Dico* subdicos;
    bool here[26];
public:
    Dico()
    {
        subdicos = NULL;
        for(int i = 0; i < 26; i++)
            here[i] = false;
    }
    ~Dico()
    {
        if(subdicos)
            delete[] subdicos;
    }
    
    void insertWord(std::string word)
    {
        int c = word.c_str()[0] - 'a';
        if(word.length() == 1)
        {
            here[c] = true;
        }
        else if(word.length() > 1)
        {
            std::string sub = word.substr(1);
            if(subdicos == NULL)
                subdicos = new Dico[26];
            subdicos[c].insertWord(sub);
        }
    }
    
    void minModif(std::string word, std::map<int,int> & possibles, int length = 0, int modif = 0)
    {
        if(word.length() == 0)
            return;
        
        length++;
        bool exists = possibles.count(length);
        int c = word.c_str()[0] - 'a';
        if(!exists || possibles[length] > modif+1)
        {
            for(int i = 0; i < 26; i++)
            {
                if(c-i > 5 || c-i < -5)
                {
                    if(here[i])
                    {
                        possibles[length] = modif+1;
                        exists = true;
                        break;
                    }
                }
            }
        }
        if(!exists || possibles[length] > modif)
            if(here[c])
                possibles[length] = modif;
        
        if(subdicos)
        {
            subdicos[c].minModif(word.substr(1), possibles, length, modif);
            for(int i = 0; i < 26; i++)
                if(c-i > 5 || c-i < -5)
                    subdicos[i].minModif(word.substr(1), possibles, length, modif+1);
        }
    }
};

int main(int argc, const char * argv[])
{
    std::ifstream fdico ("/Users/guillaumederval/Dropbox/Q4_INFO_perso/codeJam2013/codeJam2013/dico.txt");
    
    std::ifstream finput ("/Users/guillaumederval/Dropbox/Q4_INFO_perso/codeJam2013/codeJam2013/C-small.in");
    std::ofstream foutput ("/Users/guillaumederval/Dropbox/Q4_INFO_perso/codeJam2013/codeJam2013/out.out");
    
    //std::istream& input = std::cin;
    //std::ostream& output = std::cout;
    std::istream& input = finput;
    std::ostream& output = foutput;
    
    Dico dico;
    for(int i = 0; i < 521196; i++)
    {
        std::string t;
        fdico >> t;
        dico.insertWord(t);
    }
    
    int T;
    input >> T;
    for(int test = 0; test < T; test++)
    {
        std::string string;
        input >> string;
        std::vector<int> bestLength(string.length(), -1);
        for(int i = string.length()-1; i >= 0; i--)
        {
            std::map<int, int> possibles;
            dico.minModif(string.substr(i), possibles);
            for(int j = i+1; j <= string.length(); j++)
            {
                if(j != string.length() && bestLength[j] == -1)
                    continue;
                
                if(possibles.count(j-i))
                {
                    int toadd = possibles[j-i];
                    if(j != string.length())
                        toadd += bestLength[j];

                    if(toadd < bestLength[i] || bestLength[i] == -1)
                        bestLength[i] = toadd;
                }
            }
        }
        output << "Case #" << (test+1) << ": " << bestLength[0] << std::endl;
        std::cout << "Case #" << (test+1) << ": " << bestLength[0] << std::endl;
    }
    
    finput.close();
    foutput.close();
    return 0;
}

