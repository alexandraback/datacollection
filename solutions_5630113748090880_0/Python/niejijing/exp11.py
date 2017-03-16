import os

fp = open('test')
of = open('416-02','w')
s = map(lambda x: x.strip(), fp.readlines())
allcnt = int(s[0])
cnt = 0
for i in range(allcnt):
    cnt += 1
    num = int(s[cnt])

    lala = {}
    arr = []
    for j in range(2*num-1):
        cnt += 1
        aa = s[cnt].split(' ')
        for ch in aa:
            if lala.has_key(ch):
                lala[ch] = lala[ch] + 1
            else:
                lala[ch] = 1
    for k, v in lala.items():
        if v%2 == 1:
            arr.append(k)

    arr = sorted(arr, key=lambda x: int(x))
    kk = ''
    for ch in arr:
        kk = kk + ' ' + ch

    print >> of, 'Case #%d:%s' % (i+1, kk)
