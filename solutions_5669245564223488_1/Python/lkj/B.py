#inp: list of sets of connected train cars
#out: num of ways to connect them to a single train % 1'000'000'007
#       rules: all same letters are adjacent

#let's connect all parts which have to be connected from sl
#while doing this, we already have to count possibilities
#because ther may be [bc ccc cc ccc ca] -> 3! ways
#but there can only be one list after this processing for a
#   given input (start and end parts of a part aren't interchangeable
#   if it's even possible to combine them according to the rules
#if it's not possible (what we would notice in this stage), res = 0

#while i != '{' loop:
#   - we have to merge all strs in subsl
#   - if it's possible multiply poss by number of possibilities
#   - if it's impossible, the whole sl is impossible to merge

from math import factorial

def remsubsli(sl, a):
    subsl = []
    for i in sl:
        if a in i:
            subsl.append(i)
    for i in subsl:
        sl.remove(i)
    return (sl, subsl)

def mergesubsl(subsl, a):
    if len(subsl) == 0:
        return (1, '')
    elif len(subsl) == 1:
        #CHECK NEEDED!!!
        ap = True
        s = subsl[0]
        poss = 1
        for i in range(s.find(a), len(s)-1):
            if ap and s[i+1] != a:
                ap = False
            elif not ap and s[i+1] == a:
                poss = 0
                break
        if poss == 0:
            return (0, '')
        return (1, subsl[0])

    cna = 0
    begin = ''
    end = ''
    for i in subsl:
        if len(set(i)) != 1:
            cna += 1
            if i[-1] == a:
                begin = i
            elif i[0] == a:
                end = i
    if cna > 2:
        poss = 0
        s = ''
    else:
        poss = factorial(len(subsl)-cna)
        s = begin
        if begin != '':
            subsl.remove(begin)
        if end != '':
            subsl.remove(end)
        for i in subsl:
            s += i
        s += end
        #check needed
        ap = True
        for i in range(s.find(a), len(s)-1):
            if ap and s[i+1] != a:
                ap = False
            elif not ap and s[i+1] == a:
                poss = 0
                break
    if poss == 0:
        return (0, '')
    return (poss, s)


t = int(input())
for tc in range(1, t+1):
    n = int(input())
    sl = input().split()
    poss = 1
    i = 'a'
    while i != '{':
        (sl, subsl) = remsubsli(sl, i)
        (newp, news) = mergesubsl(subsl, i)
        poss = (poss * newp) % 1000000007
        if news != '':
            sl.append(news)
        if poss == 0:
            break
        i = chr(ord(i)+1)
    poss = (poss * factorial(len(sl))) % 1000000007
    print('Case #%i: %i' % (tc, poss))
        
