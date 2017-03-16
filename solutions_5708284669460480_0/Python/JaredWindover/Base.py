import sys

args = sys.argv
file = args[1]
f = open(file)

cases = int(f.readline())

memoizedExpected = {}

#flag means we've just typed the word before
def ExpectedNumWords(length,
                     wordlength,
                     prefixlength,
                     probWord,
                     probPrefix,
                     flag):
    t = (length,wordlength,prefixlength,probWord,probPrefix,flag)
    if (t in memoizedExpected):
        return memoizedExpected[t]
    result = 0
    if flag:
        if length < prefixlength:
            result = 0
        elif length == wordlength:
            result = probPrefix
        else:
            result =  ((probPrefix*
                       (1 + ExpectedNumWords(length - prefixlength,
                                             wordlength,
                                             prefixlength,
                                             probWord,
                                             probPrefix,
                                             True))) +
                       ((1 - probPrefix)*
                       ExpectedNumWords(length - 1,
                                        wordlength,
                                        prefixlength,
                                        probWord,
                                        probPrefix,
                                        False)))
    elif length < wordlength :
        result = 0
    elif length == wordlength:
        result = probWord
    else:
        result = ((probWord*(1 + ExpectedNumWords(length - wordlength,
                                                 wordlength,
                                                 prefixlength,
                                                 probWord,
                                                 probPrefix,
                                                 True))) +
                  ((1- probWord)*ExpectedNumWords(length - 1,
                                                 wordlength,
                                                 prefixlength,
                                                 probWord,
                                                 probPrefix,
                                                 False)))
    memoizedExpected[t] = result
    return result


for i in range(cases):
    l = f.readline().split(' ')
    K = int(l[0])
    L = int(l[1])
    S = int(l[2])
    Keys = f.readline()[:-1]
    Word = f.readline()[:-1]
    Start = (Word*2).find(Word,1)
    Prefix = Word[:Start]
    Counts = {}
    for x in Keys:
        if x not in Counts:
            Counts[x] = 0
        Counts[x] += 1
    if S < L:
        WorstCase = Expected = 0
    else:
        AllIn = True
        for x in Word:
            if x not in Counts:
                AllIn = False
                break
        if not AllIn:
            WorstCase = Expected = 0
        else:
            WorstCase = 1 + ((S - L) / Start)
            pWord = 1.
            for x in Word:
                pWord *= float(Counts[x])/K
            pPrefix = 1.
            for x in Prefix:
                pPrefix *= float(Counts[x])/K
            Expected = ExpectedNumWords(S,
                                        L,
                                        len(Prefix),
                                        pWord,
                                        pPrefix,
                                        False)
    #print "%s:%s:%s | %s -> %s" % (K,L,S,Keys,Word)
    print "Case #%s: %s" % (i + 1,WorstCase - Expected)
    
