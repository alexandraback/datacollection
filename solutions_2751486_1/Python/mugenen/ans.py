import sys

T = int(raw_input())
vowel = list('aeiou')
for i in xrange(1, T + 1):
    s, n = raw_input().split()
    n = int(n)
    
    last = -1
    index = 0
    count = 0
    length = len(s)
    add = 0
    for c in list(s):
        if c not in vowel:
            count += 1
            if count >= n:
                left = (index - n + 1) - last
                right = length - index
#                print index, s[index -n + 1:index + 1]
#                print left, right
                add += left * right
#                print index, left, right
                last = index - n + 1
        else:
            count = 0
        index += 1
    print "Case #{0}: {1}".format(i, add)

