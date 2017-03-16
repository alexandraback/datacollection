ff = 0
kg = 0
lm = 0

def rec (word, tt, s, kb):
    global ff
    global kg
    global lm

    if len(word) == s:
        tmp = 0
        for i in range(0, s+1):
             if word[i:i+len(tt)] == tt:
                  tmp += 1
        ff = max(ff, tmp)
        kg += tmp
        lm += 1
    else:
        for i in kb:
            rec(word + i, tt, s, kb)

t = int(raw_input())
for qq in range(t):
        k, l, s = map(int, raw_input().split())
        kb = raw_input()
        tt = raw_input()
        ff = 0
        kg = 0
        lm = 0
        rec("", tt, s, kb)
        print "Case #{}: {}".format(qq+1, round(ff - kg * 1.0 / lm, 7))
