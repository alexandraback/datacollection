t = int(raw_input(''))

for i in range(1,t+1):
    d = {s : 0 for s in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
    number = raw_input('')
    for n in number:
        d[n]+=1
    cnt = [0]*10
    cnt[4] = d['U']
    cnt[6] = d['X']
    cnt[2] = d['W']
    cnt[0] = d['Z']
    cnt[7] = d['S'] - d['X']
    cnt[5] = d['F'] - d['U']
    cnt[1] = d['O'] - d['W'] - d['U'] -d['Z']
    cnt[8] = d['G']
    cnt[3] = d['T'] - cnt[2] - cnt[8]
    cnt[9] = (d['N'] - cnt[1] - cnt[7])/2;
    print 'Case #%d:'%i,
    s=''
    for j in range(0,10):
        for k in range(cnt[j]):
            s=s+str(j)
    print s 

