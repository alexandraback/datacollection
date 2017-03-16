def binM(x,l):
    return bin(x)[2:].zfill(l)

t = input()
for case in xrange(1,t+1):
    n = input()
    ft = list()
    st = list()
    fake = 0
    for i in xrange(n):
        a,b = raw_input().split()
        ft.append(a)
        st.append(b)
    for i in xrange(1, 2**n):
        sel = binM(i,n)
        rft = list()
        rst = list()
        kft = list()
        kst = list()
        count = sel.count('0')
        for rr,j in enumerate(sel):
            if j == '1':
                rft.append(ft[rr])
                rst.append(st[rr]) 
            else:
                kft.append(ft[rr])
                kst.append(st[rr]) 
        chk = True
        for j in xrange(len(rft)):
            tf = rft[j]
            ts = rst[j]
            rft[j] = ''
            rst[j] = ''
            if tf in rft and ts in rst:
                chk = False
                break
            rft[j] = tf
            rst[j] = ts
#        print chk, i

        for j in xrange(len(kft)):
            if not chk:
                break
            if kft[j] in rft and kst[j] in rst:
                continue
            else:
                chk = False
                break
        if chk:
            fake = max(fake, count)
#        print chk, i
        
    print "Case #%d: %d"%(case,fake)
