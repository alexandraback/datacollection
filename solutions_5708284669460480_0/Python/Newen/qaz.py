
fname = 'C:\Users\itocar\Downloads\B-small-attempt0.in'

f = open(fname)

ln = f.readlines()

t = int(ln[0])

for i,l in enumerate(ln[1:]):
    if i % 3 == 0:
        k,l,s = [int(q) for q in l.split()]
    elif i%3 == 1:
        freq = {}
        for let in  l.strip():
            if let in freq:
                freq[let] = freq[let] + 1
            else:
                freq[let] = 1
        norm_freq = {}
        for q in freq:
            norm_freq[q] = float(freq[q])/float(len(l.strip()))
        #print  norm_freq
    elif i%3 == 2:
        exp_freq = 1.0
        flag = False
        for q in l.strip():
            if q in norm_freq:
                exp_freq = exp_freq * norm_freq[q]
            else:
                flag = True
                exp_freq = 0.0
        res = 0.0
        wrd= l.strip()
        gp = len(wrd)
        for q in range(1,len(wrd)):
            ln = len(wrd) - q
            if wrd[0:ln] == wrd[q:]:
                gp = q
                break
        if gp == len(wrd):
            mx = float(s/gp)
        else:
            mx = float((s-len(wrd))/gp) + 1.0
        res = mx - exp_freq*(s-len(wrd) + 1)
        if flag:
            res = 0.0
        print 'Case #' + str(i/3+1) + ': ' + str(res)
