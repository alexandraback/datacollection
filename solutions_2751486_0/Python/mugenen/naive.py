import sys

T = int(raw_input())
vowel = list('aeiou')
for i in xrange(1, T + 1):
    s, n = raw_input().split()
    n = int(n)
    
    check = 0
    index = 0
    length = len(s)
    add = 0
    for j in xrange(length):
        for k in xrange(j + 1, length + 1):
            count = 0
#            print s[j:k], j, k, count
            for c in s[j:k]:
                if c not in vowel:
                    count += 1
                    if count >= n:
                        add += 1
                        break
                else:
                    count = 0
    print "Case #{0}: {1}".format(i, add)

