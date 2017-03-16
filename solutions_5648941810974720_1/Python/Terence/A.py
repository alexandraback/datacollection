from collections import deque

ws = [("ZERO",0,'Z'),("SIX",6,'X'),("TWO",2,'W'),("FOUR",4,'U'),("EIGHT",8,'G'),("FIVE",5,'F'),("SEVEN",7,'S'),("ONE",1,'O'),("THREE",3,'R'),("NINE",9,'N')]
for i,(w,d,c) in enumerate(ws):
    assert(w.count(c)>0)
    for j in range(i+1,len(ws)):
        assert(ws[j][0].count(c) == 0)

def digits(s):
    cnt = [0]*26
    for c in s:
        cnt[ord(c)-65] += 1
    ds = ''
    for w,d,c in ws:
        cx = cnt[ord(c)-65] / w.count(c)
        ds += str(d)*cx
        for wc in w:
            cnt[ord(wc)-65] -= cx
    return ''.join(sorted(ds))

t = int(raw_input())
for icase in range(1,t+1):
    s = raw_input().strip()
    print 'Case #%d: %s' % (icase,digits(s))