import sys

path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
file = open(path, "r")
T = int(file.readline())

def factor(n):
    f = 1
    while n > 1:
        f = f * n
        n -= 1
    return f

for casenum in range(T):
    N = int(file.readline())
    ss = file.readline().strip().split()
    possible = True
    for i in range(len(ss)):
        s = ss[i]
        a , e = [s[0]], set(s[0])
        for j in range(1, len(s)):
            if s[j] == s[j-1]:
                continue
            else:
                if s[j] in e:
                    possible = False
                    break
                a.append(s[j])
                e.add(j)
        if not possible:
            break
        ss[i] = ''.join(a)

    if not possible:
        print("Case #{0}: {1}".format(casenum+1, 0))
        continue

    dic = {}
    for i in range(len(ss)):
        s = ss[i]
        for j in range(len(s)):
            if dic.get(s[j]) == None:
                dic[s[j]] = set()
            dic[s[j]].add(i)

    #print(dic)
    a = []
    for ch in dic.keys():
        if len(dic[ch]) >= 2:
            # all these strings need to be together
            count_1 = 0
            count_m = 0
            start, end = '', ''
            for idx in dic[ch]:
                s = ss[idx]
                if len(s) == 1:
                    count_1 += 1
                else:
                    count_m += 1
                    if s[0] == ch:
                        if end == '':
                            end = s
                        else:
                            possible = False
                            break
                    elif s[len(s)-1] == ch:
                        if start == '':
                            start = s
                        else:
                            possible = False
                            break
                    else:
                        possible = False
                        break
            if not possible:
                break

    if not possible:
        print("Case #{0}: {1}".format(casenum+1, 0))
        continue
    
    dic = {}
    for i in range(len(ss)):
        if dic.get(ss[i]) == None:
            dic[ss[i]] = 0
        dic[ss[i]] += 1

    while True:
        merged = False
        for s in dic.keys():
            for s2 in dic.keys():
                if s == s2:
                    continue
                if s[0] == s2[len(s2)-1]:
                    merged = True
                    dic[s2 + s] = dic[s] * dic[s2]
                elif s2[0] == s[len(s)-1]:
                    merged = True
                    dic[s + s2] = dic[s] * dic[s2]
                if merged:
                    del dic[s]
                    del dic[s2]
                    break
            if merged:
                break
        if not merged:
            break

    num = factor(len(dic))
    for key in dic.keys():
        num = num * dic[key]

    print("Case #{0}: {1}".format(casenum+1, num))
