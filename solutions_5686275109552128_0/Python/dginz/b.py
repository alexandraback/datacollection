#!/usr/bin/python3

import sys
import math

T = int(input())
for case in range(T):
    n = int(input())
    cakes = list(map(int, input().split()))

    bestResult = 1001
    initMax = max(cakes)

    for i in range(1, initMax + 1):
        operations = sum(map(lambda person: math.ceil(person / i) - 1, cakes))
        operations += i
        bestResult = min(bestResult, operations)

    print ("Case #%d: %d" % (case + 1, bestResult))

# вообще, есть 2 операции: разделить кучку или уменьшить все кучки на 1
# понятно, что все ожидания можно проводить только в начале, так как разделяемые поля могут от этого только уменьшиться
# существуют ситуации, в которых надо делить не пополам: 9 3 3 3 3 3 3 3 3 3 (6 3, 3 3 3)
# 
#

