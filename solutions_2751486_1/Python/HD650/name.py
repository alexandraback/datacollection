import os, sys

infile = sys.stdin

class Group(object):
    def __init__(self, begin, end):
        self.begin = begin
        self.end = end

def good(ch):
    return ch not in 'aeiou'

def solve(word, size):
    #print 'solving (%s,%d)' % (word, size)
    groups = list()
    i = 0
    while i < len(word):
        if not good(word[i]):
            i += 1
            continue
        else:
            j = i + 1
            while j < len(word):
                if not good(word[j]):
                    break
                j += 1
            if j - i >= size:
                groups.append(Group(i, j - 1))
            i = j

    # for group in groups:
    #     print "%d, %d" % (group.begin, group.end)

    left = 0
    idx = 0
    count = 0
    num = len(word)
    
    while True:
        if idx == len(groups):
            break

        cur = groups[idx]
        right = cur.begin + size - 1


        while left <= cur.begin:
            count += (num - right)
            left += 1

        right += 1
        while right <= cur.end:
            count += (num - right)
            left += 1
            right += 1

        idx += 1
    
    return count

if __name__ == "__main__":
    T = int(infile.readline())
    for i in range(T):
        line = infile.readline().split()
        word = line[0]
        size = int(line[1])
        ret = solve(word, size)
        print "Case #%d: %d" % (i+1, ret)
