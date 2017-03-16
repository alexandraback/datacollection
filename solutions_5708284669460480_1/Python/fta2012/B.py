
from collections import defaultdict
T = int(raw_input())

for t in xrange(T):
    k, l, s = [int(x) for x in raw_input().split(' ')]
    letters = raw_input()
    target = raw_input()
    pletters = defaultdict(float)
    for c in letters:
        pletters[c] += 1.0 / len(letters)
    def probWord(word):
        p = 1
        for c in word:
            if c not in pletters:
                p *= 0
            else:
                p *= pletters[c]
        return p
    expectedFound = max(0, s - l + 1) * probWord(target)

    if l > s or any((c not in pletters) for c in target):
        maxToBring = 0
    else:
        repeat = 0
        for i in xrange(1, l + 1):
            if target[i:] == target[:len(target) - i]:
                repeat = i
                break
        maxToBring = 1 + (s - l) / repeat 

    print 'Case #' + str(t + 1) + ': ' + str('%.07f' % (maxToBring - expectedFound))

