import sys
fin = open("A-large.in")
fout = open("ans.out", "w")

def minus(am, w):
    for q in w:
        if q in am:
            am[q] -= 1


t = int(fin.readline())
for q in range(1, t + 1):
    l = list(fin.readline())
    am = dict()
    for i in l:
        if i not in am:
            am[i] = 0
        am[i] += 1
    ans = []
    while am.get('Z', 0):
        ans += [0]
        minus(am, ['Z', 'E', 'R', 'O'])
    while am.get('W', 0):
        ans += [2]
        minus(am, ['T', 'W', 'O'])
    while am.get('G', 0):
        ans += [8]
        minus(am, ['E', 'I', 'G', 'H', 'T'])
    while am.get('U', 0):
        ans += [4]
        minus(am, ['F', 'O', 'U', 'R'])
    while am.get('F', 0):
        ans += [5]
        minus(am, ['F', 'I', "V", 'E'])
    while am.get('X', 0):
        ans += [6]
        minus(am, ['S', 'I', 'X'])
    while am.get('V', 0):
        ans += [7]
        minus(am, ['S', 'E', 'V', 'E', 'N'])
    while am.get('I', 0):
        ans += [9]
        minus(am, ['N', 'I', 'N', 'E'])
    while am.get('N', 0):
        ans += [1]
        minus(am, ['O', 'N', 'E'])
    while am.get('T', 0):
        ans += [3]
        minus(am, ['T', 'H', 'R', 'E', 'E'])
    ans.sort()
    print("Case #", q, ': ', ''.join(map(str, ans)), sep = '', file = fout)
    
fout.close()