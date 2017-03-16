import itertools as it

def findT(word, target):
    if len(target) > len(word):
        return 0
    res = 0
    for i in range(len(word)-(len(target)-1)):
        if word[i:i+len(target)] == target:
            res += 1
    return res

def makeAllWords(keys, S, target):
    allWords = list(it.product(keys, repeat = S))
    res = 0
    best = 0
    for word in allWords:
        word = ''.join(list(word))
        r = findT(word, target)
        res += r
        if r > best:
            best = r
    return best - res/float(len(allWords))

for i in range(input()):
    K, L, S = map(int, raw_input().split())
    keys = raw_input()
    target = raw_input()
    print 'Case #' + str(i+1) + ': ' + str(makeAllWords(keys, S, target))
    
