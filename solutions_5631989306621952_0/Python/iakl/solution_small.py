input_file = "A-small-attempt2.in"
output_file = "A-small-attempt2.out"

in_f = open(input_file)
T_read = False
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if not T_read:
        T = int(sl)
        T_read = True
        continue
    tcs.append(sl)
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    out_f.write("Case #" + str(tcn) + ": " + str(x) + "\n")

def GetLastWord(S, m):
    r = ""
    for ch in S:
        if ch == m:
            r = ch + r
        else:
            if len(r) > 0 and r[0] <= ch:
                r = ch + r
            else:
                r = r + ch
    return r

def SolveTestCase(S):
    if len(S) == 0:
        return ""
    m = S[0]
    for ch in S:
        if ch > m:
            m = ch
    return GetLastWord(S, m)

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

