import os

def find_max_length(k, dict, tr):
    if dict.has_key(k):
        ll = dict[k]
    else:
        return 1
    maxlen = 1

    for a in ll:
        if tr.count(a) >= 1:
            i = 0
            if i > maxlen:
                maxlen = i
        else:
            i = 1 + find_max_length(a, dict, tr+[a])
            if i > maxlen:
                maxlen = i
    return maxlen

fp = open('test')
of = open('416-03','w')
s = map(lambda x: x.strip(), fp.readlines())
allcnt = int(s[0])
cnt = 0
for i in range(allcnt):
    cnt += 1
    num = int(s[cnt])
    lala = {}
    baba = {}
    maxnum = 0
    cnt += 1
    aa = s[cnt].split(' ')
    for j in range(1, num + 1):
        lala[j] = int(aa[j-1])
    arr = []
    for k, v in lala.items():
        if baba.has_key(v):
            baba[v].append(k)
        else:
            baba[v] = [k]

    for k, ll in baba.items():


        alllen = []

        for abc in ll:
            alllen.append(find_max_length(abc, baba, [k, abc]))
        sorted(alllen)
        print ll, k, alllen

        if len(alllen) >= 2:
            arr.append(alllen[-1]+alllen[-2]+1)

        elif len(alllen) == 1:
            arr.append(alllen[-1]+ 1)


    sorted(arr)
    print >>of, 'Case #%d: %d' % (i+1, arr[-1])


