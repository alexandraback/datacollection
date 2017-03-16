#!/usr/bin/env python
import sys
from collections import Counter
from itertools import combinations

    
 

def  fake( topics):
    
    word1 = Counter( [ i[0] for i in topics  ] )
    word2 = Counter( [ i[1] for i in topics  ] )

    word1 = sorted( word1.keys() ) 
    word2 = sorted( word2.keys() ) 

    n = len(topics)

    index = range(n)

    flag = False

    for nchoices in range(1, n+1 ):
        
        for c in  combinations( index, nchoices ):
            s_word1={}
            s_word2={}
            for t in c:
                s_word1[ topics[t][0] ] =1 
                s_word2[ topics[t][1] ] =1 

            if ( sorted(s_word1.keys() ) == word1 ) and \
                ( sorted( s_word2.keys() ) == word2 ) :
                
                flag= True
                break

        if flag:
            return n - nchoices




fin = open(sys.argv[1], 'r')
cases = int( fin.readline().strip() )
for i  in range(cases):
    n = int( fin.readline().strip() )
    topics = []
    for _ in range(n):
        topics.append( fin.readline().strip().split() )
        
    print "Case #%d: %s" % ( i+1 , fake(topics) )
