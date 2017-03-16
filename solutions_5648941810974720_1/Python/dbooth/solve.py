#python 2.7

import sys
import math
import string

def subcount(counts, word):
    charcounts = dict()
    for x in word:
        charcounts[x] = 0 
    for x in word:
        charcounts[x] = charcounts[x] + 1
    
    newMin = min([counts[x]/charcounts[x] for x in word])
    oldMin = min([counts[x] for x in word])
    assert(newMin == oldMin)
    return newMin

def solve(S):
    words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    charcounts = dict()
    for word in words:
        for c in word:
            charcounts[c] = 0
    for c in S:
        charcounts[c] = charcounts[c]+1
    
    ret = []
    uniqueWordSets = [["ZERO", "EIGHT", "TWO", "SIX"],
                      ["THREE", "FOUR", "SEVEN"],
                      ["ONE", "FIVE"],
                      ["NINE"]]
    for uniqueWords in uniqueWordSets:
        for word in uniqueWords:
            remcount = subcount(charcounts, word)
            for i in range(0,remcount):
                ret.append(word)
            for c in word:
                charcounts[c] = charcounts[c] - remcount;
    print "Remaining counts: " + str(sum(charcounts.values()))

    sortedRet = ""
    debugRet = ""
    index = 0
    for word in words:
        for i in range(0, ret.count(word)):
            sortedRet += str(index)
            debugRet += word
        index += 1
    print S
    print sorted(S)
    print debugRet
    print sorted(debugRet)
    assert(sorted(S) == sorted(debugRet))
    print sortedRet
    return sortedRet
def main():
    if (not len(sys.argv) == 3):
        print("Need exactly twos args: input filename and output filename")
        return
    input_data = open(sys.argv[1], 'r').read()
    output_file = open(sys.argv[2], 'w')
    split_input = input_data.split("\n")
    case_count = int(split_input[0])
    for i in range(0,case_count):
        res = solve(split_input[i+1])
        output_file.write("Case #" + str(i+1) + ": " + str(res) + "\n")
    
if __name__ == "__main__":
    main()
