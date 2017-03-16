#!/usr/bin/env python

from __future__ import print_function

FLAG = 26
def buildPrefixTree(dictfile):
    f = file(dictfile, 'r')
    prefixTree = [None] * 27
    for word in f:
        curSubtree = prefixTree
        for letter in word.strip():
            lcode = ord(letter) - ord('a')
            if not curSubtree[lcode]:
                curSubtree[lcode] = [None] * 27
            curSubtree = curSubtree[lcode]
        curSubtree[FLAG] = True
    return prefixTree

def solveCase(S, prefixTree):
    INFINITY = 666666
    S = S + 'z' # guard
    minChanges = [[INFINITY] * 5 for i in xrange(len(S))]
    minChanges[-1] = [0] * 5 # guard
    for i in xrange(len(S) - 1, -1, -1):
        letCode = ord(S[i]) - ord('a')
        for first in xrange(26):
            curTree = prefixTree[first]
            j = 1
            if first == letCode:
                while curTree and i + j < len(S):
                    if curTree[FLAG]:
                        editOffset = min(j, 4)
                        for k in xrange(editOffset+1):
                            minChanges[i][k] = min(minChanges[i][k],
                                    minChanges[i+j][0])
                        for k in xrange(1, 4 - editOffset + 1):
                            minChanges[i][editOffset+k] = (
                                    min(minChanges[i][editOffset+k],
                                        minChanges[i+j][k]))
                    curTree = curTree[ord(S[i+j]) - ord('a')]
                    j += 1
            else:
                while curTree and i + j < len(S):
                    if curTree[FLAG]:
                        minChanges[i][0] = min(minChanges[i][0],
                                minChanges[i+j][max(5-j, 0)] + 1)
                    curTree = curTree[ord(S[i+j]) - ord('a')]
                    j += 1
    return min(minChanges[0])

def processFile(inp, out, prefixTree):
    fi = file(inp, 'r')
    fo = file(out, 'w')
    T = int(fi.readline())
    for casenum in xrange(1, T+1):
        case = fi.readline().strip()
        fo.write('Case #' + str(casenum) + ': ' + str(solveCase(case, prefixTree)) + '\n')
