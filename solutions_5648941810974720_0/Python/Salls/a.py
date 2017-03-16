import sys

with open(sys.argv[1]) as f:
    lines = f.readlines()

words = zip(range(10), ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"))

class NotFound(Exception):
    pass

def remove_word(s, word):
    for c in word:
        if c in s:
            pos = s.find(c)
            s = s[:pos] + s[pos+1:]
        else:
            raise NotFound()
    return s

global memoized
memoized = None

def solve(s, words):
    #print s
    global memoized
    if len(s) == 0:
        return ""
    for i in range(len(words)):
        try:
            t = remove_word(s, words[i][1])
            #print "s:",s,"t:", t
            return str(words[i][0]) + solve(t, words[i:])
        except NotFound:
            pass
    raise NotFound()



T = int(lines[0],10)
for i, l in enumerate(lines[1:]):
    s = l.strip()
    memoized = dict()
    ans = solve(s,words)

    print ("Case #%d:" % (i+1)), ans

        

